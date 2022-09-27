all: draw_shape

draw_shape: main.o shapes.o
	g++ -o draw_shape main.o shapes.o

main.o: main.cc shapes.h
	g++ -c -o main.o main.cc

shapes.o: shapes.cc shapes.h
	g++ -c -o shapes.o shapes.cc

clean:
	rm draw_shape *.o