`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:39:20 02/04/2013
// Design Name:   Lab3Part2
// Module Name:   L:/LABpart2/Lab3part2test.v
// Project Name:  LABpart2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Lab3Part2
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Lab3part2test;

	// Inputs
	reg [3:0] SWITCH;

	// Outputs
	wire [7:0] SEG;
	wire [3:0] AN;

	// Instantiate the Unit Under Test (UUT)
	Lab3Part2 uut (
		.SWITCH(SWITCH), 
		.SEG(SEG), 
		.AN(AN)
	);

	initial begin
		// Initialize Inputs
		SWITCH = 0;
		// Wait 100 ns for global reset to finish
		#100
		
		SWITCH = 1;
		
		#100
		
		SWITCH = 2;
		
		#100
		
		SWITCH = 3;
		
       #100
		 SWITCH = 4;
		 #100
		 SWITCH = 5;
		 #100
		 SWITCH = 6;
		 #100
		 SWITCH = 7;
		 #100
		 SWITCH = 8;
		 #100
		 SWITCH = 9;
		 #100
		 SWITCH = 10;
		 #100
		 SWITCH = 11;
		 #100
		 SWITCH = 12;
		 #100
		 SWITCH = 13;
		 #100
		 SWITCH = 14;
		 #100
		 SWITCH = 15;
		 // Add stimulus here

	end      
endmodule

