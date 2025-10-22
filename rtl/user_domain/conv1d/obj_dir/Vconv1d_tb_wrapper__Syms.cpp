// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vconv1d_tb_wrapper__pch.h"
#include "Vconv1d_tb_wrapper.h"
#include "Vconv1d_tb_wrapper___024root.h"
#include "Vconv1d_tb_wrapper_conv1d_control_reg_pkg.h"

// FUNCTIONS
Vconv1d_tb_wrapper__Syms::~Vconv1d_tb_wrapper__Syms()
{
}

Vconv1d_tb_wrapper__Syms::Vconv1d_tb_wrapper__Syms(VerilatedContext* contextp, const char* namep, Vconv1d_tb_wrapper* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__conv1d_control_reg_pkg{this, Verilated::catName(namep, "conv1d_control_reg_pkg")}
{
        // Check resources
        Verilated::stackCheck(40);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__conv1d_control_reg_pkg = &TOP__conv1d_control_reg_pkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__conv1d_control_reg_pkg.__Vconfigure(true);
}
