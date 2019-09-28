`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:18:38 04/24/2015 
// Design Name: 
// Module Name:    receivermod
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
module receivermod(input clk, input data, input rdy, input reset, output ack, output error, output [2:0] dataout, output shiftr, output reg [1:0] y);

	reg [3:0] Q = 0;
	wire shift;

	reg [1:0] Y;
	parameter [1:0] A=2'b00, B=2'b01, C=2'b10, D=2'b11;
	
	always@(rdy, y)
	begin
		case(y)
			A:	if(rdy==0) Y=B;
				else	Y=A;
			B:	Y=C;
			C:	if(rdy) Y=D;
				else Y=C;
			D:	Y=A;
		endcase				
	end

	always@(posedge clk)
	begin
		if(reset) y <= A;
		else y <= Y;
	end

	assign ack = (y == A)|(y == B);
	assign shift = (y == B)|(y == D);
	assign error = (y == A)&(^Q==1);
	assign dataout = Q;
	assign shiftr = shift;

	always@(posedge clk)
	begin
		if(shift)
			Q <= {data, Q[3:1]};
	end

endmodule
