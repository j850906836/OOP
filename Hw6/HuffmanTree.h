#ifndef _HuffmanTree_H
#define _HuffmanTree_H
#include <string>
using namespace std;
class Node {
public:
	Node();	
	int getFeq();
	virtual int getNodeType()=0;
	virtual char getValue()=0;
	virtual Node* getLChild()=0;
	virtual Node* getRChild()=0;
protected:
	int freq;
};

class HuffmanTree {
public:		
	HuffmanTree(const string& s);
	void encoding(Node*,string);
	~HuffmanTree();
	void Clear(Node*);
	string encode(const string& s) const;
	string decode(const string& s) const;
private:
	Node* root;
	int cnt;
	typedef struct {
		char ascii;
		string code;
	}enc;
	enc encod[130];
};

class InternalNode : public Node {
public:		
	InternalNode( Node* L,Node* R );
	int getNodeType();
	Node* getLChild();
	Node* getRChild();
	char getValue();
private:
	Node* lChild;
	Node* rChild;
};

class TerminalNode : public Node {
public:		
	TerminalNode(char value,int freq);
	int getNodeType();
	Node* getLChild();
	Node* getRChild();
	char getValue();
private:
	char value;
};
#endif
