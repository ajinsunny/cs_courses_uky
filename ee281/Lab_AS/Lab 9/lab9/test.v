`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:55:38 04/24/2015
// Design Name:   topmod
// Module Name:   C:/Users/Lab9/test.v
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

module test;

	// Inputs
	reg load;
	reg reset;
	reg [2:0] datain;
	reg clk;

	// Outputs
	wire error;
	wire [2:0] dataout;
	wire rdyo;
	wire acko;
	wire datao;
	wire shiftr;
	wire shifts;
	wire [3:0] ys;
	wire [1:0] yr;
	

	// Instantiate the Unit Under Test (UUT)
	topmod uut (
		.load(load), 
		.reset(reset), 
		.datain(datain), 
		.error(error), 
		.dataout(dataout), 
		.clk(clk), 
		.rdyo(rdyo), 
		.acko(acko), 
		.datao(datao), 
		.shiftr(shiftr), 
		.shifts(shifts),
		.ys(ys),
		.yr(yr)
	);

	initial begin
		// Initialize Inputs
	
		#100
		load = 0;
		reset = 0;
		datain = 3'b001;
		clk = 0;
		#100

		
		reset=1;
		#100
		reset=0;
		
		#100
		load = 1;
		
		#100
		load=0;
		#30000
		

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
		always begin
		#10 
		clk=!clk;
		end
      
endmodule
