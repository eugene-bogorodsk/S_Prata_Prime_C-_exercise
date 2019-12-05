//============================================================================
// Name        : hw_7_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : factorial
//============================================================================

#include <iostream>
using namespace std;

int factorial( int n);
int main() {
	int n;
	cout<<"Enter number:\n";
	while(cin>>n)
	{
		cout<<"Result:"<<factorial(n)<<endl;
		cout<<"Enter next number or q for exit:\n";
		if(!cin)
		{
			cout<<"Bye.\n";
			break;
		}
	}
	return 0;
}

int factorial(int n)
{
	if (n<2)
		return 1;
	return n*factorial(n-1);
}
