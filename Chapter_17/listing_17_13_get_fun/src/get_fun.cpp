//============================================================================
// Name        : get_fun.cpp
// Author      : 
// Version     :using get() and getline()
// Copyright   : Your copyright notice
// Description : listing 17.13
//============================================================================

#include <iostream>
const int Limit=255;

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	char input[Limit];

	cout<<"Enter a stirng for getline() processing:\n";
	cin.getline(input,Limit,'#');
	cout<<"Here is your input:\n";
	cout<<input<<"\nDone with phase 1\n";

	char ch;
	cin.get(ch);
	cout<<"The next input character is "<<ch<<endl;
	if (ch !='\n')
		cin.ignore(Limit,'\n');//discarding the rest part of the string

	cout<<"Enter a string for get() processing:'\n";
	cin.get(input,Limit,'#');
	cout<<"Here is your input:\n";
	cout<<input<<"\nDone with phase 2\n";

	 cin.get(ch);
	 cout<<"The next input character is "<<ch<<endl;

	return 0;
}
