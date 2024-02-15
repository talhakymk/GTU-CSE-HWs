module mod_fsm_cu(input reset , input  CLK , input lt  , output reg make_sub , output reg make_asg , output reg make_comp, output reg asg_tempp, output reg done);
	reg [2:0] curr_state, next_state;
	
	localparam 	ASG_TEMP = 3'b000,
					SUB 	= 3'b001,
					MAKE_ASGN = 3'b010,
					COMP	= 3'b011,
					FINAL = 3'b100;
					
	
	//State Registers			
	always @(posedge CLK)
		begin
		if(reset)
			curr_state <= ASG_TEMP;
		else
			curr_state <= next_state;
		end
		
	//Next State Logic
	always @(*)
		begin
		case(curr_state)
		ASG_TEMP:	begin
						next_state = SUB;
						end
						
		SUB: 	begin
					next_state = MAKE_ASGN;
				end
		MAKE_ASGN: begin
					next_state = COMP;
				end
		
		COMP: begin
				if(lt)
					next_state = FINAL;
				else
					next_state = SUB;
				end
		
		FINAL: begin
					next_state = FINAL; 
				 end
		
		
		
		endcase
		end
		
		//Output Logic
	always @(*)
		begin
		asg_tempp = 1'b0;
		make_sub = 1'b0;
		make_asg = 1'b0;
		make_comp = 1'b0;
		done = 1'b0;
		case(curr_state)
		ASG_TEMP:	begin
						asg_tempp = 1'b1;
						end
		
		SUB: 	begin
				asg_tempp = 1'b0;
				make_sub = 1'b1;
				make_comp = 1'b0;
				end
				
		MAKE_ASGN:begin
				make_sub = 1'b0;
				make_asg = 1'b1;
				end
		
		COMP: begin
				make_asg = 1'b0;
				make_comp = 1'b1;
				end
		
		FINAL: begin
				 asg_tempp = 1'b0;
				 make_sub = 1'b0;
				 make_asg = 1'b0;
				 make_comp = 1'b0;
				 done = 1'b1;
				 end
		
		endcase
		end
		
endmodule
		
		
		
		