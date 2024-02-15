module lessthan32bit(output out , input[31:0] a ,  input[31:0] b);
	wire g,e;
	thirtytwo_bit_comp comp(g, out, e, a, b);
endmodule
