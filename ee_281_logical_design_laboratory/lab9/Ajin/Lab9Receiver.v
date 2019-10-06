`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:08:28 04/13/2015 
// Design Name: 
// Module Name:    Lab9 
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
module shiftr(input data, input shift, input clk, output reg error, output reg [3:0] number);

	reg [3:0] Q;
	reg [2:0] thisisathing;
	
	always@(posedge clk)
	begin
		if(shift)
		begin
			Q[0] <= Q[1];
			Q[1] <= Q[2];
			Q[2] <= Q[3];
			Q[3] <= data;
		end
		
		thisisathing[2] <= Q[2];
		thisisathing[1] <= Q[1];
		thisisathing[0] <= Q[0];
		
		number <= thisisathing;
	end

endmodule


module receivestatemachine(input clk, input ready, input reset, output reg ack, output reg shift);

	reg [1:0] y, Y;
	parameter [1:0] A = 2'b00, B = 2'b01, C = 2'b10, D = 2'b11;
	
	always@(ready, y)
		case(y)
			A: if(!ready) 	Y=B;
			   else			Y=A;
			B: Y=C;
			C: if(ready) 	Y=D;
			   else			Y=C;
			D: Y=A;
			default:		Y=2'bxx;
		endcase
		
		
	always@(posedge clk)
	begin
		if(reset)	y <= A;
		else	y <= Y;
		
		assign ack = (y==A)|(y==B);
		assign shift = (y==B)|(y==D);
				
	end
	
endmodule


module codeconverter(input [2:0] numbertoconvert, input errorinput, output [3:0] AN, output reg [6:0] ssegdisp, output reg error);

	assign AN = 4'b1110;

	always@(numbertoconvert)
	
	begin
		case(numbertoconvert)
			3'b000: ssegdisp = 7'b1000000; //0
			3'b001: ssegdisp = 7'b1111001; //1
			3'b010: ssegdisp = 7'b0100100; //2
			3'b011: ssegdisp = 7'b0110000; //3
			3'b100: ssegdisp = 7'b0011001; //4
			3'b101: ssegdisp = 7'b0010010; //5
			3'b110: ssegdisp = 7'b0000010; //6
			3'b111: ssegdisp = 7'b1111000; //7
			default: ssegdisp = 7'b1111111;
		endcase
	end
	
	always@(errorinput)
	begin
		case(errorinput)
			1'b0: error = 0; //dont care
			1'b1: error = 1; //yes
		endcase
	end

endmodule
	

module topmodr(input clk, output ack, input data, input reset, input ready, output error, output [3:0] AN, output [7:0] SSEG);
	
	//statemachine receivestatemachine(input clk, input ready, input reset, output reg ack, output reg shift);
	wire shift;
	receivestatemachine module2(clk, ready, reset, ack, shift);
	
	//shift module shiftr(input data, input shift, input clk, output reg error, output reg [3:0] number);
	wire [2:0] num;
	wire waserror;
	shiftr module1(data, shift, clk, waserror, num);
	
	//codeconvert codeconverter(input [2:0] numbertoconvert, input errorinput, output reg [3:0] AN, output reg [6:0] ssegdisp, output reg error);
	codeconverter module3(num, waserror, AN, SSEG, error);
	
	
endmodule
