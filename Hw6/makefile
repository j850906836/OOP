all:exe
exe:main Huffman HuffmanTree.h 
	g++ -g main.o HuffmanTree.o
main:main.cpp HuffmanTree.h
	g++ -g -c main.cpp
Huffman:HuffmanTree.cpp HuffmanTree.h
	g++ -g -c HuffmanTree.cpp
clean:
	rm -f *.o 
