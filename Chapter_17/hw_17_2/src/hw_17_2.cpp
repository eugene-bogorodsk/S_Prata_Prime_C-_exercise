//============================================================================
// Name        : hw_17_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : copy keyboard input
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]) {
	string str;
	cout<<"Enter your string: ";
	getline(cin,str);

	if(argc ==1)
	{
		cerr<<"Usage : "<<argv[0]<<" filename[s]\n";
		exit(EXIT_FAILURE);
	}
	ofstream fout(argv[1]);
	fout<<str;
	fout.clear();
	fout.close();

	cout<<"Your string:\n";
	ifstream fin(argv[1]);
	if(!fin.is_open())
	{
		cerr<<"Could not open `"<<argv[1]<<endl;
		fin.clear();
	}
	char ch;
	while(fin.get(ch))
		cout<<ch;
	cout<<"\n Done.\n";
	fin.clear();
	fin.close();

	return 0;
}
