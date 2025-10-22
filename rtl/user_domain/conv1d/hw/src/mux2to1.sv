module mux2to1 #(
  parameter WIDTH = 8
) (
  input  logic             sel,
  input  logic [WIDTH-1:0] din1,
  input  logic [WIDTH-1:0] din2,
  output logic [WIDTH-1:0] dout
);
  always_comb begin
    case (sel)
      1'b0:    dout = din1;
      1'b1:    dout = din2;
      default: dout = {WIDTH{1'b0}};
    endcase
  end
endmodule
