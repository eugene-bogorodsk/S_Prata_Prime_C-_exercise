//============================================================================
// Name        : precise.cpp
// Author      : 
// Version     : the precision setting
// Copyright   : Your copyright notice
// Description : listing 17.6
//============================================================================

#include <iostream>

int main() {
	using namespace std;
	float price1=20.40;
	float price2=1.9+8.0/9.0;

	cout<<"\"Furry Friends\" is $"<<price1<<"!\n";
	cout<<"\"Fiery Friends\" is $"<<price2<<"!\n";

	cout.precision(2);
	cout<<"\"Furry Friends\" is $"<<price1<<"!\n";
	cout<<"\"Fiery Friends\" is $" <<price2<<"!\n";

	return 0;
}
