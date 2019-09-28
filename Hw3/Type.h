#ifndef TYPE_H
#define TYPE_H
using namespace std;

class Type {
	public:
		Type(int,char,Account&);	
	private:
		int amount[100];
		int i;
		char typ[100][100];
		Account acc[100];
};
#endif
