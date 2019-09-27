`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:55:39 09/08/2009
// Design Name:   dec3x8en_rtl
// Module Name:   C:/PSEhw2TMP/HW2dec3x8/dec3x8en_tb.v
// Project Name:  HW2dec3x8
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: dec3x8en_rtl
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module dec3x8en_tb_v;

	// Inputs
	reg [2:0] code;
	reg en;

	// Outputs
	wire [7:0] dec;
	
	//Cross-test
	wire [7:0] dec_cross;
	reg Error;

	// Instantiate the Unit Under Test (UUT)
	dec3x8en_rtl dec_rtl (
		.code(code), 
		.dec(dec), 
		.en(en)
	);
	
	dec3x8en_bhv dec_bhv (
		.code(code), 
		.dec(dec_cross), 
		.en(en)
	);

	initial begin:testit
		integer i;
			#100;//Evade GSR
		for(i=0;i<2;i=i+1)
		begin:enloop
			integer j;
			for(j=0;j<9;j=j+1)
			begin:codeloop
				#25 en=i; code=j; //Count each input
				//Cross-test
					#12 if(dec_cross==dec)Error=0;
					else Error=1;
			end
		end
	end
      
	initial //Guard
	begin
		#1000 $stop; //cutoff after given steps
	end
		
endmodule

