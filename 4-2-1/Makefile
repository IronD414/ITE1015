all: LinkedList

LinkedList: main.o LinkedList.o
	g++ -o LinkedList main.o LinkedList.o

main.o: main.cc LinkedList.h
	g++ -c -o main.o main.cc

LinkedList.o: LinkedList.cc LinkedList.h
	g++ -c -o LinkedList.o LinkedList.cc

clear:
	rm LinkedList *.o