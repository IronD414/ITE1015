all: message_book

message_book: main.o message.o
	g++ -o message_book main.o message.o

main.o: main.cpp message.h
	g++ -c -o main.o main.cpp

message.o: message.cpp message.h
	g++ -c -o message.o message.cpp

clean:
	rm message_book *.o