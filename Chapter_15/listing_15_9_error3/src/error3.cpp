//============================================================================
// Name        : error3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : listing 15.9
//============================================================================

#include <iostream>
double hmean(double a,double b);

int main() {
	double x,y,z;
	std::cout<<"Enter two numbers:";
	while(std::cin>>x>>y)
	{
		try{ 					//begin of try block
			z=hmean(x,y);
		}						//end of try block
		catch(const char *s) //begin of exception handler
		{
			std::cout<<s<<std::endl;
			std::cout<<"Enter a new pair of numbers: ";//require the new pair of numbers
			continue;
		}						//end of exception handler

		std::cout<<"Harmonic mean of "<<x<<" and "<<y
			<<" is "<<z<<std::endl; //return of harmonic mean
		std::cout<<"Enter next set of number <q to quit>: ";
						//require the next pair of numbers
	}
	std::cout<<"Bye!/n";
	return 0;
}
double hmean(double a,double b)
{

	if(a==-b)
		throw "bad hmean() arguments: a=-b not allowed";
	return 1.0*a*b/(a+b);
}
