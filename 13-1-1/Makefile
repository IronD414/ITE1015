all: container

container: main.o
	g++ -o container main.o

main.o: main.cpp my_container.h
	g++ -c -o main.o main.cpp

clean:
	rm container main.o