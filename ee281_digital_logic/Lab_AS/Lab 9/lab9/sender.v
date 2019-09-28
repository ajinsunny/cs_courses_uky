`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:13:57 04/24/2015 
// Design Name: 
// Module Name:    sendermod
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
module sendermod(input clk, input load, input reset, input [2:0] datain, input ack, output rdy, output data, output shifts, output reg [3:0] y);

	reg [3:0] Q = 0;
	wire shift;

	reg [3:0] Y;
	parameter [3:0] A=4'b0000, B=4'b0001, C=4'b0010, D=4'b0011, E=4'b0100, F=4'b0101, G=4'b0110, H=4'b0111, I=4'b1000;


	always@(ack, load, y)
	begin
		case(y)
			A:	if(load) Y=B;
				else	Y=A;
			B:	if(load==0) Y=C;
				else Y=B;
			C:	if(ack==0) Y=D;
				else Y=C;
			D:	Y=E;
			E:	if(ack) Y=F;
				else Y=E;
			F:	Y=G;
			G:	if(ack==0)	Y=H;
				else	Y=G;
			H:	Y=I;
			I: if(ack)	Y=A;
				else	Y = I;
		endcase				
	end

	always@(posedge clk)
	begin
		if(reset) y <= A;
		else y <= Y;
	end

	assign rdy = (y == A)|(y == B)|(y == E)|(y == F)|(y == I);
	assign shift = (y == D)|(y == F)|(y == H);
	assign shifts = shift;
	assign data = Q[0];

	always@(posedge clk)
	begin
		if(load)
			Q <= {^datain, datain};
		else if(shift)
		begin
			Q[0] <= Q[1];
			Q[1] <= Q[2];
			Q[2] <= Q[3];
			Q[3] <= 0;
		end
	end

endmodule
