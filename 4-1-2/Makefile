all: simple_account

simple_account: main.o accounts.o
	g++ -o simple_account main.o accounts.o

main.o: main.cc accounts.h
	g++ -c -o main.o main.cc

accounts.o: accounts.cc accounts.h
	g++ -c -o accounts.o accounts.cc

clear:
	rm simple_account *.o