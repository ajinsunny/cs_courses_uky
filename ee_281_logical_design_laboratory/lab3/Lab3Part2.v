`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:13:34 02/09/2015 
// Design Name: 
// Module Name:    Lab3Part2 
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
module Lab3Part2(SW, SSEG, AN, DISP);
    input [3:0] SW;
	 output [2:0] AN;
    output reg [6:0] SSEG;
	 output DISP;
	 
	 assign AN = 3'b111;

	 assign DISP = 0;
	
	// Control the segments of the display
	always @(SW)
	begin
		case (SW)
		4'b0000: SSEG =   7'b1000000;	// 0000 = 0
		4'b0001: SSEG =   7'b1111001;	// 0001 = 1
		4'b0010: SSEG =   7'b0100100;	// 0010 = 2
		4'b0011: SSEG =   7'b0110000;	// 0011 = 3		
		4'b0100: SSEG =   7'b0011001;	// 0100 = 4		
		4'b0101: SSEG =   7'b0010010;	// 0101 = 5
		4'b0110: SSEG =   7'b0000010;	// 0110 = 6
		4'b0111: SSEG =   7'b1111000;	// 0111 = 7
		4'b1000: SSEG =   7'b0000000;	// 1000 = 8
		4'b1001: SSEG =   7'b0010000;	// 1001 = 9
		default: SSEG =   7'b0100011;	// Everything else = o
		endcase
	end
endmodule
