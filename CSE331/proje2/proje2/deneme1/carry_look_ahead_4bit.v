module carry_look_ahead_4bit( input [3:0] a, input [3:0] b, input cin, output [3:0] sum, output cout);

wire [3:0] p,g,c;

xor_4bit xor1(p , a , b);
and_4bit and1(g , a , b);

//carry=gi + Pi.ci
not(cin_not , cin);
not(c[0] , cin_not);

and(P0andCIN , p[0] , c[0]);
or(c[1] , P0andCIN , g[0]);

and(P1andP0andC0 , p[1] , p[0] , c[0]);
and(P1andG0 , p[1] , g[0]);
or(c[2] , P1andP0andC0 , P1andG0 , g[1]);

and(P2andP1andP0andC0 , p[2] , p[1] , p[0] , c[0]);
and(P2andP1andG0 , p[2] , p[1] , g[0]);
and(P2andG1 , p[2] , g[1]);
or(c[3] , g[2] , P2andG1 ,P2andP1andG0 , P2andP1andP0andC0);

and(P3andP2andP1andP0andC0 , p[3] , p[2] , p[1] , p[0] , c[0]);
and(p3andP2andP1andG0 , p[3] ,p[2] , p[1] , g[0]);
and(P3andP2andG1 , p[3] , p[2] , g[1]);
and(P3andG2 , p[3] , g[2]);
or(cout , g[3] , P3andG2 ,P3andP2andG1 , p3andP2andP1andG0 , P3andP2andP1andP0andC0 );

xor_4bit son(sum , p , c);

endmodule
