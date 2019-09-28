#Course: CS216-002
#Project: Lab Assignemnt 11
#Date: 4/24/15
#Purpose: to build a parse tree which shows the relationships
#		  among operators and operands in an expression
#	      display the tree structure visually
#Author: Ajin Sunny

OBJECTS = main.o parsetree.o 
HEADERS = parsetree.h
Lab11: $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -f *.o Lab11






























