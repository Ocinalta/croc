// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vconv1d_tb_wrapper.h for the primary calling header

#include "Vconv1d_tb_wrapper__pch.h"
#include "Vconv1d_tb_wrapper__Syms.h"
#include "Vconv1d_tb_wrapper___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vconv1d_tb_wrapper___024root___dump_triggers__stl(Vconv1d_tb_wrapper___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root___eval_triggers__stl(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval_triggers__stl\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vconv1d_tb_wrapper___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
