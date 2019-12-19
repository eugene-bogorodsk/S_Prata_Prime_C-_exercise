//============================================================================
// Name        : variadio2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : listing 18.10
//============================================================================

#include <iostream>

//definition for 0 parameters
void show_list(){}

//definition for 1 parameter
template <typename T>
void show_list(const T& value)
{
	std::cout<<value<<'\n';
}

//definition for 2 and more patameters
template <typename T,typename ...Args>
void show_list(const T& value,const Args...args)
{
	std::cout<<value<<", ";
	show_list(args...);
}
int main() {
	int n=14;
	double x=2.71828;
	std::string mr="Mr. String objects!";
	show_list(n,x);
	show_list(x*x,'!',7,mr);
	return 0;
}
