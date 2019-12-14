//============================================================================
// Name        : openfiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

int main() {
	using namespace std;

	ifstream fin1("testfile.txt");
	if (!fin1.is_open())
	{
		cout<<"Error of opening testfile. Check your file.\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin2("test1.txt");
	if (!fin2.is_open())
	{
		cout<<"Error of opening test1. Check your file.\n";
		exit(EXIT_FAILURE);
	}
	ofstream fout("outfile.txt");
	string line1,line2;
	while (!fin1.eof() or !fin2.eof())
	{
		if(getline(fin1,line1))
		{
			fout<<line1;
		}
		if(getline(fin2,line2))
		{
			fout<<' '<<line2;
		}
		fout<<endl;
	}
	fin1.clear();fin2.clear();
	fin1.close();fin2.close();
	fin2.open("outfile.txt");
	if (!fin2.is_open())
	{
		cout<<"Error of opening outfile. Check your file.\n";
		exit(EXIT_FAILURE);
	}
	while(getline(fin2,line2))
		cout<<line2<<endl;
	fin2.clear();fin2.close();

	return 0;
}
