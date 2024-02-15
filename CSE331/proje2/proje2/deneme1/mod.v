module mod(input [31:0] a , input [31:0] b , input reset , input CLK , output[31:0] result);

	wire make_sub, make_asg, make_comp, asg_tempp, done;
	
	mod_fsm_cu cu(reset ,CLK ,lt , make_sub ,  make_asg ,  make_comp,  asg_tempp, done);
	mod_fsm_dp dp(CLK , make_sub , make_asg , make_comp , done , asg_tempp , a , b , lt , result);
	
endmodule
