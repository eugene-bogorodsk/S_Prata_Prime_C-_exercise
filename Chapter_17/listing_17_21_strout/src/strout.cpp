//============================================================================
// Name        : strout.cpp
// Author      : 
// Version     : internal formatting(output)
// Copyright   : Your copyright notice
// Description : listing 17.21
//============================================================================

#include <iostream>
#include <sstream>
#include <string>

int main() {
	using namespace std;
	ostringstream outstr; //control string stream
	string hdisk;
	cout<<"What's the name of your hard disk?";
	getline(cin,hdisk);
	int cap;
	cout<<"What's its capacity in GB?";
	cin>>cap;

	//record formatted information in sting stream
	outstr<<"The hard disk "<<hdisk<<" has a capacity of "
			<<cap<<" gigabytes.\n";
	string result = outstr.str();
	cout<<result;
	return 0;
}
