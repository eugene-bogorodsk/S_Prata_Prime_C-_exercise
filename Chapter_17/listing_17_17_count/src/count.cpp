//============================================================================
// Name        : count.cpp
// Author      : 
// Version     : count of characters in list of the files
// Copyright   : Your copyright notice
// Description : listing 17.17
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>


int main(int argc,char * argv[]) {
	using namespace std;
	if (argc ==1)  // output with no arguments
	{
		cerr<<"Usage: "<<argv[0]<<" filename[a]\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin;
	long count;
	long total=0;
	char ch;
	for (int file =1;file <argc; file++)
	{
		fin.open(argv[file]);//connecting the stream to argc[file]
		if(!fin.is_open())
		{
			cerr<<"Could not open "<<argv[file]<<endl;//impossible to open the file
			fin.clear();
			continue;
		}
		count=0;
		while (fin.get(ch))
			count++;
		cout<<count<<" charactes in "<<argv[file]<<endl;
					//amount of characters in the file
		total+=count;
		fin.clear();
		fin.close();// close the file

	}
	cout<<total<<" characters in all files\n"; //amount of symbols in all files
	return 0;
}
