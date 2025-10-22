module final_sum #(
  parameter WIDTH = 32
) (
  input  logic             clk,
  input  logic             ld_partial,
  input  logic             rst_partial,
  input  logic [      1:0] sel,
  input  logic [WIDTH-1:0] in_branch1,
  input  logic [WIDTH-1:0] in_branch2,
  input  logic [WIDTH-1:0] in_branch3,
  input  logic [WIDTH-1:0] in_branch4,
  output logic [WIDTH-1:0] dout
);

  //Signal definition
  //Multiplexer signal
  logic [WIDTH-1:0] mux_final_out;
  //Adder signal
  logic [WIDTH-1:0] add_tot_out;
  //Register signal
  logic [WIDTH-1:0] reg_partial_out;


  //Component instantiation
  //Multiplexer
  mux4to1 #(
    .WIDTH(WIDTH)
  ) mux_final (
    .sel (sel),
    .din1(in_branch1),
    .din2(in_branch2),
    .din3(in_branch3),
    .din4(in_branch4),
    .dout(mux_final_out)
  );
  //Adder
  adder #(
    .WIDTH(WIDTH)
  ) add_tot (
    .add1(mux_final_out),
    .add2(reg_partial_out),
    .sum (add_tot_out)
  );
  //Register
  register #(
    .WIDTH(WIDTH)
  ) reg_partial (
    .load(ld_partial),
    .rst (rst_partial),
    .clk (clk),
    .din (add_tot_out),
    .dout(reg_partial_out)
  );
  assign dout = reg_partial_out;
endmodule
