// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void Vconv1d_tb_wrapper___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"STATE_IDLE", "STATE_A", "STATE_B", "STATE_C", 
                                "STATE_D", "STATE_E"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101"};
        tracep->declDTypeEnum(1, "fsm_qalc.state_t", 6, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"STATE_IDLE", "STATE_A", "STATE_B", "STATE_C", 
                                "STATE_D", "STATE_E", 
                                "STATE_F", "STATE_G", 
                                "STATE_H", "STATE_I", 
                                "STATE_J", "STATE_K", 
                                "STATE_L", "STATE_M", 
                                "STATE_N", "STATE_O", 
                                "STATE_P", "STATE_Q", 
                                "STATE_R", "STATE_S", 
                                "STATE_T1", "STATE_T2", 
                                "STATE_U", "STATE_V", 
                                "STATE_W", "STATE_X", 
                                "STATE_Y", "STATE_Z"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000", "1001", 
                                "1010", "1011", "1100", 
                                "1101", "1110", "1111", 
                                "10000", "10001", "10010", 
                                "10011", "10100", "10101", 
                                "10110", "10111", "11000", 
                                "11001", "11010", "11011"};
        tracep->declDTypeEnum(2, "fsm_tot.state_t", 28, 5, __VenumItemNames, __VenumItemValues);
    }
}

void Vconv1d_tb_wrapper___024root__trace_decl_types(VerilatedFst* tracep) {
    Vconv1d_tb_wrapper___024root__traceDeclTypesSub0(tracep);
}
