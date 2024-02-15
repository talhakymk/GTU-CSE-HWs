module alu(O,a,b,reset,CLK,aluOP,less_than);

input [31:0] a,b;
output [31:0] O;
wire[31:0] wADD,wXOR,wSUB,wMOD,wNOR,wAND,wOR;
wire[31:0] resADD,resXOR,resSUB,resMOD,resNOR,resAND,resOR,resLTH;
wire wSLT ;
input CLK;
input reset;
input [2:0] aluOP;
output less_than;

wire cout , G , L , E;

subtractor_32bit subb(wSUB , a , b , 32'b00000000000000000000000000000001 , 1'b0); // subtraction
carry_look_ahead_32bit add(a, b, 1'b0, wADD, cout); // addition
xor_32bit exor(wXOR , a , b); // xor
nor_32bit enor(wNOR , a , b); // nor
and_32bit mand(wAND , a , b); // and
or_32bit mor(wOR , a ,b); // or
mod mamod(a , b ,  reset , CLK , wMOD);//mod
thirtytwo_bit_comp comparator(G, less_than, E, a, b); //less than

not(s1not , aluOP[0]);
not(s2not , aluOP[1]);
not(s3not , aluOP[2]);

mux_and res_and(resAND ,{32{s1not}} , {32{s2not}} , {32{s3not}} , wAND);
mux_and res_or(resOR ,{32{s2not}} , {32{s3not}} , {32{aluOP[0]}} , wOR);
mux_and res_xor(resXOR ,{32{s1not}} , {32{aluOP[1]}} , {32{s3not}} , wXOR);
mux_and res_nor(resNOR ,{32{s3not}} , {32{aluOP[1]}} , {32{aluOP[0]}} , wNOR);
mux_and res_lth(resLTH ,{32{aluOP[2]}} , {32{s1not}} , {32{s2not}} , {32{less_than}});
mux_and res_add(resADD ,{32{aluOP[2]}}, {32{s2not}} , {32{aluOP[0]}} , wADD);
mux_and res_sub(resSUB ,{32{aluOP[2]}}, {32{aluOP[1]}} , {32{s1not}} , wSUB);
mux_and res_mod(resMOD ,{32{aluOP[0]}}, {32{aluOP[1]}} , {32{aluOP[2]}} , wMOD);

wire[31:0] ilk , iki , uc , dort , bes , alti;

or_32bit first(ilk,resAND,resOR);
or_32bit sec(iki,ilk,resXOR);
or_32bit thir(uc,iki,resNOR);
or_32bit fourr(dort,uc,resLTH);
or_32bit four(bes,dort,resADD);
or_32bit fift(alti,bes,resSUB);
or_32bit six(O,alti,resMOD);









endmodule
