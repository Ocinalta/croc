// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vconv1d_tb_wrapper__Syms.h"


void Vconv1d_tb_wrapper___024root__trace_chg_0_sub_0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vconv1d_tb_wrapper___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_chg_0\n"); );
    // Init
    Vconv1d_tb_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vconv1d_tb_wrapper___024root*>(voidSelf);
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vconv1d_tb_wrapper___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vconv1d_tb_wrapper___024root__trace_chg_0_sub_0(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_chg_0_sub_0\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0U]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[1U]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[2U]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[3U]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[4U]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[5U]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[6U]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[7U]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[8U]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[9U]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xaU]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xbU]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xcU]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xdU]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xeU]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0xfU]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x10U]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x11U]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x12U]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x13U]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x14U]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x15U]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x16U]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x17U]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x18U]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x19U]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1aU]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1bU]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1cU]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1dU]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1eU]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x1fU]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x20U]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x21U]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x22U]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x23U]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x24U]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x25U]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x26U]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x27U]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x28U]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x29U]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2aU]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2bU]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2cU]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2dU]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2eU]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x2fU]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x30U]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x31U]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x32U]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x33U]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x34U]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x35U]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x36U]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x37U]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x38U]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x39U]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3aU]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3bU]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3cU]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3dU]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3eU]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x3fU]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x40U]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x41U]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x42U]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x43U]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x44U]),32);
        bufp->chgIData(oldp+69,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x45U]),32);
        bufp->chgIData(oldp+70,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x46U]),32);
        bufp->chgIData(oldp+71,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x47U]),32);
        bufp->chgIData(oldp+72,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x48U]),32);
        bufp->chgIData(oldp+73,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x49U]),32);
        bufp->chgIData(oldp+74,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4aU]),32);
        bufp->chgIData(oldp+75,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4bU]),32);
        bufp->chgIData(oldp+76,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4cU]),32);
        bufp->chgIData(oldp+77,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4dU]),32);
        bufp->chgIData(oldp+78,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4eU]),32);
        bufp->chgIData(oldp+79,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x4fU]),32);
        bufp->chgIData(oldp+80,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x50U]),32);
        bufp->chgIData(oldp+81,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x51U]),32);
        bufp->chgIData(oldp+82,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x52U]),32);
        bufp->chgIData(oldp+83,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x53U]),32);
        bufp->chgIData(oldp+84,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x54U]),32);
        bufp->chgIData(oldp+85,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x55U]),32);
        bufp->chgIData(oldp+86,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x56U]),32);
        bufp->chgIData(oldp+87,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x57U]),32);
        bufp->chgIData(oldp+88,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x58U]),32);
        bufp->chgIData(oldp+89,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x59U]),32);
        bufp->chgIData(oldp+90,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5aU]),32);
        bufp->chgIData(oldp+91,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5bU]),32);
        bufp->chgIData(oldp+92,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5cU]),32);
        bufp->chgIData(oldp+93,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5dU]),32);
        bufp->chgIData(oldp+94,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5eU]),32);
        bufp->chgIData(oldp+95,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x5fU]),32);
        bufp->chgIData(oldp+96,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x60U]),32);
        bufp->chgIData(oldp+97,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x61U]),32);
        bufp->chgIData(oldp+98,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x62U]),32);
        bufp->chgIData(oldp+99,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x63U]),32);
        bufp->chgIData(oldp+100,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x64U]),32);
        bufp->chgIData(oldp+101,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x65U]),32);
        bufp->chgIData(oldp+102,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x66U]),32);
        bufp->chgIData(oldp+103,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x67U]),32);
        bufp->chgIData(oldp+104,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x68U]),32);
        bufp->chgIData(oldp+105,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x69U]),32);
        bufp->chgIData(oldp+106,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6aU]),32);
        bufp->chgIData(oldp+107,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6bU]),32);
        bufp->chgIData(oldp+108,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6cU]),32);
        bufp->chgIData(oldp+109,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6dU]),32);
        bufp->chgIData(oldp+110,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6eU]),32);
        bufp->chgIData(oldp+111,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x6fU]),32);
        bufp->chgIData(oldp+112,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x70U]),32);
        bufp->chgIData(oldp+113,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x71U]),32);
        bufp->chgIData(oldp+114,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x72U]),32);
        bufp->chgIData(oldp+115,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x73U]),32);
        bufp->chgIData(oldp+116,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x74U]),32);
        bufp->chgIData(oldp+117,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x75U]),32);
        bufp->chgIData(oldp+118,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x76U]),32);
        bufp->chgIData(oldp+119,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x77U]),32);
        bufp->chgIData(oldp+120,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x78U]),32);
        bufp->chgIData(oldp+121,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x79U]),32);
        bufp->chgIData(oldp+122,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7aU]),32);
        bufp->chgIData(oldp+123,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7bU]),32);
        bufp->chgIData(oldp+124,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7cU]),32);
        bufp->chgIData(oldp+125,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7dU]),32);
        bufp->chgIData(oldp+126,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7eU]),32);
        bufp->chgIData(oldp+127,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0x7fU]),32);
        bufp->chgIData(oldp+128,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__proc_sram_init__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+129,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__proc_sram_init__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+130,(((vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[2U] 
                                   << 0x16U) | (vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[1U] 
                                                >> 0xaU))),32);
        bufp->chgBit(oldp+131,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[1U] 
                                      >> 9U))));
        bufp->chgCData(oldp+132,((0xfU & (vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[1U] 
                                          >> 5U))),4);
        bufp->chgIData(oldp+133,(((vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[1U] 
                                   << 0x1bU) | (vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[0U] 
                                                >> 5U))),32);
        bufp->chgCData(oldp+134,((7U & (vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[0U] 
                                        >> 2U))),3);
        bufp->chgBit(oldp+135,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[0U] 
                                      >> 1U))));
        bufp->chgBit(oldp+136,((1U & vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[0U])));
        bufp->chgBit(oldp+137,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_we));
        bufp->chgBit(oldp+138,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we));
        bufp->chgBit(oldp+139,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
        bufp->chgBit(oldp+140,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we));
        bufp->chgCData(oldp+141,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0),3);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [3U])))) {
        bufp->chgIData(oldp+142,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next),32);
        bufp->chgBit(oldp+143,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
                                      >> 5U))));
        bufp->chgBit(oldp+144,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
                                      >> 4U))));
        bufp->chgCData(oldp+145,((0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])),4);
        bufp->chgIData(oldp+146,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]),32);
        bufp->chgIData(oldp+147,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U]),32);
        bufp->chgCData(oldp+148,((0x7fU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U])),7);
        bufp->chgIData(oldp+149,(((IData)((0x20U == 
                                           (0x30U & 
                                            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])))
                                   ? (((0U == (0x1fU 
                                               & VL_SHIFTL_III(12,32,32, 
                                                               (0x7fU 
                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))
                                        ? 0U : (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                                                (((IData)(0x1fU) 
                                                  + 
                                                  (0xfffU 
                                                   & VL_SHIFTL_III(12,32,32, 
                                                                   (0x7fU 
                                                                    & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))) 
                                                 >> 5U)] 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(12,32,32, 
                                                                  (0x7fU 
                                                                   & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                                      | (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                                         (0x7fU & (
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U) 
                                                   >> 5U))] 
                                         >> (0x1fU 
                                             & VL_SHIFTL_III(12,32,32, 
                                                             (0x7fU 
                                                              & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))
                                   : (((0U == (0x1fU 
                                               & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U)))
                                        ? 0U : (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                                                (((IData)(0x1fU) 
                                                  + 
                                                  (0xfffU 
                                                   & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U))) 
                                                 >> 5U)] 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U))))) 
                                      | (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                                         (0x7fU & (
                                                   VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U) 
                                                   >> 5U))] 
                                         >> (0x1fU 
                                             & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U)))))),32);
        bufp->chgBit(oldp+150,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x35U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+151,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x27U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+152,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x37U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+153,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x31U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+154,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x2fU)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+155,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x2bU)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+156,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x24U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+157,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x21U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+158,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x1bU)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+159,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x33U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+160,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x39U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))));
        bufp->chgBit(oldp+161,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x12U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))));
        bufp->chgBit(oldp+162,((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 9U)) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))));
        bufp->chgBit(oldp+163,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                                      | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+164,((0U == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))));
        bufp->chgBit(oldp+165,((3U == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))));
        bufp->chgIData(oldp+166,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out),32);
        bufp->chgIData(oldp+167,((((- (IData)((1U & 
                                               ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product) 
                                                >> 0xfU)))) 
                                   << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product))),32);
        bufp->chgIData(oldp+168,((((- (IData)((1U & 
                                               ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product) 
                                                >> 0xfU)))) 
                                   << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product))),32);
        bufp->chgIData(oldp+169,((((- (IData)((1U & 
                                               ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product) 
                                                >> 0xfU)))) 
                                   << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product))),32);
        bufp->chgIData(oldp+170,((((- (IData)((1U & 
                                               ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product) 
                                                >> 0xfU)))) 
                                   << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product))),32);
        bufp->chgCData(oldp+171,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in),3);
        bufp->chgCData(oldp+172,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin),2);
        bufp->chgIData(oldp+173,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator1),32);
        bufp->chgIData(oldp+174,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator2),32);
        bufp->chgIData(oldp+175,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator3),32);
        bufp->chgIData(oldp+176,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator4),32);
        bufp->chgBit(oldp+177,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in) 
                                      >> 2U))));
        bufp->chgIData(oldp+178,(((((- (IData)((1U 
                                                & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product) 
                                                   >> 0xfU)))) 
                                    << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product)) 
                                  + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                      ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out))),32);
        bufp->chgIData(oldp+179,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out),32);
        bufp->chgIData(oldp+180,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out)),32);
        bufp->chgIData(oldp+181,(((((- (IData)((1U 
                                                & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product) 
                                                   >> 0xfU)))) 
                                    << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product)) 
                                  + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                      ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out))),32);
        bufp->chgIData(oldp+182,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out),32);
        bufp->chgIData(oldp+183,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out)),32);
        bufp->chgIData(oldp+184,(((((- (IData)((1U 
                                                & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product) 
                                                   >> 0xfU)))) 
                                    << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product)) 
                                  + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                      ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out))),32);
        bufp->chgIData(oldp+185,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out),32);
        bufp->chgIData(oldp+186,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out)),32);
        bufp->chgIData(oldp+187,(((((- (IData)((1U 
                                                & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product) 
                                                   >> 0xfU)))) 
                                    << 0x10U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product)) 
                                  + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                      ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out))),32);
        bufp->chgIData(oldp+188,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out),32);
        bufp->chgIData(oldp+189,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out)),32);
        bufp->chgCData(oldp+190,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data0_out),8);
        bufp->chgCData(oldp+191,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data1_out),8);
        bufp->chgCData(oldp+192,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data2_out),8);
        bufp->chgCData(oldp+193,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data3_out),8);
        bufp->chgCData(oldp+194,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data4_out),8);
        bufp->chgCData(oldp+195,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight0_out),8);
        bufp->chgCData(oldp+196,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight1_out),8);
        bufp->chgCData(oldp+197,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight2_out),8);
        bufp->chgCData(oldp+198,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight3_out),8);
        bufp->chgCData(oldp+199,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight4_out),8);
        bufp->chgCData(oldp+200,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                ? 0U
                                                : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data0_out)))
                                   : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data1_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data2_out))
                                       : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data3_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data4_out))))),8);
        bufp->chgCData(oldp+201,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                ? 0U
                                                : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight0_out)))
                                   : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight1_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight2_out))
                                       : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight3_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight4_out))))),8);
        bufp->chgSData(oldp+202,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product),16);
        bufp->chgCData(oldp+203,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data0_out),8);
        bufp->chgCData(oldp+204,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data1_out),8);
        bufp->chgCData(oldp+205,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data2_out),8);
        bufp->chgCData(oldp+206,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data3_out),8);
        bufp->chgCData(oldp+207,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data4_out),8);
        bufp->chgCData(oldp+208,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight0_out),8);
        bufp->chgCData(oldp+209,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight1_out),8);
        bufp->chgCData(oldp+210,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight2_out),8);
        bufp->chgCData(oldp+211,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight3_out),8);
        bufp->chgCData(oldp+212,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight4_out),8);
        bufp->chgCData(oldp+213,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                ? 0U
                                                : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data0_out)))
                                   : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data1_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data2_out))
                                       : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data3_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data4_out))))),8);
        bufp->chgCData(oldp+214,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                ? 0U
                                                : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight0_out)))
                                   : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight1_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight2_out))
                                       : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight3_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight4_out))))),8);
        bufp->chgSData(oldp+215,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product),16);
        bufp->chgCData(oldp+216,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data0_out),8);
        bufp->chgCData(oldp+217,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data1_out),8);
        bufp->chgCData(oldp+218,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data2_out),8);
        bufp->chgCData(oldp+219,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data3_out),8);
        bufp->chgCData(oldp+220,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data4_out),8);
        bufp->chgCData(oldp+221,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight0_out),8);
        bufp->chgCData(oldp+222,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight1_out),8);
        bufp->chgCData(oldp+223,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight2_out),8);
        bufp->chgCData(oldp+224,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight3_out),8);
        bufp->chgCData(oldp+225,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight4_out),8);
        bufp->chgCData(oldp+226,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                ? 0U
                                                : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data0_out)))
                                   : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data1_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data2_out))
                                       : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data3_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data4_out))))),8);
        bufp->chgCData(oldp+227,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                ? 0U
                                                : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight0_out)))
                                   : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight1_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight2_out))
                                       : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight3_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight4_out))))),8);
        bufp->chgSData(oldp+228,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product),16);
        bufp->chgCData(oldp+229,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data0_out),8);
        bufp->chgCData(oldp+230,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data1_out),8);
        bufp->chgCData(oldp+231,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data2_out),8);
        bufp->chgCData(oldp+232,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data3_out),8);
        bufp->chgCData(oldp+233,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data4_out),8);
        bufp->chgCData(oldp+234,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight0_out),8);
        bufp->chgCData(oldp+235,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight1_out),8);
        bufp->chgCData(oldp+236,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight2_out),8);
        bufp->chgCData(oldp+237,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight3_out),8);
        bufp->chgCData(oldp+238,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight4_out),8);
        bufp->chgCData(oldp+239,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                ? 0U
                                                : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data0_out)))
                                   : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data1_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data2_out))
                                       : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data3_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data4_out))))),8);
        bufp->chgCData(oldp+240,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                   ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? 0U : ((1U 
                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                ? 0U
                                                : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight0_out)))
                                   : ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                       ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight1_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight2_out))
                                       : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                           ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight3_out)
                                           : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight4_out))))),8);
        bufp->chgSData(oldp+241,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product),16);
        bufp->chgIData(oldp+242,(((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                   ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                       ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator4
                                       : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator3)
                                   : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                       ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator2
                                       : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator1))),32);
        bufp->chgIData(oldp+243,((((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                    ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                        ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator4
                                        : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator3)
                                    : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                        ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator2
                                        : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator1)) 
                                  + vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out)),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+244,((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__obi_rsp 
                                          >> 7U))),32);
        bufp->chgCData(oldp+245,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__obi_rsp 
                                                >> 4U)))),3);
        bufp->chgBit(oldp+246,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__obi_rsp 
                                              >> 3U)))));
        bufp->chgBit(oldp+247,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__obi_rsp 
                                              >> 2U)))));
        bufp->chgBit(oldp+248,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__obi_rsp 
                                              >> 1U)))));
        bufp->chgBit(oldp+249,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__obi_rsp))));
        bufp->chgBit(oldp+250,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x2fU)))));
        bufp->chgBit(oldp+251,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x2eU)))));
        bufp->chgBit(oldp+252,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x2dU)))));
        bufp->chgBit(oldp+253,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x2cU)))));
        bufp->chgBit(oldp+254,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x2bU)))));
        bufp->chgBit(oldp+255,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x2aU)))));
        bufp->chgBit(oldp+256,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x29U)))));
        bufp->chgBit(oldp+257,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x28U)))));
        bufp->chgBit(oldp+258,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                              >> 0x27U)))));
        bufp->chgCData(oldp+259,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                >> 0x24U)))),3);
        bufp->chgCData(oldp+260,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                >> 0x21U)))),3);
        bufp->chgCData(oldp+261,((3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                >> 0x1fU)))),2);
        bufp->chgCData(oldp+262,((3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                >> 0x1dU)))),2);
        bufp->chgCData(oldp+263,((0x1fU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                   >> 0x18U)))),5);
        bufp->chgCData(oldp+264,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                   >> 0x10U)))),8);
        bufp->chgCData(oldp+265,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                   >> 8U)))),8);
        bufp->chgCData(oldp+266,((0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw))),8);
        bufp->chgBit(oldp+267,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x3aU)))));
        bufp->chgBit(oldp+268,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x39U)))));
        bufp->chgBit(oldp+269,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x38U)))));
        bufp->chgBit(oldp+270,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x37U)))));
        bufp->chgBit(oldp+271,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x36U)))));
        bufp->chgBit(oldp+272,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x35U)))));
        bufp->chgBit(oldp+273,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x34U)))));
        bufp->chgBit(oldp+274,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x33U)))));
        bufp->chgBit(oldp+275,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x32U)))));
        bufp->chgBit(oldp+276,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x31U)))));
        bufp->chgBit(oldp+277,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x30U)))));
        bufp->chgBit(oldp+278,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x2fU)))));
        bufp->chgCData(oldp+279,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                >> 0x2cU)))),3);
        bufp->chgBit(oldp+280,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x2bU)))));
        bufp->chgCData(oldp+281,((7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                >> 0x28U)))),3);
        bufp->chgBit(oldp+282,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x27U)))));
        bufp->chgCData(oldp+283,((3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                >> 0x25U)))),2);
        bufp->chgBit(oldp+284,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x24U)))));
        bufp->chgCData(oldp+285,((3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                >> 0x22U)))),2);
        bufp->chgBit(oldp+286,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x21U)))));
        bufp->chgCData(oldp+287,((0x1fU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                   >> 0x1cU)))),5);
        bufp->chgBit(oldp+288,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x1bU)))));
        bufp->chgCData(oldp+289,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                   >> 0x13U)))),8);
        bufp->chgBit(oldp+290,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x12U)))));
        bufp->chgCData(oldp+291,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                   >> 0xaU)))),8);
        bufp->chgBit(oldp+292,((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 9U)))));
        bufp->chgCData(oldp+293,((0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                   >> 1U)))),8);
        bufp->chgBit(oldp+294,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg))));
        bufp->chgBit(oldp+295,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                                      >> 5U))));
        bufp->chgBit(oldp+296,((1U & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                                      >> 4U))));
        bufp->chgCData(oldp+297,((0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U])),4);
        bufp->chgIData(oldp+298,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]),32);
        bufp->chgIData(oldp+299,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[0U]),32);
        bufp->chgIData(oldp+300,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q),32);
        bufp->chgBit(oldp+301,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt));
        bufp->chgBit(oldp+302,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc));
        bufp->chgBit(oldp+303,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_cnt_fin));
        bufp->chgBit(oldp+304,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_cnt_branch));
        bufp->chgBit(oldp+305,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__en_cnt_fin));
        bufp->chgBit(oldp+306,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__en_cnt_branch));
        bufp->chgBit(oldp+307,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_tmp));
        bufp->chgBit(oldp+308,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_branch));
        bufp->chgBit(oldp+309,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_partial));
        bufp->chgBit(oldp+310,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_partial));
        bufp->chgBit(oldp+311,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__done_qalc));
        bufp->chgCData(oldp+312,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight),5);
        bufp->chgCData(oldp+313,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din),5);
        bufp->chgCData(oldp+314,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din),5);
        bufp->chgCData(oldp+315,((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                                  >> 0x18U)),8);
        bufp->chgCData(oldp+316,((0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                                           >> 0x10U))),8);
        bufp->chgCData(oldp+317,((0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                                           >> 8U))),8);
        bufp->chgCData(oldp+318,((0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q)),8);
        bufp->chgBit(oldp+319,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))));
        bufp->chgBit(oldp+320,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din))));
        bufp->chgBit(oldp+321,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din) 
                                      >> 1U))));
        bufp->chgBit(oldp+322,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din) 
                                      >> 1U))));
        bufp->chgBit(oldp+323,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din) 
                                      >> 2U))));
        bufp->chgBit(oldp+324,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din) 
                                      >> 2U))));
        bufp->chgBit(oldp+325,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din) 
                                      >> 3U))));
        bufp->chgBit(oldp+326,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din) 
                                      >> 3U))));
        bufp->chgBit(oldp+327,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din) 
                                      >> 4U))));
        bufp->chgBit(oldp+328,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din) 
                                      >> 4U))));
        bufp->chgBit(oldp+329,((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight))));
        bufp->chgBit(oldp+330,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight) 
                                      >> 1U))));
        bufp->chgBit(oldp+331,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight) 
                                      >> 2U))));
        bufp->chgBit(oldp+332,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight) 
                                      >> 3U))));
        bufp->chgBit(oldp+333,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight) 
                                      >> 4U))));
        bufp->chgBit(oldp+334,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q));
        bufp->chgBit(oldp+335,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q));
        bufp->chgBit(oldp+336,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q));
        bufp->chgBit(oldp+337,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q));
        bufp->chgBit(oldp+338,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q));
        bufp->chgBit(oldp+339,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q));
        bufp->chgCData(oldp+340,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_filter_number_sram__q),3);
        bufp->chgCData(oldp+341,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_data_number_sram__q),3);
        bufp->chgCData(oldp+342,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q),2);
        bufp->chgCData(oldp+343,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_weights__q),2);
        bufp->chgCData(oldp+344,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_tower_din__q),5);
        bufp->chgCData(oldp+345,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_din_address__q),8);
        bufp->chgCData(oldp+346,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_dout_address__q),8);
        bufp->chgCData(oldp+347,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_weight_address__q),8);
        bufp->chgCData(oldp+348,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state),3);
        bufp->chgCData(oldp+349,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state),5);
        bufp->chgCData(oldp+350,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state),5);
        bufp->chgIData(oldp+351,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0U]),32);
        bufp->chgIData(oldp+352,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[1U]),32);
        bufp->chgIData(oldp+353,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[2U]),32);
        bufp->chgIData(oldp+354,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[3U]),32);
        bufp->chgIData(oldp+355,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[4U]),32);
        bufp->chgIData(oldp+356,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[5U]),32);
        bufp->chgIData(oldp+357,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[6U]),32);
        bufp->chgIData(oldp+358,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[7U]),32);
        bufp->chgIData(oldp+359,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[8U]),32);
        bufp->chgIData(oldp+360,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[9U]),32);
        bufp->chgIData(oldp+361,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xaU]),32);
        bufp->chgIData(oldp+362,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xbU]),32);
        bufp->chgIData(oldp+363,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xcU]),32);
        bufp->chgIData(oldp+364,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xdU]),32);
        bufp->chgIData(oldp+365,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xeU]),32);
        bufp->chgIData(oldp+366,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0xfU]),32);
        bufp->chgIData(oldp+367,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x10U]),32);
        bufp->chgIData(oldp+368,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x11U]),32);
        bufp->chgIData(oldp+369,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x12U]),32);
        bufp->chgIData(oldp+370,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x13U]),32);
        bufp->chgIData(oldp+371,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x14U]),32);
        bufp->chgIData(oldp+372,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x15U]),32);
        bufp->chgIData(oldp+373,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x16U]),32);
        bufp->chgIData(oldp+374,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x17U]),32);
        bufp->chgIData(oldp+375,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x18U]),32);
        bufp->chgIData(oldp+376,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x19U]),32);
        bufp->chgIData(oldp+377,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1aU]),32);
        bufp->chgIData(oldp+378,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1bU]),32);
        bufp->chgIData(oldp+379,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1cU]),32);
        bufp->chgIData(oldp+380,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1dU]),32);
        bufp->chgIData(oldp+381,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1eU]),32);
        bufp->chgIData(oldp+382,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x1fU]),32);
        bufp->chgIData(oldp+383,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x20U]),32);
        bufp->chgIData(oldp+384,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x21U]),32);
        bufp->chgIData(oldp+385,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x22U]),32);
        bufp->chgIData(oldp+386,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x23U]),32);
        bufp->chgIData(oldp+387,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x24U]),32);
        bufp->chgIData(oldp+388,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x25U]),32);
        bufp->chgIData(oldp+389,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x26U]),32);
        bufp->chgIData(oldp+390,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x27U]),32);
        bufp->chgIData(oldp+391,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x28U]),32);
        bufp->chgIData(oldp+392,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x29U]),32);
        bufp->chgIData(oldp+393,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2aU]),32);
        bufp->chgIData(oldp+394,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2bU]),32);
        bufp->chgIData(oldp+395,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2cU]),32);
        bufp->chgIData(oldp+396,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2dU]),32);
        bufp->chgIData(oldp+397,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2eU]),32);
        bufp->chgIData(oldp+398,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x2fU]),32);
        bufp->chgIData(oldp+399,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x30U]),32);
        bufp->chgIData(oldp+400,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x31U]),32);
        bufp->chgIData(oldp+401,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x32U]),32);
        bufp->chgIData(oldp+402,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x33U]),32);
        bufp->chgIData(oldp+403,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x34U]),32);
        bufp->chgIData(oldp+404,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x35U]),32);
        bufp->chgIData(oldp+405,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x36U]),32);
        bufp->chgIData(oldp+406,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x37U]),32);
        bufp->chgIData(oldp+407,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x38U]),32);
        bufp->chgIData(oldp+408,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x39U]),32);
        bufp->chgIData(oldp+409,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3aU]),32);
        bufp->chgIData(oldp+410,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3bU]),32);
        bufp->chgIData(oldp+411,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3cU]),32);
        bufp->chgIData(oldp+412,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3dU]),32);
        bufp->chgIData(oldp+413,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3eU]),32);
        bufp->chgIData(oldp+414,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x3fU]),32);
        bufp->chgIData(oldp+415,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x40U]),32);
        bufp->chgIData(oldp+416,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x41U]),32);
        bufp->chgIData(oldp+417,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x42U]),32);
        bufp->chgIData(oldp+418,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x43U]),32);
        bufp->chgIData(oldp+419,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x44U]),32);
        bufp->chgIData(oldp+420,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x45U]),32);
        bufp->chgIData(oldp+421,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x46U]),32);
        bufp->chgIData(oldp+422,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x47U]),32);
        bufp->chgIData(oldp+423,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x48U]),32);
        bufp->chgIData(oldp+424,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x49U]),32);
        bufp->chgIData(oldp+425,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4aU]),32);
        bufp->chgIData(oldp+426,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4bU]),32);
        bufp->chgIData(oldp+427,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4cU]),32);
        bufp->chgIData(oldp+428,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4dU]),32);
        bufp->chgIData(oldp+429,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4eU]),32);
        bufp->chgIData(oldp+430,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x4fU]),32);
        bufp->chgIData(oldp+431,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x50U]),32);
        bufp->chgIData(oldp+432,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x51U]),32);
        bufp->chgIData(oldp+433,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x52U]),32);
        bufp->chgIData(oldp+434,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x53U]),32);
        bufp->chgIData(oldp+435,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x54U]),32);
        bufp->chgIData(oldp+436,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x55U]),32);
        bufp->chgIData(oldp+437,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x56U]),32);
        bufp->chgIData(oldp+438,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x57U]),32);
        bufp->chgIData(oldp+439,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x58U]),32);
        bufp->chgIData(oldp+440,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x59U]),32);
        bufp->chgIData(oldp+441,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5aU]),32);
        bufp->chgIData(oldp+442,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5bU]),32);
        bufp->chgIData(oldp+443,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5cU]),32);
        bufp->chgIData(oldp+444,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5dU]),32);
        bufp->chgIData(oldp+445,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5eU]),32);
        bufp->chgIData(oldp+446,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x5fU]),32);
        bufp->chgIData(oldp+447,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x60U]),32);
        bufp->chgIData(oldp+448,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x61U]),32);
        bufp->chgIData(oldp+449,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x62U]),32);
        bufp->chgIData(oldp+450,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x63U]),32);
        bufp->chgIData(oldp+451,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x64U]),32);
        bufp->chgIData(oldp+452,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x65U]),32);
        bufp->chgIData(oldp+453,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x66U]),32);
        bufp->chgIData(oldp+454,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x67U]),32);
        bufp->chgIData(oldp+455,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x68U]),32);
        bufp->chgIData(oldp+456,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x69U]),32);
        bufp->chgIData(oldp+457,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6aU]),32);
        bufp->chgIData(oldp+458,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6bU]),32);
        bufp->chgIData(oldp+459,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6cU]),32);
        bufp->chgIData(oldp+460,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6dU]),32);
        bufp->chgIData(oldp+461,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6eU]),32);
        bufp->chgIData(oldp+462,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x6fU]),32);
        bufp->chgIData(oldp+463,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x70U]),32);
        bufp->chgIData(oldp+464,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x71U]),32);
        bufp->chgIData(oldp+465,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x72U]),32);
        bufp->chgIData(oldp+466,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x73U]),32);
        bufp->chgIData(oldp+467,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x74U]),32);
        bufp->chgIData(oldp+468,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x75U]),32);
        bufp->chgIData(oldp+469,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x76U]),32);
        bufp->chgIData(oldp+470,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x77U]),32);
        bufp->chgIData(oldp+471,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x78U]),32);
        bufp->chgIData(oldp+472,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x79U]),32);
        bufp->chgIData(oldp+473,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7aU]),32);
        bufp->chgIData(oldp+474,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7bU]),32);
        bufp->chgIData(oldp+475,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7cU]),32);
        bufp->chgIData(oldp+476,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7dU]),32);
        bufp->chgIData(oldp+477,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7eU]),32);
        bufp->chgIData(oldp+478,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[0x7fU]),32);
        bufp->chgCData(oldp+479,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q),7);
        bufp->chgIData(oldp+480,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk10__DOT__i),32);
        bufp->chgIData(oldp+481,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk10__DOT__unnamedblk11__DOT__j),32);
        bufp->chgIData(oldp+482,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i),32);
        bufp->chgIData(oldp+483,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk6__DOT__i),32);
        bufp->chgIData(oldp+484,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk6__DOT__unnamedblk7__DOT__j),32);
        bufp->chgIData(oldp+485,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk8__DOT__i),32);
        bufp->chgIData(oldp+486,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk8__DOT__unnamedblk9__DOT__j),32);
        bufp->chgBit(oldp+487,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__rvalid_q));
        bufp->chgCData(oldp+488,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__id_q),3);
        bufp->chgBit(oldp+489,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_start__q));
        bufp->chgBit(oldp+490,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_mcu_using_sram__q));
        bufp->chgBit(oldp+491,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_loaded_flag__q));
        bufp->chgBit(oldp+492,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q));
        bufp->chgBit(oldp+493,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q));
        bufp->chgBit(oldp+494,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q));
        bufp->chgBit(oldp+495,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q));
        bufp->chgBit(oldp+496,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q));
        bufp->chgBit(oldp+497,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q));
        bufp->chgBit(oldp+498,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_loaded_flag__DOT__qe));
        bufp->chgBit(oldp+499,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_mcu_using_sram__DOT__qe));
        bufp->chgBit(oldp+500,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_start__DOT__qe));
        bufp->chgBit(oldp+501,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_accelerator_using_sram__DOT__qe));
        bufp->chgBit(oldp+502,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_data_number_sram__DOT__qe));
        bufp->chgBit(oldp+503,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done__DOT__qe));
        bufp->chgBit(oldp+504,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done_calculation__DOT__qe));
        bufp->chgBit(oldp+505,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done_filter__DOT__qe));
        bufp->chgBit(oldp+506,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_filter_number_sram__DOT__qe));
        bufp->chgBit(oldp+507,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_number_din__DOT__qe));
        bufp->chgBit(oldp+508,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_number_weights__DOT__qe));
        bufp->chgBit(oldp+509,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_tower_din__DOT__qe));
        bufp->chgBit(oldp+510,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_reload_flag__DOT__qe));
        bufp->chgBit(oldp+511,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_running__DOT__qe));
        bufp->chgBit(oldp+512,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_din_address__DOT__qe));
        bufp->chgBit(oldp+513,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_dout_address__DOT__qe));
        bufp->chgBit(oldp+514,(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_weight_address__DOT__qe));
    }
    bufp->chgBit(oldp+515,(vlSelfRef.clk_i));
    bufp->chgBit(oldp+516,(vlSelfRef.rst_ni));
    bufp->chgBit(oldp+517,(vlSelfRef.obi_req_i));
    bufp->chgBit(oldp+518,(vlSelfRef.obi_we_i));
    bufp->chgCData(oldp+519,(vlSelfRef.obi_be_i),4);
    bufp->chgIData(oldp+520,(vlSelfRef.obi_addr_i),32);
    bufp->chgIData(oldp+521,(vlSelfRef.obi_wdata_i),32);
    bufp->chgBit(oldp+522,(vlSelfRef.obi_gnt_o));
    bufp->chgBit(oldp+523,(vlSelfRef.obi_rvalid_o));
    bufp->chgIData(oldp+524,(vlSelfRef.obi_rdata_o),32);
    bufp->chgBit(oldp+525,(vlSelfRef.reg_valid_i));
    bufp->chgBit(oldp+526,(vlSelfRef.reg_write_i));
    bufp->chgCData(oldp+527,(vlSelfRef.reg_wstrb_i),4);
    bufp->chgIData(oldp+528,(vlSelfRef.reg_addr_i),32);
    bufp->chgIData(oldp+529,(vlSelfRef.reg_wdata_i),32);
    bufp->chgBit(oldp+530,(vlSelfRef.reg_error_o));
    bufp->chgBit(oldp+531,(vlSelfRef.reg_ready_o));
    bufp->chgIData(oldp+532,(vlSelfRef.reg_rdata_o),32);
    bufp->chgBit(oldp+533,(vlSelfRef.done_int_o));
    bufp->chgBit(oldp+534,((1U & (~ (IData)(vlSelfRef.rst_ni)))));
    bufp->chgCData(oldp+535,(((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
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
    bufp->chgBit(oldp+536,((vlSelfRef.conv1d_tb_wrapper__DOT__obi_req[0U] 
                            & (IData)(vlSelfRef.obi_gnt_o))));
    bufp->chgBit(oldp+537,(((~ (IData)(vlSelfRef.reg_write_i)) 
                            & (IData)(vlSelfRef.reg_valid_i))));
    bufp->chgCData(oldp+538,((0xfU & vlSelfRef.reg_addr_i)),4);
    bufp->chgBit(oldp+539,(((~ (IData)((0U != (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0)))) 
                            & (((~ (IData)(vlSelfRef.reg_write_i)) 
                                & (IData)(vlSelfRef.reg_valid_i)) 
                               | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_we)))));
    bufp->chgBit(oldp+540,((1U & vlSelfRef.reg_wdata_i)));
    bufp->chgBit(oldp+541,((1U & (vlSelfRef.reg_wdata_i 
                                  >> 1U))));
    bufp->chgBit(oldp+542,((1U & (vlSelfRef.reg_wdata_i 
                                  >> 2U))));
    bufp->chgBit(oldp+543,((1U & (vlSelfRef.reg_wdata_i 
                                  >> 3U))));
    bufp->chgBit(oldp+544,((1U & (vlSelfRef.reg_wdata_i 
                                  >> 4U))));
    bufp->chgBit(oldp+545,((1U & (vlSelfRef.reg_wdata_i 
                                  >> 5U))));
    bufp->chgCData(oldp+546,((7U & (vlSelfRef.reg_wdata_i 
                                    >> 8U))),3);
    bufp->chgCData(oldp+547,((7U & (vlSelfRef.reg_wdata_i 
                                    >> 0xbU))),3);
    bufp->chgCData(oldp+548,((3U & (vlSelfRef.reg_wdata_i 
                                    >> 0xeU))),2);
    bufp->chgCData(oldp+549,((3U & (vlSelfRef.reg_wdata_i 
                                    >> 0x10U))),2);
    bufp->chgCData(oldp+550,((0x1fU & (vlSelfRef.reg_wdata_i 
                                       >> 0x12U))),5);
    bufp->chgCData(oldp+551,((0xffU & vlSelfRef.reg_wdata_i)),8);
    bufp->chgCData(oldp+552,((0xffU & (vlSelfRef.reg_wdata_i 
                                       >> 8U))),8);
    bufp->chgCData(oldp+553,((0xffU & (vlSelfRef.reg_wdata_i 
                                       >> 0x10U))),8);
    bufp->chgBit(oldp+554,((1U & VL_REDXOR_32(vlSelfRef.reg_wdata_i))));
    bufp->chgBit(oldp+555,((1U & VL_REDXOR_4(vlSelfRef.reg_wstrb_i))));
    bufp->chgBit(oldp+556,(((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                            & (vlSelfRef.reg_wdata_i 
                               >> 2U))));
    bufp->chgBit(oldp+557,(((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                            & (vlSelfRef.reg_wdata_i 
                               >> 1U))));
    bufp->chgBit(oldp+558,(((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                            & vlSelfRef.reg_wdata_i)));
    bufp->chgBit(oldp+559,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                   ? (vlSelfRef.reg_wdata_i 
                                      >> 2U) : (IData)(
                                                       (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                        >> 0x36U))))));
    bufp->chgCData(oldp+560,((7U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                     ? (vlSelfRef.reg_wdata_i 
                                        >> 0xbU) : (IData)(
                                                           (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                            >> 0x28U))))),3);
    bufp->chgBit(oldp+561,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                   ? (vlSelfRef.reg_wdata_i 
                                      >> 1U) : (IData)(
                                                       (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                        >> 0x38U))))));
    bufp->chgBit(oldp+562,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                   ? (vlSelfRef.reg_wdata_i 
                                      >> 4U) : (IData)(
                                                       (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                        >> 0x32U))))));
    bufp->chgBit(oldp+563,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                   ? (vlSelfRef.reg_wdata_i 
                                      >> 5U) : (IData)(
                                                       (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                        >> 0x30U))))));
    bufp->chgCData(oldp+564,((7U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                     ? (vlSelfRef.reg_wdata_i 
                                        >> 8U) : (IData)(
                                                         (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                          >> 0x2cU))))),3);
    bufp->chgCData(oldp+565,((3U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                     ? (vlSelfRef.reg_wdata_i 
                                        >> 0xeU) : (IData)(
                                                           (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                            >> 0x25U))))),2);
    bufp->chgCData(oldp+566,((3U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                     ? (vlSelfRef.reg_wdata_i 
                                        >> 0x10U) : (IData)(
                                                            (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                             >> 0x22U))))),2);
    bufp->chgCData(oldp+567,((0x1fU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                        ? (vlSelfRef.reg_wdata_i 
                                           >> 0x12U)
                                        : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                   >> 0x1cU))))),5);
    bufp->chgBit(oldp+568,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                   ? (vlSelfRef.reg_wdata_i 
                                      >> 3U) : (IData)(
                                                       (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                        >> 0x34U))))));
    bufp->chgBit(oldp+569,((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                                   ? vlSelfRef.reg_wdata_i
                                   : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                              >> 0x3aU))))));
    bufp->chgCData(oldp+570,((0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                                        ? vlSelfRef.reg_wdata_i
                                        : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                   >> 0x13U))))),8);
    bufp->chgCData(oldp+571,((0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                                        ? (vlSelfRef.reg_wdata_i 
                                           >> 8U) : (IData)(
                                                            (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                             >> 0xaU))))),8);
    bufp->chgCData(oldp+572,((0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                                        ? (vlSelfRef.reg_wdata_i 
                                           >> 0x10U)
                                        : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                   >> 1U))))),8);
}

void Vconv1d_tb_wrapper___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root__trace_cleanup\n"); );
    // Init
    Vconv1d_tb_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vconv1d_tb_wrapper___024root*>(voidSelf);
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
