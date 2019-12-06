//============================================================================
// Name        : manip.cpp
// Author      : 
// Version     :using format manipulator
// Copyright   : Your copyright notice
// Description : listing 17.3
//============================================================================

#include <iostream>


int main() {
	using namespace std;
	cout<<"Enter integer: ";
	int n;
	cin>>n;
	cout<<"n  n*n\n";
	cout<<n<<"   "<<n*n<<" (decimal)\n";

	//setting hexadecimal input mode
	cout<<hex;
	cout<<n<<  "  ";
	cout<<n*n<<" (hecadecimal)\n";

	//setting octal mode
	cout<<oct<<n<<  "   "<<n*n<<" (octal)\n";

	//an alternative way to call manipulator
	dec(cout);
	cout<<n<<"  "<<n*n<<" (decimal)\n";
	return 0;
}
