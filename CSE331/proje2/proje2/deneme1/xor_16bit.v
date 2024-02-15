module xor_16bit(output [16:0] out , input [16:0] a , input [16:0] b);
	xor_4bit f(out[3:0] , a[3:0] , b[3:0]);
	xor_4bit s(out[7:4] , a[7:4] , b[7:4]);
	xor_4bit t(out[11:8] , a[11:8] , b[11:8]);
	xor_4bit l(out[15:12] , a[15:12] , b[15:12]);
endmodule
