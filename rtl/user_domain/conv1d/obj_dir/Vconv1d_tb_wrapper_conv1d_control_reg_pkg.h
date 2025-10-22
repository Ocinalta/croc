// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vconv1d_tb_wrapper.h for the primary calling header

#ifndef VERILATED_VCONV1D_TB_WRAPPER_CONV1D_CONTROL_REG_PKG_H_
#define VERILATED_VCONV1D_TB_WRAPPER_CONV1D_CONTROL_REG_PKG_H_  // guard

#include "verilated.h"


class Vconv1d_tb_wrapper__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vconv1d_tb_wrapper_conv1d_control_reg_pkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vconv1d_tb_wrapper__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr VlUnpacked<CData/*3:0*/, 3> __PVT__CONV1D_CONTROL_PERMIT = {{
        0x01U, 0x07U, 0x07U
    }};

    // CONSTRUCTORS
    Vconv1d_tb_wrapper_conv1d_control_reg_pkg(Vconv1d_tb_wrapper__Syms* symsp, const char* v__name);
    ~Vconv1d_tb_wrapper_conv1d_control_reg_pkg();
    VL_UNCOPYABLE(Vconv1d_tb_wrapper_conv1d_control_reg_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
