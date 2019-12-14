//============================================================================
// Name        : sc_17_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : formatting dates
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
/*	cout<<"Enter your name:\n";
	string name;
	getline(cin,name);

	cout<<"Enter your hourly wages:\n";
	int wages;
	cin>>wages;

	cout<<"Enter your hours worked:\n";
	double hours;
	cin>>hours;*/

	string name="Billy Gruff";
	double wages = 12;
	double hours =7.5;
	cout<<"First format:"<<endl;
	cout<<fixed<<right;
	cout<<setw(30)<<name<<": $"<<setw(10)<<setprecision(2)
			<<wages<<": "<<setprecision(1)<<hours<<endl;
	cout<<"Second format:"<<endl;
	cout<<left<<setw(30)<<name<<": $"<<setprecision(2)
			<<setw(10)<<wages<<":"<<setprecision(1)<<hours<<endl;
/*	cout.width(30);
	cout<<name<<": $";
	cout.setf(ios_base::showpoint);
	cout.precision(4);
	cout.width(10);
	cout<<wages<<": ";
	cout.precision(2);
	cout<<hours<<endl;
	cout<<"Second format:"<<endl;
	cout<<name;
	cout.width(20);
	cout.precision(4);
	cout<<": $"<<wages;
	cout.width(10);
	cout.precision(2);
	cout<<":"<<hours<<endl;*/
	return 0;
}
