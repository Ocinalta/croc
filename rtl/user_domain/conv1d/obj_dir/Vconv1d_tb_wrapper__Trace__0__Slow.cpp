// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vconv1d_tb_wrapper__Syms.h"


VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_init_sub__TOP__conv1d_control_reg_pkg__0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_init_sub__TOP__0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_init_sub__TOP__0\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("conv1d_control_reg_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vconv1d_tb_wrapper___024root__trace_init_sub__TOP__conv1d_control_reg_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+506,0,"obi_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"obi_we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"obi_be_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"obi_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"obi_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+511,0,"obi_gnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+512,0,"obi_rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+513,0,"obi_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+514,0,"reg_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"reg_write_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"reg_wstrb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+517,0,"reg_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"reg_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+519,0,"reg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+520,0,"reg_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+521,0,"reg_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+522,0,"done_int_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("conv1d_tb_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+506,0,"obi_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"obi_we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"obi_be_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"obi_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"obi_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+511,0,"obi_gnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+512,0,"obi_rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+513,0,"obi_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+514,0,"reg_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"reg_write_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"reg_wstrb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+517,0,"reg_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"reg_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+519,0,"reg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+520,0,"reg_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+521,0,"reg_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+522,0,"done_int_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("obi_req", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+506,0,"req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("obi_rsp", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+241,0,"gnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_req", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+514,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+517,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_rsp", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+519,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+561,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_conv1d_obi", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("obi_req_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+506,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"be",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("obi_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+241,0,"gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_req_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+514,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+517,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+519,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+561,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+522,0,"done_int_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("control", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+243,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mcu_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+244,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("loaded_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+246,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+247,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+248,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+249,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+250,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+251,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+252,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+253,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+254,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+255,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+256,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+257,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+258,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+259,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+260,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+262,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+264,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+266,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+268,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+270,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+272,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+274,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+275,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+276,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+277,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+278,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+279,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+280,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+281,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+283,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+285,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+287,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_conv1d", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem_req_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+506,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"be",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mem_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+241,0,"gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg2hw_t", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("control", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+243,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mcu_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+244,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("loaded_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+246,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+247,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+248,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+249,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+250,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+251,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+252,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+253,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+254,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+255,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+256,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+257,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+258,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+259,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg_t", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+260,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+262,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+264,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+266,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+268,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+270,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+272,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+274,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+275,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+276,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+277,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+278,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+279,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+280,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+281,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+283,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+285,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+287,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBus(c+562,0,"NumWords",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+563,0,"AddrWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("int_mem_req", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+288,0,"req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+290,0,"be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+291,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+292,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("ext_mem_req", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+506,0,"req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mem_req", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+138,0,"req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+141,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mem_rsp", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+242,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+241,0,"ext_mem_gnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("accelerator_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"reset_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("control", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+243,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mcu_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+244,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("loaded_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+246,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+247,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+248,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+249,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+250,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+251,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+252,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+253,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+254,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+255,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+256,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+257,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+258,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+259,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+260,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+262,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+264,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+266,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+268,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+270,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+272,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+274,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+275,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+276,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+277,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+278,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+279,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+280,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+281,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+283,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+285,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+287,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("req", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+288,0,"req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+290,0,"be",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+291,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+292,0,"wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("rsp", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+242,0,"rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+241,0,"grant",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+293,0,"start_qalc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"tc_cnt_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"tc_cnt_fin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+294,0,"rst_cnt_fin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+295,0,"rst_cnt_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+296,0,"en_cnt_fin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+297,0,"en_cnt_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"ld_reg_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"ld_reg_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+300,0,"ld_reg_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"rst_reg_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"done_qalc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+163,0,"reg_partial_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"ld_reg_weight",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+304,0,"ld_reg_din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+305,0,"rst_reg_din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+523,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_datapath", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+304,0,"ld_reg_din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+305,0,"rst_reg_din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+303,0,"ld_reg_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+298,0,"en_tmp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+295,0,"rst_cnt_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+294,0,"rst_cnt_sel_add_fin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+297,0,"en_cnt_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+296,0,"en_cnt_sel_add_fin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"en_reg_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+300,0,"en_partial",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"rst_partial",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"in_memory",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+161,0,"tc_cnt_sel_in",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"tc_cnt_sel_add_fin",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+163,0,"misa",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+306,0,"in_branch1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+307,0,"in_branch2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+308,0,"in_branch3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+309,0,"in_branch4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+164,0,"out_branch1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"out_branch2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"out_branch3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"out_branch4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"count_cnt_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+169,0,"count_cnt_add_fin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+170,0,"out_accumulator1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"out_accumulator2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"out_accumulator3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"out_accumulator4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("accumulator1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"ld_tmp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"ld_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+164,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"add_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"reg_tmp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"mux_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"add1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"add2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_sum", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+174,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+176,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+565,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_branch", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+299,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+176,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_tmp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+298,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+175,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("accumulator2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"ld_tmp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"ld_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+165,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"add_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"reg_tmp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"mux_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"add1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"add2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_sum", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+174,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+179,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+565,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_branch", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+299,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+179,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_tmp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+298,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+178,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("accumulator3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"ld_tmp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"ld_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+166,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+181,0,"add_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"reg_tmp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"mux_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"add1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"add2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+181,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_sum", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+174,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+182,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+565,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_branch", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+299,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+182,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_tmp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+298,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+181,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("accumulator4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"ld_tmp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"ld_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+167,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"add_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"reg_tmp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"mux_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"add1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"add2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_sum", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+174,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+185,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+565,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_branch", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+299,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+185,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_tmp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+298,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+184,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("branch1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+304,0,"ld_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+305,0,"rst_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+303,0,"ld_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+306,0,"in_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+164,0,"out_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"reg_data0_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+188,0,"reg_data1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+189,0,"reg_data2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+190,0,"reg_data3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+191,0,"reg_data4_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+192,0,"reg_weight0_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+193,0,"reg_weight1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+194,0,"reg_weight2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+195,0,"reg_weight3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+196,0,"reg_weight4_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+197,0,"mux_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+198,0,"mux_weight_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"mult1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+198,0,"mult2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+164,0,"prod",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"internal_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_data", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+187,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+188,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+189,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+190,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+191,0,"din5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+197,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_weight", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+192,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+193,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+194,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+195,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+196,0,"din5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+198,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+310,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+187,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+312,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+188,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+314,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+189,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+316,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+190,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+318,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+191,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+320,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+192,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+321,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+193,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+322,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+194,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+323,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+195,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+324,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+196,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("branch2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+304,0,"ld_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+305,0,"rst_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+303,0,"ld_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+307,0,"in_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+165,0,"out_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+200,0,"reg_data0_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+201,0,"reg_data1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+202,0,"reg_data2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+203,0,"reg_data3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+204,0,"reg_data4_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+205,0,"reg_weight0_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+206,0,"reg_weight1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+207,0,"reg_weight2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+208,0,"reg_weight3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+209,0,"reg_weight4_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+210,0,"mux_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+211,0,"mux_weight_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"mult1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+211,0,"mult2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+165,0,"prod",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"internal_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_data", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+200,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+201,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+202,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+203,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+204,0,"din5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+210,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_weight", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+205,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+206,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+207,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+208,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+209,0,"din5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+211,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+310,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+200,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+312,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+201,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+314,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+202,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+316,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+203,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+318,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+204,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+320,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+205,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+321,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+206,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+322,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+207,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+323,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+208,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+324,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+209,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("branch3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+304,0,"ld_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+305,0,"rst_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+303,0,"ld_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+308,0,"in_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+166,0,"out_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+213,0,"reg_data0_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+214,0,"reg_data1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+215,0,"reg_data2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+216,0,"reg_data3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+217,0,"reg_data4_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+218,0,"reg_weight0_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+219,0,"reg_weight1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+220,0,"reg_weight2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+221,0,"reg_weight3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+222,0,"reg_weight4_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+223,0,"mux_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+224,0,"mux_weight_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+223,0,"mult1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+224,0,"mult2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+166,0,"prod",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+225,0,"internal_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_data", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+213,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+214,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+215,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+216,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+217,0,"din5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+223,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_weight", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+218,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+219,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+220,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+221,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+222,0,"din5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+224,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+310,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+213,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+312,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+214,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+314,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+215,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+316,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+216,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+318,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+217,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+320,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+218,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+321,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+219,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+322,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+220,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+323,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+221,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+324,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+222,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("branch4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+304,0,"ld_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+305,0,"rst_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+303,0,"ld_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+309,0,"in_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+167,0,"out_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"reg_data0_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+227,0,"reg_data1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+228,0,"reg_data2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+229,0,"reg_data3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+230,0,"reg_data4_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+231,0,"reg_weight0_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+232,0,"reg_weight1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+233,0,"reg_weight2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+234,0,"reg_weight3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+235,0,"reg_weight4_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+236,0,"mux_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+237,0,"mux_weight_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+236,0,"mult1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+237,0,"mult2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+167,0,"prod",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"internal_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_data", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+226,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+227,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+228,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+229,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+230,0,"din5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+236,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_weight", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+231,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+232,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+233,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+234,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+235,0,"din5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+237,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+310,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+226,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+312,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+227,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+314,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+228,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+316,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+229,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_data4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+318,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+230,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+320,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+231,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+321,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+232,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+322,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+233,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+323,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+234,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_weight4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+567,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+324,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+566,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+235,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("cnt_sel_add_fin", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+294,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+296,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"tc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+169,0,"count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("cnt_sel_in", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+295,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+297,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"tc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+168,0,"count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("francesca", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+300,0,"ld_partial",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"rst_partial",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+169,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+170,0,"in_branch1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"in_branch2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"in_branch3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"in_branch4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+239,0,"mux_final_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+240,0,"add_tot_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"reg_partial_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("add_tot", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+239,0,"add1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"add2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+240,0,"sum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mux_final", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+170,0,"din1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"din2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"din3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"din4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+239,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_partial", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+564,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+300,0,"load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+240,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_fsm_qalc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+523,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+293,0,"start_qalc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"tc_cnt_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"tc_cnt_fin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+325,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+326,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+327,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+328,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+329,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+330,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+331,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+332,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+333,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+334,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+335,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+336,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+337,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+338,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBit(c+294,0,"rst_cnt_fin",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+295,0,"rst_cnt_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+296,0,"en_cnt_fin",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+297,0,"en_cnt_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"ld_reg_tmp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"ld_reg_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+300,0,"ld_reg_partial",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"rst_reg_partial",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"done_qalc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+339,0,"current_state",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+524,0,"next_state",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_fsm_tot", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+523,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"done_qalc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+163,0,"reg_partial_out",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("control", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+243,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mcu_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+244,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("loaded_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+246,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+247,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+248,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+249,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+250,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+251,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+252,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+253,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+254,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+255,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+256,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+257,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+258,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+259,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+260,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+262,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+264,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+266,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+268,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+270,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+272,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+274,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+275,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+276,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+277,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+278,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+279,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+280,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+281,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+283,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+285,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+287,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("reqq", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+288,0,"req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+290,0,"be",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+291,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+292,0,"wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+241,0,"grant",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+303,0,"ld_reg_weight",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+304,0,"ld_reg_din",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+305,0,"rst_reg_din",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+293,0,"start_qalc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+340,0,"current_state",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+341,0,"next_state",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_internal_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+562,0,"NUM_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+568,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+563,0,"AddrWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+143,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+142,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"be_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+242,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_tc_sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+562,0,"NumWords",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+568,0,"DataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+569,0,"ByteWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+570,0,"NumPorts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+570,0,"Latency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+571,0,"SimInit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+572,0,"PrintSimCfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+563,0,"AddrWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+573,0,"BeWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+138,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+139,0,"we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("addr_i", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+143,0,"[0]",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("wdata_i", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+142,0,"[0]",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("be_i", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+140,0,"[0]",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("rdata_o", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+242,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("sram", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+342,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+343,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+344,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+345,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+346,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+347,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+348,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+349,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+350,0,"[8]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+351,0,"[9]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+352,0,"[10]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+353,0,"[11]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+354,0,"[12]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+355,0,"[13]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+356,0,"[14]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+357,0,"[15]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+358,0,"[16]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+359,0,"[17]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+360,0,"[18]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+361,0,"[19]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+362,0,"[20]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+363,0,"[21]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+364,0,"[22]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+365,0,"[23]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+366,0,"[24]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+367,0,"[25]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+368,0,"[26]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+369,0,"[27]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+370,0,"[28]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+371,0,"[29]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+372,0,"[30]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+373,0,"[31]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+374,0,"[32]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+375,0,"[33]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+376,0,"[34]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+377,0,"[35]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+378,0,"[36]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+379,0,"[37]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+380,0,"[38]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+381,0,"[39]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+382,0,"[40]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+383,0,"[41]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+384,0,"[42]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+385,0,"[43]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+386,0,"[44]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+387,0,"[45]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+388,0,"[46]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+389,0,"[47]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+390,0,"[48]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+391,0,"[49]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+392,0,"[50]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+393,0,"[51]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+394,0,"[52]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+395,0,"[53]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+396,0,"[54]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+397,0,"[55]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+398,0,"[56]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+399,0,"[57]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+400,0,"[58]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+401,0,"[59]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+402,0,"[60]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+403,0,"[61]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+404,0,"[62]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+405,0,"[63]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+406,0,"[64]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+407,0,"[65]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+408,0,"[66]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+409,0,"[67]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+410,0,"[68]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+411,0,"[69]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"[70]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+413,0,"[71]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+414,0,"[72]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+415,0,"[73]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+416,0,"[74]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+417,0,"[75]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+418,0,"[76]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+419,0,"[77]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+420,0,"[78]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+421,0,"[79]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+422,0,"[80]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+423,0,"[81]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+424,0,"[82]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+425,0,"[83]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+426,0,"[84]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+427,0,"[85]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+428,0,"[86]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+429,0,"[87]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+430,0,"[88]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+431,0,"[89]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"[90]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+433,0,"[91]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+434,0,"[92]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+435,0,"[93]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+436,0,"[94]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+437,0,"[95]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+438,0,"[96]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+439,0,"[97]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+440,0,"[98]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+441,0,"[99]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+442,0,"[100]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+443,0,"[101]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+444,0,"[102]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+445,0,"[103]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+446,0,"[104]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+447,0,"[105]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+448,0,"[106]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+449,0,"[107]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+450,0,"[108]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+451,0,"[109]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+452,0,"[110]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+453,0,"[111]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+454,0,"[112]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+455,0,"[113]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+456,0,"[114]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+457,0,"[115]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+458,0,"[116]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+459,0,"[117]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+460,0,"[118]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+461,0,"[119]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+462,0,"[120]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+463,0,"[121]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+464,0,"[122]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+465,0,"[123]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+466,0,"[124]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+467,0,"[125]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+468,0,"[126]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+469,0,"[127]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("r_addr_q", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+470,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("init_val", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+1,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"[8]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"[9]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"[10]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"[11]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"[12]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"[13]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"[14]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"[15]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"[16]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"[17]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"[18]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"[19]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"[20]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"[21]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"[22]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"[23]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"[24]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"[25]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"[26]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"[27]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"[28]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"[29]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"[30]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"[31]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"[32]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"[33]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"[34]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"[35]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"[36]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"[37]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"[38]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"[39]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"[40]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"[41]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"[42]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"[43]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"[44]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"[45]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"[46]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"[47]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"[48]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"[49]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"[50]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"[51]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"[52]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"[53]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"[54]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"[55]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"[56]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"[57]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"[58]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"[59]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"[60]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"[61]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"[62]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"[63]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"[64]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"[65]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"[66]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"[67]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"[68]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"[69]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"[70]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"[71]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"[72]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"[73]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"[74]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"[75]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"[76]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"[77]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"[78]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"[79]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"[80]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"[81]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"[82]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"[83]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"[84]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"[85]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"[86]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"[87]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"[88]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"[89]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"[90]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"[91]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"[92]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"[93]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"[94]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"[95]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"[96]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"[97]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"[98]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"[99]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"[100]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"[101]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"[102]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"[103]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+105,0,"[104]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"[105]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"[106]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"[107]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"[108]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"[109]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"[110]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"[111]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"[112]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"[113]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"[114]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"[115]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"[116]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"[117]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"[118]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+120,0,"[119]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"[120]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"[121]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"[122]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+124,0,"[123]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+125,0,"[124]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"[125]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"[126]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"[127]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("rdata_q", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+242,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rdata_d", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_PACKED);
    tracep->declBus(c+144,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_read_lat", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+570,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+574,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("proc_sram_init", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+129,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+130,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk10", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+471,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk11", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+472,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+473,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+474,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+475,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+476,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk9", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+477,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_obi_bridge", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+570,0,"DELAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("obi_req_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+506,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"be",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("obi_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+241,0,"gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("sram_req_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+506,0,"req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+507,0,"we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"be",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+510,0,"wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+241,0,"sram_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sram_rsp_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+242,0,"rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("obi_rvalid", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBit(c+145+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_conv1d_control_reg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("req_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+514,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+517,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("rsp_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+519,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+561,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg2hw_tt", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("control", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+243,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mcu_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+244,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("loaded_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+246,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+247,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+248,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+249,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+250,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+251,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+252,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+253,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+254,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+255,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+256,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+257,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+258,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+259,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg_tt", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+260,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+262,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+264,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+266,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+268,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+270,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+272,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+274,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+275,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+276,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+277,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+278,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+279,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+280,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+281,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+283,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+285,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+287,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_conv1d_control_reg_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+575,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("reg_req_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+514,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+517,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+519,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+561,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("control", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+243,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mcu_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+244,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("loaded_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+245,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+246,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+247,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+248,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+249,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+250,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+251,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+252,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+253,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+254,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+255,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+256,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+257,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+258,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+259,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status1", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("running", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+260,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+262,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("accelerator_using_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+264,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reload_flag", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+266,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_calculation", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+268,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("done_filter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+270,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("filter_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+272,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_number_sram", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+274,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+275,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+276,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+277,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_number_weights", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+278,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+279,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lego_tower_din", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+280,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+281,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("din_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+283,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("dout_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+285,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("weight_address", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+287,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBit(c+566,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+576,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+575,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+131,0,"reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+525,0,"reg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+526,0,"reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+518,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+516,0,"reg_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+137,0,"reg_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+519,0,"reg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+527,0,"addrmiss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+519,0,"wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"reg_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reg_intf_req", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+514,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+515,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+516,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+517,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("reg_intf_rsp", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+519,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+561,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBit(c+478,0,"control_start_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+528,0,"control_start_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"control_start_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+479,0,"control_mcu_using_sram_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+529,0,"control_mcu_using_sram_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"control_mcu_using_sram_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+480,0,"control_loaded_flag_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+530,0,"control_loaded_flag_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"control_loaded_flag_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+481,0,"status1_running_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+528,0,"status1_running_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"status1_running_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+482,0,"status1_done_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+529,0,"status1_done_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"status1_done_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+483,0,"status1_accelerator_using_sram_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+530,0,"status1_accelerator_using_sram_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"status1_accelerator_using_sram_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+484,0,"status1_reload_flag_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+531,0,"status1_reload_flag_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"status1_reload_flag_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+485,0,"status1_done_calculation_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+532,0,"status1_done_calculation_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"status1_done_calculation_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+486,0,"status1_done_filter_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+533,0,"status1_done_filter_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"status1_done_filter_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+331,0,"status1_filter_number_sram_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+534,0,"status1_filter_number_sram_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+133,0,"status1_filter_number_sram_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+332,0,"status1_data_number_sram_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+535,0,"status1_data_number_sram_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+133,0,"status1_data_number_sram_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+333,0,"status1_lego_number_din_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+536,0,"status1_lego_number_din_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+133,0,"status1_lego_number_din_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+334,0,"status1_lego_number_weights_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+537,0,"status1_lego_number_weights_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+133,0,"status1_lego_number_weights_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+335,0,"status1_lego_tower_din_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+538,0,"status1_lego_tower_din_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+133,0,"status1_lego_tower_din_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+336,0,"status2_din_address_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+539,0,"status2_din_address_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+134,0,"status2_din_address_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+337,0,"status2_dout_address_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+540,0,"status2_dout_address_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+134,0,"status2_dout_address_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+338,0,"status2_weight_address_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+541,0,"status2_weight_address_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+134,0,"status2_weight_address_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+135,0,"addr_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+542,0,"unused_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+543,0,"unused_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_control_loaded_flag", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+530,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+566,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+566,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+487,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+480,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+480,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+132,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+544,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+132,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+530,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+566,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+566,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+480,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+132,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+544,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+480,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_control_mcu_using_sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+529,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+566,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+566,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+488,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+479,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+479,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+132,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+545,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+132,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+529,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+566,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+566,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+479,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+132,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+545,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+479,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_control_start", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+528,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+566,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+566,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+489,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+478,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+478,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+132,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+546,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+132,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+528,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+566,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+566,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+478,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+132,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+546,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+478,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_accelerator_using_sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+530,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+265,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+490,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+483,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+483,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+147,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+547,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+530,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+265,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+483,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+147,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+547,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+483,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_data_number_sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+580,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+581,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+535,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+275,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+274,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+491,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+332,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+332,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+148,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+548,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+580,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+535,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+275,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+274,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+332,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+148,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+548,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+332,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_done", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+529,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+263,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+262,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+492,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+482,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+482,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+149,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+549,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+529,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+263,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+262,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+482,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+149,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+549,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+482,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_done_calculation", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+532,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+269,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+268,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+493,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+485,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+485,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+150,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+550,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+532,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+269,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+268,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+485,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+150,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+550,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+485,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_done_filter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+533,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+271,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+270,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+494,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+486,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+486,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+151,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+551,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+533,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+271,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+270,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+486,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+151,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+551,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+486,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_filter_number_sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+580,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+581,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+534,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+272,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+495,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+331,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+331,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+152,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+552,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+580,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+534,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+272,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+331,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+152,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+552,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+331,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_lego_number_din", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+582,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+583,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+536,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+277,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+276,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+496,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+333,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+333,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+153,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+553,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+582,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+536,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+277,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+276,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+333,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+153,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+553,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+333,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_lego_number_weights", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+582,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+583,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+537,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+279,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+278,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+497,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+334,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+334,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+154,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+554,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+582,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+537,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+279,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+278,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+334,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+154,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+554,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+334,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_lego_tower_din", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+584,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+585,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+538,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+281,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+280,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+498,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+335,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+335,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+155,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+555,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+584,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+538,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+281,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+280,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+335,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+155,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+555,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+335,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_reload_flag", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+531,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+267,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+266,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+499,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+484,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+484,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+156,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+556,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+531,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+267,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+266,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+484,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+156,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+556,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+484,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status1_running", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+579,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+528,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+261,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+260,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+500,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+481,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+481,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+157,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+557,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+577,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+133,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+528,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+261,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+260,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+481,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+157,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+557,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+481,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status2_din_address", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+586,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+587,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+539,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+283,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+501,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+336,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+336,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+158,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+558,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+586,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+134,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+539,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+283,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+336,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+158,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+558,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+336,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status2_dout_address", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+586,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+587,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+540,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+285,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+502,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+337,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+337,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+159,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+559,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+586,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+134,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+540,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+285,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+337,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+159,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+559,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+337,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_status2_weight_address", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+586,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+587,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+504,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+505,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+541,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+287,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+503,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+338,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+338,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+160,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+560,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+586,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+578,0,"SWACCESS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+134,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+541,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+287,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+338,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+160,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+560,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+338,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_init_sub__TOP__conv1d_control_reg_pkg__0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_init_sub__TOP__conv1d_control_reg_pkg__0\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+575,0,"BlockAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+588,0,"CONV1D_CONTROL_CONTROL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+589,0,"CONV1D_CONTROL_STATUS1_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+590,0,"CONV1D_CONTROL_STATUS2_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("CONV1D_CONTROL_PERMIT", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+591+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
}

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_init_top(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_init_top\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vconv1d_tb_wrapper___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vconv1d_tb_wrapper___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vconv1d_tb_wrapper___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_register(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_register\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vconv1d_tb_wrapper___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vconv1d_tb_wrapper___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vconv1d_tb_wrapper___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vconv1d_tb_wrapper___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_const_0_sub_0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_const_0\n"); );
    // Init
    Vconv1d_tb_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vconv1d_tb_wrapper___024root*>(voidSelf);
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vconv1d_tb_wrapper___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_const_0_sub_0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_const_0_sub_0\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+561,(1U));
    bufp->fullIData(oldp+562,(0x80U),32);
    bufp->fullIData(oldp+563,(7U),32);
    bufp->fullIData(oldp+564,(0x20U),32);
    bufp->fullIData(oldp+565,(0U),32);
    bufp->fullBit(oldp+566,(0U));
    bufp->fullIData(oldp+567,(8U),32);
    bufp->fullIData(oldp+568,(0x20U),32);
    bufp->fullIData(oldp+569,(8U),32);
    bufp->fullIData(oldp+570,(1U),32);
    bufp->fullIData(oldp+571,(0x6e6f6e65U),32);
    bufp->fullBit(oldp+572,(0U));
    bufp->fullIData(oldp+573,(4U),32);
    bufp->fullIData(oldp+574,(0U),32);
    bufp->fullIData(oldp+575,(4U),32);
    bufp->fullIData(oldp+576,(0x20U),32);
    bufp->fullIData(oldp+577,(1U),32);
    bufp->fullSData(oldp+578,(0x5257U),16);
    bufp->fullBit(oldp+579,(0U));
    bufp->fullIData(oldp+580,(3U),32);
    bufp->fullCData(oldp+581,(0U),3);
    bufp->fullIData(oldp+582,(2U),32);
    bufp->fullCData(oldp+583,(0U),2);
    bufp->fullIData(oldp+584,(5U),32);
    bufp->fullCData(oldp+585,(0U),5);
    bufp->fullIData(oldp+586,(8U),32);
    bufp->fullCData(oldp+587,(0U),8);
    bufp->fullCData(oldp+588,(0U),4);
    bufp->fullCData(oldp+589,(4U),4);
    bufp->fullCData(oldp+590,(8U),4);
    bufp->fullCData(oldp+591,(vlSymsp->TOP__conv1d_control_reg_pkg.__PVT__CONV1D_CONTROL_PERMIT[0]),4);
    bufp->fullCData(oldp+592,(vlSymsp->TOP__conv1d_control_reg_pkg.__PVT__CONV1D_CONTROL_PERMIT[1]),4);
    bufp->fullCData(oldp+593,(vlSymsp->TOP__conv1d_control_reg_pkg.__PVT__CONV1D_CONTROL_PERMIT[2]),4);
}

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_full_0_sub_0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_full_0\n"); );
    // Init
    Vconv1d_tb_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vconv1d_tb_wrapper___024root*>(voidSelf);
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vconv1d_tb_wrapper___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_full_0_sub_0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_full_0_sub_0\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0U]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[1U]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[2U]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[3U]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[4U]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[5U]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[6U]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[7U]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[8U]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[9U]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xaU]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xbU]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xcU]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xdU]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xeU]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xfU]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x10U]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x11U]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x12U]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x13U]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x14U]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x15U]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x16U]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x17U]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x18U]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x19U]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1aU]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1bU]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1cU]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1dU]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1eU]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1fU]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x20U]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x21U]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x22U]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x23U]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x24U]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x25U]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x26U]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x27U]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x28U]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x29U]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2aU]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2bU]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2cU]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2dU]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2eU]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2fU]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x30U]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x31U]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x32U]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x33U]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x34U]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x35U]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x36U]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x37U]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x38U]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x39U]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3aU]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3bU]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3cU]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3dU]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3eU]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3fU]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x40U]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x41U]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x42U]),32);
    bufp->fullIData(oldp+68,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x43U]),32);
    bufp->fullIData(oldp+69,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x44U]),32);
    bufp->fullIData(oldp+70,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x45U]),32);
    bufp->fullIData(oldp+71,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x46U]),32);
    bufp->fullIData(oldp+72,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x47U]),32);
    bufp->fullIData(oldp+73,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x48U]),32);
    bufp->fullIData(oldp+74,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x49U]),32);
    bufp->fullIData(oldp+75,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4aU]),32);
    bufp->fullIData(oldp+76,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4bU]),32);
    bufp->fullIData(oldp+77,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4cU]),32);
    bufp->fullIData(oldp+78,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4dU]),32);
    bufp->fullIData(oldp+79,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4eU]),32);
    bufp->fullIData(oldp+80,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4fU]),32);
    bufp->fullIData(oldp+81,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x50U]),32);
    bufp->fullIData(oldp+82,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x51U]),32);
    bufp->fullIData(oldp+83,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x52U]),32);
    bufp->fullIData(oldp+84,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x53U]),32);
    bufp->fullIData(oldp+85,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x54U]),32);
    bufp->fullIData(oldp+86,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x55U]),32);
    bufp->fullIData(oldp+87,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x56U]),32);
    bufp->fullIData(oldp+88,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x57U]),32);
    bufp->fullIData(oldp+89,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x58U]),32);
    bufp->fullIData(oldp+90,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x59U]),32);
    bufp->fullIData(oldp+91,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5aU]),32);
    bufp->fullIData(oldp+92,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5bU]),32);
    bufp->fullIData(oldp+93,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5cU]),32);
    bufp->fullIData(oldp+94,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5dU]),32);
    bufp->fullIData(oldp+95,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5eU]),32);
    bufp->fullIData(oldp+96,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5fU]),32);
    bufp->fullIData(oldp+97,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x60U]),32);
    bufp->fullIData(oldp+98,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x61U]),32);
    bufp->fullIData(oldp+99,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x62U]),32);
    bufp->fullIData(oldp+100,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x63U]),32);
    bufp->fullIData(oldp+101,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x64U]),32);
    bufp->fullIData(oldp+102,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x65U]),32);
    bufp->fullIData(oldp+103,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x66U]),32);
    bufp->fullIData(oldp+104,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x67U]),32);
    bufp->fullIData(oldp+105,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x68U]),32);
    bufp->fullIData(oldp+106,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x69U]),32);
    bufp->fullIData(oldp+107,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6aU]),32);
    bufp->fullIData(oldp+108,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6bU]),32);
    bufp->fullIData(oldp+109,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6cU]),32);
    bufp->fullIData(oldp+110,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6dU]),32);
    bufp->fullIData(oldp+111,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6eU]),32);
    bufp->fullIData(oldp+112,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6fU]),32);
    bufp->fullIData(oldp+113,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x70U]),32);
    bufp->fullIData(oldp+114,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x71U]),32);
    bufp->fullIData(oldp+115,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x72U]),32);
    bufp->fullIData(oldp+116,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x73U]),32);
    bufp->fullIData(oldp+117,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x74U]),32);
    bufp->fullIData(oldp+118,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x75U]),32);
    bufp->fullIData(oldp+119,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x76U]),32);
    bufp->fullIData(oldp+120,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x77U]),32);
    bufp->fullIData(oldp+121,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x78U]),32);
    bufp->fullIData(oldp+122,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x79U]),32);
    bufp->fullIData(oldp+123,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7aU]),32);
    bufp->fullIData(oldp+124,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7bU]),32);
    bufp->fullIData(oldp+125,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7cU]),32);
    bufp->fullIData(oldp+126,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7dU]),32);
    bufp->fullIData(oldp+127,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7eU]),32);
    bufp->fullIData(oldp+128,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7fU]),32);
    bufp->fullIData(oldp+129,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__proc_sram_init__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+130,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__proc_sram_init__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j),32);
    bufp->fullBit(oldp+131,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_we));
    bufp->fullBit(oldp+132,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we));
    bufp->fullBit(oldp+133,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    bufp->fullBit(oldp+134,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we));
    bufp->fullCData(oldp+135,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0),3);
    bufp->fullBit(oldp+136,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__obi_rvalid
                            [1U]));
    bufp->fullIData(oldp+137,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next),32);
    bufp->fullBit(oldp+138,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
                                   >> 5U))));
    bufp->fullBit(oldp+139,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
                                   >> 4U))));
    bufp->fullCData(oldp+140,((0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])),4);
    bufp->fullIData(oldp+141,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]),32);
    bufp->fullIData(oldp+142,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U]),32);
    bufp->fullCData(oldp+143,((0x7fU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U])),7);
    bufp->fullIData(oldp+144,(((IData)((0x20U == (0x30U 
                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])))
                                ? (((0U == (0x1fU & 
                                            VL_SHIFTL_III(12,32,32, 
                                                          (0x7fU 
                                                           & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))
                                     ? 0U : (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                                             (((IData)(0x1fU) 
                                               + (0xfffU 
                                                  & VL_SHIFTL_III(12,32,32, 
                                                                  (0x7fU 
                                                                   & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(12,32,32, 
                                                                  (0x7fU 
                                                                   & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                                   | (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                                      (0x7fU & (VL_SHIFTL_III(12,32,32, 
                                                              (0x7fU 
                                                               & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(12,32,32, 
                                                                (0x7fU 
                                                                 & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))
                                : (((0U == (0x1fU & 
                                            VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U)))
                                     ? 0U : (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                                             (((IData)(0x1fU) 
                                               + (0xfffU 
                                                  & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U))))) 
                                   | (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                                      (0x7fU & (VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U) 
                                                >> 5U))] 
                                      >> (0x1fU & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U)))))),32);
    bufp->fullBit(oldp+145,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__obi_rvalid[0]));
    bufp->fullBit(oldp+146,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__obi_rvalid[1]));
    bufp->fullBit(oldp+147,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x35U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+148,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x27U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+149,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x37U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+150,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x31U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+151,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x2fU)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+152,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x2bU)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+153,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x24U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+154,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x21U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+155,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x1bU)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+156,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x33U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+157,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x39U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
    bufp->fullBit(oldp+158,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 0x12U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))));
    bufp->fullBit(oldp+159,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                            >> 9U)) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))));
    bufp->fullBit(oldp+160,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))));
    bufp->fullBit(oldp+161,((0U == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))));
    bufp->fullBit(oldp+162,((3U == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))));
    bufp->fullIData(oldp+163,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out),32);
    bufp->fullIData(oldp+164,((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product))),32);
    bufp->fullIData(oldp+165,((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product))),32);
    bufp->fullIData(oldp+166,((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product))),32);
    bufp->fullIData(oldp+167,((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product))),32);
    bufp->fullCData(oldp+168,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in),3);
    bufp->fullCData(oldp+169,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin),2);
    bufp->fullIData(oldp+170,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator1),32);
    bufp->fullIData(oldp+171,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator2),32);
    bufp->fullIData(oldp+172,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator3),32);
    bufp->fullIData(oldp+173,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator4),32);
    bufp->fullBit(oldp+174,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in) 
                                   >> 2U))));
    bufp->fullIData(oldp+175,(((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product) 
                                                   >> 0xfU)))) 
                                 << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product)) 
                               + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out))),32);
    bufp->fullIData(oldp+176,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out),32);
    bufp->fullIData(oldp+177,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out)),32);
    bufp->fullIData(oldp+178,(((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product) 
                                                   >> 0xfU)))) 
                                 << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product)) 
                               + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out))),32);
    bufp->fullIData(oldp+179,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out),32);
    bufp->fullIData(oldp+180,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out)),32);
    bufp->fullIData(oldp+181,(((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product) 
                                                   >> 0xfU)))) 
                                 << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product)) 
                               + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out))),32);
    bufp->fullIData(oldp+182,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out),32);
    bufp->fullIData(oldp+183,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out)),32);
    bufp->fullIData(oldp+184,(((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product) 
                                                   >> 0xfU)))) 
                                 << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product)) 
                               + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out))),32);
    bufp->fullIData(oldp+185,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out),32);
    bufp->fullIData(oldp+186,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out)),32);
    bufp->fullCData(oldp+187,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data0_out),8);
    bufp->fullCData(oldp+188,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data1_out),8);
    bufp->fullCData(oldp+189,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data2_out),8);
    bufp->fullCData(oldp+190,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data3_out),8);
    bufp->fullCData(oldp+191,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data4_out),8);
    bufp->fullCData(oldp+192,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight0_out),8);
    bufp->fullCData(oldp+193,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight1_out),8);
    bufp->fullCData(oldp+194,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight2_out),8);
    bufp->fullCData(oldp+195,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight3_out),8);
    bufp->fullCData(oldp+196,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight4_out),8);
    bufp->fullCData(oldp+197,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                             ? 0U : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data0_out)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data1_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data2_out))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data3_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data4_out))))),8);
    bufp->fullCData(oldp+198,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                             ? 0U : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight0_out)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight1_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight2_out))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight3_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight4_out))))),8);
    bufp->fullSData(oldp+199,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product),16);
    bufp->fullCData(oldp+200,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data0_out),8);
    bufp->fullCData(oldp+201,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data1_out),8);
    bufp->fullCData(oldp+202,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data2_out),8);
    bufp->fullCData(oldp+203,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data3_out),8);
    bufp->fullCData(oldp+204,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data4_out),8);
    bufp->fullCData(oldp+205,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight0_out),8);
    bufp->fullCData(oldp+206,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight1_out),8);
    bufp->fullCData(oldp+207,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight2_out),8);
    bufp->fullCData(oldp+208,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight3_out),8);
    bufp->fullCData(oldp+209,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight4_out),8);
    bufp->fullCData(oldp+210,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                             ? 0U : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data0_out)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data1_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data2_out))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data3_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data4_out))))),8);
    bufp->fullCData(oldp+211,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                             ? 0U : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight0_out)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight1_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight2_out))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight3_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight4_out))))),8);
    bufp->fullSData(oldp+212,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product),16);
    bufp->fullCData(oldp+213,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data0_out),8);
    bufp->fullCData(oldp+214,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data1_out),8);
    bufp->fullCData(oldp+215,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data2_out),8);
    bufp->fullCData(oldp+216,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data3_out),8);
    bufp->fullCData(oldp+217,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data4_out),8);
    bufp->fullCData(oldp+218,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight0_out),8);
    bufp->fullCData(oldp+219,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight1_out),8);
    bufp->fullCData(oldp+220,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight2_out),8);
    bufp->fullCData(oldp+221,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight3_out),8);
    bufp->fullCData(oldp+222,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight4_out),8);
    bufp->fullCData(oldp+223,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                             ? 0U : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data0_out)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data1_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data2_out))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data3_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data4_out))))),8);
    bufp->fullCData(oldp+224,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                             ? 0U : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight0_out)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight1_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight2_out))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight3_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight4_out))))),8);
    bufp->fullSData(oldp+225,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product),16);
    bufp->fullCData(oldp+226,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data0_out),8);
    bufp->fullCData(oldp+227,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data1_out),8);
    bufp->fullCData(oldp+228,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data2_out),8);
    bufp->fullCData(oldp+229,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data3_out),8);
    bufp->fullCData(oldp+230,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data4_out),8);
    bufp->fullCData(oldp+231,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight0_out),8);
    bufp->fullCData(oldp+232,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight1_out),8);
    bufp->fullCData(oldp+233,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight2_out),8);
    bufp->fullCData(oldp+234,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight3_out),8);
    bufp->fullCData(oldp+235,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight4_out),8);
    bufp->fullCData(oldp+236,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                             ? 0U : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data0_out)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data1_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data2_out))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data3_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data4_out))))),8);
    bufp->fullCData(oldp+237,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                             ? 0U : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight0_out)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight1_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight2_out))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                        ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight3_out)
                                        : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight4_out))))),8);
    bufp->fullSData(oldp+238,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product),16);
    bufp->fullIData(oldp+239,(((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                    ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator4
                                    : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator3)
                                : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                    ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator2
                                    : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator1))),32);
    bufp->fullIData(oldp+240,((((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                 ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                     ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator4
                                     : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator3)
                                 : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                     ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator2
                                     : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator1)) 
                               + vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out)),32);
    bufp->fullBit(oldp+241,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt));
    bufp->fullIData(oldp+242,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q),32);
    bufp->fullBit(oldp+243,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x2fU)))));
    bufp->fullBit(oldp+244,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x2eU)))));
    bufp->fullBit(oldp+245,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x2dU)))));
    bufp->fullBit(oldp+246,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x2cU)))));
    bufp->fullBit(oldp+247,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x2bU)))));
    bufp->fullBit(oldp+248,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x2aU)))));
    bufp->fullBit(oldp+249,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x29U)))));
    bufp->fullBit(oldp+250,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x28U)))));
    bufp->fullBit(oldp+251,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x27U)))));
    bufp->fullCData(oldp+252,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                             >> 0x24U)))),3);
    bufp->fullCData(oldp+253,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                             >> 0x21U)))),3);
    bufp->fullCData(oldp+254,((3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                             >> 0x1fU)))),2);
    bufp->fullCData(oldp+255,((3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                             >> 0x1dU)))),2);
    bufp->fullCData(oldp+256,((0x1fU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                >> 0x18U)))),5);
    bufp->fullCData(oldp+257,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                >> 0x10U)))),8);
    bufp->fullCData(oldp+258,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                >> 8U)))),8);
    bufp->fullCData(oldp+259,((0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw))),8);
    bufp->fullBit(oldp+260,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x3aU)))));
    bufp->fullBit(oldp+261,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x39U)))));
    bufp->fullBit(oldp+262,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x38U)))));
    bufp->fullBit(oldp+263,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x37U)))));
    bufp->fullBit(oldp+264,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x36U)))));
    bufp->fullBit(oldp+265,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x35U)))));
    bufp->fullBit(oldp+266,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x34U)))));
    bufp->fullBit(oldp+267,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x33U)))));
    bufp->fullBit(oldp+268,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x32U)))));
    bufp->fullBit(oldp+269,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x31U)))));
    bufp->fullBit(oldp+270,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x30U)))));
    bufp->fullBit(oldp+271,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x2fU)))));
    bufp->fullCData(oldp+272,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                             >> 0x2cU)))),3);
    bufp->fullBit(oldp+273,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x2bU)))));
    bufp->fullCData(oldp+274,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                             >> 0x28U)))),3);
    bufp->fullBit(oldp+275,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x27U)))));
    bufp->fullCData(oldp+276,((3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                             >> 0x25U)))),2);
    bufp->fullBit(oldp+277,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x24U)))));
    bufp->fullCData(oldp+278,((3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                             >> 0x22U)))),2);
    bufp->fullBit(oldp+279,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x21U)))));
    bufp->fullCData(oldp+280,((0x1fU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                >> 0x1cU)))),5);
    bufp->fullBit(oldp+281,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x1bU)))));
    bufp->fullCData(oldp+282,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                >> 0x13U)))),8);
    bufp->fullBit(oldp+283,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 0x12U)))));
    bufp->fullCData(oldp+284,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                >> 0xaU)))),8);
    bufp->fullBit(oldp+285,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                           >> 9U)))));
    bufp->fullCData(oldp+286,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                >> 1U)))),8);
    bufp->fullBit(oldp+287,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg))));
    bufp->fullBit(oldp+288,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                                   >> 5U))));
    bufp->fullBit(oldp+289,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                                   >> 4U))));
    bufp->fullCData(oldp+290,((0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U])),4);
    bufp->fullIData(oldp+291,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]),32);
    bufp->fullIData(oldp+292,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[0U]),32);
    bufp->fullBit(oldp+293,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc));
    bufp->fullBit(oldp+294,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_cnt_fin));
    bufp->fullBit(oldp+295,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_cnt_branch));
    bufp->fullBit(oldp+296,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__en_cnt_fin));
    bufp->fullBit(oldp+297,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__en_cnt_branch));
    bufp->fullBit(oldp+298,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_tmp));
    bufp->fullBit(oldp+299,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_branch));
    bufp->fullBit(oldp+300,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_partial));
    bufp->fullBit(oldp+301,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_partial));
    bufp->fullBit(oldp+302,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__done_qalc));
    bufp->fullCData(oldp+303,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight),5);
    bufp->fullCData(oldp+304,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din),5);
    bufp->fullCData(oldp+305,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din),5);
    bufp->fullCData(oldp+306,((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                               >> 0x18U)),8);
    bufp->fullCData(oldp+307,((0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                                        >> 0x10U))),8);
    bufp->fullCData(oldp+308,((0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                                        >> 8U))),8);
    bufp->fullCData(oldp+309,((0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q)),8);
    bufp->fullBit(oldp+310,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))));
    bufp->fullBit(oldp+311,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din))));
    bufp->fullBit(oldp+312,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din) 
                                   >> 1U))));
    bufp->fullBit(oldp+313,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din) 
                                   >> 1U))));
    bufp->fullBit(oldp+314,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din) 
                                   >> 2U))));
    bufp->fullBit(oldp+315,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din) 
                                   >> 2U))));
    bufp->fullBit(oldp+316,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din) 
                                   >> 3U))));
    bufp->fullBit(oldp+317,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din) 
                                   >> 3U))));
    bufp->fullBit(oldp+318,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din) 
                                   >> 4U))));
    bufp->fullBit(oldp+319,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din) 
                                   >> 4U))));
    bufp->fullBit(oldp+320,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight))));
    bufp->fullBit(oldp+321,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight) 
                                   >> 1U))));
    bufp->fullBit(oldp+322,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight) 
                                   >> 2U))));
    bufp->fullBit(oldp+323,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight) 
                                   >> 3U))));
    bufp->fullBit(oldp+324,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight) 
                                   >> 4U))));
    bufp->fullBit(oldp+325,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q));
    bufp->fullBit(oldp+326,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q));
    bufp->fullBit(oldp+327,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q));
    bufp->fullBit(oldp+328,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q));
    bufp->fullBit(oldp+329,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q));
    bufp->fullBit(oldp+330,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q));
    bufp->fullCData(oldp+331,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_filter_number_sram__q),3);
    bufp->fullCData(oldp+332,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_data_number_sram__q),3);
    bufp->fullCData(oldp+333,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q),2);
    bufp->fullCData(oldp+334,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_weights__q),2);
    bufp->fullCData(oldp+335,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_tower_din__q),5);
    bufp->fullCData(oldp+336,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_din_address__q),8);
    bufp->fullCData(oldp+337,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_dout_address__q),8);
    bufp->fullCData(oldp+338,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_weight_address__q),8);
    bufp->fullCData(oldp+339,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state),3);
    bufp->fullCData(oldp+340,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state),5);
    bufp->fullCData(oldp+341,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state),5);
    bufp->fullIData(oldp+342,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0U]),32);
    bufp->fullIData(oldp+343,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[1U]),32);
    bufp->fullIData(oldp+344,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[2U]),32);
    bufp->fullIData(oldp+345,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[3U]),32);
    bufp->fullIData(oldp+346,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[4U]),32);
    bufp->fullIData(oldp+347,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[5U]),32);
    bufp->fullIData(oldp+348,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[6U]),32);
    bufp->fullIData(oldp+349,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[7U]),32);
    bufp->fullIData(oldp+350,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[8U]),32);
    bufp->fullIData(oldp+351,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[9U]),32);
    bufp->fullIData(oldp+352,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xaU]),32);
    bufp->fullIData(oldp+353,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xbU]),32);
    bufp->fullIData(oldp+354,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xcU]),32);
    bufp->fullIData(oldp+355,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xdU]),32);
    bufp->fullIData(oldp+356,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xeU]),32);
    bufp->fullIData(oldp+357,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xfU]),32);
    bufp->fullIData(oldp+358,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x10U]),32);
    bufp->fullIData(oldp+359,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x11U]),32);
    bufp->fullIData(oldp+360,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x12U]),32);
    bufp->fullIData(oldp+361,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x13U]),32);
    bufp->fullIData(oldp+362,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x14U]),32);
    bufp->fullIData(oldp+363,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x15U]),32);
    bufp->fullIData(oldp+364,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x16U]),32);
    bufp->fullIData(oldp+365,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x17U]),32);
    bufp->fullIData(oldp+366,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x18U]),32);
    bufp->fullIData(oldp+367,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x19U]),32);
    bufp->fullIData(oldp+368,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1aU]),32);
    bufp->fullIData(oldp+369,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1bU]),32);
    bufp->fullIData(oldp+370,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1cU]),32);
    bufp->fullIData(oldp+371,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1dU]),32);
    bufp->fullIData(oldp+372,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1eU]),32);
    bufp->fullIData(oldp+373,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1fU]),32);
    bufp->fullIData(oldp+374,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x20U]),32);
    bufp->fullIData(oldp+375,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x21U]),32);
    bufp->fullIData(oldp+376,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x22U]),32);
    bufp->fullIData(oldp+377,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x23U]),32);
    bufp->fullIData(oldp+378,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x24U]),32);
    bufp->fullIData(oldp+379,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x25U]),32);
    bufp->fullIData(oldp+380,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x26U]),32);
    bufp->fullIData(oldp+381,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x27U]),32);
    bufp->fullIData(oldp+382,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x28U]),32);
    bufp->fullIData(oldp+383,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x29U]),32);
    bufp->fullIData(oldp+384,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2aU]),32);
    bufp->fullIData(oldp+385,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2bU]),32);
    bufp->fullIData(oldp+386,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2cU]),32);
    bufp->fullIData(oldp+387,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2dU]),32);
    bufp->fullIData(oldp+388,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2eU]),32);
    bufp->fullIData(oldp+389,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2fU]),32);
    bufp->fullIData(oldp+390,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x30U]),32);
    bufp->fullIData(oldp+391,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x31U]),32);
    bufp->fullIData(oldp+392,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x32U]),32);
    bufp->fullIData(oldp+393,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x33U]),32);
    bufp->fullIData(oldp+394,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x34U]),32);
    bufp->fullIData(oldp+395,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x35U]),32);
    bufp->fullIData(oldp+396,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x36U]),32);
    bufp->fullIData(oldp+397,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x37U]),32);
    bufp->fullIData(oldp+398,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x38U]),32);
    bufp->fullIData(oldp+399,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x39U]),32);
    bufp->fullIData(oldp+400,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3aU]),32);
    bufp->fullIData(oldp+401,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3bU]),32);
    bufp->fullIData(oldp+402,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3cU]),32);
    bufp->fullIData(oldp+403,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3dU]),32);
    bufp->fullIData(oldp+404,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3eU]),32);
    bufp->fullIData(oldp+405,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3fU]),32);
    bufp->fullIData(oldp+406,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x40U]),32);
    bufp->fullIData(oldp+407,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x41U]),32);
    bufp->fullIData(oldp+408,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x42U]),32);
    bufp->fullIData(oldp+409,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x43U]),32);
    bufp->fullIData(oldp+410,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x44U]),32);
    bufp->fullIData(oldp+411,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x45U]),32);
    bufp->fullIData(oldp+412,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x46U]),32);
    bufp->fullIData(oldp+413,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x47U]),32);
    bufp->fullIData(oldp+414,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x48U]),32);
    bufp->fullIData(oldp+415,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x49U]),32);
    bufp->fullIData(oldp+416,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4aU]),32);
    bufp->fullIData(oldp+417,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4bU]),32);
    bufp->fullIData(oldp+418,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4cU]),32);
    bufp->fullIData(oldp+419,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4dU]),32);
    bufp->fullIData(oldp+420,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4eU]),32);
    bufp->fullIData(oldp+421,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4fU]),32);
    bufp->fullIData(oldp+422,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x50U]),32);
    bufp->fullIData(oldp+423,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x51U]),32);
    bufp->fullIData(oldp+424,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x52U]),32);
    bufp->fullIData(oldp+425,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x53U]),32);
    bufp->fullIData(oldp+426,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x54U]),32);
    bufp->fullIData(oldp+427,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x55U]),32);
    bufp->fullIData(oldp+428,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x56U]),32);
    bufp->fullIData(oldp+429,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x57U]),32);
    bufp->fullIData(oldp+430,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x58U]),32);
    bufp->fullIData(oldp+431,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x59U]),32);
    bufp->fullIData(oldp+432,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5aU]),32);
    bufp->fullIData(oldp+433,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5bU]),32);
    bufp->fullIData(oldp+434,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5cU]),32);
    bufp->fullIData(oldp+435,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5dU]),32);
    bufp->fullIData(oldp+436,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5eU]),32);
    bufp->fullIData(oldp+437,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5fU]),32);
    bufp->fullIData(oldp+438,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x60U]),32);
    bufp->fullIData(oldp+439,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x61U]),32);
    bufp->fullIData(oldp+440,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x62U]),32);
    bufp->fullIData(oldp+441,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x63U]),32);
    bufp->fullIData(oldp+442,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x64U]),32);
    bufp->fullIData(oldp+443,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x65U]),32);
    bufp->fullIData(oldp+444,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x66U]),32);
    bufp->fullIData(oldp+445,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x67U]),32);
    bufp->fullIData(oldp+446,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x68U]),32);
    bufp->fullIData(oldp+447,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x69U]),32);
    bufp->fullIData(oldp+448,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6aU]),32);
    bufp->fullIData(oldp+449,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6bU]),32);
    bufp->fullIData(oldp+450,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6cU]),32);
    bufp->fullIData(oldp+451,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6dU]),32);
    bufp->fullIData(oldp+452,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6eU]),32);
    bufp->fullIData(oldp+453,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6fU]),32);
    bufp->fullIData(oldp+454,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x70U]),32);
    bufp->fullIData(oldp+455,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x71U]),32);
    bufp->fullIData(oldp+456,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x72U]),32);
    bufp->fullIData(oldp+457,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x73U]),32);
    bufp->fullIData(oldp+458,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x74U]),32);
    bufp->fullIData(oldp+459,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x75U]),32);
    bufp->fullIData(oldp+460,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x76U]),32);
    bufp->fullIData(oldp+461,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x77U]),32);
    bufp->fullIData(oldp+462,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x78U]),32);
    bufp->fullIData(oldp+463,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x79U]),32);
    bufp->fullIData(oldp+464,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7aU]),32);
    bufp->fullIData(oldp+465,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7bU]),32);
    bufp->fullIData(oldp+466,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7cU]),32);
    bufp->fullIData(oldp+467,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7dU]),32);
    bufp->fullIData(oldp+468,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7eU]),32);
    bufp->fullIData(oldp+469,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7fU]),32);
    bufp->fullCData(oldp+470,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q),7);
    bufp->fullIData(oldp+471,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk10__DOT__i),32);
    bufp->fullIData(oldp+472,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk10__DOT__unnamedblk11__DOT__j),32);
    bufp->fullIData(oldp+473,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i),32);
    bufp->fullIData(oldp+474,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk6__DOT__i),32);
    bufp->fullIData(oldp+475,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk6__DOT__unnamedblk7__DOT__j),32);
    bufp->fullIData(oldp+476,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk8__DOT__i),32);
    bufp->fullIData(oldp+477,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk8__DOT__unnamedblk9__DOT__j),32);
    bufp->fullBit(oldp+478,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_start__q));
    bufp->fullBit(oldp+479,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_mcu_using_sram__q));
    bufp->fullBit(oldp+480,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_loaded_flag__q));
    bufp->fullBit(oldp+481,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q));
    bufp->fullBit(oldp+482,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q));
    bufp->fullBit(oldp+483,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q));
    bufp->fullBit(oldp+484,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q));
    bufp->fullBit(oldp+485,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q));
    bufp->fullBit(oldp+486,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q));
    bufp->fullBit(oldp+487,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_loaded_flag__DOT__qe));
    bufp->fullBit(oldp+488,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_mcu_using_sram__DOT__qe));
    bufp->fullBit(oldp+489,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_start__DOT__qe));
    bufp->fullBit(oldp+490,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_accelerator_using_sram__DOT__qe));
    bufp->fullBit(oldp+491,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_data_number_sram__DOT__qe));
    bufp->fullBit(oldp+492,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done__DOT__qe));
    bufp->fullBit(oldp+493,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done_calculation__DOT__qe));
    bufp->fullBit(oldp+494,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done_filter__DOT__qe));
    bufp->fullBit(oldp+495,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_filter_number_sram__DOT__qe));
    bufp->fullBit(oldp+496,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_number_din__DOT__qe));
    bufp->fullBit(oldp+497,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_number_weights__DOT__qe));
    bufp->fullBit(oldp+498,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_tower_din__DOT__qe));
    bufp->fullBit(oldp+499,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_reload_flag__DOT__qe));
    bufp->fullBit(oldp+500,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_running__DOT__qe));
    bufp->fullBit(oldp+501,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_din_address__DOT__qe));
    bufp->fullBit(oldp+502,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_dout_address__DOT__qe));
    bufp->fullBit(oldp+503,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_weight_address__DOT__qe));
    bufp->fullBit(oldp+504,(vlSelfRef.clk_i));
    bufp->fullBit(oldp+505,(vlSelfRef.rst_ni));
    bufp->fullBit(oldp+506,(vlSelfRef.obi_req_i));
    bufp->fullBit(oldp+507,(vlSelfRef.obi_we_i));
    bufp->fullCData(oldp+508,(vlSelfRef.obi_be_i),4);
    bufp->fullIData(oldp+509,(vlSelfRef.obi_addr_i),32);
    bufp->fullIData(oldp+510,(vlSelfRef.obi_wdata_i),32);
    bufp->fullBit(oldp+511,(vlSelfRef.obi_gnt_o));
    bufp->fullBit(oldp+512,(vlSelfRef.obi_rvalid_o));
    bufp->fullIData(oldp+513,(vlSelfRef.obi_rdata_o),32);
    bufp->fullBit(oldp+514,(vlSelfRef.reg_valid_i));
    bufp->fullBit(oldp+515,(vlSelfRef.reg_write_i));
    bufp->fullCData(oldp+516,(vlSelfRef.reg_wstrb_i),4);
    bufp->fullIData(oldp+517,(vlSelfRef.reg_addr_i),32);
    bufp->fullIData(oldp+518,(vlSelfRef.reg_wdata_i),32);
    bufp->fullBit(oldp+519,(vlSelfRef.reg_error_o));
    bufp->fullBit(oldp+520,(vlSelfRef.reg_ready_o));
    bufp->fullIData(oldp+521,(vlSelfRef.reg_rdata_o),32);
    bufp->fullBit(oldp+522,(vlSelfRef.done_int_o));
    bufp->fullBit(oldp+523,((1U & (~ (IData)(vlSelfRef.rst_ni)))));
    bufp->fullCData(oldp+524,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                    ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                             ? 0U : 
                                            ((3U == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                              ? 5U : 4U)))
                                : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                        ? 4U : ((0U 
                                                 == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q))
                                                 ? 3U
                                                 : 4U))
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                        ? ((0U == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                            ? 2U : 1U)
                                        : ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc)
                                            ? 1U : 0U))))),3);
    bufp->fullBit(oldp+525,(((~ (IData)(vlSelfRef.reg_write_i)) 
                             & (IData)(vlSelfRef.reg_valid_i))));
    bufp->fullCData(oldp+526,((0xfU & vlSelfRef.reg_addr_i)),4);
    bufp->fullBit(oldp+527,(((~ (IData)((0U != (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0)))) 
                             & (((~ (IData)(vlSelfRef.reg_write_i)) 
                                 & (IData)(vlSelfRef.reg_valid_i)) 
                                | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_we)))));
    bufp->fullBit(oldp+528,((1U & vlSelfRef.reg_wdata_i)));
    bufp->fullBit(oldp+529,((1U & (vlSelfRef.reg_wdata_i 
                                   >> 1U))));
    bufp->fullBit(oldp+530,((1U & (vlSelfRef.reg_wdata_i 
                                   >> 2U))));
    bufp->fullBit(oldp+531,((1U & (vlSelfRef.reg_wdata_i 
                                   >> 3U))));
    bufp->fullBit(oldp+532,((1U & (vlSelfRef.reg_wdata_i 
                                   >> 4U))));
    bufp->fullBit(oldp+533,((1U & (vlSelfRef.reg_wdata_i 
                                   >> 5U))));
    bufp->fullCData(oldp+534,((7U & (vlSelfRef.reg_wdata_i 
                                     >> 8U))),3);
    bufp->fullCData(oldp+535,((7U & (vlSelfRef.reg_wdata_i 
                                     >> 0xbU))),3);
    bufp->fullCData(oldp+536,((3U & (vlSelfRef.reg_wdata_i 
                                     >> 0xeU))),2);
    bufp->fullCData(oldp+537,((3U & (vlSelfRef.reg_wdata_i 
                                     >> 0x10U))),2);
    bufp->fullCData(oldp+538,((0x1fU & (vlSelfRef.reg_wdata_i 
                                        >> 0x12U))),5);
    bufp->fullCData(oldp+539,((0xffU & vlSelfRef.reg_wdata_i)),8);
    bufp->fullCData(oldp+540,((0xffU & (vlSelfRef.reg_wdata_i 
                                        >> 8U))),8);
    bufp->fullCData(oldp+541,((0xffU & (vlSelfRef.reg_wdata_i 
                                        >> 0x10U))),8);
    bufp->fullBit(oldp+542,((1U & VL_REDXOR_32(vlSelfRef.reg_wdata_i))));
    bufp->fullBit(oldp+543,((1U & VL_REDXOR_4(vlSelfRef.reg_wstrb_i))));
    bufp->fullBit(oldp+544,(((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                             & (vlSelfRef.reg_wdata_i 
                                >> 2U))));
    bufp->fullBit(oldp+545,(((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                             & (vlSelfRef.reg_wdata_i 
                                >> 1U))));
    bufp->fullBit(oldp+546,(((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                             & vlSelfRef.reg_wdata_i)));
    bufp->fullBit(oldp+547,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                    ? (vlSelfRef.reg_wdata_i 
                                       >> 2U) : (IData)(
                                                        (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                         >> 0x36U))))));
    bufp->fullCData(oldp+548,((7U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                      ? (vlSelfRef.reg_wdata_i 
                                         >> 0xbU) : (IData)(
                                                            (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                             >> 0x28U))))),3);
    bufp->fullBit(oldp+549,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                    ? (vlSelfRef.reg_wdata_i 
                                       >> 1U) : (IData)(
                                                        (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                         >> 0x38U))))));
    bufp->fullBit(oldp+550,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                    ? (vlSelfRef.reg_wdata_i 
                                       >> 4U) : (IData)(
                                                        (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                         >> 0x32U))))));
    bufp->fullBit(oldp+551,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                    ? (vlSelfRef.reg_wdata_i 
                                       >> 5U) : (IData)(
                                                        (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                         >> 0x30U))))));
    bufp->fullCData(oldp+552,((7U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                      ? (vlSelfRef.reg_wdata_i 
                                         >> 8U) : (IData)(
                                                          (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                           >> 0x2cU))))),3);
    bufp->fullCData(oldp+553,((3U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                      ? (vlSelfRef.reg_wdata_i 
                                         >> 0xeU) : (IData)(
                                                            (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                             >> 0x25U))))),2);
    bufp->fullCData(oldp+554,((3U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                      ? (vlSelfRef.reg_wdata_i 
                                         >> 0x10U) : (IData)(
                                                             (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                              >> 0x22U))))),2);
    bufp->fullCData(oldp+555,((0x1fU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                         ? (vlSelfRef.reg_wdata_i 
                                            >> 0x12U)
                                         : (IData)(
                                                   (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                    >> 0x1cU))))),5);
    bufp->fullBit(oldp+556,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                    ? (vlSelfRef.reg_wdata_i 
                                       >> 3U) : (IData)(
                                                        (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                         >> 0x34U))))));
    bufp->fullBit(oldp+557,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                    ? vlSelfRef.reg_wdata_i
                                    : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x3aU))))));
    bufp->fullCData(oldp+558,((0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                                         ? vlSelfRef.reg_wdata_i
                                         : (IData)(
                                                   (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                    >> 0x13U))))),8);
    bufp->fullCData(oldp+559,((0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                                         ? (vlSelfRef.reg_wdata_i 
                                            >> 8U) : (IData)(
                                                             (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                              >> 0xaU))))),8);
    bufp->fullCData(oldp+560,((0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                                         ? (vlSelfRef.reg_wdata_i 
                                            >> 0x10U)
                                         : (IData)(
                                                   (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                    >> 1U))))),8);
}
