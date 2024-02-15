module or_16bit(output [16:0] out , input [16:0] a , input [16:0] b);
	or_4bit first(out[3:0] , a[3:0] , b[3:0]);
	or_4bit second(out[7:4] , a[7:4] , b[7:4]);
	or_4bit third(out[11:8] , a[11:8] , b[11:8]);
	or_4bit fourth(out[15:12] , a[15:12] , b[15:12]);
endmodule
