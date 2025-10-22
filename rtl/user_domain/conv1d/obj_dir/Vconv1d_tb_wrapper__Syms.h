// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCONV1D_TB_WRAPPER__SYMS_H_
#define VERILATED_VCONV1D_TB_WRAPPER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vconv1d_tb_wrapper.h"

// INCLUDE MODULE CLASSES
#include "Vconv1d_tb_wrapper___024root.h"
#include "Vconv1d_tb_wrapper_conv1d_control_reg_pkg.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vconv1d_tb_wrapper__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vconv1d_tb_wrapper* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vconv1d_tb_wrapper___024root   TOP;
    Vconv1d_tb_wrapper_conv1d_control_reg_pkg TOP__conv1d_control_reg_pkg;

    // CONSTRUCTORS
    Vconv1d_tb_wrapper__Syms(VerilatedContext* contextp, const char* namep, Vconv1d_tb_wrapper* modelp);
    ~Vconv1d_tb_wrapper__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
