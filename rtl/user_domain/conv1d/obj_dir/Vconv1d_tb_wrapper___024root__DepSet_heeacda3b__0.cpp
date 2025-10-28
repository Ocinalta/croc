// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vconv1d_tb_wrapper.h for the primary calling header

#include "Vconv1d_tb_wrapper__pch.h"
#include "Vconv1d_tb_wrapper___024root.h"

void Vconv1d_tb_wrapper___024root___ico_sequent__TOP__0(Vconv1d_tb_wrapper___024root* vlSelf);

void Vconv1d_tb_wrapper___024root___eval_ico(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval_ico\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vconv1d_tb_wrapper___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vconv1d_tb_wrapper___024root___ico_sequent__TOP__0(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___ico_sequent__TOP__0\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgRegularize_h1c82a3ae_0_7;
    conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgRegularize_h1c82a3ae_0_7 = 0;
    // Body
    vlSelfRef.__VdfgRegularize_hd87f99a1_1_0 = (((QData)((IData)(vlSelfRef.obi_addr_i)) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelfRef.obi_wdata_i)));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_we 
        = ((IData)(vlSelfRef.reg_valid_i) & (IData)(vlSelfRef.reg_write_i));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0 
        = (((8U == (0xfU & vlSelfRef.reg_addr_i)) << 2U) 
           | (((4U == (0xfU & vlSelfRef.reg_addr_i)) 
               << 1U) | (0U == (0xfU & vlSelfRef.reg_addr_i))));
    if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
            = (IData)((((QData)((IData)((((IData)(vlSelfRef.obi_req_i) 
                                          << 0x1bU) 
                                         | (((IData)(vlSelfRef.obi_we_i) 
                                             << 0x1aU) 
                                            | (((IData)(vlSelfRef.obi_be_i) 
                                                << 0x16U) 
                                               | (vlSelfRef.obi_addr_i 
                                                  >> 0xaU)))))) 
                        << 0x20U) | (QData)((IData)(
                                                    (vlSelfRef.__VdfgRegularize_hd87f99a1_1_0 
                                                     >> 5U)))));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U] 
            = (IData)(((((QData)((IData)((((IData)(vlSelfRef.obi_req_i) 
                                           << 0x1bU) 
                                          | (((IData)(vlSelfRef.obi_we_i) 
                                              << 0x1aU) 
                                             | (((IData)(vlSelfRef.obi_be_i) 
                                                 << 0x16U) 
                                                | (vlSelfRef.obi_addr_i 
                                                   >> 0xaU)))))) 
                         << 0x20U) | (QData)((IData)(
                                                     (vlSelfRef.__VdfgRegularize_hd87f99a1_1_0 
                                                      >> 5U)))) 
                       >> 0x20U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
            = ((0x20U & (vlSelfRef.obi_wdata_i << 5U)) 
               | (0x1fU & (vlSelfRef.obi_addr_i >> 5U)));
    } else {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[0U];
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U] 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U];
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U];
    }
    vlSelfRef.reg_error_o = ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_we) 
                             & (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0) 
                                 & (0U != (1U & (~ (IData)(vlSelfRef.reg_wstrb_i))))) 
                                | ((IData)((0U != (6U 
                                                   & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0)))) 
                                   & (0U != (7U & (~ (IData)(vlSelfRef.reg_wstrb_i)))))));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next 
            = ((0xfffffff8U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_loaded_flag__q) 
                   << 2U) | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_mcu_using_sram__q) 
                              << 1U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_start__q))));
    } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next 
            = ((0xffffffc0U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next) 
               | ((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q) 
                    << 5U) | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q) 
                              << 4U)) | ((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q) 
                                           << 3U) | 
                                          ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q) 
                                           << 2U)) 
                                         | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q)))));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next 
            = ((0xff8000ffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_tower_din__q) 
                   << 0x12U) | ((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_weights__q) 
                                  << 0x10U) | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q) 
                                               << 0xeU)) 
                                | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_data_number_sram__q) 
                                    << 0xbU) | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_filter_number_sram__q) 
                                                << 8U)))));
    } else {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next 
            = ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0))
                ? ((0xff000000U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_weight_address__q) 
                       << 0x10U) | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_dout_address__q) 
                                     << 8U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_din_address__q))))
                : 0xffffffffU);
    }
    conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgRegularize_h1c82a3ae_0_7 
        = ((~ (IData)(vlSelfRef.reg_error_o)) & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_we));
    vlSelfRef.reg_rdata_o = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we 
        = ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0) 
           & (IData)(conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgRegularize_h1c82a3ae_0_7));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we 
        = (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0) 
            >> 1U) & (IData)(conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgRegularize_h1c82a3ae_0_7));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we 
        = (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0) 
            >> 2U) & (IData)(conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgRegularize_h1c82a3ae_0_7));
}

void Vconv1d_tb_wrapper___024root___eval_triggers__ico(Vconv1d_tb_wrapper___024root* vlSelf);

bool Vconv1d_tb_wrapper___024root___eval_phase__ico(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval_phase__ico\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vconv1d_tb_wrapper___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vconv1d_tb_wrapper___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vconv1d_tb_wrapper___024root___eval_act(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval_act\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vconv1d_tb_wrapper___024root___nba_sequent__TOP__0(Vconv1d_tb_wrapper___024root* vlSelf);
void Vconv1d_tb_wrapper___024root___nba_sequent__TOP__1(Vconv1d_tb_wrapper___024root* vlSelf);
void Vconv1d_tb_wrapper___024root___nba_comb__TOP__0(Vconv1d_tb_wrapper___024root* vlSelf);

void Vconv1d_tb_wrapper___024root___eval_nba(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval_nba\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vconv1d_tb_wrapper___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vconv1d_tb_wrapper___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        Vconv1d_tb_wrapper___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vconv1d_tb_wrapper___024root___nba_sequent__TOP__0(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___nba_sequent__TOP__0\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in;
    __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in = 0;
    CData/*1:0*/ __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin;
    __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin = 0;
    // Body
    __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin 
        = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin;
    __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in 
        = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in;
    if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_cnt_fin) {
        __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin = 0U;
    } else if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__en_cnt_fin) {
        __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin)));
    }
    if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_cnt_branch) {
        __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in = 4U;
    } else if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__en_cnt_branch) {
        __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in 
            = (7U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in) 
                     - (IData)(1U)));
    }
    if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_partial) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out = 0U;
    } else if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_partial) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__add_tot_out;
    }
    if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_branch) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator1 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator2 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator3 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator4 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out;
    }
    if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight0_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight0_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight0_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight0_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight1_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight1_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight1_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight1_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight2_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight2_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight2_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight2_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((8U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight3_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight3_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight3_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight3_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((0x10U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight4_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight4_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight4_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight4_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data0_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data0_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data0_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data0_out = 0U;
    } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data0_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data0_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data0_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data0_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data1_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data1_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data1_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data1_out = 0U;
    } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data1_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data1_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data1_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data1_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data2_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data2_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data2_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data2_out = 0U;
    } else if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data2_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data2_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data2_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data2_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((8U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data3_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data3_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data3_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data3_out = 0U;
    } else if ((8U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data3_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data3_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data3_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data3_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    if ((0x10U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data4_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data4_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data4_out = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data4_out = 0U;
    } else if ((0x10U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data4_out 
            = (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
               >> 0x18U);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data4_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 0x10U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data4_out 
            = (0xffU & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
                        >> 8U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data4_out 
            = (0xffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q);
    }
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin 
        = __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in 
        = __Vdly__conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in;
    if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_tmp) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__add_out;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__add_out;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__add_out;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__add_out;
    }
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__add_tot_out 
        = (((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
             ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                 ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator4
                 : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator3)
             : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                 ? vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator2
                 : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__out_accumulator1)) 
           + vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, 
                                                              ((4U 
                                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                ? 
                                                               ((2U 
                                                                 & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                 ? 0U
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? 0U
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data0_out)))
                                                                : 
                                                               ((2U 
                                                                 & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                 ? 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data1_out)
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data2_out))
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data3_out)
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_data4_out)))))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, 
                                                          ((4U 
                                                            & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? 0U
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight0_out)))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight1_out)
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight2_out))
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight3_out)
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__reg_weight4_out))))))));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, 
                                                              ((4U 
                                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                ? 
                                                               ((2U 
                                                                 & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                 ? 0U
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? 0U
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data0_out)))
                                                                : 
                                                               ((2U 
                                                                 & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                 ? 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data1_out)
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data2_out))
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data3_out)
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_data4_out)))))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, 
                                                          ((4U 
                                                            & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? 0U
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight0_out)))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight1_out)
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight2_out))
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight3_out)
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__reg_weight4_out))))))));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, 
                                                              ((4U 
                                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                ? 
                                                               ((2U 
                                                                 & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                 ? 0U
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? 0U
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data0_out)))
                                                                : 
                                                               ((2U 
                                                                 & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                 ? 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data1_out)
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data2_out))
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data3_out)
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_data4_out)))))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, 
                                                          ((4U 
                                                            & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? 0U
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight0_out)))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight1_out)
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight2_out))
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight3_out)
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__reg_weight4_out))))))));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product 
        = (0xffffU & VL_MULS_III(16, (0xffffU & VL_EXTENDS_II(16,8, 
                                                              ((4U 
                                                                & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                ? 
                                                               ((2U 
                                                                 & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                 ? 0U
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? 0U
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data0_out)))
                                                                : 
                                                               ((2U 
                                                                 & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                 ? 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data1_out)
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data2_out))
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                                  ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data3_out)
                                                                  : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_data4_out)))))), 
                                 (0xffffU & VL_EXTENDS_II(16,8, 
                                                          ((4U 
                                                            & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? 0U
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight0_out)))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight1_out)
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight2_out))
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                              ? (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight3_out)
                                                              : (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__reg_weight4_out))))))));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__add_out 
        = ((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product) 
                               >> 0xfU)))) << 0x10U) 
            | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch1__DOT__mult__DOT__internal_product)) 
           + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
               ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator1__DOT__reg_tmp_out));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__add_out 
        = ((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product) 
                               >> 0xfU)))) << 0x10U) 
            | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch2__DOT__mult__DOT__internal_product)) 
           + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
               ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator2__DOT__reg_tmp_out));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__add_out 
        = ((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product) 
                               >> 0xfU)))) << 0x10U) 
            | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch3__DOT__mult__DOT__internal_product)) 
           + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
               ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator3__DOT__reg_tmp_out));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__add_out 
        = ((((- (IData)((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product) 
                               >> 0xfU)))) << 0x10U) 
            | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__branch4__DOT__mult__DOT__internal_product)) 
           + ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
               ? 0U : vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__accumulator4__DOT__reg_tmp_out));
}

extern const VlUnpacked<CData/*0:0*/, 8> Vconv1d_tb_wrapper__ConstPool__TABLE_he59eb7a0_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vconv1d_tb_wrapper__ConstPool__TABLE_hab2a74e7_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vconv1d_tb_wrapper__ConstPool__TABLE_hde1f335d_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vconv1d_tb_wrapper__ConstPool__TABLE_hf1fd9a8e_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vconv1d_tb_wrapper__ConstPool__TABLE_hb32e8b2b_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vconv1d_tb_wrapper__ConstPool__TABLE_h8d37a555_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vconv1d_tb_wrapper__ConstPool__TABLE_hc8f699ff_0;

VL_INLINE_OPT void Vconv1d_tb_wrapper___024root___nba_sequent__TOP__1(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___nba_sequent__TOP__1\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelfRef.rst_ni) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk10__DOT__i = 1U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk8__DOT__unnamedblk9__DOT__j = 1U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk8__DOT__i = 1U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__id_q 
            = (7U & (vlSelfRef.obi_wdata_i >> 2U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__next_state;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state;
        if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_start__q 
                = ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                   & vlSelfRef.reg_wdata_i);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_mcu_using_sram__q 
                = ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                   & (vlSelfRef.reg_wdata_i >> 1U));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_loaded_flag__q 
                = ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we) 
                   & (vlSelfRef.reg_wdata_i >> 2U));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x12U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_din_address__q 
                = (0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                             ? vlSelfRef.reg_wdata_i
                             : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                        >> 0x13U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 9U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_dout_address__q 
                = (0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                             ? (vlSelfRef.reg_wdata_i 
                                >> 8U) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                  >> 0xaU))));
        }
        if ((1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                   | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_weight_address__q 
                = (0xffU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we)
                             ? (vlSelfRef.reg_wdata_i 
                                >> 0x10U) : (IData)(
                                                    (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                     >> 1U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x39U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q 
                = (1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? vlSelfRef.reg_wdata_i : (IData)(
                                                            (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                             >> 0x3aU))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x37U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q 
                = (1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 1U) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x38U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x35U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q 
                = (1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 2U) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x36U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x33U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q 
                = (1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 3U) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x34U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x31U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q 
                = (1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 4U) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x32U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x2fU)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q 
                = (1U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 5U) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x30U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x2bU)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_filter_number_sram__q 
                = (7U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 8U) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                               >> 0x2cU))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x27U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_data_number_sram__q 
                = (7U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 0xbU) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                 >> 0x28U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x21U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_weights__q 
                = (3U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 0x10U) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                  >> 0x22U))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x1bU)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_tower_din__q 
                = (0x1fU & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                             ? (vlSelfRef.reg_wdata_i 
                                >> 0x12U) : (IData)(
                                                    (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                     >> 0x1cU))));
        }
        if ((1U & ((IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            >> 0x24U)) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q 
                = (3U & ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we)
                          ? (vlSelfRef.reg_wdata_i 
                             >> 0xeU) : (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                                                 >> 0x25U))));
        }
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
            = ((IData)((0x20U == (0x30U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])))
                ? (((0U == (0x1fU & VL_SHIFTL_III(12,32,32, 
                                                  (0x7fU 
                                                   & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))
                     ? 0U : (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                             (((IData)(0x1fU) + (0xfffU 
                                                 & VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))) 
                              >> 5U)] << ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(12,32,32, 
                                                             (0x7fU 
                                                              & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                   | (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                      (0x7fU & (VL_SHIFTL_III(12,32,32, 
                                              (0x7fU 
                                               & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U) 
                                >> 5U))] >> (0x1fU 
                                             & VL_SHIFTL_III(12,32,32, 
                                                             (0x7fU 
                                                              & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))
                : (((0U == (0x1fU & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U)))
                     ? 0U : (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                             (((IData)(0x1fU) + (0xfffU 
                                                 & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U))) 
                              >> 5U)] << ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U))))) 
                   | (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                      (0x7fU & (VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U) 
                                >> 5U))] >> (0x1fU 
                                             & VL_SHIFTL_III(12,32,32, (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q), 5U)))));
        if ((0x20U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])) {
            if ((0x10U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk10__DOT__unnamedblk11__DOT__j = 0x20U;
                if ((1U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & VL_SHIFTL_III(12,32,32, 
                                                                (0x7fU 
                                                                 & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (VL_SHIFTL_III(12,32,32, 
                                                    (0x7fU 
                                                     & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U]) 
                                                   << 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(12,32,32, 
                                                                    (0x7fU 
                                                                     & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(1U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(1U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 1U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(1U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(2U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(2U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 2U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(2U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(3U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(3U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 3U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(4U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(4U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 4U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(4U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(5U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(5U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 5U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(5U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(6U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(6U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 6U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(6U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(7U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(7U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 7U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(7U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                }
                if ((2U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(8U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(8U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(8U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 8U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(8U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(9U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(9U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(9U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 9U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0xaU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0xaU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0xaU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0xaU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0xaU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0xbU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0xbU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0xbU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0xbU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0xbU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0xcU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0xcU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0xcU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0xcU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0xcU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0xdU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0xdU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0xdU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0xdU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0xdU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0xeU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0xeU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0xeU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0xeU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0xeU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0xfU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0xfU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0xfU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0xfU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0xfU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                }
                if ((4U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x10U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x10U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x10U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x10U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x10U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x11U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x11U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x11U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x11U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x11U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x12U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x12U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x12U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x12U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x12U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x13U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x13U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x13U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x13U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x13U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x14U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x14U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x14U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x14U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x14U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x15U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x15U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x15U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x15U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x15U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x16U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x16U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x16U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x16U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x16U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x17U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x17U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x17U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x17U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x17U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                }
                if ((8U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U])) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x18U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x18U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x18U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x18U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x18U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x19U) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x19U) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x19U) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x19U)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x19U) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x1aU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x1aU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x1aU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x1aU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x1aU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x1bU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x1bU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x1bU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x1bU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x1bU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x1cU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x1cU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x1cU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x1cU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x1cU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x1dU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x1dU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x1dU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x1dU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x1dU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x1eU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x1eU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x1eU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (1U 
                                                    & (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                       >> 0x1eU)) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x1eU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[(0x7fU 
                                                                                & (((IData)(0x1fU) 
                                                                                + 
                                                                                VL_SHIFTL_III(12,32,32, 
                                                                                (0x7fU 
                                                                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(0x1fU) 
                                                   + 
                                                   VL_SHIFTL_III(12,32,32, 
                                                                 (0x7fU 
                                                                  & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U))))) 
                            & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram[
                            (0x7fU & (((IData)(0x1fU) 
                                       + VL_SHIFTL_III(12,32,32, 
                                                       (0x7fU 
                                                        & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)) 
                                      >> 5U))]) | (
                                                   (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
                                                    >> 0x1fU) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(0x1fU) 
                                                       + 
                                                       VL_SHIFTL_III(12,32,32, 
                                                                     (0x7fU 
                                                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]), 5U)))));
                }
            }
            if ((1U & (~ (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
                          >> 4U)))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT____Vlvbound_hc876ad9b__0 
                    = (0x7fU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U]);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q 
                    = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT____Vlvbound_hc876ad9b__0;
            }
        }
    } else {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__id_q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_start__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_mcu_using_sram__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_loaded_flag__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_din_address__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_dout_address__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_weight_address__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_filter_number_sram__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_data_number_sram__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_weights__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_tower_din__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[0U];
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__r_addr_q = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i = 0U;
        while ((0x80U > vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i)) {
            VL_ASSIGNSEL_WI(4096,32,(0xfffU & VL_SHIFTL_III(12,32,32, vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i, 5U)), vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__sram, 
                            (((0U == (0x1fU & VL_SHIFTL_III(12,32,32, vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i, 5U)))
                               ? 0U : (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[
                                       (((IData)(0x1fU) 
                                         + (0xfffU 
                                            & VL_SHIFTL_III(12,32,32, vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i, 5U))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           VL_SHIFTL_III(12,32,32, vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i, 5U))))) 
                             | (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__init_val[
                                (0x7fU & (VL_SHIFTL_III(12,32,32, vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i, 5U) 
                                          >> 5U))] 
                                >> (0x1fU & VL_SHIFTL_III(12,32,32, vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i, 5U)))));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i 
                = ((IData)(1U) + vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk5__DOT__i);
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.rst_ni)))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk6__DOT__unnamedblk7__DOT__j = 1U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__unnamedblk6__DOT__i = 1U;
    }
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_start__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_mcu_using_sram__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_control_loaded_flag__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__control_start_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_din_address__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_dout_address__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status2_weight_address__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status2_din_address_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_running__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_accelerator_using_sram__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_reload_flag__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done_calculation__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_done_filter__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_filter_number_sram__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_data_number_sram__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_number_din__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_number_weights__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__u_status1_lego_tower_din__DOT__qe 
        = ((IData)(vlSelfRef.rst_ni) && (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__status1_running_we));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__rvalid_q 
        = ((IData)(vlSelfRef.rst_ni) && (1U & (vlSelfRef.obi_wdata_i 
                                               & (IData)(
                                                         (vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o 
                                                          >> 1U)))));
    __Vtableidx1 = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__done_qalc 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_he59eb7a0_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_cnt_branch 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_hab2a74e7_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_cnt_fin 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_hde1f335d_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__en_cnt_branch 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_hf1fd9a8e_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__en_cnt_fin 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_hb32e8b2b_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_tmp 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_hf1fd9a8e_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_branch 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_h8d37a555_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_partial 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_hb32e8b2b_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_partial 
        = Vconv1d_tb_wrapper__ConstPool__TABLE_hc8f699ff_0
        [__Vtableidx1];
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight = 0U;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din = 0U;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din = 0U;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc = 0U;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt = 1U;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next 
            = ((0xfffffff8U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_loaded_flag__q) 
                   << 2U) | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_mcu_using_sram__q) 
                              << 1U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_start__q))));
    } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next 
            = ((0xffffffc0U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next) 
               | ((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q) 
                    << 5U) | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q) 
                              << 4U)) | ((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q) 
                                           << 3U) | 
                                          ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q) 
                                           << 2U)) 
                                         | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q)))));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next 
            = ((0xff8000ffU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_tower_din__q) 
                   << 0x12U) | ((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_weights__q) 
                                  << 0x10U) | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q) 
                                               << 0xeU)) 
                                | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_data_number_sram__q) 
                                    << 0xbU) | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_filter_number_sram__q) 
                                                << 8U)))));
    } else {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next 
            = ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____VdfgExtracted_h59725bcd__0))
                ? ((0xff000000U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_weight_address__q) 
                       << 0x10U) | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_dout_address__q) 
                                     << 8U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_din_address__q))))
                : 0xffffffffU);
    }
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
        = (((QData)((IData)(((((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_start__q) 
                                 << 0x1fU) | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_mcu_using_sram__q) 
                                               << 0x1eU) 
                                              | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_control_loaded_flag__q) 
                                                 << 0x1dU))) 
                               | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_running__q) 
                                   << 0x1cU) | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done__q) 
                                                 << 0x1bU) 
                                                | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_accelerator_using_sram__q) 
                                                   << 0x1aU)))) 
                              | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_reload_flag__q) 
                                  << 0x19U) | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_calculation__q) 
                                                << 0x18U) 
                                               | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_done_filter__q) 
                                                   << 0x17U) 
                                                  | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_filter_number_sram__q) 
                                                     << 0x14U))))) 
                             | ((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_data_number_sram__q) 
                                  << 0x11U) | ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q) 
                                               << 0xfU)) 
                                | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_weights__q) 
                                    << 0xdU) | (((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_tower_din__q) 
                                                 << 8U) 
                                                | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_din_address__q))))))) 
            << 0x10U) | (QData)((IData)((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_dout_address__q) 
                                          << 8U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status2_weight_address__q)))));
    vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o = 0ULL;
    if ((0x10U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        if ((8U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight = 0U;
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din = 0U;
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc = 0U;
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt = 1U;
            } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din 
                    = (0xfU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din));
            }
            if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                          >> 2U)))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din 
                    = ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                        ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                            ? (0x10U | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din))
                            : (0x18U | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din)))
                        : 0U);
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                             >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt 
                    = (1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state));
            } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt = 0U;
            }
        }
    } else {
        if ((8U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state)))) {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight 
                            = (0xfU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight));
                    }
                }
            }
            if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    if ((1U & (~ (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state)))) {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din 
                            = (0xfU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din));
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc = 1U;
                    } else {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc = 0U;
                    }
                } else {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din 
                        = ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                            ? (0x10U | (7U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din)))
                            : (8U | (0x13U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))));
                }
                if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                              >> 1U)))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt 
                        = (1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state));
                }
            } else {
                if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din 
                        = ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                            ? (4U | (0x19U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din)))
                            : (2U | (0x1cU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din))));
                } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din 
                        = (1U | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din));
                }
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt = 0U;
            }
        } else {
            if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight 
                    = ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                        ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                            ? (0x10U | (7U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight)))
                            : (8U | (0x13U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight))))
                        : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                            ? (4U | (0x19U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight)))
                            : (2U | (0x1cU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight)))));
            } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight 
                        = (1U | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state)))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_weight = 0U;
            }
            if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state)))) {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__ld_reg_din = 0U;
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc = 0U;
                    }
                }
            }
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt 
                = ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                             >> 2U))) && (1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                                                   >> 1U))));
        }
        if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state)))) {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__rst_reg_din = 0U;
                    }
                }
            }
        }
    }
    vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o 
        = ((0x7ffffffffcULL & vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o) 
           | (IData)((IData)((((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt) 
                               << 1U) | (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__rvalid_q)))));
    vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o 
        = ((7ULL & vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o) 
           | (((QData)((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_internal_mem__DOT__u_tc_sram__DOT__rdata_q)) 
               << 7U) | ((QData)((IData)(((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__u_obi_bridge__DOT__id_q) 
                                          << 1U))) 
                         << 3U)));
    vlSelfRef.reg_rdata_o = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT__reg_rdata_next;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x6ffffffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7bfffffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7efffffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7feffffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7ff8fffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7fff8ffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7ffff9fffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7fffff3ffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7fffffe0fffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0xa00000ULL | (0x7fffffff807ffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x1b000ULL | (0x7fffffffffc03ffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
        = (0x7fffffffffffe01ULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
    if ((0x10U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        if ((8U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x6ffffffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7bfffffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7efffffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7feffffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7ff8fffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7fff8ffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7ffff9fffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7fffff3ffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7fffffe0fffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0xa00000ULL | (0x7fffffff807ffffULL 
                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x1b000ULL | (0x7fffffffffc03ffULL 
                                     & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7fffffffffffe01ULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 0U;
            } else {
                if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            = (0x7ffffefffffffffULL 
                               & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            = ((0x7fffffff803ffffULL 
                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                               | ((QData)((IData)((1U 
                                                   | (0x1feU 
                                                      & (((IData)(
                                                                  (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                   >> 0x10U)) 
                                                          - (IData)(0x45U)) 
                                                         << 1U))))) 
                                  << 0x12U));
                    } else {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            = (0x40000ULL | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            = (0x7ffffefffffffffULL 
                               & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                            = ((0x7fffffff807ffffULL 
                                & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                               | ((QData)((IData)((0xffU 
                                                   & ((IData)(0x12U) 
                                                      + (IData)(
                                                                (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                 >> 0x10U)))))) 
                                  << 0x13U));
                    }
                }
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
                    = ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                        ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                            ? ((0x57U < (0xffU & (IData)(
                                                         (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                          >> 0x10U))))
                                ? 0x19U : 0x18U) : 
                           ((0x57U < (0xffU & (IData)(
                                                      (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                       >> 0x10U))))
                             ? 0x19U : 0x18U)) : 0xeU);
            }
        } else if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x180000000000000ULL | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7ffff7fffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7fffffffffbffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7fffffffffffdffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7fffffffffffffeULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 0U;
                } else {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7ffff7fffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7fffffffffbffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7fffffffffffdffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7fffffffffffffeULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = ((0x7ff87ffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                           | ((QData)((IData)((1U | 
                                               (0xeU 
                                                & (((IData)(1U) 
                                                    + (IData)(
                                                              (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                               >> 0x24U))) 
                                                   << 1U))))) 
                              << 0x2bU));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x1800000000000ULL | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x8000000000ULL | (0x7fff87fffffffffULL 
                                          & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0xa5b201ULL | (0x7fffffff8000000ULL 
                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
                    = ((6U == (7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                             >> 0x21U))))
                        ? ((7U == (7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                 >> 0x24U))))
                            ? 0x17U : 0x16U) : 1U);
            } else {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = ((0x7fff87fffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                       | ((QData)((IData)((1U | (0xeU 
                                                 & (((IData)(1U) 
                                                     + (IData)(
                                                               (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                >> 0x21U))) 
                                                    << 1U))))) 
                          << 0x27U));
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0xa5b201ULL | (0x7fffffff8000000ULL 
                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
                    = ((6U == (7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                             >> 0x21U))))
                        ? ((7U == (7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                 >> 0x24U))))
                            ? 0x17U : 0x16U) : 1U);
            }
        } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = (0x7fffffffffffdffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
                    = ((6U == (7U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                             >> 0x21U))))
                        ? ((0x80U == (0xffU & (IData)(
                                                      (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                       >> 8U))))
                            ? 0x15U : 2U) : ((0x7eU 
                                              == (0xffU 
                                                  & (IData)(
                                                            (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                             >> 8U))))
                                              ? 0x14U
                                              : 2U));
            } else {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                    = ((0x7fffffffffc01ffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                       | ((QData)((IData)((1U | (0x1feU 
                                                 & (((IData)(1U) 
                                                     + (IData)(
                                                               (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                >> 8U))) 
                                                    << 1U))))) 
                          << 9U));
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 0x13U;
            }
        } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = (0x7fffffff7ffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = (0x7fffffffffffffeULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 0x12U;
        } else {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = (0x7ffffefffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = ((0x7fffffe07ffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                   | ((QData)((IData)((1U | (0x3eU 
                                             & (((IData)(1U) 
                                                 + (IData)(
                                                           (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                            >> 0x18U))) 
                                                << 1U))))) 
                      << 0x1bU));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = (1ULL | (0x7fffffffffffe00ULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 0x11U;
        }
    } else if ((8U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = ((0x7ffff8fffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                           | ((QData)((IData)((1U | 
                                               (6U 
                                                & (((IData)(1U) 
                                                    + (IData)(
                                                              (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                               >> 0x1fU))) 
                                                   << 1U))))) 
                              << 0x24U));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
                        = ((0U == (3U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                 >> 0x1dU))))
                            ? 0x10U : 2U);
                } else {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = (0x7fffffffffbffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
                        = ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__done_qalc)
                            ? 0xfU : 0xeU);
                }
            } else {
                if ((1U & (~ (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state)))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                        = ((0x7fffffff803ffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                           | ((QData)((IData)((0x1feU 
                                               & (((IData)(1U) 
                                                   + (IData)(
                                                             (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                              >> 0x10U))) 
                                                  << 1U)))) 
                              << 0x12U));
                }
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
                    = ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                        ? ((0x57U < (0xffU & (IData)(
                                                     (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                      >> 0x10U))))
                            ? 0x19U : 0x18U) : ((6U 
                                                 == 
                                                 (7U 
                                                  & (IData)(
                                                            (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                             >> 0x21U))))
                                                 ? 
                                                ((0x7eU 
                                                  <= 
                                                  (0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                              >> 8U))))
                                                  ? 
                                                 ((0x7fU 
                                                   == 
                                                   (0xffU 
                                                    & (IData)(
                                                              (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                               >> 8U))))
                                                   ? 0x1aU
                                                   : 0x1bU)
                                                  : 0xdU)
                                                 : 0xdU));
            }
        } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = ((0x7fffffff803ffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                   | ((QData)((IData)(((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                                        ? (1U | (0x1feU 
                                                 & (((IData)(1U) 
                                                     + (IData)(
                                                               (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                >> 0x10U))) 
                                                    << 1U)))
                                        : (1U | (0x1feU 
                                                 & (((IData)(1U) 
                                                     + (IData)(
                                                               (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                >> 0x10U))) 
                                                    << 1U)))))) 
                      << 0x12U));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
                = ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                    ? 0xcU : 0xbU);
        } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = (0x7fffffdffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = ((0x7fffffff803ffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                   | ((QData)((IData)((1U | (0x1feU 
                                             & (((IData)(1U) 
                                                 + (IData)(
                                                           (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                            >> 0x10U))) 
                                                << 1U))))) 
                      << 0x12U));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 0xaU;
        } else {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = (0x7fffffffffffffeULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = ((0x7fffff1ffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                   | ((QData)((IData)((1U | (6U & (
                                                   ((IData)(1U) 
                                                    + (IData)(
                                                              (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                               >> 0x1dU))) 
                                                   << 1U))))) 
                      << 0x21U));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = ((0x7fffffff803ffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                   | ((QData)((IData)((1U | (0x1feU 
                                             & (((IData)(1U) 
                                                 + (IData)(
                                                           (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                            >> 0x10U))) 
                                                << 1U))))) 
                      << 0x12U));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 9U;
        }
    } else if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = ((0x7fffffffffffe00ULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
               | (IData)((IData)(((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                                   ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                                       ? (0x1feU & 
                                          (((IData)(1U) 
                                            + (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)) 
                                           << 1U)) : 
                                      (1U | (0x1feU 
                                             & (((IData)(1U) 
                                                 + (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)) 
                                                << 1U))))
                                   : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                                       ? (1U | (0x1feU 
                                                & (((IData)(1U) 
                                                    + (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)) 
                                                   << 1U)))
                                       : (1U | (0x1feU 
                                                & (((IData)(1U) 
                                                    + (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)) 
                                                   << 1U))))))));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
            = ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                ? ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                    ? 8U : 7U) : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))
                                   ? 6U : 5U));
    } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = ((0x7fffffffffffe00ULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                   | (IData)((IData)((1U | (0x1feU 
                                            & (((IData)(1U) 
                                                + (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)) 
                                               << 1U))))));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 4U;
        } else {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = (0x68000000000000ULL | (0x787ffffffffffffULL 
                                          & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = (0x7ffffefffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
                = ((0x7fffffffffffe00ULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg) 
                   | (IData)((IData)((1U | (0x1feU 
                                            & (((IData)(1U) 
                                                + (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)) 
                                               << 1U))))));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x80000000000000ULL | (0x47fffffffffffffULL 
                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x18000000000000ULL | (0x7c7ffffffffffffULL 
                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x2000000000000ULL | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7ff7fffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7fff7ffffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7ffff7fffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7ffffefffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7fffffdffffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7fffffff7ffffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7fffffffffbffffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7fffffffffffdffULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x7fffffffffffffeULL & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
            = ((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                              >> 0x2dU))) ? 2U : 1U);
    } else {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x28000000000000ULL | (0x607ffffffffffffULL 
                                      & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg 
            = (0x889208a5b201ULL | (0x7fe000000000000ULL 
                                    & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__hw2reg));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__next_state 
            = ((1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                              >> 0x2fU))) ? 1U : 0U);
    }
    vlSelfRef.obi_gnt_o = (1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o 
                                         >> 0x21U)));
    vlSelfRef.obi_rvalid_o = (1U & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o 
                                            >> 0x20U)));
    vlSelfRef.obi_rdata_o = (IData)(vlSelfRef.conv1d_tb_wrapper__DOT____Vcellout__u_conv1d_obi__obi_rsp_o);
}

VL_INLINE_OPT void Vconv1d_tb_wrapper___024root___nba_comb__TOP__0(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___nba_comb__TOP__0\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__next_state 
        = ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
            ? ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                ? 0U : ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                         ? 0U : ((3U == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_add_fin))
                                  ? 5U : 4U))) : ((2U 
                                                   & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                                    ? 4U
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d_control_reg__DOT__u_conv1d_control_reg_top__DOT____Vcellout__u_status1_lego_number_din__q))
                                                     ? 3U
                                                     : 4U))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_qalc__DOT__current_state))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__count_cnt_in))
                                                     ? 2U
                                                     : 1U)
                                                    : 
                                                   ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__start_qalc)
                                                     ? 1U
                                                     : 0U))));
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
        = (0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[0U] = 0U;
    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
        = (0xfU | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
    if ((0x10U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                            = (0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                    } else {
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                            = (0x30U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[0U] 
                            = (IData)((((QData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                    >> 8U))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out))));
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                            = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                               | (IData)(((((QData)((IData)(
                                                            (0xffU 
                                                             & (IData)(
                                                                       (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                        >> 8U))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out))) 
                                          >> 0x20U)));
                        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                            = (0xfU | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                    }
                } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                        = (0x30U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[0U] 
                        = (IData)((((QData)((IData)(
                                                    (0xffU 
                                                     & (IData)(
                                                               (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                >> 8U))))) 
                                    << 0x20U) | (QData)((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out))));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                        = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                           | (IData)(((((QData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                                                    >> 8U))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_datapath__DOT__francesca__DOT__reg_partial_out))) 
                                      >> 0x20U)));
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                        = (0xfU | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((1U & (~ ((IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                        = (0x1fU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                } else {
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                        = (0x20U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                    vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                        = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                           | (0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                               >> 0x10U))));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                    = (0x20U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                    = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                       | (0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x10U))));
            } else {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                    = (0x20U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                    = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                       | (0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x10U))));
            }
        } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                = (0x20U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                   | (0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                       >> 0x10U))));
        } else {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                = (0x20U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                   | (0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                       >> 0x10U))));
        }
    } else if ((4U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                    = (0x20U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                    = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                       | (0xffU & (IData)((vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw 
                                           >> 0x10U))));
            } else {
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                    = (0x20U | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
                vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                    = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                       | (0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)));
            }
        } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                = (0x20U | (0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                   | (0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)));
        } else {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                = (0x20U | (0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                   | (0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)));
        }
    } else if ((2U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                = (0x20U | (0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                   | (0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)));
        } else {
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
                = (0x20U | (0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]));
            vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
                = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
                   | (0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)));
        }
    } else if ((1U & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__accelerator_inst__DOT__u_fsm_tot__DOT__current_state))) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
            = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
               | (0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)));
    } else {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
            = (0xfU & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[0U] = 0U;
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U] 
            = (0xfU | vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U]);
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U] 
            = ((0xffffff00U & vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U]) 
               | (0xffU & (IData)(vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__reg2hw)));
    }
    if (vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__ext_mem_gnt) {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
            = (IData)((((QData)((IData)((((IData)(vlSelfRef.obi_req_i) 
                                          << 0x1bU) 
                                         | (((IData)(vlSelfRef.obi_we_i) 
                                             << 0x1aU) 
                                            | (((IData)(vlSelfRef.obi_be_i) 
                                                << 0x16U) 
                                               | (vlSelfRef.obi_addr_i 
                                                  >> 0xaU)))))) 
                        << 0x20U) | (QData)((IData)(
                                                    (vlSelfRef.__VdfgRegularize_hd87f99a1_1_0 
                                                     >> 5U)))));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U] 
            = (IData)(((((QData)((IData)((((IData)(vlSelfRef.obi_req_i) 
                                           << 0x1bU) 
                                          | (((IData)(vlSelfRef.obi_we_i) 
                                              << 0x1aU) 
                                             | (((IData)(vlSelfRef.obi_be_i) 
                                                 << 0x16U) 
                                                | (vlSelfRef.obi_addr_i 
                                                   >> 0xaU)))))) 
                         << 0x20U) | (QData)((IData)(
                                                     (vlSelfRef.__VdfgRegularize_hd87f99a1_1_0 
                                                      >> 5U)))) 
                       >> 0x20U));
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
            = ((0x20U & (vlSelfRef.obi_wdata_i << 5U)) 
               | (0x1fU & (vlSelfRef.obi_addr_i >> 5U)));
    } else {
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[0U] 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[0U];
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[1U] 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[1U];
        vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__mem_req[2U] 
            = vlSelfRef.conv1d_tb_wrapper__DOT__u_conv1d_obi__DOT__u_conv1d__DOT__int_mem_req[2U];
    }
}

void Vconv1d_tb_wrapper___024root___eval_triggers__act(Vconv1d_tb_wrapper___024root* vlSelf);

bool Vconv1d_tb_wrapper___024root___eval_phase__act(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval_phase__act\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vconv1d_tb_wrapper___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vconv1d_tb_wrapper___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vconv1d_tb_wrapper___024root___eval_phase__nba(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval_phase__nba\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vconv1d_tb_wrapper___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vconv1d_tb_wrapper___024root___dump_triggers__ico(Vconv1d_tb_wrapper___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vconv1d_tb_wrapper___024root___dump_triggers__nba(Vconv1d_tb_wrapper___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vconv1d_tb_wrapper___024root___dump_triggers__act(Vconv1d_tb_wrapper___024root* vlSelf);
#endif  // VL_DEBUG

void Vconv1d_tb_wrapper___024root___eval(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vconv1d_tb_wrapper___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/foss/designs/rtl/user_domain/conv1d/tb/conv1d_tb_wrapper.sv", 17, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vconv1d_tb_wrapper___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vconv1d_tb_wrapper___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/foss/designs/rtl/user_domain/conv1d/tb/conv1d_tb_wrapper.sv", 17, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vconv1d_tb_wrapper___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/foss/designs/rtl/user_domain/conv1d/tb/conv1d_tb_wrapper.sv", 17, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vconv1d_tb_wrapper___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vconv1d_tb_wrapper___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vconv1d_tb_wrapper___024root___eval_debug_assertions(Vconv1d_tb_wrapper___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconv1d_tb_wrapper___024root___eval_debug_assertions\n"); );
    Vconv1d_tb_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk_i & 0xfeU)))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.rst_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.obi_req_i & 0xfeU)))) {
        Verilated::overWidthError("obi_req_i");}
    if (VL_UNLIKELY(((vlSelfRef.obi_we_i & 0xfeU)))) {
        Verilated::overWidthError("obi_we_i");}
    if (VL_UNLIKELY(((vlSelfRef.obi_be_i & 0xf0U)))) {
        Verilated::overWidthError("obi_be_i");}
    if (VL_UNLIKELY(((vlSelfRef.reg_valid_i & 0xfeU)))) {
        Verilated::overWidthError("reg_valid_i");}
    if (VL_UNLIKELY(((vlSelfRef.reg_write_i & 0xfeU)))) {
        Verilated::overWidthError("reg_write_i");}
    if (VL_UNLIKELY(((vlSelfRef.reg_wstrb_i & 0xf0U)))) {
        Verilated::overWidthError("reg_wstrb_i");}
}
#endif  // VL_DEBUG
