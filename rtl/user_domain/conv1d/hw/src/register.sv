module register #(
  parameter WIDTH = 8
) (
  input  logic             load,
  input  logic             rst,
  input  logic             clk,
  input  logic [WIDTH-1:0] din,
  output logic [WIDTH-1:0] dout
);
  //Signal definition

  //Behaviour
  always_ff @(posedge clk) begin
    if (rst) begin
      dout <= {WIDTH{1'b0}};
    end else if (load) begin
      dout <= din;
    end
  end
endmodule
