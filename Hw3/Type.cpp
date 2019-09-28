#include "Type.h"
using namespace std;

Type::Type(int _amount,char _type, Account &_account) {
	amount[i]=_amount;
	strcpy(type[i],_type);
	acc[i]=_account;
	i++;
}
