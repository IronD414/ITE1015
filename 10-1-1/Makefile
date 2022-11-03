all: sorted_array

sorted_array: main.o sorted.o
	g++ -o sorted_array main.o sorted.o

main.o: main.cpp sorted.h
	g++ -c -o main.o main.cpp

sorted.o: sorted.cpp sorted.h
	g++ -c -o sorted.o sorted.cpp

clean:
	rm sorted_array *.o