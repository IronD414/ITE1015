all: calendar

calendar: main.o calendar.o
	g++ -o calendar main.o calendar.o

main.o: main.cc calendar.h
	g++ -c -o main.o main.cc

calendar.o: calendar.cc calendar.h
	g++ -c -o calendar.o calendar.cc

clean:
	rm calendar *.o