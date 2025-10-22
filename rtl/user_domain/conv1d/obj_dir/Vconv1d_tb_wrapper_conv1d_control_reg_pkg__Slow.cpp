// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vconv1d_tb_wrapper.h for the primary calling header

#include "Vconv1d_tb_wrapper__pch.h"
#include "Vconv1d_tb_wrapper__Syms.h"
#include "Vconv1d_tb_wrapper_conv1d_control_reg_pkg.h"

// Parameter definitions for Vconv1d_tb_wrapper_conv1d_control_reg_pkg
constexpr VlUnpacked<CData/*3:0*/, 3> Vconv1d_tb_wrapper_conv1d_control_reg_pkg::__PVT__CONV1D_CONTROL_PERMIT;


void Vconv1d_tb_wrapper_conv1d_control_reg_pkg___ctor_var_reset(Vconv1d_tb_wrapper_conv1d_control_reg_pkg* vlSelf);

Vconv1d_tb_wrapper_conv1d_control_reg_pkg::Vconv1d_tb_wrapper_conv1d_control_reg_pkg(Vconv1d_tb_wrapper__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vconv1d_tb_wrapper_conv1d_control_reg_pkg___ctor_var_reset(this);
}

void Vconv1d_tb_wrapper_conv1d_control_reg_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vconv1d_tb_wrapper_conv1d_control_reg_pkg::~Vconv1d_tb_wrapper_conv1d_control_reg_pkg() {
}
