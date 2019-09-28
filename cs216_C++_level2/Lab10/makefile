#CS 216-002 Lab 10 
#Date : 04/ 18/ 15
#Purpose: makefile to run the program
#
#Author: Ajin Sunny 
#


all: Lab10

Lab10: main.o
	g++ -o Lab10  main.o
					
main.o: main.cpp Matrix.cpp Matrix.h
	g++ -c -std=c++11 main.cpp Matrix.cpp
						 
clean:
	rm *.o

