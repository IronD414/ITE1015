all: Animal

Animal: main.o animal.o
	g++ -o Animal main.o animal.o

main.o: main.cc animal.h
	g++ -c -o main.o main.cc

animal.o: animal.cc animal.h
	g++ -c -o animal.o animal.cc

clean:
	rm Animal *.o