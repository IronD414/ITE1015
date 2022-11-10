all: string

string: main.o my_string.o
	g++ -o string main.o my_string.o

main.o: main.cpp my_string.h
	g++ -c -o main.o main.cpp

my_string.o: my_string.cpp my_string.h
	g++ -c -o my_string.o my_string.cpp

clean:
	rm string *.o