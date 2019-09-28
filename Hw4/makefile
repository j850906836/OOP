all:main
main:main.o Bag.o Bag.h
	g++ -g -w main.o Bag.o
main.o:main.cpp Bag.cpp
	g++ -c -g -w main.cpp
Bag.o:Bag.cpp Bag.h 
	g++ -c -g -w Bag.cpp
clean:
	rm -f *.o
