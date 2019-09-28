#include <cstring>
#ifndef USER_H
#define USER_H
#include "Account.h"
#include "Transaction.h"
using namespace std;

class User{
public:
	User(string);
	string &getUsername();
	Account &getAccount();
	int getID();
	void getTrans();
private:
	string name;
	int ID;
	Account account;
	Transaction *transa;
	char *trans[100];
	int *amount;
	char *transferto[100];
};
#endif
