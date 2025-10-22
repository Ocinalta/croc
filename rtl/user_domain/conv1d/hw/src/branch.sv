module branch #(
  parameter WIDTH = 8
) (
  input  logic               clk,
  input  logic [        4:0] ld_data,
  input  logic [        4:0] rst_data,
  input  logic [        4:0] ld_weight,
  input  logic [        2:0] sel,
  input  logic [  WIDTH-1:0] in_branch,
  output logic [4*WIDTH-1:0] out_branch
);

  //Signal definition
  //Data signals
  logic [WIDTH-1:0] reg_data0_out;
  logic [WIDTH-1:0] reg_data1_out;
  logic [WIDTH-1:0] reg_data2_out;
  logic [WIDTH-1:0] reg_data3_out;
  logic [WIDTH-1:0] reg_data4_out;
  //Weight signals
  logic [WIDTH-1:0] reg_weight0_out;
  logic [WIDTH-1:0] reg_weight1_out;
  logic [WIDTH-1:0] reg_weight2_out;
  logic [WIDTH-1:0] reg_weight3_out;
  logic [WIDTH-1:0] reg_weight4_out;
  //Multiplexer signals
  logic [WIDTH-1:0] mux_data_out;
  logic [WIDTH-1:0] mux_weight_out;

  //Component instantiation
  //Data registers
  register #(
    .WIDTH(WIDTH)
  ) reg_data0 (
    .load(ld_data[0]),
    .rst (rst_data[0]),
    .clk (clk),
    .din (in_branch),
    .dout(reg_data0_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_data1 (
    .load(ld_data[1]),
    .rst (rst_data[1]),
    .clk (clk),
    .din (in_branch),
    .dout(reg_data1_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_data2 (
    .load(ld_data[2]),
    .rst (rst_data[2]),
    .clk (clk),
    .din (in_branch),
    .dout(reg_data2_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_data3 (
    .load(ld_data[3]),
    .rst (rst_data[3]),
    .clk (clk),
    .din (in_branch),
    .dout(reg_data3_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_data4 (
    .load(ld_data[4]),
    .rst (rst_data[4]),
    .clk (clk),
    .din (in_branch),
    .dout(reg_data4_out)
  );
  //Weigth registers
  register #(
    .WIDTH(WIDTH)
  ) reg_weight0 (
    .load(ld_weight[0]),
    .rst (1'b0),
    .clk (clk),
    .din (in_branch),
    .dout(reg_weight0_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_weight1 (
    .load(ld_weight[1]),
    .rst (1'b0),
    .clk (clk),
    .din (in_branch),
    .dout(reg_weight1_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_weight2 (
    .load(ld_weight[2]),
    .rst (1'b0),
    .clk (clk),
    .din (in_branch),
    .dout(reg_weight2_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_weight3 (
    .load(ld_weight[3]),
    .rst (1'b0),
    .clk (clk),
    .din (in_branch),
    .dout(reg_weight3_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_weight4 (
    .load(ld_weight[4]),
    .rst (1'b0),
    .clk (clk),
    .din (in_branch),
    .dout(reg_weight4_out)
  );
  //Multiplexer 5-to-1
  mux5to1 #(
    .WIDTH(WIDTH)
  ) mux_data (
    .sel (sel),
    .din1(reg_data0_out),
    .din2(reg_data1_out),
    .din3(reg_data2_out),
    .din4(reg_data3_out),
    .din5(reg_data4_out),
    .dout(mux_data_out)
  );
  mux5to1 #(
    .WIDTH(WIDTH)
  ) mux_weight (
    .sel (sel),
    .din1(reg_weight0_out),
    .din2(reg_weight1_out),
    .din3(reg_weight2_out),
    .din4(reg_weight3_out),
    .din5(reg_weight4_out),
    .dout(mux_weight_out)
  );
  //Multiplier
  multiplier #(
    .WIDTH(WIDTH)
  ) mult (
    .mult1(mux_data_out),
    .mult2(mux_weight_out),
    .prod (out_branch)
  );
endmodule
