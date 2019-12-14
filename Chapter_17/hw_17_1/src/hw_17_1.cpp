//============================================================================
// Name        : hw_17_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout<<"Enter your string\n";
	char ch;
	int count=0;
	cin.get(ch);
	while(ch != '$')
	{
		count++;
		cout<<ch;
		cin.get(ch);
	}
	cout<<"\nThe end of the string: ";
	while(ch!='\n')
	{
		count++;
		cout<<ch;
		cin.get(ch);
	}
	cout<<"\n Counted characters: "<<count<<endl;


	return 0;
}
