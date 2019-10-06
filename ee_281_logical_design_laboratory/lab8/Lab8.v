`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:10:25 03/30/2015 
// Design Name: 
// Module Name:    Lab8 
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
module topmod(input clk, input [7:0] inputtemp, output reg [3:0] AN, output reg [7:0] ssegdisp);


	wire [7:0] adjdata;
	wire [3:0] ONES, TENS;
	wire [1:0] HUNDREDS;
	reg [17:0] count=0;
	reg [7:0] data, degreef;
	reg [1:0] segselect;
		
		
	always@(posedge clk)
	begin
		data <= inputtemp;
	end
	assign adjdata = data -73;

	always@(adjdata)
	begin 
		case(adjdata)
			15:degreef=59;
			16:degreef=61;
			17:degreef=63;
			18:degreef=64;
			19:degreef=66;
			20:degreef=68;
			21:degreef=70;
			22:degreef=72;
			23:degreef=73;
			24:degreef=75;
			25:degreef=77;
			26:degreef=79;
			27:degreef=81;
			28:degreef=82;
			29:degreef=84;
			30:degreef=86;
			31:degreef=88;
			32:degreef=90;
			33:degreef=91;
			34:degreef=93;
			35:degreef=95;
			36:degreef=97;
			default: degreef=0;
		endcase
	end
	
	binary_to_BCD binmod(degreef,ONES,TENS,HUNDREDS);

	always@(posedge clk)
	begin 
		if(count<65535)
			segselect=00;
		else if(count<131071)
			segselect=01;
		else
			segselect=11;
			count=count+1;
	end
	
	always@(posedge clk)
	begin
		if(segselect==2'b00)
		begin
			AN=4'b1110;
			case(ONES)
				4'b0000:ssegdisp = 8'b11000000;
				4'b0001:ssegdisp = 8'b11111001;
				4'b0010:ssegdisp = 8'b10100100;
				4'b0011:ssegdisp = 8'b10110000;
				4'b0100:ssegdisp = 8'b11000000;
				4'b0101:ssegdisp = 8'b10010010;
				4'b0110:ssegdisp = 8'b10000010;
				4'b0111:ssegdisp = 8'b11111000;
				4'b1000:ssegdisp = 8'b10000000;
				4'b1001:ssegdisp = 8'b10011000;
				default:ssegdisp = 8'b11111111;
			endcase
		end
		
		else if(segselect==2'b01)
		begin
			AN = 4'b1101;
			case(TENS)
				4'b0000:ssegdisp = 8'b11000000;
				4'b0001:ssegdisp = 8'b11111001;
				4'b0010:ssegdisp = 8'b10100100;
				4'b0011:ssegdisp = 8'b10110000;
				4'b0100:ssegdisp = 8'b11000000;
				4'b0101:ssegdisp = 8'b10010010;
				4'b0110:ssegdisp = 8'b10000010;
				4'b0111:ssegdisp = 8'b11111000;
				4'b1000:ssegdisp = 8'b10000000;
				4'b1001:ssegdisp = 8'b10011000;
				default:ssegdisp = 8'b11111111;
			endcase
		end
		
		else if(segselect==2'b10)
			begin 
				AN = 4'b1011;
				case(HUNDREDS)
					2'b00:ssegdisp=8'b11000000;
					2'b01:ssegdisp=8'b11111001;
					2'b10:ssegdisp=8'b10100100;
					2'b11:ssegdisp=8'b10110000;
					default: ssegdisp =8'b11111111;
				endcase
			end
		else
			ssegdisp = 8'b11111111;
	end
	
endmodule

module binary_to_BCD(A,ONES,TENS,HUNDREDS);
	input [7:0] A;
	output [3:0] ONES, TENS;
	output [1:0] HUNDREDS;
	wire [3:0] c1,c2,c3,c4,c5,c6,c7;
	wire [3:0] d1,d2,d3,d4,d5,d6,d7;
	
	assign d1 = {1'b0,A[7:5]};
	assign d2 = {c1[2:0],A[4]};
	assign d3 = {c2[2:0],A[3]};
	assign d4 = {c3[2:0],A[2]};
	assign d5 = {c4[2:0],A[1]};
	assign d6 = {1'b0,c1[3],c2[3],c3[3]};
	assign d7 = {c6[2:0],c4[3]};
	add3 m1(d1,c1);
	add3 m2(d2,c2);
	add3 m3(d3,c3);
	add3 m4(d4,c4);
	add3 m5(d5,c5);
	add3 m6(d6,c6);
	add3 m7(d7,c7);
	assign ONES = {c5[2:0],A[0]};
	assign TENS = {c7[2:0],c5[3]};
	assign HUNDREDS = {c6[3],c7[3]};

endmodule