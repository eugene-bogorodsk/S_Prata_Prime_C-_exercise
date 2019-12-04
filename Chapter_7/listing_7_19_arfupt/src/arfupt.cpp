//============================================================================
// Name        : arfupt.cpp
// Author      : 
// Version     :array of pointers
// Copyright   : Your copyright notice
// Description : listing 7.19
//============================================================================

#include <iostream>
//different notations same signatures
const double * f1(const double ar[],int n);
const double * f2(const double [], int);
const double * f3(const double *,int);

int main() {
	using namespace std;
	double av[3]{1112.3,1542.6,2227.9};

	//pointer to function
	const double *(*p1)(const double *,int)=f1;
	auto p2=f2;

	//using pointers to functions
	cout<<"Using pointers to function:\n";
	cout<<"Address Value\n";
	cout<<(*p1)(av,3)<<": "<<*(*p1)(av,3)<<endl;
	cout<<p2(av,3)<<": "<<*p2(av,3)<<endl;

	//ps=array of pointers
	//auto does not work with list initialization
	const double *(*pa[3])(const double *,int)={f1,f2,f3};
	//but works with single value initialization
	//pb - pointer to first ps element
	auto pb=pa;
	//or const double *(**pb)(const double *,int)=ps
	//using an array of pointers to functions
	cout<<"\nUsing a pointer to a pointer to a function:\n";
	cout<<"Address Value\n"; //the output address value
	for (int i=0;i < 3;i++)
		cout<<pa[i](av,3)<<": "<<*pa[i](av,3)<<endl;
	//using a pointer to a pointer to a function
	cout<<"\nUsing a pointer to a pointer to a function:\n";
	cout<<"Address Value:\n"; //the output address values
	for (int i=0;i < 3;i++)
		cout<<pb[i](av,3)<<": "<<pb[i](av,3)<<endl;
	//pointer to an array of pointers to a funcion
	cout<<"\nUsing pointers to an array of pointers:\n";
	cout<<"Address Value\n";
	//an easy way to declare a value
	auto pc=&pa;
	//or const double *(*(*pc)[3])(const double *,int)=&ps
	cout<<(*pc)[0](av,3)<<": "<<*(*pc)[0](av,3)<<endl;
	//difficult way to declare pd
	const double *(*(*pd)[3])(const double *,int)=&pa;
	//saving the returned value
	const double *pdb = (*pd)[1](av,3);
	cout<<pdb<<": "<<*pdb<<endl;
	//alternative notation
	cout<<(*(*pd)[2])(av,3)<<": "<<*(*(*pd)[2])(av,3)<<endl;

	return 0;
}

const double * f1(const double ar[],int n)
{
	return ar;
}
const double * f2(const double ar[], int n)
{
	return ar+1;
}
const double * f3(const double *ar,int n)
{
	return ar+2;
}
