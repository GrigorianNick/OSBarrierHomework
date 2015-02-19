all: main

main: barrier.o main.o
	g++ barrier.o main.o -o barrier

barrier.o: barrier.cpp
	g++ -c barrier.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
	rm barrier
