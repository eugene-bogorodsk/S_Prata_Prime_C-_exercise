//============================================================================
// Name        : append.cpp
// Author      : 
// Version     : adding information to a file
// Copyright   : Your copyright notice
// Description : listing 17.18
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const char * file ="guests.txt";
int main() {
	using namespace std;
	char ch;

	//display original content
	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout<<"Here are the current contents of the "
				<<file<<" file:\n";
		while (fin.get(ch))
			cout<<ch;
		fin.close();
	}

	//adding new names
	ofstream fout(file,ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr<<"Can't open "<<file<<" file for output.\n";
		exit(EXIT_FAILURE);
	}
	cout<<"Enter guest names (enter a blank line to quit):\n";
	string name;
	while (getline(cin,name) && name.size() >0)
	{
		fout<<name<<endl;
	}
	fout.close();

	//display changing file
	fin.clear();
	fin.open(file);
	{
		cout<<"Here are the new contents of the "
				<<file<<" file:\n";
		while (fin.get(ch))
			cout<<ch;
		fin.close();
	}
	cout<<"Done.\n";
	return 0;
}
