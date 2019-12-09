//============================================================================
// Name        : truncate.cpp
// Author      : 
// Version     :truncate
// Copyright   : Your copyright notice
// Description :listing 17.15
//============================================================================

#include <iostream>
const int SLEN=10;
inline void eatline(){while (std::cin.get() != '\n') continue;}
int main() {
	using std::cin;
	using std::endl;
	using std::cout;

	char name[SLEN];
	char title[SLEN];
	cout<<"Enter your name: ";
	cin.get(name,SLEN);
	if(cin.peek() != '\n')
		cout<<"Sorry, we only gave enough room for "<<name<<endl;// output a message
															//about lack of space
	eatline();
	cout<<"Dear "<<name<<", enter your title: \n";
	cin.get(title,SLEN);
	if(cin.peek() != '\n')
		cout<<"We were forced to truncate your title.\n";
	eatline();
	cout<<"Name: "<<name
			<<"\nTutle: "<<title<<endl;

	return 0;
}
