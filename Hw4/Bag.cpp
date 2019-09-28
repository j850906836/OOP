#include "Bag.h"
#include <iostream>
using namespace std;

template <class T_Bag>
Bag<T_Bag>::Bag() {
	this->Isize = 0;
	finger = new(struct dlinked);
//	Blist = new(struct dlinked);
	F_init = 0;
	F_num = 0;
	cout<<"Bag construct"<<endl;
}

template <class T_Bag>
Bag<T_Bag>::~Bag() {
	int n=0;
	finger = Blist;
	while( n<this->Isize ) {
		struct dlinked *next = finger->rlink; 	
		delete(finger);
		finger=next;
		n++;
	}
	Blist=0;
	cout<<"Bag destruct"<<endl;
}
		
template <class T_Bag>
Bag<T_Bag>::Bag(const Bag &a) {
	cout<<"Bag copy construct"<<endl;
	struct dlinked *newtmp , *oldtmp,*temp;
	int n=0;
	if( a.Blist == NULL ) Blist=NULL;
	else {
		Blist = new(struct dlinked);
		Blist->item = a.Blist->item;
		newtmp = Blist;
		oldtmp = a.Blist->rlink;
	}
	while( n<a.Isize ) {
		newtmp->rlink = new(struct dlinked);
		temp = newtmp;
		newtmp = newtmp->rlink;
		newtmp->llink = temp;
		newtmp->item = oldtmp->item;
		oldtmp = oldtmp->rlink;
		n++;
	}
	F_init=a.F_init;
	F_num=a.F_num;
	Isize=a.Isize;
}
template <class T_Bag>
Bag<T_Bag>&Bag<T_Bag>::operator = (const Bag<T_Bag>&a) {
		this->Blist=a.Blist;
		this->Isize=a.Isize;
		this->F_init=a.F_init;
		this->F_num=a.F_num;
		cout<<"Bag assignment operator"<<endl;
		return *this;
}
template <class T_Bag>
bool Bag<T_Bag>::insert(const T_Bag &value) {
		struct dlinked *temp,*test;
		temp = new(struct dlinked);
		temp->item = value;
		if( this->Isize == 0 ) {
			Blist = new(struct dlinked);
			struct dlinked *init;
			init = new(struct dlinked);
			init->rlink = init;
			init->llink = init;
			Blist = init;
		}
			test=Blist->rlink;
			temp->rlink = Blist->rlink;
			temp->llink = Blist;
			Blist->rlink = temp;
			Blist = Blist->rlink;
			test=Blist->rlink;
			F_init=0;
			F_num=0;
			this->Isize++;
			if( temp != NULL ) return true;
			else return false;
}

template <class T_Bag>
bool Bag<T_Bag>::contains(const T_Bag &value) const {
		struct dlinked *temp;
		temp = new(struct dlinked);
		temp = Blist;
		int n=0;
		while( n<=this->Isize ) {
			if( value == temp->item ) return true;
			n++;
			temp = temp->llink;
		}
		return false;
}

template <class T_Bag>
bool Bag<T_Bag>::empty() const {
		if (Isize==0) return true;
		else return false;
}

template <class T_Bag>
bool Bag<T_Bag>::ended() const {
		if( F_num == 0 ) return true;
		else return false;
}

template <class T_Bag>
int Bag<T_Bag>::erase(const T_Bag &value) {
		struct dlinked *frontmp , *backtmp;
		frontmp = backtmp = Blist->rlink->rlink;
		int n=0;
		backtmp = backtmp->rlink;
		while( n<this->Isize ) {
			if( frontmp->item == value ) break;
			frontmp = frontmp->rlink;
			backtmp = backtmp->rlink;
			n++;
		}
		if( n==Isize ) return 0;
		else {
			backtmp->llink = frontmp->llink;
			frontmp = frontmp->llink;
			frontmp->rlink = backtmp;
			F_init=0;
			F_num=0;
			Isize--;
			return n+1;
		}
}

template <class T_Bag>
int Bag<T_Bag>::eraseAll(const T_Bag &value) {
		struct dlinked *frontmp , *backtmp;
		frontmp = backtmp = Blist;
		int n=0,i=0;
		frontmp = frontmp->llink;
		while( n<this->Isize ) {
			if( backtmp->item == value ) {
				frontmp->rlink = backtmp->rlink;
				backtmp = backtmp->rlink;
				backtmp->llink = frontmp;
				backtmp = backtmp->llink;
				frontmp = frontmp->llink;
				i++;
				F_init=0;
				F_num=0;
			}
			else {
				backtmp = backtmp->llink;
				frontmp = frontmp->llink;
			}
			n++;
		}
		Isize-=i;
		return i;
}
template <class T_Bag>
int Bag<T_Bag>::size() const {
		return this->Isize;
} 

template <class T_Bag>
int Bag<T_Bag>::uniqueSize() const {
		if(Isize==0) return 0;
		int n=0,u=0,i=0;
		T_Bag *arr = new T_Bag[Isize+1];
		struct dlinked *temp;
		temp = new(struct dlinked);
		temp = Blist->rlink->rlink;
		while( n<this->Isize ) {
			for(i=0; i<u; i++) 	if( arr[i] == temp->item ) break;	
			
			if( i==u ) arr[u++]=temp->item;
			temp=temp->rlink;
			n++;
		}
		return u;
}

template <class T_Bag>
int Bag<T_Bag>::count(const T_Bag &value) const {
		struct dlinked *temp;
		temp = new(struct dlinked);
		temp = Blist->rlink->rlink;
		int n=0,i=0;
		while( n<this->Isize ) {
			if( temp->item == value ) i++;
			temp = temp->rlink;
			n++;
		}
		return i;
}

template <class T_Bag>
int Bag<T_Bag>::currentCount() const {
		if( F_init==0 ) {
			cout<<"Please initialize"<<endl;
			return 0;
		}
		else 
			return F_num;
}
template <class T_Bag>
void Bag<T_Bag>::start() {
		if( Isize == 0 ) {
			cout<<"Please input item"<<endl;
			return;
		}
		else {	
			finger = Blist->rlink->rlink;
			F_num++;
			F_init=1;
		}
}
template <class T_Bag>
void Bag<T_Bag>::next() {
		if( F_init==0 ) {
			cout<<"Please initialize"<<endl;
			return;
		}
		else {
			finger = finger->rlink;
			F_num++;
			if( finger == Blist->rlink ) {
				finger = NULL;
				F_num=0;
			}
		}
}
template <class T_Bag>
void combine(Bag<T_Bag> &bag1,Bag<T_Bag> &bag2, Bag<T_Bag> &result) {
	if(&bag1==&bag2 && &bag1==&result) {
		int n=bag1.size(),j=0;
		while(j<n){
			bag1.start();
			for(int i=0; i<j; i++)	bag1.next();
			bag1.insert(bag1.currentValue());
			j++;
		}
		return;
	}	
	else if(&bag1==&result){
		bag2.start();
		while(!bag2.ended()){	
			if(bag2.ended()) break;
			bag1.insert(bag2.currentValue());
			bag2.next();
			
		}
		
		return;
	}
	else{
	int n=result.uniqueSize();
	for(int i=0; i<n; i++) {
		result.start();
		result.eraseAll(result.currentValue());
	}
	bag1.start();
	while(!bag1.ended()){
		result.insert(bag1.currentValue());
		bag1.next();
	}
	
	bag2.start();
	while(!bag2.ended()){	
		result.insert(bag2.currentValue());
		bag2.next();
	}
	return;
	}

}

template <class T_Bag>
void subtract(Bag<T_Bag> &bag1,Bag<T_Bag> &bag2, Bag<T_Bag> &result) {
	if(&bag1==&bag2 && &bag1==&result) {
		int j=bag1.uniqueSize();
		for( int i=0; i<j; i++ ) {	
			bag1.start();
			bag1.eraseAll(bag1.currentValue());
		}
		return;
	}
	else if(&bag1==&bag2) {
		int j=result.uniqueSize();
		for( int i=0; i<j; i++ ) {	
			result.start();
			result.eraseAll(bag1.currentValue());
		}
		return;
	}
	else if( &bag2==&result ) {
		int n=bag2.size(),i=0,j=result.uniqueSize();	
		T_Bag *arr = new T_Bag[n];
		bag2.start();
		for(i=0; i<n; i++) {
			arr[i]=bag2.currentValue();
			bag2.next();
		}
		for(int i=0; i<j; i++) {
			result.start();
			result.eraseAll(result.currentValue());
		}
		bag1.start();
		while(!bag1.ended()){
			result.insert(bag1.currentValue());
			bag1.next();
		}
		for(i=0; i<n; i++){
			result.erase(arr[i]);	
		}
			return;
	}
	else if( &bag1==&result ) {
		int a;
		bag2.start();
		while(!bag2.ended()) {
			a=result.count(bag2.currentValue());
			if( a>0 ) result.erase(bag2.currentValue());
			bag2.next();
		}
		return;
	}
	else {		
		int a,b;
		int n=result.uniqueSize();
		for(int i=0; i<n; i++) {
			result.start();
			result.eraseAll(result.currentValue());
		}
		bag1.start();
		while(!bag1.ended()){
			result.insert(bag1.currentValue());
			bag1.next();
		}
		
		bag2.start();
		while(!bag2.ended()) {
			a=result.count(bag2.currentValue());
			if( a>0 ) result.erase(bag2.currentValue());
			bag2.next();
		}
	}
}
template <class T_Bag>
void traversal(Bag<T_Bag> &a) {
	a.start();
	while(!a.ended()){
		cout<<a.currentValue()<<endl;
		a.next();
	}
}
template <class T_Bag>
const T_Bag& Bag<T_Bag>::currentValue() const{
		if( F_init==0 ) {
			cout<<"Please initialize";
			return T_Bag();
		}
		else 
			return finger->item;
}
