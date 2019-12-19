//============================================================================
// Name        : somedefs.cpp
// Author      : 
// Version     : called types and stamples
// Copyright   : Your copyright notice
// Description : listing 18.6
//============================================================================

#include "somedefs.h"
#include <iostream>
double dub(double x){return 2.0*x;}
double square(double x) {return x*x;}

int main()
{
	using std::cout;
	using std::endl;
	double y =1.21;
	cout<<"Function pointer dub:\n";
	cout<<" "<<use_f(y,dub)<<endl;
	cout<<"Function pointer square:\n";
	cout<<" "<<use_f(y,square)<<endl;
	cout<<"Function object Fp:\n";
	cout<<" "<<use_f(y,Fp(5.0))<<endl;
	cout<<"Function object Fq:\n";
	cout<<" "<<use_f(y,Fq(5.0))<<endl;
	cout<<"Lambda expression l:\n";
	cout<<" "<<use_f(y,[](double u){return u*u;})<<endl;
	cout<<"Lambda expression 2: 'n";
	cout<<" "<<use_f(y,[](double u){return u+u/2.0;})<<endl;

}
