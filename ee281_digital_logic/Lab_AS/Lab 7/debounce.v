// A simple Timer-Based Debounce by "echo47"
//http://www.edaboard.com/ftopic130353.html

// Simple debouncer for 4 buttons.
//	Change 4-bit vectors to scalars for a single button
// Choose "count" size so its period is longer than worst-case bounce.
//	Default 20bit should be OK for the Spartan 3 Starter Board Buttons
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