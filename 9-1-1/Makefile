all: integer_set

integer_set: main.o intset.o
	g++ -o integer_set main.o intset.o

main.o: main.cpp intset.h
	g++ -c -o main.o main.cpp

intset.o: intset.cpp intset.h
	g++ -c -o intset.o intset.cpp

clean:
	rm integer_set *.o