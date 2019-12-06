//============================================================================
// Name        : setf2.cpp
// Author      : 
// Version     :using setf() with two arguments for control the formating
// Copyright   : Your copyright notice
// Description : listing 17.9
//============================================================================

#include <iostream>
#include <cmath>

int main() {
	using namespace std;

	//use the align left,show the plus sign,show trailing zeros
	//with a precision equal to three
	cout.setf(ios_base::left,ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);

	//use exponential notation and keep old format settings
	ios_base::fmtflags old=cout.setf(ios_base::scientific,
			ios_base::floatfield);
	cout<<"Left Justification:\n";
	long n;
	for(n=1;n<=41;n+=10)
	{
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt(double(n))<<"|\n";
	}
	//switch to internal alignment
	cout.setf(ios_base::internal,ios_base::adjustfield);

	//restore the default floating point display style
	cout.setf(old,ios_base::floatfield);
	cout<<"Internal Justification:\n";
	for(n=1;n<=41;n+=10)
	{
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt(double(n))<<"|\n";
	}

	//use the align right and fixed point record form
	cout.setf(ios_base::right,ios_base::adjustfield);
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout<<"Right Jistification:\n";
	for (n=1;n<=41;n+=10)
	{
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt(double(n))<<"|\n";
	}
	return 0;
}
