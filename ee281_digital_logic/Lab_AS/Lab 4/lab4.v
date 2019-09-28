`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:04:10 02/23/2015 
// Design Name: 
// Module Name:    lab4 
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
module lab4(
    input d1,
    input d2,
    input P0,
    input A1,
    input A0,
    output X1,
    output X0
    );

assign X0=A1*(~P0 | (~d2 & ~d1)) | (A0 & ~P0 & d1 & d2);
assign X1=(d1 | d2) & (A1 | ~P0) & (A1 | A0);

endmodule
