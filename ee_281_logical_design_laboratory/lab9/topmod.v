`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:35:55 04/24/2015
// Design Name: 
// Module Name:    topmod 
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
module topmod(input load, input reset, input [2:0] datain, output [3:0] AN, output reg [6:0] ssegdisp, output error, output [2:0] dataout, 
input clk, output rdyo, output acko, output datao, output shiftr, output shifts, output [3:0] ys, output [1:0] yr);

	wire data, rdy, ack;
	
	assign datao = data;
	assign rdyo = rdy;
	assign acko = ack;
	
	//module receivermod(input clk, input data, input rdy, input reset, output ack, output error, output [2:0] dataout, output shiftr, output reg [1:0] y);
	receivermod mod1(clk, data, rdy, reset, ack, error, dataout, shiftr, yr);
	
	//module sendermod(input clk, input load, input reset, input [2:0] datain, input ack, output rdy, output data, output shifts, output reg [3:0] y);
	sendermod mod2(clk, load, reset, datain, ack, rdy, data, shifts, ys);
	
	
	assign AN = 4'b1110;

	always@(dataout)
	
	begin
		case(dataout)
			3'b000: ssegdisp = 7'b1000000; //0
			3'b001: ssegdisp = 7'b1111001; //1
			3'b010: ssegdisp = 7'b0100100; //2
			3'b011: ssegdisp = 7'b0110000; //3
			3'b100: ssegdisp = 7'b0011001; //4
			3'b101: ssegdisp = 7'b0010010; //5
			3'b110: ssegdisp = 7'b0000010; //6
			3'b111: ssegdisp = 7'b1111000; //7
			default: ssegdisp = 7'b1111111; //off
		endcase
	end
	
endmodule
