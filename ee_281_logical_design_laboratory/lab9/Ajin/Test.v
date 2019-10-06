`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:06:46 04/13/2015
// Design Name:   topmod
// Module Name:   C:/Users/Lab9/Test.v
// Project Name:  Lab9
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: topmod
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Test;

	// Inputs
	reg clk;
	reg loadbutton;
	reg resetbutton;
	reg [2:0] dataswitches;

	// Outputs
	wire [3:0] AN;
	wire [7:0] SSEG;
	wire error;

	// Instantiate the Unit Under Test (UUT)
	topmod uut (
		.clk(clk), 
		.loadbutton(loadbutton), 
		.resetbutton(resetbutton), 
		.dataswitches(dataswitches), 
		.AN(AN), 
		.SSEG(SSEG), 
		.error(error)
	);
	always #25 clk=!clk;
	
	initial begin
		// Initialize Inputs
		clk = 0;
		loadbutton = 0;
		resetbutton = 0;
		dataswitches = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		loadbutton = 0;
		resetbutton = 1;

		// Wait 100 ns for global reset to finish
		#100;
		
		loadbutton = 0;
		resetbutton = 0;

		// Wait 100 ns for global reset to finish
		#100;

		loadbutton = 1;
		resetbutton = 0;

		// Wait 100 ns for global reset to finish
		#100;

		loadbutton = 0;
		resetbutton = 0;
		
		// Wait 100 ns for global reset to finish
		#100;

	end
      
endmodule

