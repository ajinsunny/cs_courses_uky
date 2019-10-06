module prelab1(W,X,Y,Z,f);
input W,X,Y,Z;
output f;

assign f = (~X & ~Y & ~Z) | (W & X & Z) | (W & ~X & Y);

endmodule