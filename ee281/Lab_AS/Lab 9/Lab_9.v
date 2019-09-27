// Code for Prelab A digital thermometer



module topmodule(clk,inputdata,AN, ssegdisp);
		input clk;
		input [7:0]inputdata;
		wire [7:0] adjdata;
		wire [3:0] ONES, TENS;
		wire [1:0] HUNDREDS;
		reg [17:0]count=0;
		reg [7:0] data, degf;
		output reg[7:0] ssegdisp;
		output reg[3:0] AN;
		reg [1:0] segselect;
		
		
		always@(posedge clk)
		begin
				data <= input
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

		binary_to_BCD bin(degreef, ONES,TENS,HUNDREDS);

		always@(posedge clk)
		begin 
				if(count<65535)
						segselect=00;
				else if(count<131071)
						segselect=01;
				else
						segselect=11;
				count++;
		end

		always@(posedge clk)
		begin
				if(segselect==2b'00)
				begin
						AN=4b'1110;
						case(ONES)
							4b'0000:ssegdisp = 8'b11000000;
							4b'0001:ssegdisp = 8'b11111001;
							4b'0010:ssegdisp = 8'b10100100;
							4b'0011:ssegdisp = 8'b10110000;
							4b'0100:ssegdisp = 8'b11000000;
							4b'0101:ssegdisp = 8'b10010010;
							4b'0110:ssegdisp = 8'b10000010;
							4b'0111:ssegdisp = 8'b11111000;
							4b'1000:ssegdisp = 8'b10000000;
							4b'1001:ssegdisp = 8'b10011000;
							4b'1010:ssegdisp = 8'b10100011;
							4b'1011:ssegdisp = 8'b10100011;
							4b'1100:ssegdisp = 8'b10100011;
							4b'1101:ssegdisp = 8'b10100011;
							4b'1110:ssegdisp = 8'b10100011;
							4b'1111:ssegdisp = 8'b10100011;
							default:ssegdisp = 8'b11111111;
						endcase
				end
				else if(segselect==2'b01)
				begin
						AN = 4'b1101;
						case(TENS)
							4b'0000:ssegdisp = 8'b11000000;
							4b'0001:ssegdisp = 8'b11111001;
							4b'0010:ssegdisp = 8'b10100100;
							4b'0011:ssegdisp = 8'b10110000;
							4b'0100:ssegdisp = 8'b11000000;
							4b'0101:ssegdisp = 8'b10010010;
							4b'0110:ssegdisp = 8'b10000010;
							4b'0111:ssegdisp = 8'b11111000;
							4b'1000:ssegdisp = 8'b10000000;
							4b'1001:ssegdisp = 8'b10011000;
							4b'1010:ssegdisp = 8'b10100011;
							4b'1011:ssegdisp = 8'b10100011;
							4b'1100:ssegdisp = 8'b10100011;
							4b'1101:ssegdisp = 8'b10100011;
							4b'1110:ssegdisp = 8'b10100011;
							4b'1111:ssegdisp = 8'b10100011;
							default:ssegdisp = 8'b11111111;
						endcase
				end
				else if(segselect==2'b10)
				begin 
						AN = 4b'1011
						case(HUNDREDS)
							2'b00:ssegdisp=8'b11000000;
							2'b01:ssegdisp=8'b11111001;
							2'b10:ssegdisp=8'b10100100;
							2'b11:ssegdisp=8'b10110000;
							default: sseg =8'b11111111;
						endcase
				end

				else
						ssegdisp = 8'b11111111;

		end

endmodule

























































