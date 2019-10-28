//============================================================================
// Name        : stringUp.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
char* stringUp(const string& s);
int main() {
	string input;
	cout<<"Enter a string (q to quit): ";
	getline(cin,input);

	while(input != "q")
	{
		cout<<stringUp(input)<<endl;
		cout<<"Next string (q to quit): ";
		getline(cin,input);
	}
	cout<<"Buy.\n";
	return 0;
}
 char* stringUp(const string& s)
{
	char* temp=new char[s.size()+1];
	for(size_t i=0;i<s.size();i++)
			temp[i]=toupper(s[i]);

	return temp;
}
