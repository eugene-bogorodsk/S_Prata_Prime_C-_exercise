//============================================================================
// Name        : worker1.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "worker1.h"
using std::cout;
using std::cin;
using std::endl;

//Worker's methods
Worker::~Worker(){}

void Worker::Data() const
{
	cout<<"Name: "<<fullname<<endl;
	cout<<"Employee ID: "<<id<<endl;
}

//protected methods
void Worker::Get()
{
	getline(cin,fullname);
	cout<<"Enter worker's ID: ";
	cin>>id;
	while(cin.get()!='\n')
		continue;
}

//Waiter's methods
void Waiter::Set()
{
	cout<<"Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout<<"Category: waiter\n";
	Worker::Data();
	Data();
}

//protected methods
void Waiter::Data() const
{
	cout<<"Panache rating: "<<panache<<endl;
}

void Waiter::Get()
{
	cout<<"Enter waiter's panache rating: ";
	//ввод индекса элегантности
	cin>>panache;
	while(cin.get()!= '\n')
		continue;
}

//Singer's methods

const char* Singer:: pv[Singer::Vtypes]={"other","alto","contralto","soprano","bass","batitone","tenor"};

void Singer::Set()
{
	cout<<"Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout<<"Category: singer\n";
	Worker::Data();
	Data();
}

//protected methods
void Singer::Data() const
{
	cout<<"Vocal range: "<<pv[voice]<<endl;
}

void Singer::Get()
{
	cout<<"Enter number for singer's vocal range:\n";
	int i;
	for(i=0;i<Vtypes;i++)
	{
		cout<<i<<": "<<pv[i]<<" ";
		if(i%4 ==3)
			cout<<endl;
	}
	if(i%4 !=0 )
		cout<<'\n';
	cin>>voice;
	while(cin.get() != '\n')
		continue;
}

//Singwaiter
void Singwaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}
void Singwaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void Singwaiter::Set()
{
	cout<<"Enter singing waiter's name: ";
	Worker::Get();
	Get();
}
void Singwaiter::Show() const
{
	cout<<"Category: singing waiter\n";
	Worker::Data();
	Data();
}
