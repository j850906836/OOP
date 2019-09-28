#ifndef _BAG_H
#define _BAG_H

using namespace std;
template <class T_Bag>
class Bag {
public:
	Bag();
	~Bag();
	Bag(const Bag& a);
	Bag & operator = (const Bag<T_Bag> &a);
	bool insert(const T_Bag &value);
	bool contains(const T_Bag &value) const;
	bool empty() const;
	bool ended() const;
	int erase(const T_Bag &value);
	int eraseAll(const T_Bag &value);
	int size() const;
	int uniqueSize() const;
	int count(const T_Bag &value) const;
	int currentCount() const;
	void start();
	void next();
	void combine(Bag<T_Bag> &bag1, Bag<T_Bag> &bag2, Bag<T_Bag> &result);
	void subtract(Bag<T_Bag> &bag1, Bag<T_Bag> &bag2, Bag<T_Bag> &result);
	void traversal(Bag<T_Bag> &a);
	const T_Bag& currentValue() const;
private:
	struct dlinked{
		struct dlinked *llink;
		T_Bag item;
		struct dlinked *rlink;
	};
	struct dlinked *Blist;
	struct dlinked *finger;
	int Isize;
	int F_init;
	int F_num;
};
#endif
