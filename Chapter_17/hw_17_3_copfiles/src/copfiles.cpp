//============================================================================
// Name        : copfiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : copy files
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc,char * argv[]) {
	using namespace std;
	if (argc ==1)
	{
		cerr<<"Usage"<<argv[0]<<" filename[s]\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		cerr<<"Error of loading "<<argv[1]<<" file.\n";
		fin.clear();
	}

	ofstream fout(argv[2]);
	char ch;
	while(fin.get(ch))
		fout<<ch;
	fin.clear();
	fout.clear();
	fin.close();
	fout.close();
	cout<<"Coping finished. Your result:\n";
	fin.open(argv[2]);
	while(fin.get(ch))
		cout<<ch;
	fin.clear();
	fin.close();



	return 0;
}
