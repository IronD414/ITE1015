all: my_clock

my_clock: main.o my_clock.o
	g++ -o my_clock main.o my_clock.o

main.o: main.cpp my_clock.h
	g++ -c -o main.o main.cpp

my_clock.o: my_clock.cpp my_clock.h
	g++ -c -o my_clock.o my_clock.cpp

clean:
	rm my_clock *.o