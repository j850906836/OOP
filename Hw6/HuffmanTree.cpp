#include "HuffmanTree.h"
#include <iostream>
#include <string.h>
#include <map>
#include <queue>
using namespace std;
HuffmanTree::HuffmanTree(const string& s) {
	int size=s.size(),add,differ=-1,i,j,temp;
	cnt=0;
	char chr[size+1] ,*ptr,tmp;
	strcpy(chr,s.c_str());
	ptr = chr;
	typedef struct {
		char value;
		int freq;
	}fre;
	fre cnt[size];

	while( *ptr!='\0' ) {
		if( *ptr>=32 && *ptr<=126 ) {
			add=0;	
			for( i=0; i<=differ; i++ ) {	
				if( cnt[i].value==*ptr ) {
					cnt[i].freq++;
					add=1;
					break;
				}
			}
			if(add==0) {
				differ++;
				cnt[differ].value=*ptr;
				cnt[differ].freq=1;
			}
			ptr++;
		}
	}

	i=0;
	priority_queue<pair<int,Node*>,vector< pair<int,Node*> >,greater< pair<int,Node*> > > nodes;
	TerminalNode *ter;
	InternalNode *inter;
	while( i<differ ) {
		ter = new TerminalNode(cnt[i].value,cnt[i].freq);	
		nodes.push(make_pair(cnt[i].freq,ter));
		i++;
	}
	int mode=-1;
	pair<int,Node*> Right,Left;
	while(!nodes.empty()) {
		Right = nodes.top();nodes.pop();
		if(nodes.empty()) mode=0;
		Left = nodes.top();nodes.pop();
		if(nodes.empty()) mode=1;
		inter = new InternalNode(Left.second,Right.second);
		if(nodes.empty()) {
			mode=2;
			break;
		}	
		nodes.push(make_pair(Left.second->getFeq()+Right.second->getFeq(),inter));
	}
	if(mode==0) root=Right.second;
	if(mode==1) root=Left.second;
	if(mode==2) root=inter;
	i=0;
	string tmpp;
	encoding(root,tmpp);
	i=0;
	cout<<"------Huffman Code Index--------"<<endl<<endl;
	while( i<differ ) {
		cout<<encod[i].ascii<<" "<<encod[i].code<<endl;
		i++;
	}
	cout<<"--------------------------------"<<endl;
}
HuffmanTree::~HuffmanTree() {
	Clear(root);
}
void HuffmanTree::Clear(Node* node) {
	if( node!=NULL ) {
		Clear(node->getLChild());
		Clear(node->getRChild());
		delete node;
	}
}
void HuffmanTree::encoding(Node* root,string tmp) {
		if(root->getRChild()!=NULL)
			encoding(root->getRChild(),tmp+'1');
		if(root->getLChild()!=NULL)
			encoding(root->getLChild(),tmp+'0');
		if(root->getValue()!=0) {
			encod[cnt].ascii = root->getValue();
			encod[cnt++].code = tmp;
		}
}
string HuffmanTree::encode(const string& s) const{
	int size=s.size(),i,in;
	char chr[size+1] ,*ptr;
	string encd;
	strcpy(chr,s.c_str());
	ptr = chr;
	while(*ptr!='\0') {
		in = 0;	
		for(i=0;i<cnt;i++) {
			if(*ptr==encod[i].ascii) {
				in=1;
				break;	
			}
		}
		if(in==0) {
			string empty;
			cout<<"error:character can not be encode"<<endl;
			return empty;
		}
		else {
			encd+=encod[i].code;
			ptr++;
		}
	}
	return encd;
}
string HuffmanTree::decode(const string& s) const{
	string old=s , fd , empty;
	int len,i,in,j=0;
	char arr[old.length()]={0};
	while(!old.empty()) {
		in=0;
		for(i=0;i<cnt;i++) {
			len=encod[i].code.length();
			fd = fd.assign(old,0,len);
			if( fd==encod[i].code ) {
				arr[j++]=encod[i].ascii;
				in=1;
				break;
			}
		}
		if(in==0) {
			cout<<"error:sequence "<<s<<" can not be encoded"<<endl;
			return empty;
		}
		else old.erase(old.begin(),(old.begin()+fd.length()));
	}
	string decd(arr);
	return decd;
}
Node::Node() {
	freq = 2;
}
int Node::getFeq() {
	return freq;
}

InternalNode::InternalNode(Node* L, Node* R) {
	lChild = L;
	rChild = R;
	freq = L->getFeq()+R->getFeq();
}
int InternalNode::getNodeType() {
	return 1;
}
Node* InternalNode::getLChild() {
	return lChild;
}
Node* InternalNode::getRChild() {
	return rChild;
}
char InternalNode::getValue() {
	cout<<"Internal Node does not have value"<<endl;
	return 0;
}
TerminalNode::TerminalNode(char val,int frq) {
	value = val;
	freq = frq;
}
int TerminalNode::getNodeType() {
	return 0;	
}
Node* TerminalNode::getLChild() {
	cout<<"Terminal Node does not have LChild"<<endl;
	return NULL;
}
Node* TerminalNode::getRChild() {
	cout<<"Terminal Node does not have RChild"<<endl;
	return NULL;
}
char TerminalNode:: getValue() {
	return value;
}
