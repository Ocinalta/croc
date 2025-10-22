// Copyright 2024 Politecnico di Torino.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 2.0 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-2.0. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//
// File: conv1d.cpp
// Author(s):
//   Luigi Giuffrida
// Date: 08/11/2024
// Description: TB for the OBI CONV1D accelerator

#include <iostream>
#include <getopt.h>
#include <random>
#include <time.h>

// Verilator libraries
#include <verilated.h>
#include <verilated_fst_c.h>

// DUT header
#include "Vconv1d_tb_wrapper.h"
#include "conv1d_control_reg.h"

// Testbench components
#include "tb_macros.hh"
#include "tb_components.hh"

// Test data
#include "data.h"

// Defines
// -------
#define FST_FILENAME "logs/waves.fst"
#define END_OF_RESET_TIME 5
#define MAX_SIM_CYCLES 2e6
#define MAX_SIM_TIME (MAX_SIM_CYCLES * 4)
#define WATCHDOG_TIMEOUT 5000 // cycles to wait for a program step to complete
#define END_OF_TEST_TIMEOUT 10 // cycles between done assertion and simulation end

// Generate clock and reset
void clkGen(Vconv1d_tb_wrapper *dut);
void rstDut(Vconv1d_tb_wrapper *dut, vluint64_t sim_time);

// Generate OBI transactions
ObiReqTx *genObiWriteReqTx(const vluint32_t addr_offs, const vluint32_t wdata, vluint8_t be);
ObiReqTx *genObiReadReqTx(const vluint32_t addr_offs);
RegReqTx *genRegWriteReqTx(const vluint32_t addr_offs, const vluint32_t wdata, vluint8_t wstrb);
RegReqTx *genRegReadReqTx(const vluint32_t addr_offs);

// Run a number of cycles
void runCycles(unsigned int ncycles, Vconv1d_tb_wrapper *dut, uint8_t gen_waves, VerilatedFstC *trace);

// Global variables
vluint64_t sim_cycles = 0;
TbLogger logger;    // testbench logger

reg_rsp_t reg_rsp;


int main(int argc, char *argv[])
{
    // Define command-line options
    const option longopts[] = {
        {"log_level", required_argument, NULL, 'l'},
        {"gen_waves", required_argument, NULL, 'w'},
        {"seed", required_argument, NULL, 's'},
        {NULL, 0, NULL, 0}
    };

    // Process command-line options
    // ----------------------------
    int opt; // current option
    int prg_seed = time(NULL);
    bool gen_waves = true;
    while ((opt = getopt_long(argc, argv, "l:w:", longopts, NULL)) >= 0)
    {
        switch (opt)
        {
        case 'l': // set the log level
            logger.setLogLvl(optarg);
            TB_CONFIG("Log level set to %s", optarg);
            break;
        case 'w': // generate waves
            if (!strcmp(optarg, "true")) {
                gen_waves = 1;
                TB_CONFIG("Waves enabled");
            }
            else {
                gen_waves = 0;
                TB_CONFIG("Waves disabled");
            }
            break;
        case 's': // set the seed
            prg_seed = atoi(optarg);
            TB_CONFIG("Seed set to %d", prg_seed);
            break;
        default:
            TB_ERR("ERROR: unrecognised option %c.\n", opt);
            exit(EXIT_FAILURE);
        }
    }

    // Create Verilator simulation context
    VerilatedContext *cntx = new VerilatedContext;

    // Pass simulation context to the logger
    logger.setSimContext(cntx);

    if (gen_waves)
    {
        Verilated::mkdir("logs");
        cntx->traceEverOn(true);
    }

    // Instantiate DUT
    Vconv1d_tb_wrapper *dut = new Vconv1d_tb_wrapper(cntx);

    // Set the file to store the waveforms in
    VerilatedFstC *trace = NULL;
    if (gen_waves)
    {
        trace = new VerilatedFstC;
        dut->trace(trace, 10);
        trace->open(FST_FILENAME);
    }

    // TB components
    Drv *drv = new Drv(dut);
    Scb *scb = new Scb();
    ReqMonitor *reqMon = new ReqMonitor(dut, scb);
    RspMonitor *rspMon = new RspMonitor(dut, scb);

    // Initialize PRG
    srand(prg_seed);

    // Simulation program
    // ------------------
    // TODO: Define simulation program variables
    uint32_t data = 0; //variabile aggiunta per scrivere il registro di controllo
    ObiReqTx *obi_req = NULL;
    vluint32_t obi_rdata = 0;
    uint32_t obi_data = 0;
    uint32_t obi_addr = 0;
    uint32_t ram_addr = 0;
    uint32_t tmp = 0;
    unsigned int data_size = 0;
    unsigned int column_number = 0; //column dei dati di ingresso
    bool obi_accepted = 0;

    RegReqTx *reg_req = NULL;
    vluint32_t reg_rdata = 0;
    bool reg_accepted = 0;

    bool irq_received = 0;

    bool end_of_test = false;
    unsigned int exit_timer = 0;
    unsigned int watchdog = 0;
    unsigned int prev_step_cnt = 0;
    unsigned int step_cnt = 0;
    unsigned int result_index = 0;

    TB_LOG(LOG_LOW, "Starting simulation...");
    while (!cntx->gotFinish() && cntx->time() < MAX_SIM_TIME)
    {
        // Generate clock and reset
        rstDut(dut, cntx->time());
        clkGen(dut);

        // Evaluate simulation step
        dut->eval();

        if (dut->clk_i == 1 && cntx->time() > END_OF_RESET_TIME)
        {
            switch (step_cnt)
            {
/*------------------------------SRAM 1 REFRESH FILTER WRITING------------------------------*/
            // Write weight matrix F to accelerator private memory - Filter 1
            case 0:
                if (!obi_accepted) {
                    obi_data = F[obi_addr] << 24 | F[obi_addr + 5] << 16 | F[obi_addr + 10] << 8 | F[obi_addr + 15];
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                // Prepare next data element
                ram_addr += 0x1; //Next cycle, we will write on the next sram address 
                data_size += 0x1; 
                if (ram_addr % 5 == 0 && ram_addr != 0) { //If we wrote 5 filters weigth, we need to go to the next row
                    obi_addr += 0x10;
                }
                else {
                    obi_addr += 0x1;
                }

                if (data_size == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
            break;

            // Wait some cycles - reset some variables
            case 1 ... 3:
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            break;

            // Read back stored data
            case 4:
                if (!obi_accepted) {
                    TB_LOG(LOG_HIGH, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                data_size += 0x4;
                if (ram_addr == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
            break;
            
            // Wait some cycles - reset some variables
            case 5 ... 7:
                obi_addr = 0;
                data_size = 0;
                step_cnt++;
            break;
/*------------------------------SRAM 1 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 0 to 19
            case 8:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 1 sram_addr: %x", ram_addr);
                    if (ram_addr == 0x14 || ram_addr == 0x15 || ram_addr == 0x2a || ram_addr == 0x2b || ram_addr == 0x40 || ram_addr == 0x41 || ram_addr == 0x56 || ram_addr == 0x57)  {    // In the described address, we will store the padding 
                        obi_data = 0x0;
                    } else {
                        obi_data = A[obi_addr] << 24 | A[obi_addr + 128] << 16 | A[obi_addr + 256] << 8 | A[obi_addr + 384];    //<<24 to store in the first 8 bit starting from the left(MSB), <<16 the second word, <<8 the third word, in the end we have LSB.
                        if (column_number==19){ //If we are in the last column we can store in the sram, we need to move the index obi_addr to 4 rows below
                            obi_addr += 0x1ed;
                            column_number=0;
                        } else {
                            obi_addr += 0x1;
                            column_number++;
                            TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                        }                  
                    }
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);               
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;

            // Wait some cycles - reset some variables
            case 9 ... 11:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break; 

            // Check if data are written correctly
            case 12:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;

            // Wait some cycles - reset some variables
            case 13 ... 15:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break; 

/*------------------------------START BIT SETTING - STARTING SIMULATION------------------------------*/ 
            // Start bit set to 1
            case 16:  
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##A Setting start bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_START_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); // Assegno il dato usando come indirizzo relativo quello del control register       
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;
    
            // Reading and check of the start bit
            case 17: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##B Reading back control register to check start bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_START_BIT)){
                    TB_LOG(LOG_LOW, "--- Start correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: start is set to 0");
                }
                reg_accepted = false;
                step_cnt++;                
            break;
/*------------------------------LFB1 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 18:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 19: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 20:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 21: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 1 REFRESH------------------------------*/   
            case 22: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    } else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 1 REFRESH------------------------------*/
            case 23: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 24:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;
/*------------------------------SRAM 2 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 16 to 37    
            case 25:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 2 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+16] << 24 | A[obi_addr + 128+16] << 16 | A[obi_addr + 256+16] << 8 | A[obi_addr + 384+16];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 26 ... 28:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 29:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 30 ... 32:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;      

/*------------------------------LFB2 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 33:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 34: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 35:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 36: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 2 REFRESH------------------------------*/
            case 37: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    } else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;          
/*------------------------------OUTPUT CHECK OF SRAM 2 REFRESH------------------------------*/
            case 38: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 39:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;
/*------------------------------SRAM 3 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 34 to 55    
            case 40:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 3 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+34] << 24 | A[obi_addr + 128+34] << 16 | A[obi_addr + 256+34] << 8 | A[obi_addr + 384+34];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 41 ... 43:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 44:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 45 ... 47:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB3 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 48:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 49: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 50:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 51: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 3 REFRESH------------------------------*/
            case 52: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break; 
/*------------------------------OUTPUT CHECK OF SRAM 3 REFRESH------------------------------*/
            case 53: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 54:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;            
/*------------------------------SRAM 4 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 52 to 73    
            case 55:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 4 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+52] << 24 | A[obi_addr + 128+52] << 16 | A[obi_addr + 256+52] << 8 | A[obi_addr + 384+52];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 56 ... 58:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 59:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 60 ... 62:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB4 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 63:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 64: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 65:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 66: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 4 REFRESH------------------------------*/
            case 67: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 4 REFRESH------------------------------*/
            case 68: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 69:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;             
/*------------------------------SRAM 5 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 70 to 91    
            case 70:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 5 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+70] << 24 | A[obi_addr + 128+70] << 16 | A[obi_addr + 256+70] << 8 | A[obi_addr + 384+70];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 71 ... 73:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 74:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 75 ... 77:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB5 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 78:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 79: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 80:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 81: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 5 REFRESH------------------------------*/
            case 82: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
 /*------------------------------OUTPUT CHECK OF SRAM 5 REFRESH------------------------------*/
            case 83: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 84:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;            
/*------------------------------SRAM 6 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 88 to 109    
            case 85:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 6 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+88] << 24 | A[obi_addr + 128+88] << 16 | A[obi_addr + 256+88] << 8 | A[obi_addr + 384+88];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 86 ... 88:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 89:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 90 ... 92:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB6 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 93:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 94: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 95:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 96: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 6 REFRESH------------------------------*/
            case 97: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 6 REFRESH------------------------------*/
            case 98: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 99:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break; 
/*------------------------------SRAM 7 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 106 to 127    
            case 100:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 7 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+106] << 24 | A[obi_addr + 128+106] << 16 | A[obi_addr + 256+106] << 8 | A[obi_addr + 384+106];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 101 ... 103:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 104:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 105 ... 107:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB7 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 108:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 109: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 110:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 111: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 7 REFRESH------------------------------*/
            case 112: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 7 REFRESH------------------------------*/
            case 113: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x80) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 114:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x80) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break; 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 
/*------------------------------END OF FILTER NUMBER 1------------------------------*/ 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 

/*------------------------------SRAM 8 REFRESH FILTER WRITING------------------------------*/
            // Wait some cycles - reset some variables
            case 115 ... 117:
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            break;

            // Write weight matrix F to accelerator private memory - Filter 2
            case 118:
                if (!obi_accepted) {
                    obi_data = F[obi_addr+80] << 24 | F[obi_addr + 5+80] << 16 | F[obi_addr + 10+80] << 8 | F[obi_addr + 15+80];
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                // Prepare next data element
                ram_addr += 0x1; //Next cycle, we will write on the next sram address 
                data_size += 0x1; 
                if (ram_addr % 5 == 0 && ram_addr != 0) { //If we wrote 5 filters weigth, we need to go to the next row
                    obi_addr += 0x10;
                }
                else {
                    obi_addr += 0x1;
                }

                if (data_size == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
            break;

            // Wait some cycles - reset some variables
            case 119 ... 121:
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            break;

            // Read back stored data
            case 122:
                if (!obi_accepted) {
                    TB_LOG(LOG_HIGH, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                data_size += 0x4;
                if (ram_addr == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
            break;
            
            // Wait some cycles - reset some variables
            case 123 ... 125:
                obi_addr = 0;
                data_size = 0;
                step_cnt++;
            break;
/*------------------------------SRAM 8 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 0 to 19
            case 126:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 8 sram_addr: %x", ram_addr);
                    if (ram_addr == 0x14 || ram_addr == 0x15 || ram_addr == 0x2a || ram_addr == 0x2b || ram_addr == 0x40 || ram_addr == 0x41 || ram_addr == 0x56 || ram_addr == 0x57)  {    // In the described address, we will store the padding 
                        obi_data = 0x0;
                    } else {
                        obi_data = A[obi_addr] << 24 | A[obi_addr + 128] << 16 | A[obi_addr + 256] << 8 | A[obi_addr + 384];    //<<24 to store in the first 8 bit starting from the left(MSB), <<16 the second word, <<8 the third word, in the end we have LSB.
                        if (column_number==19){ //If we are in the last column we can store in the sram, we need to move the index obi_addr to 4 rows below
                            obi_addr += 0x1ed;
                            column_number=0;
                        } else {
                            obi_addr += 0x1;
                            column_number++;
                            TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                        }                  
                    }
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);               
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;

            // Wait some cycles - reset some variables
            case 127 ... 129:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break; 

            // Check if data are written correctly
            case 130:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;

            // Wait some cycles - reset some variables
            case 131 ... 133:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break; 
/*------------------------------LFB8 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 134:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 135: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 136:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 137: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 8 REFRESH------------------------------*/
            case 138: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 8 REFRESH------------------------------*/
            case 139: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 140:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break; 
/*------------------------------SRAM 9 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 16 to 37    
            case 141:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 9 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+16] << 24 | A[obi_addr + 128+16] << 16 | A[obi_addr + 256+16] << 8 | A[obi_addr + 384+16];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 142 ... 144:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 145:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 146 ... 148:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;      

/*------------------------------LFB9 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 149:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 150: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 151:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 152: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 9 REFRESH------------------------------*/
            case 153: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    } else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;          
/*------------------------------OUTPUT CHECK OF SRAM 9 REFRESH------------------------------*/
            case 154: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 155:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;
/*------------------------------SRAM 10 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 34 to 55    
            case 156:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 10 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+34] << 24 | A[obi_addr + 128+34] << 16 | A[obi_addr + 256+34] << 8 | A[obi_addr + 384+34];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 157 ... 159:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 160:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 161 ... 163:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB10 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 164:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 165: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 166:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 167: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 10 REFRESH------------------------------*/
            case 168: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break; 
/*------------------------------OUTPUT CHECK OF SRAM 10 REFRESH------------------------------*/
            case 169: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 170:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;            
/*------------------------------SRAM 11 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 52 to 73    
            case 171:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 11 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+52] << 24 | A[obi_addr + 128+52] << 16 | A[obi_addr + 256+52] << 8 | A[obi_addr + 384+52];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 172 ... 174:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 175:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 176 ... 178:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB11 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 179:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 180: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 181:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 182: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 11 REFRESH------------------------------*/
            case 183: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 11 REFRESH------------------------------*/
            case 184: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 185:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;             
/*------------------------------SRAM 12 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 70 to 91    
            case 186:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 12 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+70] << 24 | A[obi_addr + 128+70] << 16 | A[obi_addr + 256+70] << 8 | A[obi_addr + 384+70];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 187 ... 189:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 190:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 191 ... 193:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB12 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 194:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 195: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 196:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 197: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 12 REFRESH------------------------------*/
            case 198: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
 /*------------------------------OUTPUT CHECK OF SRAM 12 REFRESH------------------------------*/
            case 199: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 200:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;            
/*------------------------------SRAM 13 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 88 to 109    
            case 201:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 13 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+88] << 24 | A[obi_addr + 128+88] << 16 | A[obi_addr + 256+88] << 8 | A[obi_addr + 384+88];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 202 ... 204:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 205:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 206 ... 208:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB13 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 209:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 210: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 211:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 212: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 13 REFRESH------------------------------*/
            case 213: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 13 REFRESH------------------------------*/
            case 214: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 215:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break; 
/*------------------------------SRAM 14 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 106 to 127    
            case 216:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 14 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+106] << 24 | A[obi_addr + 128+106] << 16 | A[obi_addr + 256+106] << 8 | A[obi_addr + 384+106];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 217 ... 219:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 220:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 221 ... 223:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB14 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 224:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 225: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 226:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 227: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 14 REFRESH------------------------------*/
            case 228: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 14 REFRESH------------------------------*/
            case 229: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x80) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 230:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x80) {
                    ram_addr = 0;
                    data_size = 0;
                    step_cnt++;
                }
            break; 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 
/*------------------------------END OF FILTER NUMBER 2------------------------------*/ 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 

/*------------------------------SRAM 15 REFRESH FILTER WRITING------------------------------*/
            // Write weight matrix F to accelerator private memory - Filter 3
            case 231:
                if (!obi_accepted) {
                    obi_data = F[obi_addr + 160] << 24 | F[obi_addr + 165] << 16 | F[obi_addr + 170] << 8 | F[obi_addr + 175];
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                // Prepare next data element
                ram_addr += 0x1; //Next cycle, we will write on the next sram address 
                data_size += 0x1; 
                if (ram_addr % 5 == 0 && ram_addr != 0) { //If we wrote 5 filters weigth, we need to go to the next row
                    obi_addr += 0x10;
                }
                else {
                    obi_addr += 0x1;
                }

                if (data_size == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
            break;

            // Wait some cycles - reset some variables
            case 232 ... 234:
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            break;

            // Read back stored data
            case 235:
                if (!obi_accepted) {
                    TB_LOG(LOG_HIGH, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                data_size += 0x4;
                if (ram_addr == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
            break;
            
            // Wait some cycles - reset some variables
            case 236 ... 238:
                obi_addr = 0;
                data_size = 0;
                step_cnt++;
            break;
/*------------------------------SRAM 15 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 0 to 19
            case 239:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 15 sram_addr: %x", ram_addr);
                    if (ram_addr == 0x14 || ram_addr == 0x15 || ram_addr == 0x2a || ram_addr == 0x2b || ram_addr == 0x40 || ram_addr == 0x41 || ram_addr == 0x56 || ram_addr == 0x57)  {    // In the described address, we will store the padding 
                        obi_data = 0x0;
                    } else {
                        obi_data = A[obi_addr] << 24 | A[obi_addr + 128] << 16 | A[obi_addr + 256] << 8 | A[obi_addr + 384];    //<<24 to store in the first 8 bit starting from the left(MSB), <<16 the second word, <<8 the third word, in the end we have LSB.
                        if (column_number==19){ //If we are in the last column we can store in the sram, we need to move the index obi_addr to 4 rows below
                            obi_addr += 0x1ed;
                            column_number=0;
                        } else {
                            obi_addr += 0x1;
                            column_number++;
                            TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                        }                  
                    }
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);               
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;

            // Wait some cycles - reset some variables
            case 240 ... 242:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break; 

            // Check if data are written correctly
            case 243:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;

            // Wait some cycles - reset some variables
            case 244 ... 246:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break; 

/*------------------------------LFB15 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 247:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 248: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 249:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 250: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 15 REFRESH------------------------------*/   
            case 251: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    } else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 15 REFRESH------------------------------*/
            case 252: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 253:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;
/*------------------------------SRAM 16 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 16 to 37    
            case 254:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 16 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+16] << 24 | A[obi_addr + 128+16] << 16 | A[obi_addr + 256+16] << 8 | A[obi_addr + 384+16];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 255 ... 257:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 258:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 259 ... 261:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;      

/*------------------------------LFB16 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 262:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 263: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 264:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 265: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 16 REFRESH------------------------------*/
            case 266: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    } else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;          
/*------------------------------OUTPUT CHECK OF SRAM 16 REFRESH------------------------------*/
            case 267: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 268:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;
/*------------------------------SRAM 17 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 34 to 55    
            case 269:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 17 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+34] << 24 | A[obi_addr + 128+34] << 16 | A[obi_addr + 256+34] << 8 | A[obi_addr + 384+34];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 270 ... 272:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 273:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 274 ... 276:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB17 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 277:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 278: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 279:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 280: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 17 REFRESH------------------------------*/
            case 281: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break; 
/*------------------------------OUTPUT CHECK OF SRAM 17 REFRESH------------------------------*/
            case 282: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 283:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;            
/*------------------------------SRAM 18 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 52 to 73    
            case 284:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 18 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+52] << 24 | A[obi_addr + 128+52] << 16 | A[obi_addr + 256+52] << 8 | A[obi_addr + 384+52];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 285 ... 287:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 288:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 289 ... 291:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB18 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 292:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 293: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 294:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 295: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 18 REFRESH------------------------------*/
            case 296: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 18 REFRESH------------------------------*/
            case 297: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 298:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;             
/*------------------------------SRAM 19 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 70 to 91    
            case 299:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 19 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+70] << 24 | A[obi_addr + 128+70] << 16 | A[obi_addr + 256+70] << 8 | A[obi_addr + 384+70];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 300 ... 302:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 303:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 304 ... 306:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB19 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 307:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 308: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 309:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 310: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 19 REFRESH------------------------------*/
            case 311: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
 /*------------------------------OUTPUT CHECK OF SRAM 19 REFRESH------------------------------*/
            case 312: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 313:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;            
/*------------------------------SRAM 20 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 88 to 109    
            case 314:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 20 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+88] << 24 | A[obi_addr + 128+88] << 16 | A[obi_addr + 256+88] << 8 | A[obi_addr + 384+88];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 315 ... 317:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 318:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 319 ... 321:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB20 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 322:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 323: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 324:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 325: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 20 REFRESH------------------------------*/
            case 326: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 20 REFRESH------------------------------*/
            case 327: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 328:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break; 
/*------------------------------SRAM 21 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 106 to 127    
            case 329:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 21 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+106] << 24 | A[obi_addr + 128+106] << 16 | A[obi_addr + 256+106] << 8 | A[obi_addr + 384+106];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 330 ... 332:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 333:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 334 ... 336:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB21 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 337:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 338: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 339:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 340: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 21 REFRESH------------------------------*/
            case 341: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 21 REFRESH------------------------------*/
            case 342: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x80) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 343:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x80) {
                    ram_addr = 0;
                    data_size = 0;
                    step_cnt++;
                }
            break; 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 
/*------------------------------END OF FILTER NUMBER 3------------------------------*/ 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 

/*------------------------------SRAM 22 REFRESH FILTER WRITING------------------------------*/
            // Wait some cycles - reset some variables
            case 344 ... 345:
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            break;

            // Write weight matrix F to accelerator private memory - Filter 4
            case 346:
                if (!obi_accepted) {
                    obi_data = F[obi_addr+240] << 24 | F[obi_addr + 245] << 16 | F[obi_addr + 250] << 8 | F[obi_addr + 255];
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                // Prepare next data element
                ram_addr += 0x1; //Next cycle, we will write on the next sram address 
                data_size += 0x1; 
                if (ram_addr % 5 == 0 && ram_addr != 0) { //If we wrote 5 filters weigth, we need to go to the next row
                    obi_addr += 0x10;
                }
                else {
                    obi_addr += 0x1;
                }

                if (data_size == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
            break;

            // Wait some cycles - reset some variables
            case 347 ... 349:
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            break;

            // Read back stored data
            case 350:
                if (!obi_accepted) {
                    TB_LOG(LOG_HIGH, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                data_size += 0x4;
                if (ram_addr == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
            break;
            
            // Wait some cycles - reset some variables
            case 351 ... 353:
                obi_addr = 0;
                data_size = 0;
                step_cnt++;
            break;
/*------------------------------SRAM 22 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 0 to 19
            case 354:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 22 sram_addr: %x", ram_addr);
                    if (ram_addr == 0x14 || ram_addr == 0x15 || ram_addr == 0x2a || ram_addr == 0x2b || ram_addr == 0x40 || ram_addr == 0x41 || ram_addr == 0x56 || ram_addr == 0x57)  {    // In the described address, we will store the padding 
                        obi_data = 0x0;
                    } else {
                        obi_data = A[obi_addr] << 24 | A[obi_addr + 128] << 16 | A[obi_addr + 256] << 8 | A[obi_addr + 384];    //<<24 to store in the first 8 bit starting from the left(MSB), <<16 the second word, <<8 the third word, in the end we have LSB.
                        if (column_number==19){ //If we are in the last column we can store in the sram, we need to move the index obi_addr to 4 rows below
                            obi_addr += 0x1ed;
                            column_number=0;
                        } else {
                            obi_addr += 0x1;
                            column_number++;
                            TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                        }                  
                    }
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);               
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;

            // Wait some cycles - reset some variables
            case 355 ... 357:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break; 

            // Check if data are written correctly
            case 358:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;

            // Wait some cycles - reset some variables
            case 359 ... 361:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break; 
/*------------------------------LFB22 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 362:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 363: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 364:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 365: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 22 REFRESH------------------------------*/
            case 366: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 22 REFRESH------------------------------*/
            case 367: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 368:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break; 
/*------------------------------SRAM 23 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 16 to 37    
            case 369:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 23 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+16] << 24 | A[obi_addr + 128+16] << 16 | A[obi_addr + 256+16] << 8 | A[obi_addr + 384+16];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 370 ... 372:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 373:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 374 ... 376:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;      

/*------------------------------LFB23 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 377:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 378: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 379:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 380: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 23 REFRESH------------------------------*/
            case 381: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    } else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;          
/*------------------------------OUTPUT CHECK OF SRAM 23 REFRESH------------------------------*/
            case 382: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 383:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;
/*------------------------------SRAM 24 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 34 to 55    
            case 384:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 24 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+34] << 24 | A[obi_addr + 128+34] << 16 | A[obi_addr + 256+34] << 8 | A[obi_addr + 384+34];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 385 ... 387:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 388:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 389 ... 391:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB24 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 392:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 393: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 394:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 395: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 24 REFRESH------------------------------*/
            case 396: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break; 
/*------------------------------OUTPUT CHECK OF SRAM 24 REFRESH------------------------------*/
            case 397: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 398:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;            
/*------------------------------SRAM 25 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 52 to 73    
            case 399:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 25 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+52] << 24 | A[obi_addr + 128+52] << 16 | A[obi_addr + 256+52] << 8 | A[obi_addr + 384+52];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 400 ... 401:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 402:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 403 ... 405:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB25 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 406:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 407: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 408:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 409: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 25 REFRESH------------------------------*/
            case 410: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 25 REFRESH------------------------------*/
            case 411: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 412:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;             
/*------------------------------SRAM 26 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 70 to 91    
            case 413:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 26 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+70] << 24 | A[obi_addr + 128+70] << 16 | A[obi_addr + 256+70] << 8 | A[obi_addr + 384+70];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 414 ... 416:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 417:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 418 ... 420:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB26 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 421:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 422: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 423:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 424: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 26 REFRESH------------------------------*/
            case 425: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
 /*------------------------------OUTPUT CHECK OF SRAM 26 REFRESH------------------------------*/
            case 426: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 427:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break;            
/*------------------------------SRAM 27 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 88 to 109    
            case 428:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 13 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+88] << 24 | A[obi_addr + 128+88] << 16 | A[obi_addr + 256+88] << 8 | A[obi_addr + 384+88];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 429 ... 431:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 432:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 433 ... 435:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB27 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 436:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 437: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 438:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 439: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 27 REFRESH------------------------------*/
            case 440: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 27 REFRESH------------------------------*/
            case 441: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x7e) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 442:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x7e) {
                    ram_addr = 0x14;
                    step_cnt++;
                }
            break; 
/*------------------------------SRAM 27 REFRESH INPUT SAMPLES WRITING------------------------------*/
            // Write input matrix A to accelerator private memory - Input from 106 to 127    
            case 443:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Here SRAM 14 sram_addr: %x", ram_addr);
                    obi_data = A[obi_addr+106] << 24 | A[obi_addr + 128+106] << 16 | A[obi_addr + 256+106] << 8 | A[obi_addr + 384+106];     //+16 per andare alla colonna 16  
                    if(column_number==21){
                        obi_addr += 0x1eb;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                        TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                        TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                        obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                    break;
                }
                obi_accepted = false;
                // Push expected data to the scoreboard checker queue
                // When a read request is performed, the expected data is compared with the read data
                scb->scheduleObiCheck(obi_data);
                ram_addr += 1;
                data_size += 0x1;
                if(data_size==0x58){
                    step_cnt++; //questo dato garantisce che la memoria e' stata riempita
                }
            break;
            
            // Wait some cycles - reset some variables
            case 444 ... 446:
                ram_addr=0x14;
                data_size = 0;
                obi_addr = 0;
                column_number=0;
                step_cnt++;
            break;
                
            // Check if data are written correctly
            case 447:
                if (!obi_accepted) {
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                    break;
                }
                obi_accepted = false;
                ram_addr += 0x1;
                if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
                break;  

            // Wait some cycles - reset some variables
            case 448 ... 450:
                ram_addr = 0x14;
                data_size = 0;
                column_number=0;
                obi_addr=0;
                step_cnt++;
            break;

/*------------------------------LFB28 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
            // Loaded flag bit set to 1
            case 451:  
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                    data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                    break;
                }
                reg_accepted = false;
                step_cnt++;
            break;

            // Reading and check of the loaded flag bit
            case 452: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
            
            // Loaded flag bit set to 0
            case 453:
                if (!reg_accepted) {
                    TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                    data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                    reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                    break;
                }
                reg_accepted = false;
                step_cnt++; 
            break;

            // Reading and check of the loaded flag bit
            case 454: 
                if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                    TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
                } else {
                    TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
                }
                reg_accepted = false;
                step_cnt++; 
            break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 28 REFRESH------------------------------*/
            case 455: 
                if(!reg_accepted){
                    TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                    reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                    break;
                }
                if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                    TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                    }else {
                    TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                    break;
                }
                reg_accepted = false;
                ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
                obi_accepted = false; //Added for output check
                step_cnt++;
            break;
/*------------------------------OUTPUT CHECK OF SRAM 28 REFRESH------------------------------*/
            case 456: 
                obi_data = R[result_index];
                result_index++;
                ram_addr+=0x1;
                scb->scheduleObiCheck(obi_data);
                if(ram_addr == 0x80) {
                    ram_addr = 0x6c;
                    step_cnt++;
                }
            break;

            case 457:
                if (!obi_accepted) {
                    obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                    TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                    ram_addr += 0x1; 
                    break;
                }
                obi_accepted = false;
                if (ram_addr == 0x80) {
                    ram_addr = 0;
                    data_size = 0;
                    step_cnt++;
                }
            break; 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 
/*------------------------------END OF FILTER NUMBER 4------------------------------*/ 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 

/*------------------------------SRAM 29 REFRESH FILTER WRITING------------------------------*/
            // Write weight matrix F to accelerator private memory - Filter 5
            case 458:
            if (!obi_accepted) {
                obi_data = F[obi_addr + 320] << 24 | F[obi_addr + 325] << 16 | F[obi_addr + 330] << 8 | F[obi_addr + 335];
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            // Prepare next data element
            ram_addr += 0x1; //Next cycle, we will write on the next sram address 
            data_size += 0x1; 
            if (ram_addr % 5 == 0 && ram_addr != 0) { //If we wrote 5 filters weigth, we need to go to the next row
                obi_addr += 0x10;
            }
            else {
                obi_addr += 0x1;
            }

            if (data_size == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
        break;

        // Wait some cycles - reset some variables
            case 459 ... 461:
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            break;

        // Read back stored data
        case 462:
            if (!obi_accepted) {
                TB_LOG(LOG_HIGH, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            data_size += 0x4;
            if (ram_addr == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
        break;
        
        // Wait some cycles - reset some variables
        case 463 ... 465:
            obi_addr = 0;
            data_size = 0;
            step_cnt++;
        break;
/*------------------------------SRAM 29 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 0 to 19
        case 466:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 29 sram_addr: %x", ram_addr);
                if (ram_addr == 0x14 || ram_addr == 0x15 || ram_addr == 0x2a || ram_addr == 0x2b || ram_addr == 0x40 || ram_addr == 0x41 || ram_addr == 0x56 || ram_addr == 0x57)  {    // In the described address, we will store the padding 
                    obi_data = 0x0;
                } else {
                    obi_data = A[obi_addr] << 24 | A[obi_addr + 128] << 16 | A[obi_addr + 256] << 8 | A[obi_addr + 384];    //<<24 to store in the first 8 bit starting from the left(MSB), <<16 the second word, <<8 the third word, in the end we have LSB.
                    if (column_number==19){ //If we are in the last column we can store in the sram, we need to move the index obi_addr to 4 rows below
                        obi_addr += 0x1ed;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                }
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);               
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;

        // Wait some cycles - reset some variables
        case 467 ... 469:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break; 

        // Check if data are written correctly
        case 470:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;

        // Wait some cycles - reset some variables
        case 471 ... 475:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break; 

/*------------------------------LFB29 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 476:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 477:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 478:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 479:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 29 REFRESH------------------------------*/   
        case 480:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                } else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 29 REFRESH------------------------------*/
        case 481:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 482:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;
/*------------------------------SRAM 30 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 16 to 37    
        case 483:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 30 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+16] << 24 | A[obi_addr + 128+16] << 16 | A[obi_addr + 256+16] << 8 | A[obi_addr + 384+16];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 484 ... 486:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 487:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 488 ... 490:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;      

/*------------------------------LFB30 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 491:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 492:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 493:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 494:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 30 REFRESH------------------------------*/
        case 495:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                } else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;          
/*------------------------------OUTPUT CHECK OF SRAM 30 REFRESH------------------------------*/
        case 496:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 497:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;
/*------------------------------SRAM 31 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 34 to 55    
        case 498:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 3 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+34] << 24 | A[obi_addr + 128+34] << 16 | A[obi_addr + 256+34] << 8 | A[obi_addr + 384+34];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 499 ... 501:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 502:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 503 ... 505:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB31 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 506:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 507:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 508:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 509:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 31 REFRESH------------------------------*/
        case 510:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break; 
/*------------------------------OUTPUT CHECK OF SRAM 31 REFRESH------------------------------*/
        case 511:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 512:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;            
/*------------------------------SRAM 32 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 52 to 73    
        case 513:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 4 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+52] << 24 | A[obi_addr + 128+52] << 16 | A[obi_addr + 256+52] << 8 | A[obi_addr + 384+52];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 514 ... 516:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 517:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 518 ... 520:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB32 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 521:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 522:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 523:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 524:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 32 REFRESH------------------------------*/
        case 525:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 32 REFRESH------------------------------*/
        case 526:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 527:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;             
/*------------------------------SRAM 33 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 70 to 91    
        case 528:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 5 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+70] << 24 | A[obi_addr + 128+70] << 16 | A[obi_addr + 256+70] << 8 | A[obi_addr + 384+70];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 529 ... 531:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 532:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 533 ... 535:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB33 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 536:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 537:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 538:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 539:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 33 REFRESH------------------------------*/
        case 540:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 33 REFRESH------------------------------*/
        case 541:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 542:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;            
/*------------------------------SRAM 34 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 88 to 109    
        case 543:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 34 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+88] << 24 | A[obi_addr + 128+88] << 16 | A[obi_addr + 256+88] << 8 | A[obi_addr + 384+88];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 544 ... 546:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 547:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 548 ... 550:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB34 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 551:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 552:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 553:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 554:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 34 REFRESH------------------------------*/
        case 555:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 34 REFRESH------------------------------*/
        case 556:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 557:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break; 
/*------------------------------SRAM 35 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 106 to 127    
        case 558:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 35 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+106] << 24 | A[obi_addr + 128+106] << 16 | A[obi_addr + 256+106] << 8 | A[obi_addr + 384+106];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 559 ... 561:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 562:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 563 ... 565:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB35 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 566:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 567:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 568:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 569:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 35 REFRESH------------------------------*/
        case 570:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 35 REFRESH------------------------------*/
        case 571:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x80) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 572:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x80) {
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            }
        break; 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 
/*------------------------------END OF FILTER NUMBER 5------------------------------*/ 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 

/*------------------------------SRAM 36 REFRESH FILTER WRITING------------------------------*/
        // Wait some cycles - reset some variables
        case 573 ... 575:
            ram_addr = 0;
            data_size = 0;
            step_cnt++;
        break;

        // Write weight matrix F to accelerator private memory - Filter 6
        case 576:
            if (!obi_accepted) {
                obi_data = F[obi_addr+400] << 24 | F[obi_addr + 405] << 16 | F[obi_addr + 410] << 8 | F[obi_addr + 415];
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            // Prepare next data element
            ram_addr += 0x1; //Next cycle, we will write on the next sram address 
            data_size += 0x1; 
            if (ram_addr % 5 == 0 && ram_addr != 0) { //If we wrote 5 filters weigth, we need to go to the next row
                obi_addr += 0x10;
            }
            else {
                obi_addr += 0x1;
            }

            if (data_size == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
        break;

        // Wait some cycles - reset some variables
        case 577 ... 579:
            ram_addr = 0;
            data_size = 0;
            step_cnt++;
        break;

        // Read back stored data
        case 580:
            if (!obi_accepted) {
                TB_LOG(LOG_HIGH, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            data_size += 0x4;
            if (ram_addr == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
        break;
        
        // Wait some cycles - reset some variables
        case 581 ... 583:
            obi_addr = 0;
            data_size = 0;
            step_cnt++;
        break;
/*------------------------------SRAM 36 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 0 to 19
        case 584:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 36 sram_addr: %x", ram_addr);
                if (ram_addr == 0x14 || ram_addr == 0x15 || ram_addr == 0x2a || ram_addr == 0x2b || ram_addr == 0x40 || ram_addr == 0x41 || ram_addr == 0x56 || ram_addr == 0x57)  {    // In the described address, we will store the padding 
                    obi_data = 0x0;
                } else {
                    obi_data = A[obi_addr] << 24 | A[obi_addr + 128] << 16 | A[obi_addr + 256] << 8 | A[obi_addr + 384];    //<<24 to store in the first 8 bit starting from the left(MSB), <<16 the second word, <<8 the third word, in the end we have LSB.
                    if (column_number==19){ //If we are in the last column we can store in the sram, we need to move the index obi_addr to 4 rows below
                        obi_addr += 0x1ed;
                        column_number=0;
                    } else {
                        obi_addr += 0x1;
                        column_number++;
                        TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                    }                  
                }
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);               
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;

        // Wait some cycles - reset some variables
        case 585 ... 587:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break; 

        // Check if data are written correctly
        case 588:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;

        // Wait some cycles - reset some variables
        case 589 ... 591:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break; 
/*------------------------------LFB36 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 592:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 593:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 594:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 595:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 36 REFRESH------------------------------*/
        case 596:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 36 REFRESH------------------------------*/
        case 597:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 598:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break; 
/*------------------------------SRAM 37 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 16 to 37    
        case 599:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 37 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+16] << 24 | A[obi_addr + 128+16] << 16 | A[obi_addr + 256+16] << 8 | A[obi_addr + 384+16];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 600 ... 602:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 603:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 604 ... 606:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;      

/*------------------------------LFB37 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 607:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 608:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 609:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 610:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 37 REFRESH------------------------------*/
        case 611:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                } else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;          
/*------------------------------OUTPUT CHECK OF SRAM 37 REFRESH------------------------------*/
        case 612:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 613:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;
/*------------------------------SRAM 38 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 34 to 55    
        case 614:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 10 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+34] << 24 | A[obi_addr + 128+34] << 16 | A[obi_addr + 256+34] << 8 | A[obi_addr + 384+34];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 615 ... 617:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 618:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 619 ... 621:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB38 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 622:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 623:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 624:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 625:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 38 REFRESH------------------------------*/
        case 626:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break; 
/*------------------------------OUTPUT CHECK OF SRAM 38 REFRESH------------------------------*/
        case 627:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 628:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;            
/*------------------------------SRAM 39 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 52 to 73    
        case 629:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 39 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+52] << 24 | A[obi_addr + 128+52] << 16 | A[obi_addr + 256+52] << 8 | A[obi_addr + 384+52];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 630 ... 632:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 633:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 634 ... 636:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB39 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 637:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 638:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 639:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 640:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 39 REFRESH------------------------------*/
        case 641:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 39 REFRESH------------------------------*/
        case 642:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 643:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;             
/*------------------------------SRAM 40 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 70 to 91    
        case 644:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 12 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+70] << 24 | A[obi_addr + 128+70] << 16 | A[obi_addr + 256+70] << 8 | A[obi_addr + 384+70];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 645 ... 647:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 648:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 649 ... 651:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB40 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 652:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 653:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 654:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 655:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 40 REFRESH------------------------------*/
        case 656:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 12 REFRESH------------------------------*/
        case 657:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 658:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break;            
/*------------------------------SRAM 41 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 88 to 109    
        case 659:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 41 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+88] << 24 | A[obi_addr + 128+88] << 16 | A[obi_addr + 256+88] << 8 | A[obi_addr + 384+88];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 660 ... 662:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 663:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 664 ... 666:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB41 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 667:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 668:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 669:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 670:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 41 REFRESH------------------------------*/
        case 671:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 41 REFRESH------------------------------*/
        case 672:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x7e) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 673:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x7e) {
                ram_addr = 0x14;
                step_cnt++;
            }
        break; 
/*------------------------------SRAM 42 REFRESH INPUT SAMPLES WRITING------------------------------*/
        // Write input matrix A to accelerator private memory - Input from 106 to 127    
        case 674:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Here SRAM 42 sram_addr: %x", ram_addr);
                obi_data = A[obi_addr+106] << 24 | A[obi_addr + 128+106] << 16 | A[obi_addr + 256+106] << 8 | A[obi_addr + 384+106];     //+16 per andare alla colonna 16  
                if(column_number==21){
                    obi_addr += 0x1eb;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
                    TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                    TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                    obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
                break;
            }
            obi_accepted = false;
            // Push expected data to the scoreboard checker queue
            // When a read request is performed, the expected data is compared with the read data
            scb->scheduleObiCheck(obi_data);
            ram_addr += 1;
            data_size += 0x1;
            if(data_size==0x58){
                step_cnt++; //questo dato garantisce che la memoria e' stata riempita
            }
        break;
        
        // Wait some cycles - reset some variables
        case 675 ... 677:
            ram_addr=0x14;
            data_size = 0;
            obi_addr = 0;
            column_number=0;
            step_cnt++;
        break;
            
        // Check if data are written correctly
        case 678:
            if (!obi_accepted) {
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
                break;
            }
            obi_accepted = false;
            ram_addr += 0x1;
            if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
            break;  

        // Wait some cycles - reset some variables
        case 679 ... 681:
            ram_addr = 0x14;
            data_size = 0;
            column_number=0;
            obi_addr=0;
            step_cnt++;
        break;

/*------------------------------LFB42 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
        // Loaded flag bit set to 1
        case 682:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
                data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
                break;
            }
            reg_accepted = false;
            step_cnt++;
        break;

        // Reading and check of the loaded flag bit
        case 683:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
        
        // Loaded flag bit set to 0
        case 684:
            if (!reg_accepted) {
                TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
                data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
                reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
                break;
            }
            reg_accepted = false;
            step_cnt++; 
        break;

        // Reading and check of the loaded flag bit
        case 685:
            if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
                TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
            } else {
                TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
            }
            reg_accepted = false;
            step_cnt++; 
        break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 42 REFRESH------------------------------*/
        case 686:
            if(!reg_accepted){
                TB_LOG(LOG_LOW, "##G Reading reload flag bit");
                reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
                break;
            }
            if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
                TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
                }else {
                TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
                break;
            }
            reg_accepted = false;
            ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
            obi_accepted = false; //Added for output check
            step_cnt++;
        break;
/*------------------------------OUTPUT CHECK OF SRAM 42 REFRESH------------------------------*/
        case 687:
            obi_data = R[result_index];
            result_index++;
            ram_addr+=0x1;
            scb->scheduleObiCheck(obi_data);
            if(ram_addr == 0x80) {
                ram_addr = 0x6c;
                step_cnt++;
            }
        break;

        case 688:
            if (!obi_accepted) {
                obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
                TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
                ram_addr += 0x1; 
                break;
            }
            obi_accepted = false;
            if (ram_addr == 0x80) {
                ram_addr = 0;
                data_size = 0;
                step_cnt++;
            }
        break; 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 
/*------------------------------END OF FILTER NUMBER 6------------------------------*/ 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 

/*------------------------------SRAM 43 REFRESH FILTER WRITING------------------------------*/
        // Write weight matrix F to accelerator private memory - Filter 7
        case 689:
        if (!obi_accepted) {
            obi_data = F[obi_addr + 480] << 24 | F[obi_addr + 485] << 16 | F[obi_addr + 490] << 8 | F[obi_addr + 495];
            TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
            obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        // Prepare next data element
        ram_addr += 0x1; //Next cycle, we will write on the next sram address 
        data_size += 0x1; 
        if (ram_addr % 5 == 0 && ram_addr != 0) { //If we wrote 5 filters weigth, we need to go to the next row
            obi_addr += 0x10;
        }
        else {
            obi_addr += 0x1;
        }

        if (data_size == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
    break;

    // Wait some cycles - reset some variables
    case 690 ... 692:
        ram_addr = 0;
        data_size = 0;
        step_cnt++;
    break;

    // Read back stored data
    case 693:
        if (!obi_accepted) {
            TB_LOG(LOG_HIGH, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        data_size += 0x4;
        if (ram_addr == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
    break;
    
    // Wait some cycles - reset some variables
    case 694 ... 696:
        obi_addr = 0;
        data_size = 0;
        step_cnt++;
    break;
/*------------------------------SRAM 43 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 0 to 19
    case 697:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 1 sram_addr: %x", ram_addr);
            if (ram_addr == 0x14 || ram_addr == 0x15 || ram_addr == 0x2a || ram_addr == 0x2b || ram_addr == 0x40 || ram_addr == 0x41 || ram_addr == 0x56 || ram_addr == 0x57)  {    // In the described address, we will store the padding 
                obi_data = 0x0;
            } else {
                obi_data = A[obi_addr] << 24 | A[obi_addr + 128] << 16 | A[obi_addr + 256] << 8 | A[obi_addr + 384];    //<<24 to store in the first 8 bit starting from the left(MSB), <<16 the second word, <<8 the third word, in the end we have LSB.
                if (column_number==19){ //If we are in the last column we can store in the sram, we need to move the index obi_addr to 4 rows below
                    obi_addr += 0x1ed;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
            }
            TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
            TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);               
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;

    // Wait some cycles - reset some variables
    case 698 ... 700:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break; 

    // Check if data are written correctly
    case 701:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
    break;

    // Wait some cycles - reset some variables
    case 702 ... 706:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break; 

/*------------------------------LFB43 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 707:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 708:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 709:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 710:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 43 REFRESH------------------------------*/   
    case 711:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            } else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 43 REFRESH------------------------------*/
    case 712:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 713:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;
/*------------------------------SRAM 44 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 16 to 37    
    case 714:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 44 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+16] << 24 | A[obi_addr + 128+16] << 16 | A[obi_addr + 256+16] << 8 | A[obi_addr + 384+16];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 715 ... 717:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 718:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 719 ... 721:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;      

/*------------------------------LFB44 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 722:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 723:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 724:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 725:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 44 REFRESH------------------------------*/
    case 726:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            } else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;          
/*------------------------------OUTPUT CHECK OF SRAM 44 REFRESH------------------------------*/
    case 727:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 728:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;
/*------------------------------SRAM 45 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 34 to 55    
    case 729:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 45 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+34] << 24 | A[obi_addr + 128+34] << 16 | A[obi_addr + 256+34] << 8 | A[obi_addr + 384+34];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 730 ... 732:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 733:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 734 ... 736:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB45 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 737:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 738:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 739:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 740:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 45 REFRESH------------------------------*/
    case 741:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break; 
/*------------------------------OUTPUT CHECK OF SRAM 45 REFRESH------------------------------*/
    case 742:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 743:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;            
/*------------------------------SRAM 46 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 52 to 73    
    case 744:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 46 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+52] << 24 | A[obi_addr + 128+52] << 16 | A[obi_addr + 256+52] << 8 | A[obi_addr + 384+52];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 745 ... 747:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 748:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 749 ... 751:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB46 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 752:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 753:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 754:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 755:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 46 REFRESH------------------------------*/
    case 756:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 46 REFRESH------------------------------*/
    case 757:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 758:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;             
/*------------------------------SRAM 47 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 70 to 91    
    case 759:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 47 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+70] << 24 | A[obi_addr + 128+70] << 16 | A[obi_addr + 256+70] << 8 | A[obi_addr + 384+70];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 760 ... 762:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 763:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 764 ... 766:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB47 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 767:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 768:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 769:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 770:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 47 REFRESH------------------------------*/
    case 771:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 47 REFRESH------------------------------*/
    case 772:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 773:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;            
/*------------------------------SRAM 48 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 88 to 109    
    case 774:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 48 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+88] << 24 | A[obi_addr + 128+88] << 16 | A[obi_addr + 256+88] << 8 | A[obi_addr + 384+88];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 775 ... 777:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 778:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 779 ... 781:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB48 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 782:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 783:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 784:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 785:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 48 REFRESH------------------------------*/
    case 786:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 48 REFRESH------------------------------*/
    case 787:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 788:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break; 
/*------------------------------SRAM 49 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 106 to 127    
    case 789:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 49 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+106] << 24 | A[obi_addr + 128+106] << 16 | A[obi_addr + 256+106] << 8 | A[obi_addr + 384+106];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 790 ... 792:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 793:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 794 ... 796:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB49 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 797:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 798:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 799:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 800:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 49 REFRESH------------------------------*/
    case 801:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 49 REFRESH------------------------------*/
    case 802:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x80) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 803:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x80) {
            ram_addr = 0;
            data_size = 0;
            step_cnt++;
        }
    break; 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 
/*------------------------------END OF FILTER NUMBER 7------------------------------*/ 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 

/*------------------------------SRAM 50 REFRESH FILTER WRITING------------------------------*/
    // Wait some cycles - reset some variables
    case 804 ... 806:
        ram_addr = 0;
        data_size = 0;
        step_cnt++;
    break;

    // Write weight matrix F to accelerator private memory - Filter 8
    case 807:
        if (!obi_accepted) {
            obi_data = F[obi_addr+560] << 24 | F[obi_addr + 565] << 16 | F[obi_addr + 570] << 8 | F[obi_addr + 575];
            TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
            obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        // Prepare next data element
        ram_addr += 0x1; //Next cycle, we will write on the next sram address 
        data_size += 0x1; 
        if (ram_addr % 5 == 0 && ram_addr != 0) { //If we wrote 5 filters weigth, we need to go to the next row
            obi_addr += 0x10;
        }
        else {
            obi_addr += 0x1;
        }

        if (data_size == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
    break;

    // Wait some cycles - reset some variables
    case 808 ... 810:
        ram_addr = 0;
        data_size = 0;
        step_cnt++;
    break;

    // Read back stored data
    case 811:
        if (!obi_accepted) {
            TB_LOG(LOG_HIGH, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        data_size += 0x4;
        if (ram_addr == 0x14) step_cnt++; // TODO: change exit condition with actual test data size
    break;
    
    // Wait some cycles - reset some variables
    case 812 ... 814:
        obi_addr = 0;
        data_size = 0;
        step_cnt++;
    break;
/*------------------------------SRAM 50 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 0 to 19
    case 815:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 8 sram_addr: %x", ram_addr);
            if (ram_addr == 0x14 || ram_addr == 0x15 || ram_addr == 0x2a || ram_addr == 0x2b || ram_addr == 0x40 || ram_addr == 0x41 || ram_addr == 0x56 || ram_addr == 0x57)  {    // In the described address, we will store the padding 
                obi_data = 0x0;
            } else {
                obi_data = A[obi_addr] << 24 | A[obi_addr + 128] << 16 | A[obi_addr + 256] << 8 | A[obi_addr + 384];    //<<24 to store in the first 8 bit starting from the left(MSB), <<16 the second word, <<8 the third word, in the end we have LSB.
                if (column_number==19){ //If we are in the last column we can store in the sram, we need to move the index obi_addr to 4 rows below
                    obi_addr += 0x1ed;
                    column_number=0;
                } else {
                    obi_addr += 0x1;
                    column_number++;
                    TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
                }                  
            }
            TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
            TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);               
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;

    // Wait some cycles - reset some variables
    case 816 ... 818:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break; 

    // Check if data are written correctly
    case 819:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
    break;

    // Wait some cycles - reset some variables
    case 820 ... 822:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break; 
/*------------------------------LFB50 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 823:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 824:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 825:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 826:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 50 REFRESH------------------------------*/
    case 827:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 50 REFRESH------------------------------*/
    case 828:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 829:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break; 
/*------------------------------SRAM 51 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 16 to 37    
    case 830:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 51 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+16] << 24 | A[obi_addr + 128+16] << 16 | A[obi_addr + 256+16] << 8 | A[obi_addr + 384+16];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 831 ... 833:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 834:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 835 ... 837:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;      

/*------------------------------LFB51 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 838:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 839:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 840:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 841:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 51 REFRESH------------------------------*/
    case 842:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            } else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;          
/*------------------------------OUTPUT CHECK OF SRAM 51 REFRESH------------------------------*/
    case 843:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 844:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;
/*------------------------------SRAM 52 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 34 to 55    
    case 845:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 52 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+34] << 24 | A[obi_addr + 128+34] << 16 | A[obi_addr + 256+34] << 8 | A[obi_addr + 384+34];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 846 ... 848:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 849:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 850 ... 852:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB52 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 853:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 854:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 855:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 856:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 52 REFRESH------------------------------*/
    case 857:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break; 
/*------------------------------OUTPUT CHECK OF SRAM 52 REFRESH------------------------------*/
    case 858:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 859:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;            
/*------------------------------SRAM 53 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 52 to 73    
    case 860:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 53 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+52] << 24 | A[obi_addr + 128+52] << 16 | A[obi_addr + 256+52] << 8 | A[obi_addr + 384+52];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 861 ... 863:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 864:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 865 ... 867:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB53 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 868:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 869:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 870:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 871:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 53 REFRESH------------------------------*/
    case 872:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 53 REFRESH------------------------------*/
    case 873:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 874:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;             
/*------------------------------SRAM 54 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 70 to 91    
    case 875:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 54 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+70] << 24 | A[obi_addr + 128+70] << 16 | A[obi_addr + 256+70] << 8 | A[obi_addr + 384+70];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 876 ... 878:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 879:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 880 ... 882:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB54 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 883:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 884:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 885:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 886:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 54 REFRESH------------------------------*/
    case 887:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 54 REFRESH------------------------------*/
    case 888:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 889:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break;            
/*------------------------------SRAM 55 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 88 to 109    
    case 890:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 55 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+88] << 24 | A[obi_addr + 128+88] << 16 | A[obi_addr + 256+88] << 8 | A[obi_addr + 384+88];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 891 ... 893:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 894:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 895 ... 897:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB55 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 898:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 899:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 900:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 901:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 55 REFRESH------------------------------*/
    case 902:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##G Reading reload flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_RELOAD_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Reload flag is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- Reload flag is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 55 REFRESH------------------------------*/
    case 903:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x7e) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 904:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x7e) {
            ram_addr = 0x14;
            step_cnt++;
        }
    break; 
/*------------------------------SRAM 56 REFRESH INPUT SAMPLES WRITING------------------------------*/
    // Write input matrix A to accelerator private memory - Input from 106 to 127    
    case 905:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Here SRAM 56 sram_addr: %x", ram_addr);
            obi_data = A[obi_addr+106] << 24 | A[obi_addr + 128+106] << 16 | A[obi_addr + 256+106] << 8 | A[obi_addr + 384+106];     //+16 per andare alla colonna 16  
            if(column_number==21){
                obi_addr += 0x1eb;
                column_number=0;
            } else {
                obi_addr += 0x1;
                column_number++;
                TB_LOG(LOG_LOW, "-----------------COLUMN NUMBER: '%x' ", column_number);
            }                  
                TB_LOG(LOG_LOW, "Writing '%x' to address '%x'", obi_data, ram_addr);
                TB_LOG(LOG_LOW, "OBI_ADDR: '%x' ", obi_addr);
                obi_req = genObiWriteReqTx(ram_addr, obi_data, 0xf);
            break;
        }
        obi_accepted = false;
        // Push expected data to the scoreboard checker queue
        // When a read request is performed, the expected data is compared with the read data
        scb->scheduleObiCheck(obi_data);
        ram_addr += 1;
        data_size += 0x1;
        if(data_size==0x58){
            step_cnt++; //questo dato garantisce che la memoria e' stata riempita
        }
    break;
    
    // Wait some cycles - reset some variables
    case 906 ... 908:
        ram_addr=0x14;
        data_size = 0;
        obi_addr = 0;
        column_number=0;
        step_cnt++;
    break;
        
    // Check if data are written correctly
    case 909:
        if (!obi_accepted) {
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 13
            break;
        }
        obi_accepted = false;
        ram_addr += 0x1;
        if (ram_addr == 0x6c) step_cnt++; // TODO: change exit condition with actual test data size
        break;  

    // Wait some cycles - reset some variables
    case 910 ... 912:
        ram_addr = 0x14;
        data_size = 0;
        column_number=0;
        obi_addr=0;
        step_cnt++;
    break;

/*------------------------------LFB56 - LOADED FLAG BIT SETTING & RESETTING------------------------------*/             
    // Loaded flag bit set to 1
    case 913:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##C Setting loaded flag bit in control register"); // ATTENZIONE: le costanti sono scritte nel file /sw/conv1d_control_reg.h
            data = 1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; // Per scrivere il control register prima creiamo il dato da scrivere mediante lo shift di un bit, la posizione è relativa alla posizione del control register
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1); //    assegno il dato usando come indirizzo relativo quello del control register                  
            break;
        }
        reg_accepted = false;
        step_cnt++;
    break;

    // Reading and check of the loaded flag bit
    case 914:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##D Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- Loaded flag correctly set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- ERROR: loaded flag is set to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
    
    // Loaded flag bit set to 0
    case 915:
        if (!reg_accepted) {
            TB_LOG(LOG_LOW, "##E Resetting loaded flag bit in control register");
            data = 0 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT; 
            reg_req = genRegWriteReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET, data, 0x1);
            break;
        }
        reg_accepted = false;
        step_cnt++; 
    break;

    // Reading and check of the loaded flag bit
    case 916:
        if (!reg_accepted) {  // Prima di procedere col programma viene verificato richiesta di scrittura è stata eseguita mediante questo flag
            TB_LOG(LOG_LOW, "##F Reading back control register to check loaded flag bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_CONTROL_REG_OFFSET); // Viene mandata una richiesta di lettura
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_CONTROL_LOADED_FLAG_BIT)){
            TB_LOG(LOG_LOW, "--- ERROR: flag is still set to 1");
        } else {
            TB_LOG(LOG_LOW, "--- Loaded flag is correctly reset to 0");
        }
        reg_accepted = false;
        step_cnt++; 
    break;
/*------------------------------WAIT END OF EXECUTION OF SRAM 56 REFRESH - DONE BIT------------------------------*/
    case 917:
        if(!reg_accepted){
            TB_LOG(LOG_LOW, "##Z Reading DONE bit");
            reg_req = genRegReadReqTx(CONV1D_CONTROL_STATUS1_REG_OFFSET);
            break;
        }
        if(reg_rdata & (1 << CONV1D_CONTROL_STATUS1_DONE_BIT)){
            TB_LOG(LOG_LOW, "--- DONE bit is 1. Accelerator stop execution.");
            }else {
            TB_LOG(LOG_LOW, "--- DONE bit is 0. Accelerator is still executing");
            break;
        }
        reg_accepted = false;
        ram_addr = 0x6c; // 108 -- address first output sample //Added for output check
        obi_accepted = false; //Added for output check
        step_cnt++;
    break;
/*------------------------------OUTPUT CHECK OF SRAM 56 REFRESH------------------------------*/
    case 918:
        obi_data = R[result_index];
        result_index++;
        ram_addr+=0x1;
        scb->scheduleObiCheck(obi_data);
        if(ram_addr == 0x80) {
            ram_addr = 0x6c;
            step_cnt++;
        }
    break;

    case 919:
        if (!obi_accepted) {
            obi_req = genObiReadReqTx(ram_addr); // this will trigger the check on the written data in step 0
            TB_LOG(LOG_LOW, "Reading data from address '%x'", ram_addr);
            ram_addr += 0x1; 
            break;
        }
        obi_accepted = false;
        if (ram_addr == 0x80) {
            ram_addr = 0;
            data_size = 0;
            step_cnt++;
        }
    break; 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 
/*------------------------------END OF FILTER NUMBER 8------------------------------*/ 
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/ 
/*----------------------------------------------------------------------------------*/ 

            case 920:
                TB_SUCCESS(LOG_LOW, "THE ACCELERATOR ENDED CORRECTLY");
                step_cnt++;
            break;

            case 921:
                // Set simulation exit flag
                end_of_test = true;
            break;

            default:
                // Set simulation exit flag
                end_of_test = true;
            break;
            }
            
            // Drive DUT inputs
            drv->drive(obi_req, reg_req);
            delete obi_req;
            delete reg_req;
            obi_req = NULL;
            reg_req = NULL;

            // Update input signals
            dut->eval();

            // Monitor DUT signals
            reqMon->monitor();
            rspMon->monitor();
            
            irq_received = rspMon->irq();
            obi_accepted = reqMon->acceptedObi();
            reg_accepted = reqMon->acceptedReg();

            // Get register data (to be used in the test program above)
            if (reg_accepted) {
                reg_rdata = rspMon->getRegData();
            }
            if (rspMon->isDataReadyObi()) obi_rdata = rspMon->getObiData();

            // Trigger scheduled checks
            if (scb->checkData() != 0) end_of_test = true;

            // Check for exit conditions
            if (prev_step_cnt != step_cnt) watchdog = 0;
            else watchdog++;
            if (watchdog > WATCHDOG_TIMEOUT) {
                TB_WARN("Watchdog timeout reached: terminating simulation.");
                scb->notifyError();
                break;
            }
            prev_step_cnt = step_cnt;
            if (end_of_test)
            {
                if (exit_timer++ == END_OF_TEST_TIMEOUT) {
                    TB_LOG(LOG_MEDIUM, "End of simulation reached: terminating.");
                    break;
                }
            }
        }

        // Dump waveforms and advance simulation time
        if (gen_waves) trace->dump(cntx->time());
        if (dut->clk_i == 1) sim_cycles++;
        cntx->timeInc(1);
    }

    // Simulation complete
    dut->final();

    // Print simulation summary
    if (scb->getErrNum() > 0)
    {
        TB_ERR("CHECKS FAILED > errors: %u/%u", scb->getErrNum(), scb->getTxNum());
        if (gen_waves) trace->close();
        exit(EXIT_SUCCESS);
    }
    else if (!scb->isDone())
    {
        TB_ERR("CHECKS PENDING > errors: %u/%u", scb->getErrNum(), scb->getTxNum());
        if (gen_waves) trace->close();
        exit(EXIT_SUCCESS);
    }
    TB_SUCCESS(LOG_LOW, "CHECKS PASSED > errors: %u (checked %u transactions)", scb->getErrNum(), scb->getTxNum());

    // Clean up and exit
    if (gen_waves) trace->close();
    delete dut;
    delete cntx;
    delete obi_req;
    delete reg_req;

    return 0;
}

void clkGen(Vconv1d_tb_wrapper *dut)
{
    dut->clk_i ^= 1;
}

void rstDut(Vconv1d_tb_wrapper *dut, vluint64_t sim_time)
{
    dut->rst_ni = 1;
    if (sim_time > 1 && sim_time < END_OF_RESET_TIME)
    {
        dut->rst_ni = 0;
    }
}

void runCycles(unsigned int ncycles, Vconv1d_tb_wrapper *dut, uint8_t gen_waves, VerilatedFstC *trace)
{
    VerilatedContext *cntx = dut->contextp();
    for (unsigned int i = 0; i < (2 * ncycles); i++)
    {
        // Generate clock
        clkGen(dut);

        // Evaluate the DUT
        dut->eval();

        // Save waveforms
        if (gen_waves)
            trace->dump(cntx->time());
        if (dut->clk_i == 1)
            sim_cycles++;
        cntx->timeInc(1);
    }
}

// Issue write OBI transaction
ObiReqTx *genObiWriteReqTx(const vluint32_t addr_offs, const vluint32_t wdata, vluint8_t be)
{
    ObiReqTx *req = new ObiReqTx;

    // OBI write request
    req->obi_req.req = 1;
    req->obi_req.we = 1;
    req->obi_req.be = be;
    req->obi_req.addr = addr_offs;
    req->obi_req.wdata = wdata;

    return req;
}

// Issue read OBI transaction
ObiReqTx *genObiReadReqTx(const vluint32_t addr_offs)
{
    ObiReqTx *req = new ObiReqTx;

    // OBI read request
    req->obi_req.req = 1;
    req->obi_req.we = 0;
    req->obi_req.be = 0xf;
    req->obi_req.addr = addr_offs;
    req->obi_req.wdata = 0;

    return req;
}

// Issue write register interface transaction
RegReqTx *genRegWriteReqTx(const vluint32_t addr_offs, const vluint32_t wdata, vluint8_t wstrb)
{
    RegReqTx *req = new RegReqTx;

    // OBI write request
    req->reg_req.valid = 1;
    req->reg_req.write = 1;
    req->reg_req.wstrb = wstrb;
    req->reg_req.addr = addr_offs;
    req->reg_req.wdata = wdata;

    return req;
}

// Issue read register interface transaction
RegReqTx *genRegReadReqTx(const vluint32_t addr_offs)
{
    RegReqTx *req = new RegReqTx;

    // OBI read request
    req->reg_req.valid = 1;
    req->reg_req.write = 0;
    req->reg_req.wstrb = 0xf;
    req->reg_req.addr = addr_offs;
    req->reg_req.wdata = 0;

    return req;
}