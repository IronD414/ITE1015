all: hello_world.o input_num.o
	g++ -o hello_world hello_world.o
	g++ -o input_num input_num.o
hello_world.o: hello_world.cc
	g++ -c –o hello_world.o hello_world.cc
input_num.o: input_num.cc
	g++ -c –o input_num.o input_num.cc
clean:
	rm hello_world.o hello_world input_num.o input_num

