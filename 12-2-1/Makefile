all: calendar

calendar: main.o calendar.o
	g++ -o calendar main.o calendar.o

main.o: main.cpp calendar.h
	g++ -c -o main.o main.cpp

calendar.o: calendar.cpp calendar.h
	g++ -c -o calendar.o calendar.cpp

clean:
	rm calendar *.o