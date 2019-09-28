`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:49:15 09/08/2009 
// Design Name: 
// Module Name:    dec3x8en_bhv 
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
module dec3x8en_bhv(code, dec, en);
	input en; //Enable line
	input [2:0]code; //Coded input
	output [7:0]dec; //Decoded output
	reg [7:0]dec; //Decoded output, reg'd

	always@(en, code)
	begin
	if(en==0) dec=16'b00000000; //Disabled
	else if (en==1) //Enabled
		case(code)
			7: dec=8'b10000000; //000
			6: dec=8'b01000000; //010
			5: dec=8'b00100000; //100
			4: dec=8'b00010000; //110
			3: dec=8'b00001000; //001
			2: dec=8'b00000100; //101
			1: dec=8'b00000010; //011
			0: dec=8'b00000001; //111
			default: dec=8'b11111111; //Error state
		endcase
	else dec=8'b10101010; //Distinct and different error state
	end
endmodule

