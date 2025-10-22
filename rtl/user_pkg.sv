// Copyright 2024 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Authors:
// - Philippe Sauter <phsauter@iis.ee.ethz.ch>

`include "register_interface/typedef.svh"
`include "obi/typedef.svh"

package user_pkg;

  ////////////////////////////////
  // User Manager Address maps //
  ///////////////////////////////
  
  // None


  /////////////////////////////////////
  // User Subordinate Address maps ////
  /////////////////////////////////////

  localparam int unsigned NumUserDomainSubordinates = 2; // Counter + Conv1d

  localparam bit [31:0] CntAddrOffset   = croc_pkg::UserBaseAddr; // 32'h2000_0000;
  localparam bit [31:0] CntAddrRange    = 32'h0001_0000;          // NOTE: taken by gr_heep.h slave

  localparam bit [31:0] Conv1dAddrOffset   = CntAddrOffset + CntAddrRange; // NOTE: At the end of CntAddr
  localparam bit [31:0] Conv1dAddrRange    = 32'h0001_0000;          // NOTE: taken by gr_heep.h slave

  localparam int unsigned NumDemuxSbrRules  = NumUserDomainSubordinates; // number of address rules in the decoder
  localparam int unsigned NumDemuxSbr       = NumDemuxSbrRules + 1; // additional OBI error, used for signal arrays

  // Enum for bus indices
  typedef enum int {
    UserError = 0,
    Cnt = 1,
    Conv1d = 2
  } user_demux_outputs_e;

  // Address rules given to address decoder
  localparam croc_pkg::addr_map_rule_t [NumDemuxSbrRules-1:0] user_addr_map = '{
    '{ idx: Cnt,  start_addr: CntAddrOffset, end_addr: CntAddrOffset + CntAddrRange}, // 1: Counter
    '{ idx: Conv1d,  start_addr: Conv1dAddrOffset, end_addr: Conv1dAddrOffset + Conv1dAddrRange} // 2: Conv1d
  };

endpackage
