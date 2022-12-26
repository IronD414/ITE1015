all: exception1

exception1: main.o
	g++ -o exception1 main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm exception1 main.o