module xor_32bit(output [31:0] out , input [31:0] a , input [31:0] b);
	xor_16bit first(out[15:0] , a[15:0] , b[15:0]);
	xor_16bit second(out[31:16] , a[31:16] , b[31:16]);
endmodule 
