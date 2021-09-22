#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
template <typename t>
class dll {
	template<typename t>
	struct noda {
		t data;
		noda* p_prev;
		noda* p_next;
		noda(t _data = t(), noda* _p_next = nullptr, noda* _p_prev = nullptr) {
			this->data = _data;
			this->p_prev = _p_prev;
			this->p_next = _p_next;

		}
	};
	noda<t>* first;
	noda<t>* last;
	int length;
public:
	dll();////////////////////////////////////////////////
	dll(const dll& _tmp);/////////////////////////////////
	~dll();///////////////////////////////////////////////
	dll<t>& operator=(t _data);///////////////////////////
	dll<t>& operator=(const dll& obj);////////////////////
	dll<t>& operator+=(t _data);//////////////////////////
	t& operator[](int ind);///////////////////////////////
	void push_back(t _data);//////////////////////////////
	void pop_back();//////////////////////////////////////
	void push_front(t _data);/////////////////////////////
	void pop_front();/////////////////////////////////////
	void insert(t ins_data,t bef_data);///////////////////
	void remove(t _data);/////////////////////////////////
	t& back();////////////////////////////////////////////
	t& front();///////////////////////////////////////////
	t& at(int index);/////////////////////////////////////
	dll<t>& clear(); /////////////////////////////////////
	string to_string();///////////////////////////////////
	int size(); //////////////////////////////////////////
	bool empty();/////////////////////////////////////////
	dll<t> operator+(dll& _obj); /////////////////////////
	const dll<t> operator*(dll& _obj);////////////////////
	void output();////////////////////////////////////////
};

template<typename t>
inline dll<t>::dll()
{
	first = nullptr;
	last = nullptr;
	length = 0;
}

template<typename t>
inline dll<t>::dll(const dll& _tmp)
{   
	this->clear();
	noda<t>* tmp = _tmp.first;
	for (int i = 0; i < _tmp.length; i++)
	{
		this->push_back(tmp->data);
		tmp = tmp->p_next;
	}
}

template<typename t>
inline dll<t>::~dll()
{
	clear();
}

template<typename t>
inline dll<t>& dll<t>::operator=(t _data)
{
	this->clear();
	this->push_front(_data);
	return *this;
}

template<typename t>
inline dll<t>& dll<t>::operator=(const dll& obj)
{
	this->clear();
	noda<t>* tmp = obj.first;
	for (int i = 0; i < obj.length; i++)
	{
		this->push_back(tmp->data);
		tmp = tmp->p_next;
	}
	return *this;
}

template<typename t>
inline dll<t>& dll<t>::operator+=(t _data)
{
	this->push_front(_data);
	return *this;
}

template<typename t>
inline t& dll<t>::operator[](int index)
{
	if (size() / 2 > index) {
		noda<t>* tmp = first;
		for (int i = 0; i < length; i++)
		{
			if (i == index - 1)return tmp->data;
			else tmp = tmp->p_next;
		}
	}
	else {
		noda<t>* tmp = last;
		for (int i = length - 1; i >= 0; i--)
		{
			if (i + 1 == index)return tmp->data;
			else tmp = tmp->p_prev;
		}
	}
}

template<typename t>
inline void dll<t>::push_back(t _data)
{
	if (empty()) {
		last = new noda<t>(_data);
		first = last;
		length++;
	}
	else {
		noda<t> *tmp = this->last;
		last = new noda<t>(_data,nullptr,last);
		tmp->p_next = last;
		length++;
	}
}

template<typename t>
inline void dll<t>::pop_back()
{
	if (first != nullptr && last != nullptr) {
		if (last->p_next == nullptr && last->p_prev == nullptr) {
			delete last;
			length--;
		}
		else {
			noda<t>* tmp = last;
			last = last->p_prev;
			last->p_next = nullptr;
			delete tmp;
			length--;
			if (size() == 1)first = last;
		}
	}
}

template<typename t>
inline void dll<t>::push_front(t _data)
{
	if (empty()) {
		first = new noda<t>(_data);
		last = first;
		length++;
	}
	else {
		noda<t> *tmp = first;
		first = new noda<t>(_data,first);
		tmp->p_prev = first;
		length++;
	}
}

template<typename t>
inline void dll<t>::pop_front()
{
	if (first != nullptr && last != nullptr) {
		if (first->p_next == nullptr && first->p_prev == nullptr) {
			delete first;
			length--;
		}
		else {
			noda<t>* tmp = first;
			first = first->p_next;
			first->p_prev = nullptr;
			delete tmp;
			length--;
			if (size() == 1)last = first;
		}
	}
}

template<typename t>
inline void dll<t>::insert(t ins_data, t bef_data)
{
	if (!empty()) {
		noda<t>* tmp = first;
		if (first->data == bef_data) {
			this->push_front(ins_data);
		}
		else {
			while (tmp->p_next != nullptr) {
				if (tmp->p_next->data == bef_data) {
					noda<t>* tmp2 = tmp;
					noda<t>* insert = new noda<t>(ins_data, tmp2->p_next, tmp2);
					tmp2->p_next->p_prev = insert;
					tmp2->p_next = insert;
					length++;
				tmp = tmp->p_next;
				}
				tmp = tmp->p_next;
			}
		}
	}
}

template<typename t>
inline void dll<t>::remove(t _data)
{
	if (!empty()) {
		if (size() == 1) {
			if (first->data == _data)pop_front();
		}
		else {
			noda<t>* tmp = first;
			while (tmp->p_next != nullptr) {
				if (tmp->p_next->data == _data) {
					noda<t>* rem = tmp->p_next;
					tmp->p_next->p_prev = tmp;
					tmp->p_next = tmp->p_next->p_next;
					delete rem;
					length--;
				}
				else {
					tmp = tmp->p_next;
				}
			}
		}
	}
}

template<typename t>
inline t& dll<t>::back()
{
	return last->data;
}

template<typename t>
inline t& dll<t>::front()
{
	return first->data;
}

template<typename t>
inline t& dll<t>::at(int index)
{
	if (size() / 2 > index) {
		noda<t>* tmp = first;
		for (int i = 0; i < length; i++)
		{	
			if (i == index - 1)return tmp->data;
			else tmp = tmp->p_next;
		}
	}
	else {
		noda<t>* tmp = last;
		for (int i = length-1; i >= 0; i--)
		{
			if (i+1 == index)return tmp->data;
			else tmp = tmp->p_prev;
		}
	}
}

template<typename t>
inline dll<t>& dll<t>::clear()
{
	int siz = length;
	for (int i = 0; i < siz; i++)
	{
		noda<t> *dell = first;
		if (i < siz - 1) {
			dell->p_next->p_prev = nullptr;
			first = first->p_next;
		}
		delete dell;
	}
	this->last = nullptr;
	this->first = nullptr;
	this->length = 0;
	return *this;
}

template<typename t>
inline string dll<t>::to_string()
{	
	char numb[]= {'0','1','2','3','4','5','6','7','8','9'};
	string str;
	for (int i = 0; i < this->length; i++)
	{	
		char tm[1024];
		t tmp = this->at(i + 1);
		int len = 0;
		while (tmp % 10 != 0) {
			tm[len] = numb[tmp % 10];
			tmp /= 10;
			len++;
		}
		tm[len] = '\0';
		for (int i = 0; i < len-1; i++)
		{
			swap(tm[i],tm[(len-1)-i]);
		}
		string str2 = tm;
		str += str2 + ' ';
	}

	return str;
}


template<typename t>
inline int dll<t>::size()
{
	return length;
}

template<typename t>
inline bool dll<t>::empty()
{
	return !this->length;
}

template<typename t>
inline dll<t> dll<t>::operator+(dll& _obj)
{
	dll<t> new_list;
	int new_size = this->length + _obj.length;
	for (int i = 0; i < new_size; i++)
	{
		if (i < this->length) {
			new_list.push_back(this->at(i + 1));
		}
		else {
			new_list.push_back(_obj.at((i - this->length) + 1));
		}
	}
	return new_list;
}

template<typename t>
inline const dll<t> dll<t>::operator*(dll& _obj)
{
	dll<t> new_list;
	if (this->length >= _obj.length) {
		for (int i = 0; i < this->length; i++)
		{
			for (int j = 0; j < _obj.length; j++)
			{
				if (this->at(i + 1) == _obj.at(j + 1)) {
					new_list.push_back(this->at(i + 1));
				}
			}
		}
	}
	else {
		for (int i = 0; i < _obj.length; i++)
		{
			for (int j = 0; j < this->length; j++)
			{
				if (this->at(i + 1) == _obj.at(j + 1)) {
					new_list.push_back(this->at(i + 1));
				}
			}
		}
	}
	
	return new_list;
}



template<typename t>
inline void dll<t>::output()
{
	noda<t>* tmp = first;
	cout << first->data << endl;
	while (tmp->p_next != nullptr)
	{
	tmp = tmp->p_next;
	cout << tmp->data << endl;
	}
}
