//============================================================================
// Name        : error4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : listing 15.11 using exception classes
//============================================================================

#include <iostream>
#include <cmath>//UNIX users may need -lm flag
#include "error4.h"

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
		catch(bad_hmean& bg)
		{
			cout<<bg.what();
			cout<<"Try again.\n";
			continue;
		}
		catch(bad_gmean& hg)
		{
			cout<<hg.what();
			cout<<"Sorry, you don't get to play any more.\n";//end of the work
			break;  //end of the catch block
		}
	}
	cout<<"Bye!\n";
	return 0;
}//end of main

double hmean(double a,double b)
{
	if(a==-b)
		throw bad_hmean();
	return 2.0*a*b/(a+b);
}

double gmean(double a,double b)
{
	if(a<0 || b<0)
		throw bad_gmean();
	return std::sqrt(a*b);
}
