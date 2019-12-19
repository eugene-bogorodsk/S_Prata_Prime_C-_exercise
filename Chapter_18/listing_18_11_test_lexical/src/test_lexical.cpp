//============================================================================
// Name        : test_lexical.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>


int main() {
	using namespace std;;
	cout<<"Enter your weight: ";
	float weight;
	cin>>weight;
	string gain ="A 10% increase raises ";
	string wt = boost::lexical_cast<string>(weight);
	gain =gain+wt+" to ";
	weight=1.1*weight;
	gain = gain + boost::lexical_cast<string>(weight)+".";
	cout<<gain<<endl;
	return 0;
}

