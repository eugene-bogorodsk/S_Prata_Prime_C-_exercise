//============================================================================
// Name        : iomanip.cpp
// Author      : 
// Version     :using iomanip manipulator
// Copyright   : Your copyright notice
// Description : listing 17.10
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	using namespace std;
	//the use of the new standard manipulators
	cout<<fixed<<right;

	//using iomanip manipulators for extraction square root and forth degree root
	cout<<setw(6)<<"N"<<setw(14)<<"square root"
			<<setw(15)<<"fourth root\n";

	double root;//extraction root
	for (int n=10;n<=100;n+=10)
	{
		root=sqrt(double(n));
		cout<<setw(6)<<setfill('.')<<n<<setfill(' ')
				<<setw(12)<<setprecision(3)<<root
				<<setw(14)<<setprecision(4)<<sqrt(root)
				<<endl;
	}
	return 0;
}
