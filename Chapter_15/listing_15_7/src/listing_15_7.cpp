//============================================================================
// Name        : listing_15_7.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
double hmean(double a,double b);

int main() {
	double x,y,z;
	std::cout<<"Enter two numbers: ";
	while (std::cin>>x>>y)
	{
		z=hmean(x,y);
		std::cout<<"Harmonic mean of "<<x<<" and "<<y
				<<" is "<<z<<std::endl;  //вывод среднего гармонического
		std::cout<<"Enter next set of numbers <q to quit>: ";
		//запрос следующих двух чисел
	}
	std::cout<<"Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a==b)
	{
		std::cout<<"untenable arguments to hmean()\n";// неверные аргументы для hmean
		std::abort();
	}
	return 2.0*a*b/(a+b);
}
