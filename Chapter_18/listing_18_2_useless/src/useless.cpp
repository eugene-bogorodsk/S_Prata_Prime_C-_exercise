//============================================================================
// Name        : useless.cpp
// Author      : 
// Version     :class with transfer semantics
// Copyright   : Your copyright notice
// Description : listing 18_2
//============================================================================

#include <iostream>
using namespace std;

//ingerface
class Useless
{
private:
	int n;  //cardinality
	char *pc; // a pointer to the data
	static int ct; //number of objects
	void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless & f); //normal copy constructor
	Useless(Useless && f); //transfer constructor
	~Useless();
	Useless operator+(const Useless & f)const;
	// in the copy and transfer version must operator=()
	void ShowData() const;
};

//implementation
int Useless::ct=0;

Useless::Useless()
{
	++ct;
	n=0;
	pc=nullptr;
	// call the default constructor, output the number of objects
	cout<<"default constructor called; number of objects:"<<ct<<endl;
	ShowObject();
}

Useless::Useless(int k):n(k)
{
	++ct;
	cout<<"int constructor called; number of objects:"<<ct<<endl;
	pc=new char(n);
	ShowObject();
}

Useless::Useless(int k,char ch):n(k)
{

	++ct;
	cout<<"int,char constructor called;number of objects:"<<ct<<endl;
	pc=new char(n);
	for (int i=0;i<n;i++)
		pc[i]=ch;
	ShowObject();
}
Useless::Useless(const Useless & f):n(f.n)
{
	++ct;
	cout<<"copy const called; number of objects: "<<ct<<endl;
	pc=new char[n];
	for (int i =0;i<n;i++)
		pc[i]=f.pc[i];
	ShowObject();
}
Useless::Useless(Useless && f):n(f.n)
{
	++ct;
	cout<<"move constructor called; number of objects: "<<ct<<endl;
	pc=f.pc;
	f.pc=nullptr;
	f.n=0;
	ShowObject();
}
Useless::~Useless()
{
	cout<<"desturctor called; objects left: "<<--ct<<endl;
	cout<<"deleted object:\n";
	ShowObject();
	delete [] pc;
}
Useless Useless::operator+(const Useless & f) const
{
	cout<<"Enterinf operator + ()\n";
	Useless temp = Useless(n + f.n);
	for (int  i=0;i<n;i++)
		temp.pc[i]=pc[i];
	for (int i=n;i<temp.n;i++)
		temp.pc[i]=f.pc[i-n];
	cout<<"temp object:'n";
	cout<<"Leaving operator +()\n";
	return temp;
}
void Useless::ShowObject() const
{
	cout<<"Number of elements: "<<n;
	cout<<" Data adress: "<<(void * ) pc<<endl;
}
void Useless::ShowData() const
{
	if (n==0)
		cout<<"(object empty)";
	else
		for (int i=0;i<n;i++)
			cout<<pc[i];
	cout<<endl;
}

int main() {
	Useless one(10,'x');
	Useless two=one;
	Useless three(20,'o');
	Useless four (one+three);
	cout<<"object one: ";
	one.ShowData();
	cout<<"object two: ";
	two.ShowData();
	cout<<"object three:";
	three.ShowData();
	cout<<"object four: ";
	four.ShowData();
}
