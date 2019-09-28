#include "User.h"
#include "Account.h"
#include <iostream>
using namespace std;


Transaction::Transaction(Account &acc,string type)
{
	cout<<"Transaction constructed"<<endl;	
}
void Transaction::print(char *type[],char *acc[],int *amount,int i) {
	int j=0;
	for( j=0; j<i; j++ ) {
		T_amount=*(amount+j);
		T_account=*(acc+j);
		T_type=*(type+j);
		if( T_amount == 0 )
			cout<<"TYPE: "<<T_type<<endl;
		else if( strcmp(T_account,"")==0 )
			cout<<"TYPE: "<<T_type<<" "<<T_amount<<endl;
		else
			cout<<"TYPE: "<<T_type<<" "<<T_amount<<" to "<<T_account<<endl;	
	}
}
