module datapath #(
) (
  input  logic        clk,
  //Input CU
  input  logic [ 4:0] ld_reg_din,
  input  logic [ 4:0] rst_reg_din,
  input  logic [ 4:0] ld_reg_weight,
  input  logic        en_tmp,
  input  logic        rst_cnt_sel_in,
  input  logic        rst_cnt_sel_add_fin,
  input  logic        en_cnt_sel_in,
  input  logic        en_cnt_sel_add_fin,
  input  logic        en_reg_branch,
  input  logic        en_partial,
  input  logic        rst_partial,
  //Input memory
  input  logic [31:0] in_memory,
  //Output CU
  output logic        tc_cnt_sel_in,
  output logic        tc_cnt_sel_add_fin,
  //Output memory
  output logic [31:0] misa
);

  //Signal definition
  //Branches
  logic [ 7:0] in_branch1;
  logic [ 7:0] in_branch2;
  logic [ 7:0] in_branch3;
  logic [ 7:0] in_branch4;
  logic [31:0] out_branch1;
  logic [31:0] out_branch2;
  logic [31:0] out_branch3;
  logic [31:0] out_branch4;
  //Counter
  logic [ 2:0] count_cnt_in;
  logic [ 1:0] count_cnt_add_fin;
  //Accumulator
  logic [31:0] out_accumulator1;
  logic [31:0] out_accumulator2;
  logic [31:0] out_accumulator3;
  logic [31:0] out_accumulator4;

  //Assign branches input
  assign in_branch1 = in_memory[31:24];
  assign in_branch2 = in_memory[23:16];
  assign in_branch3 = in_memory[15:8];
  assign in_branch4 = in_memory[7:0];

  //Component instantiation
  //Counter
  downcounter_3bit #() cnt_sel_in (
    .clk  (clk),
    .rst  (rst_cnt_sel_in),
    .en   (en_cnt_sel_in),
    .tc   (tc_cnt_sel_in),
    .count(count_cnt_in)
  );
  upcounter_2bit #() cnt_sel_add_fin (
    .clk  (clk),
    .rst  (rst_cnt_sel_add_fin),
    .en   (en_cnt_sel_add_fin),
    .tc   (tc_cnt_sel_add_fin),
    .count(count_cnt_add_fin)
  );
  //Branches
  branch #(
    .WIDTH(8)
  ) branch1 (
    .clk       (clk),
    .ld_data   (ld_reg_din),
    .rst_data  (rst_reg_din),
    .ld_weight (ld_reg_weight),
    .sel       (count_cnt_in),
    .in_branch (in_branch1),
    .out_branch(out_branch1)
  );
  branch #(
    .WIDTH(8)
  ) branch2 (
    .clk       (clk),
    .ld_data   (ld_reg_din),
    .rst_data  (rst_reg_din),
    .ld_weight (ld_reg_weight),
    .sel       (count_cnt_in),
    .in_branch (in_branch2),
    .out_branch(out_branch2)
  );
  branch #(
    .WIDTH(8)
  ) branch3 (
    .clk       (clk),
    .ld_data   (ld_reg_din),
    .rst_data  (rst_reg_din),
    .ld_weight (ld_reg_weight),
    .sel       (count_cnt_in),
    .in_branch (in_branch3),
    .out_branch(out_branch3)
  );
  branch #(
    .WIDTH(8)
  ) branch4 (
    .clk       (clk),
    .ld_data   (ld_reg_din),
    .rst_data  (rst_reg_din),
    .ld_weight (ld_reg_weight),
    .sel       (count_cnt_in),
    .in_branch (in_branch4),
    .out_branch(out_branch4)
  );
  //Accumlators
  accumulator #(
    .WIDTH(32)
  ) accumulator1 (
    .clk      (clk),
    .sel      (count_cnt_in[2]),
    .ld_tmp   (en_tmp),
    .ld_branch(en_reg_branch),
    .din      (out_branch1),
    .dout     (out_accumulator1)
  );
  accumulator #(
    .WIDTH(32)
  ) accumulator2 (
    .clk      (clk),
    .sel      (count_cnt_in[2]),
    .ld_tmp   (en_tmp),
    .ld_branch(en_reg_branch),
    .din      (out_branch2),
    .dout     (out_accumulator2)
  );
  accumulator #(
    .WIDTH(32)
  ) accumulator3 (
    .clk      (clk),
    .sel      (count_cnt_in[2]),
    .ld_tmp   (en_tmp),
    .ld_branch(en_reg_branch),
    .din      (out_branch3),
    .dout     (out_accumulator3)
  );
  accumulator #(
    .WIDTH(32)
  ) accumulator4 (
    .clk      (clk),
    .sel      (count_cnt_in[2]),
    .ld_tmp   (en_tmp),
    .ld_branch(en_reg_branch),
    .din      (out_branch4),
    .dout     (out_accumulator4)
  );
  //Final sum
  final_sum #(
    .WIDTH(32)
  ) francesca (
    .clk        (clk),
    .ld_partial (en_partial),
    .rst_partial(rst_partial),
    .sel        (count_cnt_add_fin),
    .in_branch1 (out_accumulator1),
    .in_branch2 (out_accumulator2),
    .in_branch3 (out_accumulator3),
    .in_branch4 (out_accumulator4),
    .dout       (misa)
  );
endmodule
