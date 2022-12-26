all: list

list: main.o
	g++ -o list main.o

main.o: main.cpp list.h
	g++ -c -o main.o main.cpp

clean:
	rm list main.o