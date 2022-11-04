all: count

count: main.o
	g++ -o count main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm count *.o *.txt