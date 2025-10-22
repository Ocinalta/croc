// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vconv1d_tb_wrapper__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vconv1d_tb_wrapper::Vconv1d_tb_wrapper(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vconv1d_tb_wrapper__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , obi_req_i{vlSymsp->TOP.obi_req_i}
    , obi_we_i{vlSymsp->TOP.obi_we_i}
    , obi_be_i{vlSymsp->TOP.obi_be_i}
    , obi_gnt_o{vlSymsp->TOP.obi_gnt_o}
    , obi_rvalid_o{vlSymsp->TOP.obi_rvalid_o}
    , reg_valid_i{vlSymsp->TOP.reg_valid_i}
    , reg_write_i{vlSymsp->TOP.reg_write_i}
    , reg_wstrb_i{vlSymsp->TOP.reg_wstrb_i}
    , reg_error_o{vlSymsp->TOP.reg_error_o}
    , reg_ready_o{vlSymsp->TOP.reg_ready_o}
    , done_int_o{vlSymsp->TOP.done_int_o}
    , obi_addr_i{vlSymsp->TOP.obi_addr_i}
    , obi_wdata_i{vlSymsp->TOP.obi_wdata_i}
    , obi_rdata_o{vlSymsp->TOP.obi_rdata_o}
    , reg_addr_i{vlSymsp->TOP.reg_addr_i}
    , reg_wdata_i{vlSymsp->TOP.reg_wdata_i}
    , reg_rdata_o{vlSymsp->TOP.reg_rdata_o}
    , __PVT__conv1d_control_reg_pkg{vlSymsp->TOP.__PVT__conv1d_control_reg_pkg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vconv1d_tb_wrapper::Vconv1d_tb_wrapper(const char* _vcname__)
    : Vconv1d_tb_wrapper(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vconv1d_tb_wrapper::~Vconv1d_tb_wrapper() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vconv1d_tb_wrapper___024root___eval_debug_assertions(Vconv1d_tb_wrapper___024root* vlSelf);
#endif  // VL_DEBUG
void Vconv1d_tb_wrapper___024root___eval_static(Vconv1d_tb_wrapper___024root* vlSelf);
void Vconv1d_tb_wrapper___024root___eval_initial(Vconv1d_tb_wrapper___024root* vlSelf);
void Vconv1d_tb_wrapper___024root___eval_settle(Vconv1d_tb_wrapper___024root* vlSelf);
void Vconv1d_tb_wrapper___024root___eval(Vconv1d_tb_wrapper___024root* vlSelf);

void Vconv1d_tb_wrapper::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vconv1d_tb_wrapper::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vconv1d_tb_wrapper___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vconv1d_tb_wrapper___024root___eval_static(&(vlSymsp->TOP));
        Vconv1d_tb_wrapper___024root___eval_initial(&(vlSymsp->TOP));
        Vconv1d_tb_wrapper___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vconv1d_tb_wrapper___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vconv1d_tb_wrapper::eventsPending() { return false; }

uint64_t Vconv1d_tb_wrapper::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vconv1d_tb_wrapper::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vconv1d_tb_wrapper___024root___eval_final(Vconv1d_tb_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vconv1d_tb_wrapper::final() {
    Vconv1d_tb_wrapper___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vconv1d_tb_wrapper::hierName() const { return vlSymsp->name(); }
const char* Vconv1d_tb_wrapper::modelName() const { return "Vconv1d_tb_wrapper"; }
unsigned Vconv1d_tb_wrapper::threads() const { return 1; }
void Vconv1d_tb_wrapper::prepareClone() const { contextp()->prepareClone(); }
void Vconv1d_tb_wrapper::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vconv1d_tb_wrapper::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vconv1d_tb_wrapper___024root__trace_decl_types(VerilatedFst* tracep);

void Vconv1d_tb_wrapper___024root__trace_init_top(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vconv1d_tb_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vconv1d_tb_wrapper___024root*>(voidSelf);
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vconv1d_tb_wrapper___024root__trace_decl_types(tracep);
    Vconv1d_tb_wrapper___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vconv1d_tb_wrapper___024root__trace_register(Vconv1d_tb_wrapper___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vconv1d_tb_wrapper::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vconv1d_tb_wrapper::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vconv1d_tb_wrapper___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
