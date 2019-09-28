all: Lab9

Lab9: main.o secondGreatest.o readData.o
		g++ -o Lab9 main.o secondGreatest.o readData.o

main.o: main.cpp
		g++ -c main.cpp

secondGreatest.o: secondGreatest.cpp
		g++ -c secondGreatest.cpp

readData.o: readData.cpp
		g++ -c -std=c++11 readData.cpp

clean:
		rm *o Lab9


































