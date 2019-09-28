#include <string>
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

using namespace std;
class Account {
public:		
	Account(int,int,string);
	bool withdraw(int deductAmount);
	bool deposit(int addAmount);
	bool transferMoney(Account &AccountOfB, int amountToTransfer);
	int getAmount();
	string &getName();
	int get_cnt();
	char *get_trans(int);
	int *get_amount();
	char *get_account(int);
private:
	int Amount;
	int ID;
	int i;
	int j;
	int deductAmount;
	int amountToTransfer;
	string nname;
	char t_trans[100][100];
	int t_amount[100];
	char t_account[100][100];
};
#endif
