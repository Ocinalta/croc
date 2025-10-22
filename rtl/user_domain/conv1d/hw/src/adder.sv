module adder #(
  parameter WIDTH = 32
) (
  input  logic signed [WIDTH-1:0] add1,
  input  logic signed [WIDTH-1:0] add2,
  output logic signed [WIDTH-1:0] sum
);
  always_comb begin
    sum = add1 + add2;
  end
endmodule
