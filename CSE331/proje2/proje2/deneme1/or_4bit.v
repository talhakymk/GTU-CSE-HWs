module or_4bit(output [3:0] out , input [3:0] a , input [3:0] b );
	or(out[0] , a[0] , b[0]);
	or(out[1] , a[1] , b[1]);
	or(out[2] , a[2] , b[2]);
	or(out[3], a[3] , b[3]);
endmodule
