`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:33:18 03/09/2015
// Design Name:   decidewinner
// Module Name:   C:/Users/Lab5/decidewinnertest.v
// Project Name:  Lab5
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: decidewinner
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module decidewinnertest;

	// Inputs
	reg [1:0] p;
	reg [1:0] c;
		// Outputs
	wire [1:0] win;
	wire [7:0] ssegoutput;
	wire [3:0] AN;

	// Instantiate the Unit Under Test (UUT)
	decidewinner uut (
		.p(p), 
		.c(c), 
		.win(win)
	);
	
	sseg uut2(
		.whowon(win), 
		.AN(AN), 
		.SSEG(ssegoutput)
	);
	
integer i;
	initial begin:testit
		
		
			#100;//Evade GSR
		for(i=0;i<4;i=i+1)
		begin:enloop
			integer j;
			for(j=0;j<4;j=j+1)
			begin:codeloop
				#25 p=i; c=j; //Count each input
				//Cross-test

			end
		end
	end
	
endmodule
