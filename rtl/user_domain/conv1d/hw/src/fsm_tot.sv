module fsm_tot (
  input logic        clk,
  input logic        reset,
  input logic        done_qalc,
  //input logic [31:0] control,
  /* verilator lint_off UNUSED */
  /* verilator lint_off UNDRIVEN */
  //input  conv1d_control_reg_pkg::conv1d_control_reg2hw_control_reg_t        control,
  input logic [31:0] reg_partial_out,
  //inout logic [31:0] status1,
  //input  conv1d_control_reg_pkg::conv1d_control_reg2hw_reg2hw.status1eg_t        reg2hw.status1,
  //inout logic [31:0] status2,
  //input  conv1d_control_reg_pkg::conv1d_control_reg2hw_reg2hw.status2eg_t        reg2hw.status2,
  //output conv1d_control_reg_pkg::conv1d_control_hw2reg_reg2hw.status1eg_t        status1,
  //output conv1d_control_reg_pkg::conv1d_control_hw2reg_reg2hw.status2eg_t        status2,

  input  conv1d_control_reg_pkg::conv1d_control_reg2hw_t reg2hw,
  output conv1d_control_reg_pkg::conv1d_control_hw2reg_t hw2reg,

  output conv1d_sram_pkg::sram_req_t reqq,

  output logic       grant,
  output logic [4:0] ld_reg_weight,
  output logic [4:0] ld_reg_din,
  output logic [4:0] rst_reg_din,
  output logic       start_qalc
);

  import conv1d_sram_pkg::*;
  import conv1d_control_reg_pkg::*;
  import conv1d_reg_pkg::*;

  typedef enum logic [4:0] {
    STATE_IDLE,
    STATE_A,
    STATE_B,
    STATE_C,
    STATE_D,
    STATE_E,
    STATE_F,
    STATE_G,
    STATE_H,
    STATE_I,
    STATE_J,
    STATE_K,
    STATE_L,
    STATE_M,
    STATE_N,
    STATE_O,
    STATE_P,
    STATE_Q,
    STATE_R,
    STATE_S,
    STATE_T1,
    STATE_T2,
    STATE_U,
    STATE_V,
    STATE_W,
    STATE_X,
    STATE_Y,
    STATE_Z
  } state_t;

  state_t current_state, next_state;

  // State transition logic
  always_ff @(posedge clk or posedge reset) begin
    if (reset) current_state <= STATE_IDLE;
    else current_state <= next_state;
  end

  // Next state logic
  always_comb begin
    case (current_state)
      STATE_IDLE: begin
        if (reg2hw.control.start == 1'b1) next_state = STATE_A;
        else next_state = STATE_IDLE;
      end
      STATE_A: begin
        if (reg2hw.control.loaded_flag == 1'b1) next_state = STATE_B;
        else next_state = STATE_A;
      end
      STATE_B: begin
        next_state = STATE_C;
      end
      STATE_C: begin
        next_state = STATE_D;
      end
      STATE_D: begin
        next_state = STATE_E;
      end
      STATE_E: begin
        next_state = STATE_F;
      end
      STATE_F: begin
        next_state = STATE_G;
      end
      STATE_G: begin
        next_state = STATE_H;
      end
      STATE_H: begin
        next_state = STATE_I;
      end
      STATE_I: begin
        next_state = STATE_J;
      end
      STATE_J: begin
        next_state = STATE_K;
      end
      STATE_K: begin
        next_state = STATE_L;
      end
      STATE_L: begin
        if (reg2hw.status1.data_number_sram == 3'd6) 
          if (reg2hw.status2.dout_address >= 8'd126) 
            if (reg2hw.status2.dout_address == 8'd127) next_state = STATE_Y;
            else next_state = STATE_Z;
          else next_state = STATE_M;
        else next_state = STATE_M;
      end
      STATE_M: begin
        if (reg2hw.status2.din_address > 8'd87) next_state = STATE_X;
        else next_state = STATE_W;
      end
      STATE_W: begin
        next_state = STATE_N;
      end
      STATE_X: begin
        next_state = STATE_N;
      end
      STATE_N: begin
        if (done_qalc == 1'b1) next_state = STATE_O;
        else next_state = STATE_N;
      end
      STATE_O: begin
        if (reg2hw.status1.lego_number_weights == 2'b00) next_state = STATE_P;
        else next_state = STATE_B;
      end
      STATE_P: begin
        next_state = STATE_Q;
      end
      STATE_Q: begin
        next_state = STATE_R;
      end
      STATE_R: begin
        next_state = STATE_S;
      end
      STATE_S: begin
        if (reg2hw.status1.data_number_sram == 3'd6)
          if (reg2hw.status2.dout_address == 8'd128) next_state = STATE_T2;
          else next_state = STATE_B;
        else
          if (reg2hw.status2.dout_address == 8'd126) next_state = STATE_T1;
          else next_state = STATE_B;
      end
      STATE_T1: begin
        if (reg2hw.status1.data_number_sram == 3'd6)
          if (reg2hw.status1.filter_number_sram == 3'd7) next_state = STATE_V;
          else next_state = STATE_U;
        else next_state = STATE_A;
      end
      STATE_T2: begin
        if (reg2hw.status1.data_number_sram == 3'd6)
          if (reg2hw.status1.filter_number_sram == 3'd7) next_state = STATE_V;
          else next_state = STATE_U;
        else next_state = STATE_A;
      end
      STATE_U: begin
        next_state = STATE_A;
      end
      STATE_V: begin
        next_state = STATE_IDLE;
      end
      STATE_Y: begin
        if (reg2hw.status2.din_address > 8'd87) next_state = STATE_X;
        else next_state = STATE_W;
      end
      STATE_Z: begin
        if (reg2hw.status2.din_address > 8'd87) next_state = STATE_X;
        else next_state = STATE_W;
      end
      default: next_state = STATE_IDLE;
    endcase
  end

  // Output logic
  always_comb begin
    // Default:

    //hw2reg.status1.done.de=1'b1;
    hw2reg.status1.done.d = 1'b0;

    //hw2reg.status1.accelerator_using_sram.de=1'b1;
    hw2reg.status1.accelerator_using_sram.d = 1'b0;

    //hw2reg.status1.reload_flag.de=1'b1;
    hw2reg.status1.reload_flag.d = 1'b0;

    //hw2reg.status1.done_filter.de=1'b1;
    hw2reg.status1.done_filter.d = 1'b0;

    //hw2reg.status1.filter_number_sram.de=1'b1;
    hw2reg.status1.filter_number_sram.d = 3'b000;

    //hw2reg.status1.data_number_sram.de=1'b1;
    hw2reg.status1.data_number_sram.d = 3'b000;

    //hw2reg.status1.lego_number_din.de=1'b1;
    hw2reg.status1.lego_number_din.d = 2'b00;

    //hw2reg.status1.lego_number_weights.de=1'b1;
    hw2reg.status1.lego_number_weights.d = 2'b00;

    //hw2reg.status1.lego_tower_din.de=1'b1;
    hw2reg.status1.lego_tower_din.d = 5'd0;

    //hw2reg.status2.din_address.de=1'b1;
    hw2reg.status2.din_address.d = 8'd20;  // at reqq.address 20 is stored the first input sample

    //hw2reg.status2.dout_address.de=1'b1;
    hw2reg.status2.dout_address.d= 8'd108;  // at reqq.address 108 is stored the first output sample

    //hw2reg.status2.weight_address.de=1'b1;
    hw2reg.status2.weight_address.d = 8'd0;

    grant = 1'b1;  // default: SRAM connected to host
    ld_reg_weight = '0;
    ld_reg_din = '0;
    rst_reg_din = '0;
    start_qalc = 1'b0;
  

    reqq.req = 1'b0;
    reqq.we = 1'b0;
    reqq.wdata = '0;
    reqq.be = 4'hf;

    case (current_state)
      STATE_IDLE: begin
        hw2reg.status1.done.de = 1'b0;
        hw2reg.status1.done.d = 1'b0;

        hw2reg.status1.accelerator_using_sram.de = 1'b1;
        hw2reg.status1.accelerator_using_sram.d = 1'b0;

        hw2reg.status1.reload_flag.de = 1'b1;
        hw2reg.status1.reload_flag.d = 1'b0;

        hw2reg.status1.done_filter.de = 1'b1;
        hw2reg.status1.done_filter.d = 1'b0;

        hw2reg.status1.filter_number_sram.de = 1'b1;
        hw2reg.status1.filter_number_sram.d = 3'b000;

        hw2reg.status1.data_number_sram.de = 1'b1;
        hw2reg.status1.data_number_sram.d = 3'b000;

        hw2reg.status1.lego_number_din.de = 1'b1;
        hw2reg.status1.lego_number_din.d = 2'b00;

        hw2reg.status1.lego_number_weights.de = 1'b1;
        hw2reg.status1.lego_number_weights.d = 2'b00;

        hw2reg.status1.lego_tower_din.de = 1'b1;
        hw2reg.status1.lego_tower_din.d = 5'd0;

        hw2reg.status2.din_address.de = 1'b1;
        hw2reg.status2.din_address.d = 8'd20;  // at req.address 20 is stored the first input sample

        hw2reg.status2.dout_address.de = 1'b1;
        hw2reg.status2.dout_address.d= 8'd108;  // at req.address 108 is stored the first output sample

        hw2reg.status2.weight_address.de = 1'b1;
        hw2reg.status2.weight_address.d = 8'd0;  // at 

        grant = 1'b1;  // default: SRAM connected to host
        ld_reg_weight = '0;
        ld_reg_din = '0;
        start_qalc = 1'b0;
        rst_reg_din = '0;

        reqq.req = 1'b0;
        reqq.we = 1'b0;
        reqq.wdata = '0;
        reqq.be = 4'hf;
        reqq.addr[7:0] = reg2hw.status2.weight_address;
      end

      STATE_A: begin

        hw2reg.status1.running.de                = 1'b0;

        hw2reg.status1.done.de                   = 1'b1;
        hw2reg.status1.done.d                    = 1'b0;

        hw2reg.status1.accelerator_using_sram.de = 1'b0;

        hw2reg.status1.reload_flag.de            = 1'b1;
        hw2reg.status1.reload_flag.d             = 1'b1;

        hw2reg.status1.done_calculation.de       = 1'b1;
        hw2reg.status1.done_filter.de            = 1'b0;

        hw2reg.status1.filter_number_sram.de     = 1'b0;
        hw2reg.status1.data_number_sram.de       = 1'b0;
        hw2reg.status1.lego_number_din.de        = 1'b0;
        hw2reg.status1.lego_number_weights.de    = 1'b0;
        hw2reg.status1.lego_tower_din.de         = 1'b0;
        hw2reg.status2.din_address.de            = 1'b0;
        hw2reg.status2.dout_address.de           = 1'b0;
        hw2reg.status2.weight_address.de         = 1'b0;

        grant                                    = 1'b1;
        reqq.addr[7:0]                           = reg2hw.status2.weight_address;
      end
      STATE_B: begin
 
        hw2reg.status1.accelerator_using_sram.de = 1'b1;
        hw2reg.status1.accelerator_using_sram.d  = 1'b1;

        hw2reg.status1.reload_flag.de            = 1'b1;
        hw2reg.status1.reload_flag.d             = 1'b0;

        grant                                    = 1'b0;
        reqq.req                                 = 1'b1;
        reqq.we                                  = 1'b0;
        reqq.addr[7:0]                           = reg2hw.status2.weight_address;
        hw2reg.status1.lego_number_din.de       = 1'b0;
        hw2reg.status2.weight_address.de         = 1'b1;
        hw2reg.status2.weight_address.d          = reg2hw.status2.weight_address + 1;
      end
      STATE_C: begin

        ld_reg_weight[0]                 = 1'b1;
        grant                            = 1'b0;
        reqq.req                         = 1'b1;
        reqq.we                          = 1'b0;
        reqq.addr[7:0]                   = reg2hw.status2.weight_address;

        hw2reg.status2.weight_address.de = 1'b1;
        hw2reg.status2.weight_address.d  = reg2hw.status2.weight_address + 1;
      end
      STATE_D: begin
        ld_reg_weight[1:0]               = 2'b10;
        hw2reg.status2.weight_address.de = 1'b1;
        hw2reg.status2.weight_address.d  = reg2hw.status2.weight_address + 1;
        grant                            = 1'b0;
        reqq.req                         = 1'b1;
        reqq.we                          = 1'b0;
        reqq.addr[7:0]                   = reg2hw.status2.weight_address;
      end
      STATE_E: begin
        ld_reg_weight[2:1]               = 2'b10;
        hw2reg.status2.weight_address.de = 1'b1;
        hw2reg.status2.weight_address.d  = reg2hw.status2.weight_address + 1;
        grant                            = 1'b0;
        reqq.req                         = 1'b1;
        reqq.we                          = 1'b0;
        reqq.addr[7:0]                   = reg2hw.status2.weight_address;
      end
      STATE_F: begin
        ld_reg_weight[3:2]               = 2'b10;
        hw2reg.status2.weight_address.de = 1'b1;
        hw2reg.status2.weight_address.d  = reg2hw.status2.weight_address + 1;
        grant                            = 1'b0;
        reqq.req                         = 1'b1;
        reqq.addr[7:0]                   = reg2hw.status2.weight_address;
      end
      STATE_G: begin
        ld_reg_weight[4:3]               = 2'b10;
        hw2reg.status2.weight_address.de = 1'b0;
        hw2reg.status2.weight_address.d  = reg2hw.status2.weight_address + 1;

        reqq.req                         = 1'b1;
        reqq.addr[7:0]                   = reg2hw.status2.din_address;
        grant                            = 1'b0;
      end
      STATE_H: begin
        hw2reg.status2.weight_address.de      = 1'b0;
        ld_reg_weight[4]                      = 1'b0;

        hw2reg.status1.lego_number_weights.de = 1'b1;
        hw2reg.status1.lego_number_weights.d  = reg2hw.status1.lego_number_weights + 1;

        reqq.req                              = 1'b1;
        reqq.addr[7:0]                        = reg2hw.status2.din_address;
        //ld_reg_din[0] = 1'b1;
        grant                                 = 1'b0;

        hw2reg.status2.din_address.de         = 1'b1;
        hw2reg.status2.din_address.d          = reg2hw.status2.din_address + 1;
      end
      STATE_I: begin
        hw2reg.status1.lego_number_weights.de = 1'b0;
        ld_reg_din[0]                         = 1'b1;
        reqq.req                              = 1'b1;
        reqq.addr[7:0]                        = reg2hw.status2.din_address;
        hw2reg.status2.din_address.de         = 1'b1;
        hw2reg.status2.din_address.d          = reg2hw.status2.din_address + 1;
        grant                                 = 1'b0;
      end
      STATE_J: begin
        ld_reg_din[1:0]               = 2'b10;
        reqq.req                      = 1'b1;
        reqq.addr[7:0]                = reg2hw.status2.din_address;
        hw2reg.status2.din_address.de = 1'b1;
        hw2reg.status2.din_address.d  = reg2hw.status2.din_address + 1;
        grant                         = 1'b0;
      end
      STATE_K: begin
        ld_reg_din[2:1]               = 2'b10;
        hw2reg.status2.din_address.de = 1'b1;
        hw2reg.status2.din_address.d  = reg2hw.status2.din_address + 1;
        reqq.req                      = 1'b1;
        reqq.addr[7:0]                = reg2hw.status2.din_address;
        grant                         = 1'b0;
      end
      STATE_L: begin
        ld_reg_din[3:2]               = 2'b10;
        hw2reg.status2.din_address.de = 1'b0;
        hw2reg.status2.din_address.d  = reg2hw.status2.din_address + 1;
        reqq.req                      = 1'b1;
        reqq.addr[7:0]                = reg2hw.status2.din_address;
        grant                         = 1'b0;
      end
      STATE_M: begin
        ld_reg_din[4:3]                  = 2'b10;

        reqq.req                         = 1'b0;
        grant                            = 1'b1;
      end
      STATE_Z: begin
        ld_reg_din[4] = 1'b0;
        rst_reg_din[4] = 1'b1;
      end
      STATE_Y: begin
        ld_reg_din[4] = 1'b0;
        rst_reg_din[4:3] = 2'b11;
      end
      STATE_W: begin
        hw2reg.status2.din_address.de = 1'b1;
        hw2reg.status1.lego_number_din.de    = 1'b0;
        hw2reg.status2.din_address.d  = reg2hw.status2.din_address + 18;
        rst_reg_din = '0;
      end
      STATE_X: begin
        hw2reg.status1.lego_number_din.de    = 1'b0;
        hw2reg.status2.din_address.de = 1'b1;
        hw2reg.status2.din_address.d  = reg2hw.status2.din_address - 69;
        rst_reg_din = '0;
      end
      STATE_N: begin
        hw2reg.status2.din_address.de = 1'b0;
        ld_reg_din[4]                 = 1'b0;
        start_qalc                    = 1'b1;
      end
      STATE_O: begin
        start_qalc = 1'b0;
                hw2reg.status1.lego_number_din.de    = 1'b1;
        hw2reg.status1.lego_number_din.d = reg2hw.status1.lego_number_din + 1;
      end
      STATE_P: begin
                hw2reg.status1.lego_number_din.de    = 1'b0;
        hw2reg.status1.lego_tower_din.de = 1'b1;
        hw2reg.status1.lego_tower_din.d  = reg2hw.status1.lego_tower_din + 1;
        hw2reg.status2.weight_address.de = 1'b1;
        hw2reg.status2.weight_address.d  = 8'd0;  // reset initial value for weight_address
      end
      STATE_Q: begin
        hw2reg.status1.lego_tower_din.de = 1'b0;
        hw2reg.status2.weight_address.de = 1'b0;

        grant                            = 1'b0;
        reqq.req                         = 1'b1;
        reqq.we                          = 1'b1;
        reqq.addr[7:0]                   = reg2hw.status2.dout_address;
        reqq.wdata                       = reg_partial_out;
        reqq.be                          = 4'hf;
      end
      STATE_R: begin
        hw2reg.status2.dout_address.de = 1'b1;
        hw2reg.status2.dout_address.d  = reg2hw.status2.dout_address + 1;
        grant                          = 1'b0;
        reqq.req                       = 1'b1;
        reqq.we                        = 1'b1;
        reqq.addr[7:0]                 = reg2hw.status2.dout_address;
        reqq.wdata                     = reg_partial_out;
        reqq.be                        = 4'hf;
      end
      STATE_S: begin
        hw2reg.status2.dout_address.de = 1'b0;
        reqq.req                       = 1'b0;
        reqq.we                        = 1'b0;
        grant                          = 1'b1;
      
      end
      STATE_T1: begin
        
        hw2reg.status1.data_number_sram.de = 1'b1;
        hw2reg.status1.data_number_sram.d  = reg2hw.status1.data_number_sram + 1;
        hw2reg.status2.din_address.de      = 1'b1;
        hw2reg.status2.din_address.d       = 8'd20;
        hw2reg.status2.dout_address.de     = 1'b1;
        hw2reg.status2.dout_address.d      = 8'd108;
        hw2reg.status2.weight_address.de   = 1'b1;
        hw2reg.status2.weight_address.d    = 8'd0;
      end
      STATE_T2: begin
        
        hw2reg.status1.data_number_sram.de = 1'b1;
        hw2reg.status1.data_number_sram.d  = 3'b000;
        hw2reg.status2.din_address.de      = 1'b1;
        hw2reg.status2.din_address.d       = 8'd20;
        hw2reg.status2.dout_address.de     = 1'b1;
        hw2reg.status2.dout_address.d      = 8'd108;
        hw2reg.status2.weight_address.de   = 1'b1;
        hw2reg.status2.weight_address.d    = 8'd0;
      end
      STATE_U: begin
        hw2reg.status1.data_number_sram.de   = 1'b0;
        hw2reg.status2.din_address.de        = 1'b0;
        hw2reg.status2.dout_address.de       = 1'b0;
        hw2reg.status2.weight_address.de     = 1'b0;

        hw2reg.status1.filter_number_sram.de = 1'b1;
        hw2reg.status1.filter_number_sram.d  = reg2hw.status1.filter_number_sram + 1;
        hw2reg.status1.done_filter.de        = 1'b1;
        hw2reg.status1.done_filter.d         = 1'b1;
      end
      STATE_V: begin
        hw2reg.status1.done.de             = 1'b1;
        hw2reg.status1.done.d              = 1'b1;

        hw2reg.status1.data_number_sram.de = 1'b0;
        hw2reg.status2.din_address.de      = 1'b0;
        hw2reg.status2.dout_address.de     = 1'b0;
        hw2reg.status2.weight_address.de   = 1'b0;
      end
      default: begin
        hw2reg.status1.done.d = 1'b0;
        hw2reg.status1.accelerator_using_sram.d = 1'b0;
        hw2reg.status1.reload_flag.d = 1'b0;
        hw2reg.status1.done_filter.d = 1'b0;
        hw2reg.status1.filter_number_sram.d = 3'b000;
        hw2reg.status1.data_number_sram.d = 3'b000;
        hw2reg.status1.lego_number_din.d = 2'b00;
        hw2reg.status1.lego_number_weights.d = 2'b00;
        hw2reg.status1.lego_tower_din.d = 5'd0;
        hw2reg.status2.din_address.d= 8'd20;  // at reqq.address 20 is stored the first input sample
        hw2reg.status2.dout_address.d= 8'd108;  // at reqq.address 108 is stored the first output sample
        hw2reg.status2.weight_address.d = 8'd0;
        grant = 1'b1;
        ld_reg_weight = '0;
        ld_reg_din = '0;
        start_qalc = 1'b0;
      end
    endcase
  end
endmodule
