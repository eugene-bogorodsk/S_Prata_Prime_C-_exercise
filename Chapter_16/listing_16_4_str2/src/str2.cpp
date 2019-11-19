//============================================================================
// Name        : str2.cpp
// Author      : 
// Version     :using capacity() and reserve() methods
// Copyright   : Your copyright notice
// Description : listing 16.4
//============================================================================

#include <iostream>
#include <string>


int main() {
	using namespace std;
	string empty;
	string small="bit";
	string larger="Elephants are a girl's best friend";
	cout<<"Sizes:\n";
	cout<<"\tempty: "<<empty.size()<<endl;
	cout<<"\tsmall: "<<small.size()<<endl;
	cout<<"t\larger: "<<larger.size()<<endl;
	cout<<"Capacities:\n";
	cout<<"\tempty: "<<empty.capacity()<<endl;
	cout<<"\tsmall: "<<small.capacity()<<endl;
	cout<<"\nlarger: "<<larger.capacity()<<endl;
	empty.reserve(50);
	cout<<"Capacity after empty.reserve(50):"

	 <<empty.capacity()<<endl;
	return 0;
}
