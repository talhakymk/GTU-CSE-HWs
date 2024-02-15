module my_testbench();
	reg [31:0]a;
	reg [31:0]b;
	wire[31:0]O;
	reg reset;
	reg CLK;
	reg [2:0]aluOP;
	wire less_than;
	
	alu nulursun( O ,a , b , reset , CLK , aluOP , less_than);
	
	initial begin
		#0 a = 32'b00000000000000000000000000010111; b = 32'b00000000000000000000000000000101;aluOP = 3'b111; reset = 1; CLK = 0;
		#2 reset = 0;
		#100 $display("%0d mod %0d = %0d",a,b,O);
		
		#0 a = 32'b00000000000000000000000000000111; b = 32'b00000000000000000000000000000010;aluOP = 3'b000;
		#100 $display("%b and %b = %b",a,b,O);
		
		#0 a = 32'b00000110000000000000000000000111; b = 32'b00000000000000000000000000000010;aluOP = 3'b001;
		#100 $display("%b or %b = %b",a,b,O);
		
		#0 a = 32'b01110000000000001100000000000111; b = 32'b00100000000000000000000000000010;aluOP = 3'b010;
		#100 $display("%b xor %b = %b",a,b,O);
		
		#0 a = 32'b01111100000000000000000000000111; b = 32'b01100000000000000000000000000010;aluOP = 3'b011;
		#100 $display("%b nor %b = %b",a,b,O);
		
		#0 a = 32'b00000000000000000000000000000001; b = 32'b00000000000000000000000000000110;aluOP = 3'b100;
		#100 $display("is %b less than %b = %b (1 is yes 0 is no)",a,b,O);
		
		#0 a = 32'b00000000000000000000000000001111; b = 32'b00000000000000000000000000000010;aluOP = 3'b101; // // all results are signed binary numbers
		#100 $display("%0d add %0d = %b",a,b,O);
		
		#0 a = 32'b00000000000000000000000000010111; b = 32'b00000000000000000000000000000010;aluOP = 3'b110; // all results are signed binary numbers
		#100 $display("%0d sub %0d = %b",a,b,O);
	end
	
	always 
		begin
		#1
		CLK = ~CLK;
		end
	
endmodule
