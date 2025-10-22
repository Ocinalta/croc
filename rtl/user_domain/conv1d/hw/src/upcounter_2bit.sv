module upcounter_2bit #(
) (
  input  logic       clk,
  input  logic       rst,
  input  logic       en,
  output logic       tc,
  output logic [1:0] count
);
  always_ff @(posedge clk) begin
    if (rst) begin
      count <= 2'b00;
    end else if (en) begin
      count <= count + 1;
    end
  end
  always_comb begin
    tc = (count == 2'b11);
  end
endmodule
