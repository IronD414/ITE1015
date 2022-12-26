all: exception2

exception2: main.o
	g++ -o exception2 main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm exception2 main.o