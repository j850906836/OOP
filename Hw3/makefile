all:main11
main11:main.o User.o Account.o Transaction.o
	g++ main.o Account.o User.o Transaction.o
main.o:main.cpp 
	g++ -c main.cpp
Account.o:Account.cpp
	g++ -c Account.cpp
User.o:User.cpp
	g++ -c User.cpp
Transaction.o:Transaction.cpp
	g++ -c Transaction.cpp
clean:
	rm -rf *.o
