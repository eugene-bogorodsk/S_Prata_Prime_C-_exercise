//============================================================================
// Name        : check_it.cpp
// Author      : 
// Version     :validation of input
// Copyright   : Your copyright notice
// Description : listing 17.11
//============================================================================

#include <iostream>


int main() {
	using namespace std;
	cout<<"Enter numbers: ";

	int sum=0;
	int input;while (cin>>input)
	{
		sum+=input;
	}
	cout<<"Last value enterd="<<input<<endl;
	cout<<"Sum="<<sum<<endl;

	return 0;
}
