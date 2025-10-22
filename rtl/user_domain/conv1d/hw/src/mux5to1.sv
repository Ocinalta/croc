module mux5to1 #(
  parameter WIDTH = 8
) (
  input  logic [      2:0] sel,
  input  logic [WIDTH-1:0] din1,
  input  logic [WIDTH-1:0] din2,
  input  logic [WIDTH-1:0] din3,
  input  logic [WIDTH-1:0] din4,
  input  logic [WIDTH-1:0] din5,
  output logic [WIDTH-1:0] dout
);
  always_comb begin
    case (sel)
      3'b100:  dout = din1;
      3'b011:  dout = din2;
      3'b010:  dout = din3;
      3'b001:  dout = din4;
      3'b000:  dout = din5;
      default: dout = {WIDTH{1'b0}};
    endcase
  end
endmodule
