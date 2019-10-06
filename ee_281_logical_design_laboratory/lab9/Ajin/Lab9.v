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
module debounce (clk, button_in, button_out);
	input clk; // my clock is 50 MHz
	input  button_in; // four bouncy buttons
	reg [19:0] count = 0; // period approximately 20 ms
	reg  button_tmp = 0; // synchronize the inputs
	output reg	 button_out = 0; // four debounced buttons

	always @ (posedge clk) 
	begin
		count <= count + 1;
		button_tmp <= button_in;
	if (count == 0)
		button_out <= button_tmp;
	end
endmodule

module gatherinput(input [2:0] inputdata, input load, output wire [3:0] outputdata);

	reg [2:0] temp;
	wire [3:0] withparity;
	reg paritybit;

	always@(load)
		temp <= inputdata;
	
	always@(temp)
	begin
		case(temp)
			3'b001:paritybit=1;
			3'b010:paritybit=1;
			3'b100:paritybit=1;
			3'b111:paritybit=1;
			default: paritybit=0; 
		endcase
	end
	
	assign withparity = {paritybit, temp};
	assign outputdata = withparity;
		
endmodule

module shift(input [3:0] data, input shift, input clk, output reg z);

	reg [3:0] Q;
	
	always@(posedge clk)
	begin
		if(shift)
		begin
			Q[0] <= Q[1];
			Q[1] <= Q[2];
			Q[2] <= Q[3];
			Q[3] <= 0;
		end
		
		z<=Q[0];
	end

endmodule


module sendstatemachine(input clk, input reset, input load, input ack, output reg ready, output reg shift);

	reg [3:0] y, Y;
	parameter [3:0] A = 4'b0000, B = 4'b0001, C = 4'b0010, D = 4'b0011, E = 4'b0100, F = 4'b0101, G = 4'b0110, H = 4'b0111, I = 4'b1000;
	
	always@(load, ack, y)
		case(y)
			A: if(load) Y=B;
			   else		Y=A;
			B: if(load) Y=B;
			   else		Y=C;
			C: if(!ack) Y=D;
			   else		Y=C;
			D: Y=E;
			E: if(ack)	Y=F;
			   else		Y=E;
			F: Y=G;
			G: if(!ack)	Y=H;
			   else		Y=G;
			H: Y=I;
			I: if(ack)	Y=A;
			   else		Y=I;
			default:	Y=4'bxxxx;
		endcase
		
		
	always@(posedge clk)
	begin
		if(reset)	y <= A;
		else	y <= Y;
		
		assign ready = (y==A)|(y==B)|(y==E)|(y==F)|(y==I);
		assign shift = (y==D)|(y==F)|(y==H);
	end
	
endmodule
	

module topmods(input clk, input loadbutton, input resetbutton, input [2:0] dataswitches, input ack, output ready, output reg data);


	//debounce input
	wire loadbut;
	debounce module1(clk, loadbutton, loadbut);
	
	//gatherinput   gatherinput(input [2:0] data, input load, output reg [3:0] data);
	wire[3:0] transferthis;
	gatherinput module2(dataswitches, loadbut, transferthis);
	
	
	//statemachine sendstatemachine(input clk, input reset, input load, input ack, output ready, output shift);
	wire shift;
	sendstatemachine module4(clk, resetbutton, loadbut, ack, ready, shift);
	
	//shift module shift(input [3:0] data, input shift, input clk, output z);
	wire sendthisbit;
	shift module3(transferthis, shift, clk, sendthisbit);
	
	always@(sendthisbit)
	begin
		data <= sendthisbit;
	end
	
endmodule


module topmod(input clk, input loadbutton, input resetbutton, input [2:0] dataswitches, output [3:0] AN, output[7:0] SSEG, output error);

	//call send
	wire ready, data;
	wire ackinput;
	topmods module1(clk, loadbutton, resetbutton, dataswitches, ackinput, ready, data);
	
	//call receive      topmodr(input clk, output ack, input data, input reset, input ready, output error, output [3:0] AN, output [7:0] SSEG);
	topmodr module2(clk, ackinput, data, resetbutton, ready, error, AN, SSEG); 

endmodule
