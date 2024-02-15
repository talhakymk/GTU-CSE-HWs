module sixteen_bit_comp(output G, L, E, input [15:0] a,input [15:0] b);
	wire [1:0]g;
	wire [1:0]l;
	wire [1:0]e;
	
	eight_bit_comp comp1(g[1], l[1], e[1], a[15:8], b[15:8]);
   eight_bit_comp comp2(g[0], l[0], e[0], a[7:0], b[7:0]);
	
	and(E1andG0 , e[1] , g[0]);
	or(G , E1andG0 , g[1]);
	
	and(E1andL0 , e[1] , l[0]);
	or(L , l[1] , E1andL0 );
	
	and(E , e[0] , e[1]);
	
endmodule
