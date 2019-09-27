OBJECTS = main.o LinkedList.o
			#(listing all of your object files here, seperated by spaces)
HEADERS = LinkedList.h
			#(listing all headers here, seperated by spaces)

lab8: $(OBJECTS)
	g++ $^ -o lab8

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -f *.o lab8


