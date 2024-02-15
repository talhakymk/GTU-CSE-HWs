module carry_look_ahead_32bit(input [31:0] a, input [31:0] b, input cin, output [31:0] sum, output cout);
	wire [7:1] t;
	carry_look_ahead_4bit cla1 (.a(a[3:0]), .b(b[3:0]), .cin(cin), .sum(sum[3:0]), .cout(t[1]));
	carry_look_ahead_4bit cla2 (.a(a[7:4]), .b(b[7:4]), .cin(t[1]), .sum(sum[7:4]), .cout(t[2]));
	carry_look_ahead_4bit cla3 (.a(a[11:8]), .b(b[11:8]), .cin(t[2]), .sum(sum[11:8]), .cout(t[3]));
	carry_look_ahead_4bit cla4 (.a(a[15:12]), .b(b[15:12]), .cin(t[3]), .sum(sum[15:12]), .cout(t[4]));
	carry_look_ahead_4bit cla5 (.a(a[19:16]), .b(b[19:16]), .cin(t[4]), .sum(sum[19:16]), .cout(t[5]));
	carry_look_ahead_4bit cla6 (.a(a[23:20]), .b(b[23:20]), .cin(t[5]), .sum(sum[23:20]), .cout(t[6]));
	carry_look_ahead_4bit cla7 (.a(a[27:24]), .b(b[27:24]), .cin(t[6]), .sum(sum[27:24]), .cout(t[7]));
	carry_look_ahead_4bit cla8 (.a(a[31:28]), .b(b[31:28]), .cin(t[7]), .sum(sum[31:28]), .cout(cout));
endmodule
