module accumulator #(
  parameter WIDTH = 32
) (
  input  logic             clk,
  input  logic             sel,
  input  logic             ld_tmp,
  input  logic             ld_branch,
  input  logic [WIDTH-1:0] din,
  output logic [WIDTH-1:0] dout
);

  //Signal definition
  //Adder signal
  logic [WIDTH-1:0] add_out;
  //Register signal
  logic [WIDTH-1:0] reg_tmp_out;
  //Multiplexer signal
  logic [WIDTH-1:0] mux_out;

  //Component instantiation
  //Adder
  adder #(
    .WIDTH(WIDTH)
  ) add (
    .add1(din),
    .add2(mux_out),
    .sum (add_out)
  );
  //Registers
  register #(
    .WIDTH(WIDTH)
  ) reg_tmp (
    .load(ld_tmp),
    .rst (1'b0),
    .clk (clk),
    .din (add_out),
    .dout(reg_tmp_out)
  );
  register #(
    .WIDTH(WIDTH)
  ) reg_branch (
    .load(ld_branch),
    .rst (1'b0),
    .clk (clk),
    .din (reg_tmp_out),
    .dout(dout)
  );
  //Multiplexer 2-to-1
  mux2to1 #(
    .WIDTH(WIDTH)
  ) mux_sum (
    .sel (sel),
    .din1(reg_tmp_out),
    .din2({WIDTH{1'b0}}),
    .dout(mux_out)
  );

endmodule
