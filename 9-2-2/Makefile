all: simple_int_set

simple_int_set: main.o setfunc.o
	g++ -o simple_int_set main.o setfunc.o

main.o: main.cpp setfunc.h
	g++ -c -o main.o main.cpp

setfunc.o: setfunc.cpp setfunc.h
	g++ -c -o setfunc.o setfunc.cpp

clean:
	rm simple_int_set *.o