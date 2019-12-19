//============================================================================
// Name        : variadic1.cpp
// Author      : 
// Version     :the use of recursion for unwrap of  parameters pack
// Copyright   : Your copyright notice
// Description : listing 18.9
//============================================================================

#include <iostream>
using namespace std;

//definition for 0 parameters,end of call
void show_list3(){}

//definition for 1 and more parameters
template <typename T,typename...Args>
void show_list3( T value,Args...args)
{
	std::cout<<value<<", ";
	show_list3(args...);
}
int main() {
	int n=14;
	double x=2.71828;
			std::string mr= "Mr. String objects!";
	show_list3(n,x);
	show_list3(x*x, '!',7, mr);
	return 0;
}
