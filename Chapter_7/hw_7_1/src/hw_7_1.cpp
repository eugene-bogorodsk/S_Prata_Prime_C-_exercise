//============================================================================
// Name        : hw_7_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_7_1 mean harmonic
//============================================================================

#include <iostream>

double mhar(int,int);
int main() {
	using namespace std;
	int x,y;
	cout<<"Enter two numbers for calculate mean harmonic:\n";
	while(cin>>x>>y)
	{
		if (x==0 or y==0)
		{
			cout<<"You can not use 0 for calculate mean harmonic. End of programm.\n";
			break;
		}
		else
		{
			cout<<"mean harmonic for "<<x<<" and "<<y<<" = "<<mhar(x,y)<<endl;
			cout<<"Enter next numbers:\n";
		}
	}
	return 0;
}

double mhar(int x,int y)
{
	return 2.0*x*y/(x+y);
}
