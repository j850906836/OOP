#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
int fword( char * , char [] , int , int &);
int locate( fstream & , char [] , int );
int main()
{
	fstream fin;
	string  cmd;
	char command[150] = {0} , comd[4][20]={0};		//command line maxsize is 150
	int i=0 , j=0,len;
	char *ptr;
	cout<<"Please enter some command, and follow the below format, otherwise it won't work"<<endl;
	cout<<"load <filename> || "<<"locate <word> <n> || "<<"new || "<<"end "<<endl;
	
	while(1){
		cout<<">>";
		cin.getline(command,150);
		len = strlen(command);
		command[len] = ' ';
		command[len+1] = '\n';
		ptr = command;
		j=0,i=0;
		while( *ptr != '\n' ) {						//get the command(seperated by space)
			while( *ptr == ' ' ) {
				ptr++;
			}
			while( *ptr != ' ' ) {
				comd[j][i++] = *ptr;	
				ptr++;
			}
			ptr++;
			i=0;
			if( j>2 ) {
				j=5;
				break;	
			}
			j++;
		}

		if( j==1 ){									// new or end 					
			if( strcmp(comd[0] , "new" ) == 0 ) 
				fin.close();	
			else if( strcmp(comd[0] , "end" ) == 0 )
				break;	
			else
				cout<<"ERROR:Invalid command"<<endl;
		}
		else if( j==2 ) {
			if( strcmp(comd[0] , "load" ) == 0 ){	// load
				fin.open(comd[1],ios::in);
				if( fin == NULL ) 
					cout<<"ERROR:Error reading from file"<<endl;	
			}
			else
				cout<<"ERROR:Invalid command"<<endl;
		}	
		else if( j==3 ) {							// locate
			if( strcmp( comd[0] , "locate" ) == 0 ){
				int n=atoi(comd[2]);
				if( n<1 ) {
					cout<<"<n> must larger than 0"<<endl;
					memset(comd[0],'\0',sizeof(comd[0]));
					memset(comd[1],'\0',sizeof(comd[1]));
					memset(comd[2],'\0',sizeof(comd[2]));
					memset(command,'\0',sizeof(command));
					continue;
				}
				n = locate( fin , comd[1] , n );
				if( n == 0 ) {
					if( fin == NULL )
						cout<<"No file, please load file"<<endl;
					else
						cout<<"No matching entry"<<endl;	
				}
				else
					cout<<"word count: "<<n<<endl;
			}
			else		
				cout<<"ERROR:Invalid command"<<endl;
		}
		else
			cout<<"ERROR:Invalid command"<<endl;
	
		memset(comd[0],'\0',sizeof(comd[0]));
		memset(comd[1],'\0',sizeof(comd[1]));
		memset(comd[2],'\0',sizeof(comd[2]));
		memset(command,'\0',sizeof(command));
	}
	return 0;
}

int locate( fstream &fin , char word[] , int n )
{
	int wordcnt = 0;
	char line[300];
	int i = 0 , state;
	fin.seekg(0,ios::beg);
	while(fin.getline( line , sizeof(line) , '\n') ){		//fetch one line from file, and store in "line" array
		i = strlen(line);
		line[i-1] = '\n';
		state = 0;
		i = fword( line , word , n , state );	
		wordcnt += i;

		if(state == 1) {
			if( n==1 )
				return wordcnt;
			else
				n--;	
		}
		else 
			continue;
	}
	fin.clear();
	fin.seekg(0);											//back to the front of file
	return 0;
}
int fword( char line[] , char word[], int n, int &state ) 
{
	char *ptr , cmp[30] = {0};
	int i=0, cnt=0;
	ptr = line;
	cnt = 0;
	while( *ptr != '\n' ) {
		while( *ptr != ' ' ) {								//get word from "line" array
			cmp[i++] = *ptr;
			ptr++;
			if( ispunct(*ptr) || *ptr == '\n' )
				break;	
		}
		if(isalpha(cmp[0])||isdigit(cmp[0]))
				cnt++;
		
		if( strcmp( cmp , word ) == 0 ) {					//compare
			state = 1;
			if( n==1 ) {
				state = 1;
				return cnt;
			}
		}
		memset( cmp , '\0' , sizeof(cmp) );
		if( *ptr == '\n' )
			break;	
		ptr++;
		i=0;
	
	}
	return cnt;
}
