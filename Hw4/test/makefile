all:exe
exe:main.o Bag.h
	g++ -g -w main.o
main.o:main.cpp Bag.h
	g++ -c -g -w main.cpp
clean:
	rm -f *.o
