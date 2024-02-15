module four_bit_comp(output G, L, E, input [3:0] a,input [3:0] b);
	wire [1:0]g;
	wire [1:0]l;
	wire [1:0]e;
	
	two_bit_comp comp1(g[1], l[1], e[1], a[3:2], b[3:2]);
   two_bit_comp comp2(g[0], l[0], e[0], a[1:0], b[1:0]);
	
	and(E1andG0 , e[1] , g[0]);
	or(G , E1andG0 , g[1]);
	
	and(E1andL0 , e[1] , l[0]);
	or(L , l[1] , E1andL0 );
	
	and(E , e[0] , e[1]);
	
	
endmodule
