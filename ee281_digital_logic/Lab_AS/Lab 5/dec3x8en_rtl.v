`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:49:15 09/08/2009 
// Design Name: 
// Module Name:    dec3x8en 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module dec3x8en_rtl(code, dec, en);
	input en; //Enable line
	input [2:0]code; //Coded input
	output [7:0]dec; //Decoded output

	assign dec[0]= ~code[0] & ~code[1] & ~code[2] & en; //000
	assign dec[1]=  code[0] & ~code[1] & ~code[2] & en; //100
	assign dec[2]= ~code[0] &  code[1] & ~code[2] & en; //010
	assign dec[3]=  code[0] &  code[1] & ~code[2] & en; //110
	assign dec[4]= ~code[0] & ~code[1] &  code[2] & en; //001
	assign dec[5]=  code[0] & ~code[1] &  code[2] & en; //101
	assign dec[6]= ~code[0] &  code[1] &  code[2] & en; //011
	assign dec[7]=  code[0] &  code[1] &  code[2] & en; //111

endmodule

