all:exe
exe:main.o TriangularMatrix.h
	g++ -g main.o
main.o:main.cpp TriangularMatrix.h
	g++ -g -c main.cpp
clean:	
	rm -f *.o
