module eight_bit_comp(output G, L, E, input [7:0] a,input [7:0] b);
	wire [1:0]g;
	wire [1:0]l;
	wire [1:0]e;
	
	four_bit_comp comp1(g[1], l[1], e[1], a[7:4], b[7:4]);
   four_bit_comp comp2(g[0], l[0], e[0], a[3:0], b[3:0]);
	
	and(E1andG0 , e[1] , g[0]);
	or(G , E1andG0 , g[1]);
	
	and(E1andL0 , e[1] , l[0]);
	or(L , l[1] , E1andL0 );
	
	and(E , e[0] , e[1]);
	
endmodule
