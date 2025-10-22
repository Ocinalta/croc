module downcounter_3bit #(
) (
  input  logic       clk,
  input  logic       rst,
  input  logic       en,
  output logic       tc,
  output logic [2:0] count
);
  always_ff @(posedge clk) begin
    if (rst) begin
      count <= 3'b100;
    end else if (en) begin
      count <= count - 1;
    end
  end
  always_comb begin
    tc = (count == 3'b000);
  end
endmodule
