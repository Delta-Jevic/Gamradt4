runqueue :  main.o Queue.o
	g++ -std=c++11 -o runqueue main.o Queue.o

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

Queue.o : Queue.h  Queue.cpp
	g++ -std=c++11 -c Queue.cpp

clean :
	rm runqueue main.o Queue.o