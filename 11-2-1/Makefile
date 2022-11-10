all: MyVector

MyVector: main.o my_vector.o
	g++ -o MyVector main.o my_vector.o

main.o: main.cpp my_vector.h
	g++ -c -o main.o main.cpp

my_vector.o: my_vector.cpp my_vector.h
	g++ -c -o my_vector.o my_vector.cpp

clean:
	rm MyVector *.o