//============================================================================
// Name        : strin.cpp
// Author      : 
// Version     :formatting reading from symbol array
// Copyright   : Your copyright notice
// Description : listing 17.22
//============================================================================

#include <iostream>
#include <sstream>
#include <string>


int main() {
	using namespace std;
	string lit = "It was a dark and stormy day, and"
			"the full moon glowed brilliantly.";
	istringstream instr(lit); //using buffer for output
	string word;
	while (instr>>word) //reading word by word
		cout<<word<<endl;
	return 0;
}
