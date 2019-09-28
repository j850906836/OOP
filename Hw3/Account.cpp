#include "Account.h"
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

char tmp[100] = {0};

Account::Account(int init, int _ID,string _name) {
		i=0;
		Amount=init;
		ID = _ID;
		cout<<"Account constructed"<<endl; 
		nname = _name;
		string str="Create";
		strcpy(t_trans[i],str.c_str());
		t_amount[i++]=0;
}
bool Account::withdraw(int money) {
		
		deductAmount=money;
		if( (Amount-deductAmount) >= 0 ){
			Amount-=deductAmount;
			string str="Withdraw";
			strcpy(t_trans[i],str.c_str());
			t_amount[i++]=deductAmount;	
			return true;
		}
		else
			return false;
}
bool Account::deposit(int addAmount) {
		Amount+=addAmount;
		string str="Deposit";
		strcpy(t_trans[i],str.c_str());
		t_amount[i++]=addAmount;
		return true;
}
bool Account::transferMoney(Account &AccountOfB, int money) {
		
		amountToTransfer=money;	
		if( (Amount-amountToTransfer) >= 0 ){
			Amount-=amountToTransfer;
			string strr = AccountOfB.getName();
			strcpy(t_account[i],strr.c_str());
			AccountOfB.deposit(amountToTransfer);
			string str = "Transferred";
			strcpy(t_trans[i],str.c_str());
			t_amount[i++]=amountToTransfer;
			return true;
		}
		else 
			return false;
}
int Account::getAmount() {
	return Amount;
}
string& Account::getName() {
	return nname;	
}
int Account::get_cnt() {
	return i;
}
int* Account::get_amount() {
	int *r_amount=t_amount;
	return r_amount;
}
char* Account::get_trans(int n) {
	j=n;
	char *r_trans = t_trans[j];
	return r_trans;
}
char* Account::get_account(int n) {
	j=n;
	char *r_account = t_account[j];
	return r_account;
}
