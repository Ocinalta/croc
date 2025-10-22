module mux4to1 #(
  parameter WIDTH = 32
) (
  input  logic [      1:0] sel,
  input  logic [WIDTH-1:0] din1,
  input  logic [WIDTH-1:0] din2,
  input  logic [WIDTH-1:0] din3,
  input  logic [WIDTH-1:0] din4,
  output logic [WIDTH-1:0] dout
);
  always_comb begin
    case (sel)
      2'b00:   dout = din1;
      2'b01:   dout = din2;
      2'b10:   dout = din3;
      2'b11:   dout = din4;
      default: dout = {WIDTH{1'b0}};
    endcase
  end
endmodule
