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
// File: conv1d.sv
// Author(s):
//   Luigi Giuffrida
//   Michele Caon
// Date: 08/11/2024
// Description: conv1d accelerator top module

module conv1d (
  /* verilator lint_off UNUSED */  // TODO: Remove this line when the signal is used
  /* verilator lint_off UNDRIVEN */  // TODO: Remove this line when the signal is used
  input logic clk_i,
  input logic rst_ni,

  // Interface towards internal memory
  input  conv1d_obi_pkg::obi_req_t  mem_req_i,    // Luca: vista la gerarchia l'interfaccia con la memoria interna non è in OBI
  output conv1d_obi_pkg::obi_resp_t mem_rsp_o,  // ""

  // TODO: add here other interface signals (e.g., from the config. registers)
  // MARCO: Segnali credo aggiunti da noi, forse non vanno aggiunti, bisogna capire guardandp conv1d_obi.sv. Bro dove li hai presi che non esistono nei package?
  //input conv1d_control_reg_pkg::control_reg_t control_reg_i, // GAETANO: serve per impostare i parametri di funzionamento del nostro acceleratore control register
  //output conv1d_control_reg_pkg::control_reg_t control_reg_o // GAETANO: serve per leggere lo status di funzuionamento del nostro acceleratore status register
  //  input  conv1d_reg_pkg::reg_req_t  reg_req_i,  // from host system
  //  output conv1d_reg_pkg::reg_resp_t reg_rsp_o,   // to host system

  input  conv1d_control_reg_pkg::conv1d_control_reg2hw_t reg2hw_t,
  output conv1d_control_reg_pkg::conv1d_control_hw2reg_t hw2reg_t


);
  // PARAMETERS
  localparam int unsigned NumWords = 32'd128;  // DO NOT CHANGE THIS!
  localparam int unsigned AddrWidth = (NumWords > 32'd1) ? unsigned'($clog2(NumWords)) : 32'd1;

  // INTERNAL SIGNALS
  // ----------------
  // import of packages
  import conv1d_sram_pkg::*;
  import conv1d_obi_pkg::*;
  import conv1d_control_reg_pkg::*;
  import conv1d_reg_pkg::*;

  // Memory multiplexer signals
  conv1d_sram_pkg::sram_req_t int_mem_req, ext_mem_req, mem_req;
  conv1d_sram_pkg::sram_rsp_t mem_rsp;
  logic                       ext_mem_gnt;

  // ---------------------
  // INTERNAL ARCHITECTURE
  // ---------------------
  // TODO: write here your code, you are encouraged to use a hierarchical (but not too hierarchical) approach.
  // The internal memory available to the accelerator as a data buffer has been
  // already instantiated below.


  accelerator accelerator_inst (
    /* verilator lint_off UNUSED */
    .clk     (clk_i),
    .reset_ni(rst_ni),
    //.control (reg2hw.control),  
    //.status1 (reg2hw.status1),  
    //.status2 (reg2hw.status2),  
    //.status1_o(hw2reg.status1),  
    //.status2_o(hw2reg.status2),  
    .reg2hw  (reg2hw_t),
    .hw2reg  (hw2reg_t),
    .req     (int_mem_req),
    .rsp     (mem_rsp),
    .grant   (ext_mem_gnt)
  );

  // Internal memory
  // ---------------
  // Internal memory request multiplexer
  // Because the same, single-port memory must be accessed both through the
  // GR-HEEP bus (host CPU/DMA) and by the accelerator internal hardware, a
  // multiplexer is used to arbitrate between the two.
  // TODO: change the following assignment to be low when the internal memory is
  // being used by the accelerator, so that external requests are not granted npr
  // propagated to the memory instance.
  // ------------------------------- qui dice che dobbiamo mettere ext_mem_gnt a 0 quando l'accelleratore sta usando la memoria interna (sram) cosi' da capire se la richiesta venga dall'interno o dall'esterno
  //assign ext_mem_gnt = 1'b1;  // MARCO: Credo vada gestito dalla CU

  // Internal memory multiplexer
  always_comb begin : mem_req_mux
    if (ext_mem_gnt == 1'b1) begin
      mem_req = ext_mem_req;
    end else begin
      mem_req = int_mem_req;
    end
  end

  // OBI to SRAM bridge
  conv1d_obi_to_sram_gnt #(
    .obi_req_t (conv1d_obi_pkg::obi_req_t),
    .obi_resp_t(conv1d_obi_pkg::obi_resp_t),
    .sram_req_t(conv1d_sram_pkg::sram_req_t),
    .sram_rsp_t(conv1d_sram_pkg::sram_rsp_t)
  ) u_obi_bridge (
    .clk_i     (clk_i),
    .rst_ni    (rst_ni),
    .obi_req_i (mem_req_i),
    .obi_rsp_o (mem_rsp_o),
    .sram_req_o(ext_mem_req),
    .sram_gnt_i(ext_mem_gnt),
    .sram_rsp_i(mem_rsp)
  );

  // Internal memory instance
  // NOTE: you may choose to instantiate two internal memories, each half the
  // size of this one (i.e., 64 words as the first parameter) to implement
  // double buffering.
  conv1d_sram_wrapper #(
    .NUM_WORDS (NumWords),
    .DATA_WIDTH(32'd32)
  ) u_internal_mem (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .req_i(mem_req.req),
    .we_i(mem_req.we),
    .addr_i(mem_req.addr[AddrWidth-1:0]),
    .wdata_i(mem_req.wdata),
    .be_i(mem_req.be),
    .rdata_o(mem_rsp.rdata) // MARCO: Invocare rdata è superfluo, forse (cioè serve, ma solo perchè sono tipi diversi?)
  );

  //  conv1d_control_reg control_reg_inst (
  //    /* verilator lint_off UNUSED */
  //    /* verilator lint_off UNDRIVEN */
  //    .clk_i (clk_i),
  //    .rst_ni(rst_ni),
  //    .req_i (reg_req_i),
  //    .rsp_o (reg_rsp_o),
  //    .reg2hw_tt(reg2hw_t),
  //    .hw2reg_tt(hw2reg_t)
  //  );

endmodule
