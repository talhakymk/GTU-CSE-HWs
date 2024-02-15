module two_bit_comp(output G, L, E, input [1:0]a ,input [1:0]b);
    not(a0_not,a[0]);
	 not(a1_not,a[1]);
	 not(b0_not,b[0]);
	 not(b1_not,b[1]);
	 
	 xnor(A1xnorB1 , a[1] , b[1]);
	 xnor(A0xnorB0 , a[0] , b[0]);
	 
	 and(A1andB1not , a[1] , b1_not);
	 and(A0andB0not , a[0] , b0_not);
	 and(A1xnorB1_and_A0andB0not , A1xnorB1  ,A0andB0not );
	 or(G , A1andB1not , A1xnorB1_and_A0andB0not);
    
	 and(A1notandB1 , a1_not , b[1]);
	 and(A0notandB0 , a0_not , b[0]);
	 and(A1xnorB1_and_A0notandB0 , A1xnorB1  ,A0notandB0);
	 or(L , A1notandB1 , A1xnorB1_and_A0notandB0);
	 
	 and(E ,A1xnorB1 ,A0xnorB0);
endmodule