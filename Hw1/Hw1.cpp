#include <iostream>
#include <locale>
#include <string>

using namespace std;
int main(int argc , char *argv[])
{

		string str(argv[1]);										// turn argument to string
		cout<< str << endl;	
	
		int len = str.size() , j=0 , cnt=0 , i;
		char array[len+1];	

		for( i=0; i<len; i++ ) {										
			if( isalpha(str[i]) ) {									//find letters only, and put it inot an array
				str[i] = tolower(str[i]);							//transfer uppercase to lowercase
				array[j++] = str[i];
			}
		}
		len = j;
		for( i=0; i<len/2; i++,j-- ) {								//create a loop to check whether the string is palindrome
			if( array[i] == array[j-1] )
				cnt++;														
		}
		if( cnt == len/2 )											//if cnt equals len/2(odd or even doesn't matter,since "len" is integer) , it means the string is palindorme		
			cout << "This String is Palindrome" <<endl;
		else
			cout << "This String is not Palindrome" << endl;	
}
