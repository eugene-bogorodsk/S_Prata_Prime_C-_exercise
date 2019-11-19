//============================================================================
// Name        : strfile.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : reading strings from file
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
	using namespace std;
	ifstream fin;
	fin.open("C:\\Users\\Eugene\\S_Prata_Prime_C-_exercise\\strfile\\src\\tobuy.txt.txt");
	if(fin.is_open()==false)
	{
		cerr<<"Can't open file. Bye.\n"; //file is not opened
		exit(EXIT_FAILURE);
	}
	string item;
	int count =0;
	getline(fin,item,':');
	while(fin) //untill enter mistakes
	{
		++count;
		cout<<count<<": "<<item<<endl;
		getline(fin,item,':');
	}
	cout<<"Done\n";
	fin.close();
	return 0;
}
