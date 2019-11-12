//============================================================================
// Name        : worker.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "worker0.h"
using std::cin;
using std::cout;
using std::endl;

//Worler's methods
Worker::~Worker(){}

void Worker::Set()
{
	cout<<"Enter worker's name: ";
	getline(cin,fullname);
	cout<<"Enter worker's ID: ";
	cin>>id;
	while(cin.get() != '\n')
		continue;
}
void Worker::Show() const
{
	cout<<"Name: "<<fullname<<'\n';
	cout<<"Employee ID: "<<id<<'\n';
}

//Waiter methods
void Waiter::Set()
{
	Worker::Set();
	cout<<"Enter waiter's panache rating: ";
	//ввод индекса элегантности официанта
	cin>>panache;
	while(cin.get() != '\n')
		continue;
}

void Waiter::Show() const
{
	cout<<"Category waiters:\n";
	Worker::Show();
	cout<<"Panache rating: "<<panache<<'\n';
}

//Singer's methods

const char* Singer::pv[]={"other","alto","contralto","soprano","bass","batitone","tenor"};

void Singer::Set()
{
	Worker::Set();
	cout<<"Enter number for singer's vocal range:\n";
	//ввод номера вокального диапазона
	int i;
	for(i=0;i<Vtypes;++i)
	{
		cout<<i<<": "<<pv[i]<<" ";
		if(i % 4 == 3)
			cout<<endl;
	}
	if(i % 4 ==0)
		cout<<endl;

	while(cin>>voice and (voice<0 or voice>=Vtypes))
		cout<<"Please enter a value >=0 and < "<<Vtypes<<endl;
	while(cin.get() != '\n')
		continue;
}
void Singer:: Show() const
{
	cout<<"Category: singer\n";
	Worker::Show();
	cout<<"Vocal range: "<<pv[voice]<<endl;
}
