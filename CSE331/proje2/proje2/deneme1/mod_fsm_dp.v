module mod_fsm_dp(input CLK ,input make_sub , input make_asg , input make_comp ,input done,input asg_tempp ,input [31:0] a, input [31:0] b, output reg lt , output reg [31:0] result );
	reg[31:0] temp;
	reg[31:0] res_sub;
	
	always @(posedge CLK)
		begin
			if(asg_tempp)
			temp <= a;
			else if(make_sub) begin
			res_sub = temp - b;
			end 
			else if(make_asg) begin
			temp = res_sub;
			end
			else if(make_comp) begin
			lt = (temp < b);
			end
			else if(done) begin
			result = temp + b;
			end
		end
	
endmodule
		