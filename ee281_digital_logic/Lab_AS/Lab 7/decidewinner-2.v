`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:24:54 03/09/2015 
// Design Name: 
// Module Name:    decidewinner 
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
module decidewinner(
    input [1:0] p,
    input [1:0] c,
    output reg [1:0] win
    );


	always@(p,c)
	begin
		case({p,c})
			4'b0000: win=0;
			4'b0001: win=2;
			4'b0010: win=2;
			4'b0011: win=2;
			4'b0100: win=1;
			4'b0101: win=0;
			4'b0110: win=2;
			4'b0111: win=2;
			4'b1000: win=1;
			4'b1001: win=1;
			4'b1010: win=0;
			4'b1011: win=2;
			4'b1100: win=1;
			4'b1101: win=1;
			4'b1110: win=1;
			4'b1111: win=0;
			default: win=0;
		endcase
	end
endmodule



module sseg(
    input [1:0] whowon,
	 output [3:0] AN,
    output reg [6:0] SSEG
	 );
	 
	 assign AN = 4'b1110;
	
	// Control the segments of the display
	always @(whowon)
	begin
		case (whowon)
		2'b00: SSEG = 7'b0100001;	// draw = d
		2'b01: SSEG = 7'b0001011;	// human wins = h
		2'b10: SSEG = 7'b0100111;	// computer wins = c
		default: SSEG = 7'b0100001;	// Everything else = d
		endcase
	end
endmodule


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


module computerchoice(
	input debounceinput,
	input clk,
	input reset,
	output[1:0] computerchoice);
	
	always@(posedge clk)
	begin
	
	if(reset)
		computerchoice <= 2'b11;
	else if(debounceinput)
		if(computerchoice==2'b11)
			computerchoice <= 2'b00; //rock
		else if(computerchoice==0)
			computerchoice <= 2'b01; //paper
		else if(computerchoice==1)
			computerchoice<=2'b10; //scissors
		else if(computerchoice==2)
			computerchoice<=2'b00;
			
	end
endmodule



module comparemod(
	input[1:0] x, 
	input[1:0] y,
	output[6:0] ssegdisp, 
	output[3:0] AN,
	input debouncebutton,
	input clk);
	
	wire[1:0] num;
	
	decidewinner module1(x,y,num);
	sseg module2(num,AN,ssegdisp);
	
	
	wire debounceoutput;
	
	debounce module3(clk, debouncebutton, debouceoutput);
	
	

endmodule
