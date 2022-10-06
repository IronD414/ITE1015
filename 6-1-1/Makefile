all: Animal

Animal: main.o animal.o
	g++ -o Animal main.o animal.o

main.o: main.cpp animal.h
	g++ -c -o main.o main.cpp

animal.o: animal.cpp animal.h
	g++ -c -o animal.o animal.cpp

clean:
	rm Animal *.o