#include <iostream>
#include "Account.h"
#include "User.h"

int main()
{
	
	User u1("john");
	User u2("mary");

	Account &a1 = u1.getAccount();
	a1.deposit(400);
	a1.withdraw(100);
	cout<<"Balance of "<<u1.getUsername()<<" account is "<<a1.getAmount()<<endl;

	a1.transferMoney(u2.getAccount(),200);
	cout<<"Balance of "<<u1.getUsername()<<" account is "<<a1.getAmount()<<endl;
	cout<<"Balance of "<<u2.getUsername()<<" account is "<<u2.getAccount().getAmount()<<endl;
	cout<<"ID of "<<u1.getUsername()<<" is "<<u1.getID()<<endl;
	cout<<"ID of "<<u2.getUsername()<<" is "<<u2.getID()<<endl;
	u2.getTrans();
	u1.getTrans();//call getTrans will automatically call print(),so you don't have to call print() in main function
	return 0;
}
