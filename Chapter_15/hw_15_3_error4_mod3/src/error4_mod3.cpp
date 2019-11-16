//============================================================================
// Name        : error4_mod3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>//UNIX users may need -lm flag
#include "error4mod3.h"

	//function prototype
	double hmean(double a,double b);
	double gmean(double a,double b);

int main() {
	using std::cout;
	using std::endl;
	using std::cin;
	double x,y,z;
	cout<<"Enter two numbers: ";
	while(cin>>x>>y)
	{
		try{
			z=hmean(x,y);
			cout<<"Harmonic mean of "<<x<<" and "<<y
					<<" is "<<z<<endl;
			gmean(x,y);
			cout<<"Geometric mean of "<<x<<" and "<<y
					<<" is "<<gmean(x,y)<<endl;
			cout<<"Enter next set of numbers <q to quit>:";
		}
		catch(int i)
		{
			switch(i)
			{
			case -1:{
				bad_hmean bh(x,y);
					cout<<"error "<<i<<" "<<bh.what();
					cout<<"Invalid arguments : "<<bh.b_v1()<<", "<<bh.b_v2()<<endl;
				break;
				}
			case -2:{
				bad_gmean bg(x,y);
				cout<<"error "<<i<<" "<<bg.what();
				cout<<"Invalid arguments : "<<bg.bi_v1()<<", "<<bg.bi_v2()<<endl;
				break;
				}

			}
			break;
		}//end of catch block

	}
	cout<<"Bye!\n";
	return 0;
}//end of main

double hmean(double a,double b)
{
	if(a==-b)
		throw -1;
	return 2.0*a*b/(a+b);
}
double gmean(double a,double b)
{
	if(a<0 || b<0)
		throw -2;
	return std::sqrt(a*b);
}
