// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VCONV1D_TB_WRAPPER_H_
#define VERILATED_VCONV1D_TB_WRAPPER_H_  // guard

#include "verilated.h"

class Vconv1d_tb_wrapper__Syms;
class Vconv1d_tb_wrapper___024root;
class VerilatedFstC;
class Vconv1d_tb_wrapper_conv1d_control_reg_pkg;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vconv1d_tb_wrapper VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vconv1d_tb_wrapper__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk_i,0,0);
    VL_IN8(&rst_ni,0,0);
    VL_IN8(&obi_req_i,0,0);
    VL_IN8(&obi_we_i,0,0);
    VL_IN8(&obi_be_i,3,0);
    VL_OUT8(&obi_gnt_o,0,0);
    VL_OUT8(&obi_rvalid_o,0,0);
    VL_IN8(&reg_valid_i,0,0);
    VL_IN8(&reg_write_i,0,0);
    VL_IN8(&reg_wstrb_i,3,0);
    VL_OUT8(&reg_error_o,0,0);
    VL_OUT8(&reg_ready_o,0,0);
    VL_OUT8(&done_int_o,0,0);
    VL_IN(&obi_addr_i,31,0);
    VL_IN(&obi_wdata_i,31,0);
    VL_OUT(&obi_rdata_o,31,0);
    VL_IN(&reg_addr_i,31,0);
    VL_IN(&reg_wdata_i,31,0);
    VL_OUT(&reg_rdata_o,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vconv1d_tb_wrapper_conv1d_control_reg_pkg* const __PVT__conv1d_control_reg_pkg;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vconv1d_tb_wrapper___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vconv1d_tb_wrapper(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vconv1d_tb_wrapper(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vconv1d_tb_wrapper();
  private:
    VL_UNCOPYABLE(Vconv1d_tb_wrapper);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
