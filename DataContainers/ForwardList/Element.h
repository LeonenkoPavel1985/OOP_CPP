#pragma once
#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>class Element
{
	T Data;		//Çíà÷åíèå ýëåìåíòà
	Element<T>* pNext;	//Óêàçàòåëü íà ñëåäóþùèé ýëåìåíò
	static int count;
public:
	Element(T Data, Element<T>* pNext = nullptr);
	~Element();
	friend class Iterator<T>;
	friend class ForwardList<T>;
};
