module fsm_qalc (
  input  logic                                                       clk,
  input  logic                                                       reset,
  input  logic                                                       start_qalc,
  input  logic                                                       tc_cnt_branch,
  input  logic                                                       tc_cnt_fin,
  //inout logic [32:0] status2
  /* verilator lint_off UNUSED */
  /* verilator lint_off UNDRIVEN */
  input  conv1d_control_reg_pkg::conv1d_control_reg2hw_status1_reg_t status1,
  input  conv1d_control_reg_pkg::conv1d_control_reg2hw_status2_reg_t status2,
  output logic                                                       rst_cnt_fin,
  output logic                                                       rst_cnt_branch,
  output logic                                                       en_cnt_fin,
  output logic                                                       en_cnt_branch,
  output logic                                                       ld_reg_tmp,
  output logic                                                       ld_reg_branch,
  output logic                                                       ld_reg_partial,
  output logic                                                       rst_reg_partial,
  output logic                                                       done_qalc
);

  // State encoding
  typedef enum logic [2:0] {
    STATE_IDLE = 3'b000,
    STATE_A    = 3'b001,
    STATE_B    = 3'b010,
    STATE_C    = 3'b011,
    STATE_D    = 3'b100,
    STATE_E    = 3'b101
  } state_t;

  state_t current_state, next_state;

  // State transition logic
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      current_state <= STATE_IDLE;
    end else begin
      current_state <= next_state;
    end
  end

  // Next state logic
  always_comb begin
    case (current_state)
      STATE_IDLE: begin
        if (start_qalc == 1'b1) next_state = STATE_A;
        else next_state = STATE_IDLE;
      end
      STATE_A: begin
        if (tc_cnt_branch == 1'b1) next_state = STATE_B;
        else next_state = STATE_A;
      end
      STATE_B: begin
        if (status1.lego_number_din == 2'b00)
          next_state = STATE_C;  //if (status1.lego_number_weights == 2'b00) next_state = STATE_C;
        else next_state = STATE_D;
      end
      STATE_C: begin
        next_state = STATE_D;
      end
      STATE_D: begin
        if (tc_cnt_fin == 1'b1) next_state = STATE_E;
        else next_state = STATE_D;
      end
      STATE_E: begin
        next_state = STATE_IDLE;
      end
      default: next_state = STATE_IDLE;
    endcase
  end

  // Output logic
  always_comb begin
    // Default:
    done_qalc       = 1'b0;
    rst_cnt_branch  = 1'b1;
    rst_cnt_fin     = 1'b1;
    en_cnt_branch   = 1'b0;
    en_cnt_fin      = 1'b0;
    ld_reg_tmp      = 1'b0;
    ld_reg_branch   = 1'b0;
    ld_reg_partial  = 1'b0;
    rst_reg_partial = 1'b0;

    case (current_state)
      STATE_IDLE: begin
        rst_cnt_branch = 1'b1;
        rst_cnt_fin    = 1'b1;
        en_cnt_branch  = 1'b0;
        en_cnt_fin     = 1'b0;
        ld_reg_tmp     = 1'b0;
        ld_reg_branch  = 1'b0;
        ld_reg_partial = 1'b0;
        done_qalc      = done_qalc;
      end
      STATE_A: begin
        done_qalc      = 1'b0;
        rst_cnt_branch = 1'b0;
        en_cnt_branch  = 1'b1;
        ld_reg_tmp     = 1'b1;
      end
      STATE_B: begin
        ld_reg_tmp     = 1'b0;
        ld_reg_branch  = 1'b1;
        en_cnt_branch  = 1'b0;
        rst_cnt_branch = 1'b1;
      end
      STATE_C: begin
        rst_reg_partial = 1'b1;
      end
      STATE_D: begin
        rst_cnt_branch  = 1'b0;
        ld_reg_branch   = 1'b0;
        rst_reg_partial = 1'b0;
        rst_cnt_fin     = 1'b0;
        en_cnt_fin      = 1'b1;
        ld_reg_partial  = 1'b1;
      end
      STATE_E: begin
        en_cnt_fin     = 1'b0;
        rst_cnt_fin    = 1'b1;
        ld_reg_partial = 1'b0;
        done_qalc      = 1'b1;
      end
      default: begin
        done_qalc       = 1'b0;
        rst_cnt_branch  = 1'b1;
        rst_cnt_fin     = 1'b1;
        en_cnt_branch   = 1'b0;
        en_cnt_fin      = 1'b0;
        ld_reg_tmp      = 1'b0;
        ld_reg_branch   = 1'b0;
        ld_reg_partial  = 1'b0;
        rst_reg_partial = 1'b0;
      end
    endcase
  end

endmodule
