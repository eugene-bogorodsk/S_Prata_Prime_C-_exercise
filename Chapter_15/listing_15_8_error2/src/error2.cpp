//============================================================================
// Name        : error2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : listing 15.8
//============================================================================

#include <iostream>
#include <cfloat>
bool hmean(double a,double b,double *ans);

int main() {
	double x,y,z;
	std::cout<<"Enter two numbers:"; //require for two numbers enter
	while(std::cin>>x>>y)
	{
		if(hmean(x,y,&z))
			std::cout<<"Harmonic mean of  "<<x<<" and "<<y
				<<" is "<<z<<std::endl;//enter harmonic mean
		else
			std::cout<<"One value should not be the negative "
			<<"of the other - try again.\n";//one value can not be negative of the another
		std::cout<<"Enter next set of numbers <q to quit>: ";
	}
	std::cout<<"Bye!\n";
	return 0;
}
bool hmean(double a,double b,double *ans)
{
	if(a==-b)
	{
		*ans=DBL_MAX;
		return false;
	}
	else
	{
		*ans=1.0*a*b/(a+b);
		return true;
	}
}
