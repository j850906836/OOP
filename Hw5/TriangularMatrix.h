#ifndef TriangularMatrix_H
#define TriangularMatrix_H
#include <iostream>
#include <iomanip>
using namespace std;
class Matrix {
public:
	Matrix(int n);
	~Matrix();
	Matrix(const Matrix& m);
	void readMatrix();
	int size() const;
	const Matrix& operator=(const Matrix& m);
	friend ostream& operator<<(ostream& out,const Matrix& x);
	friend Matrix operator*(const Matrix& lt,double s);
	friend Matrix operator*(double s , const Matrix& rt);
	friend Matrix operator+(const Matrix& lt,const Matrix& rt);
	friend Matrix operator-(const Matrix& lt,const Matrix& rt);
	friend Matrix operator*(const Matrix& lt,const Matrix& rt);
	Matrix& operator+=(const Matrix& m);
	Matrix& operator-=(const Matrix& m);
	Matrix& operator*=(const Matrix& m);
	Matrix& operator*=(double s);
	double operator()(int i,int j) const;
private:
	double *arr;
	int element;
	int msize;
	int type;
};
#endif

Matrix::Matrix(int n=2) {
	arr = new double[3];	
	type = 1;
	arr[0] = arr[1] = arr[2] = 0;
	element = 3;
	msize = 2;
	cout<<"constructed"<<endl;
}
Matrix::~Matrix() {
	delete [] arr;	
	cout<<"destructed"<<endl;
}
Matrix::Matrix(const Matrix& m) {
	element = m.element;
	msize = m.msize;
	type = m.type;
	arr = new double[element];
	int i=0;
	
	while(i<element) {
		arr[i] = m.arr[i];
		i++;
	}
		
	cout<<"copy constructor"<<endl;
}
void Matrix::readMatrix() {
	int i=0;
	double input;
	cout<<"Please input number of rows"<<endl;
	cin>>msize;
	if(msize>2){
	delete [] arr;		
	element = (msize+1)*msize/2;
	arr = new double[element];
	}
	cout<<"input '0' for lower triangular||input '1' for upper triangular"<<endl;
	cin>>type;
	cout<<"input elements of the matrix"<<endl;
	while(i<element) {
		cin>>input;
		arr[i++] = input;
	}
}
int Matrix::size() const {
	return msize;
}
const Matrix&Matrix::operator=(const Matrix& m) {
	if( this == &m ) return *this;
	int i=0;
	if(msize<m.msize) {
	delete [] arr;
	this->arr = new double[m.element];
	}
	while(i<m.element){
		arr[i] = m.arr[i];
		i++;
	}
	this->element = m.element;
	this->msize = m.msize;
	this->type = m.type;
	return *this;
}
ostream& operator<<(ostream& out,const Matrix& x) {
	int n=0,i=0,j,row,col=1;
	cout<<endl;
	if(x.type==0) {
		for(row=0; row<x.msize; row++) {
			for(j=0; j<col; j++) cout<<setw(8)<<x.arr[i++]<<"  ";
			
			for(j=0; j<x.msize-col; j++) cout<<setw(8)<<"0"<<"  ";
			col++;
			cout<<endl;
		}
		cout<<endl;
	}
	else if(x.type==1) {
		col=x.msize;
		for(row=0; row<x.msize; row++) {
			
			for(j=0; j<x.msize-col; j++) cout<<setw(8)<<"0"<<"  ";
			
			for(j=0; j<col; j++) cout<<setw(8)<<x.arr[i++]<<"  ";
			
			col--;
			cout<<endl;
		}
		cout<<endl;
	}
}
Matrix operator*(const Matrix&lt , double s ) {
	Matrix tmp=lt;
	int i=0;
	while(i<tmp.element) {
		tmp.arr[i] = tmp.arr[i]*s;
		i++;
	}
	return tmp;
}
Matrix operator*(double s , const Matrix&rt) {
	Matrix tmp=rt;
	int i=0;
	while(i<tmp.element) {
		tmp.arr[i] = tmp.arr[i]*s;
		i++;
	}
	return tmp;
}
Matrix operator+(const Matrix& lt,const Matrix& rt){
	if(lt.type!=rt.type){
		Matrix tmp;
		return tmp;
	}
	else if(lt.msize!=rt.msize) {
		Matrix tmp;
		return tmp;
	}
	else {
		Matrix tmp=rt;
		tmp+=lt;
		return tmp;
	}
}
Matrix operator-(const Matrix& lt,const Matrix& rt){
	if(lt.type!=rt.type){
		Matrix tmp;
		return tmp;
	}
	else if(lt.msize!=rt.msize) {
		Matrix tmp;
		return tmp;
	}
	else {
		Matrix tmp=rt;
		tmp-=lt;
		return tmp;
	}
}
Matrix operator*(const Matrix& lt,const Matrix& rt) {
	if(lt.type!=rt.type){
		Matrix tmp;
		return tmp;
	}
	else if(lt.msize!=rt.msize) {
		Matrix tmp;
		return tmp;
	}
	else {
		Matrix tmp=rt;
		tmp*=lt;
		return tmp;
	}
}
Matrix& Matrix::operator+=(const Matrix& m) {
	if(m.type!=type){
		cout<<"you cannot plus an upper triangular matrix with a lower traingular matrix"<<endl;
	}
	else if(m.element!=element) {
		cout<<"you cannot plus two matrix with different size"<<endl;
	}
	else {
		int i=0;
		while(i<element) {
			arr[i] = arr[i] + m.arr[i];
			i++;
		}
	}
}
Matrix& Matrix::operator-=(const Matrix& m) {
	if(m.type!=type){
		cout<<"you cannot plus an upper triangular matrix with a lower traingular matrix"<<endl;
	}
	else if(m.element!=element) {
		cout<<"you cannot plus two matrix with different size"<<endl;
	}
	else {
		int i=0;
		while(i<element) {
			arr[i] = arr[i] - m.arr[i];
			i++;
		}
	}
}
Matrix& Matrix::operator*=(const Matrix& m) {
	if(m.type!=type){
		cout<<"you cannot times an upper triangular matrix with a lower traingular matrix"<<endl;
	}
	else if(m.element!=element) {
		cout<<"you cannot plus two matrix with different size"<<endl;
	}
	else {
		int i=0,j,cnt=0,k,a;
		double tmp[element];
		if(type==0) {
			a=0;	
			for(j=0;j<msize;j++) {
				for(i=0;i<msize;i++) {	
					for(k=0;k<msize;k++){
						if(i<=j) {
							tmp[a] += (*this)(j,k)*m(k,i);	
						}
					}
					if(i<=j) a++;
				}
			}
		}
		if(type==1) {
			a=0;	
			for(j=0;j<msize;j++) {
				for(i=0;i<msize;i++) {	
					for(k=0;k<msize;k++){
						if(j<=i) {
							tmp[a] += (*this)(j,k)*m(k,i);	
						}
					}
					if(j<=i) a++;
				}
			}
		}
		i=0;
		while(i<element){
			arr[i] = tmp[i];
			i++;
		}
	}
}
Matrix& Matrix::operator*=(double s) {
	int i=0;
	while(i<element) {
		arr[i] = arr[i] * s;
		i++;
	}
}
double Matrix::operator()(int i,int j) const {
	int n,row,col,a=0,b=0;
	double rec[msize*msize];
	n=i*msize+j;
	if(i>msize||j>msize) return double();
	if(type==0) {
		col=1;
		for(row=0; row<msize; row++) {
			for(j=0; j<col; j++) {
				rec[b]=arr[a];
				b++;
				a++;
			}
			
			for(j=0; j<msize-col; j++) rec[b++]=0;
			col++;
		}	
	}
	else if(type==1) {
		col=msize;	
		for(row=0; row<msize; row++) {
			
			for(j=0; j<msize-col; j++) rec[b++]=0.0;
			
			for(j=0; j<col; j++) {
				rec[b]=arr[a];
				b++;
				a++;
			}
			col--;
		}
	}
	return rec[n];
}
