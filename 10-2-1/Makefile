all: match

match: main.o
	g++ -o match main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm match *.o