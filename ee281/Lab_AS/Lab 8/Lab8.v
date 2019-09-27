`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:10:25 03/30/2015 
// Design Name: 
// Module Name:    Lab8 
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
module topmod(input clk, input [7:0] SW, output reg motoroutput);

	parameter clkdiv=8000;
	reg[22:0] cnt;
	reg newclktick;
	reg[7:0] newclkcount;
	
	always@(posedge clk)
	begin
	newclktick<=(cnt==clkdiv);
	if(newclktick==1)
		cnt<=0;
	else
		cnt<=cnt+1;
	end
	
	always@(posedge clk)
	begin
	if(newclktick)
		newclkcount<=newclkcount+1;
	end
	

	always@(posedge clk)
	begin
	if(newclkcount<SW)
		output=1;
	else
		output=0;
	end
	
endmodule