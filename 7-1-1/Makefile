all: shapes

shapes: main.o shape.o
	g++ -o shapes main.o shape.o

main.o: main.cpp shape.h
	g++ -c -o main.o main.cpp

shape.o: shape.cpp shape.h
	g++ -c -o shape.o shape.cpp

clean:
	rm shapes *.o