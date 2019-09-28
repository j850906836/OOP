#include "User.h"
#include <iostream>
using namespace std;

static int a=-1;
User::User(string _name):account(0,ID,_name) {
	cout<<"User constructed"<<endl;
	name = _name;
	a++;
	ID = a;
}
string& User::getUsername() {
	return name;
}
Account& User::getAccount() {
	Account &a=account;
	return a;	
}	
int User::getID() {
	return ID;
}
void User::getTrans() {
	int j;
	int i = account.get_cnt();
	for(j=0;j<i;j++){ 
		*(trans+j) = account.get_trans(j);
		*(transferto+j)=account.get_account(j);
	}
	amount = account.get_amount();
	Transaction t1(account,"Create");
	cout<<"the detail of "<<name<<" is:"<<endl;
	t1.print(trans,transferto,amount,i);
}

