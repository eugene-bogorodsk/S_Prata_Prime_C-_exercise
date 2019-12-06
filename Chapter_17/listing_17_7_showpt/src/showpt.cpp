//============================================================================
// Name        : showpt.cpp
// Author      : 
// Version     :precision setting with end point display
// Copyright   : Your copyright notice
// Description : listing 17.7
//============================================================================

#include <iostream>

int main() {

	using std::cout;
	using std::ios_base;

	float price1=20.40;
	float price2=1.9+8.0/9.0;

	cout.setf(ios_base::showpoint);
	cout<<"\"Furry Friends\" is $"<<price1<<"!\n";
	cout<<"\"Fiery Friends\" is $"<<price2<<"!\n";

	cout.precision(2);
	cout<<"\"Furry Friends\" is $"<<price1<<"!\n";
	cout<<"\"Fiery Fiends\" is $"<<price2<<"!\n";

	return 0;
}
