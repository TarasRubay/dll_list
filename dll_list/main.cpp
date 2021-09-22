#include "dll.h"
int main() {
	dll<int> lst;
	lst.push_front(126);
	lst.push_back(278);
	lst.push_back(396);
	lst.push_back(478);
	//lst.remove(222);
	lst.push_back(524);
	lst.insert(675757, 478);
	lst.insert(573763, 524);
	cout << lst.to_string();

	int a =  lst.at(2);
	lst.output();
	dll<int> l = lst;
	cout << "\nlength - " << lst.size();
	lst.clear();
	cout << "\nlength - " << lst.size();
	cout << endl;
	lst = 652;
	l += 68686;
	l.output();
	cout << "\nlength - " << l.size()<<endl;
	lst.clear();
	l.clear();
	for (int i = 0; i < 5; i++)
	{
		lst.push_front(i);
		l.push_front(i);
	}
	l.at(1);
	l.at(5);

	dll<int> N = lst + l;
	
	N.output();
	
	lst.clear();
	l.clear();
	for (int i = 0; i < 3; i++)
	{
		lst.push_front(i+11);
		l.push_front(i+11);
	}
	l.pop_back();
	N.clear();
	N = lst * l;
	//dll<int> R = lst * l;
	N.output();
	return 0;
}