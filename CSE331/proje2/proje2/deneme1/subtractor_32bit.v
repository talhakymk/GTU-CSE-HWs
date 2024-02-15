module subtractor_32bit(output [31:0] out , input [31:0] a , input [31:0] b , input[31:0] one , input zero);
	wire [31:0] b_not;
	not_32bit bitartik(b_not , b);
	wire cout;
	wire [31:0] two_comp;
	carry_look_ahead_32bit first(b_not,one, zero,two_comp, cout);
	carry_look_ahead_32bit second(a,two_comp, zero, out, cout);
endmodule
