#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "User.h"
#include "Account.h"
using namespace std;

class Transaction {
public:
	Transaction(Account &account,string type);
	void print(char *[],char *[],int *amount,int);
private:
	int T_amount;
	char *T_account;
	char *T_type;
};
#endif
