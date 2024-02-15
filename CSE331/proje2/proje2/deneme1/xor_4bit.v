module xor_4bit(output [3:0]out , input [3:0] a , input [3:0] b);
	xor(out[0] , a[0] , b[0]);
	xor(out[1] , a[1] , b[1]);
	xor(out[2] , a[2] , b[2]);
	xor(out[3] , a[3] , b[3]);
endmodule
