#__________________________________________#
#course: CS216 - 002 
#Program Assignment 4 
#Date : 04 / 24 / 15
#Purpose: makefile 
#Author: Ajin Sunny
#__________________________________________#

#creates the object 

OBJECTS = main.o parsetree.o
HEADERS = stack.h parsetree.h
CS216PA4: $(OBJECTS)
		g++ -std=c++11 $^ -o $@
%.o: %.cpp $(HEADERS)
		g++ -std=c++11 -c $< -o $@
clean:
		rm -f *.o CS216PA4	















