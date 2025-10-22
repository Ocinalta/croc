module accelerator #(
) (
  input logic clk,
  input logic reset_ni,
  //input logic [31:0] control,
  //inout logic [31:0] status1,
  //inout logic [31:0] status2,

  //input conv1d_control_reg_pkg::conv1d_control_reg2hw_control_reg_t control,
  //input conv1d_control_reg_pkg::conv1d_control_reg2hw_status1_reg_t status1,
  //input conv1d_control_reg_pkg::conv1d_control_reg2hw_status2_reg_t status2,
  //output conv1d_control_reg_pkg::conv1d_control_hw2reg_status1_reg_t status1_o,
  //output conv1d_control_reg_pkg::conv1d_control_hw2reg_status2_reg_t status2_o,
  input  conv1d_control_reg_pkg::conv1d_control_reg2hw_t reg2hw,
  output conv1d_control_reg_pkg::conv1d_control_hw2reg_t hw2reg,

  // signals for memory interface: 
  output conv1d_sram_pkg::sram_req_t req,
  input  conv1d_sram_pkg::sram_rsp_t rsp,
  output logic                       grant
);

  import conv1d_control_reg_pkg::*;
  import conv1d_sram_pkg::*;

  //    import conv1d_reg_pkg::*;
  //    import conv1d_control_reg_pkg::*;
  // Signals to connect the components
  logic        start_qalc;
  logic        tc_cnt_branch;
  logic        tc_cnt_fin;
  logic        rst_cnt_fin;
  logic        rst_cnt_branch;
  logic        en_cnt_fin;
  logic        en_cnt_branch;
  logic        ld_reg_tmp;
  logic        ld_reg_branch;
  logic        ld_reg_partial;
  logic        rst_reg_partial;
  logic        done_qalc;
  logic [31:0] reg_partial_out;
  logic [ 4:0] ld_reg_weight;
  logic [ 4:0] ld_reg_din;
  logic [4:0]  rst_reg_din;
  logic        reset;

  assign reset = ~reset_ni;

  // Instantiate fsm_qalc
  fsm_qalc u_fsm_qalc (
    .clk            (clk),
    .reset          (reset),
    .start_qalc     (start_qalc),
    .tc_cnt_branch  (tc_cnt_branch),
    .tc_cnt_fin     (tc_cnt_fin),
    .status1        (reg2hw.status1),
    .status2        (reg2hw.status2),
    .rst_cnt_fin    (rst_cnt_fin),
    .rst_cnt_branch (rst_cnt_branch),
    .en_cnt_fin     (en_cnt_fin),
    .en_cnt_branch  (en_cnt_branch),
    .ld_reg_tmp     (ld_reg_tmp),
    .ld_reg_branch  (ld_reg_branch),
    .ld_reg_partial (ld_reg_partial),
    .rst_reg_partial(rst_reg_partial),
    .done_qalc      (done_qalc)
  );

  // Instantiate fsm_tot
  fsm_tot u_fsm_tot (
    .clk            (clk),
    .reset          (reset),
    .done_qalc      (done_qalc),
    //.control        (reg2hw.control),
    .reg_partial_out(reg_partial_out),
    //.status1_r      (reg2hw.status1),
    //.status2_r      (reg2hw.status2),
    //.status1        (hw2reg.status1),
    //.status2        (hw2reg.status2),
    .reg2hw         (reg2hw),
    .hw2reg         (hw2reg),
    .reqq           (req),
    .grant          (grant),
    .ld_reg_weight  (ld_reg_weight),
    .ld_reg_din     (ld_reg_din),
    .rst_reg_din    (rst_reg_din),
    .start_qalc     (start_qalc)
  );

  // Instantiate datapath
  datapath u_datapath (
    .clk                (clk),
    .ld_reg_din         (ld_reg_din),
    .rst_reg_din        (rst_reg_din),
    .ld_reg_weight      (ld_reg_weight),
    .en_tmp             (ld_reg_tmp),
    .rst_cnt_sel_in     (rst_cnt_branch),
    .rst_cnt_sel_add_fin(rst_cnt_fin),
    .en_cnt_sel_in      (en_cnt_branch),
    .en_cnt_sel_add_fin (en_cnt_fin),
    .en_reg_branch      (ld_reg_branch),
    .en_partial         (ld_reg_partial),
    .rst_partial        (rst_reg_partial),
    .in_memory          (rsp.rdata),
    .tc_cnt_sel_in      (tc_cnt_branch),
    .tc_cnt_sel_add_fin (tc_cnt_fin),
    .misa               (reg_partial_out)
  );

endmodule
