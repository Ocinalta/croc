module multiplier #(
  parameter WIDTH = 8
) (
  input  logic signed [  WIDTH-1:0] mult1,
  input  logic signed [  WIDTH-1:0] mult2,
  output logic signed [4*WIDTH-1:0] prod
);
  logic signed [2*WIDTH-1:0] internal_product;  //Internal product on 2*WIDTH dimension

  always_comb begin
    internal_product = mult1 * mult2;
  end
  assign prod[2*WIDTH-1:0] = internal_product;
  assign prod[4*WIDTH-1:2*WIDTH] = {2 * WIDTH{internal_product[2*WIDTH-1]}};  //Adding 2*WIDTH bit in MSB
endmodule
