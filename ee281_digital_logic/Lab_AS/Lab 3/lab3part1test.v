`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:31:43 02/04/2013
// Design Name:   lab3part1
// Module Name:   L:/lab3/lab3part1test.v
// Project Name:  lab3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: lab3part1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module lab3part1test;

	// Inputs
	reg [1:0] HAND;
	reg GO1;
	reg GO2;

	// Outputs
	wire [2:0] AN;
	wire [7:0] SSEG;
	wire DISP;

	// Instantiate the Unit Under Test (UUT)
	ee281tut uut (
		.HAND(HAND), 
		.GO1(GO1), 
		.GO2(GO2), 
		.AN(AN), 
		.SSEG(SSEG), 
		.DISP(DISP)
	);

	initial begin
		// Initialize Inputs
		HAND = 0;
		GO1 = 0;
		GO2 = 0;

		// Wait 100 ns for global reset to finish
		#100
		
		GO1 = 0;
		GO2 = 1;
		
		#100
		
		GO1 = 1;
		GO2 = 1;
		
		#100
		
		HAND = 1;
		
		#100
		
		HAND = 2;
		
		#100
		
		HAND = 3;
        
		// Add stimulus here

	end
      
endmodule

