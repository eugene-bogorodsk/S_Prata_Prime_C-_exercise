//============================================================================
// Name        : fileio.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : listing 17.16
//============================================================================

#include <iostream>
#include <fstream>
#include <string>


int main() {
	using namespace std;
	string filename;
	cout<<"Enter name for new file:";
	cin>>filename;

	//create an output stream object for a new file and name it fout
	ofstream fout(filename.c_str());
	fout<<"For your eyes only!\n";//record to file
	cout<<"Enter your secret number: ";//output to the screen
	float secret;
	cin>>secret;
	fout<<"Your secret number is "<<secret<<endl;
	fout.close();

	//create an input stream object for a new file and assign it fin name
	ifstream fin(filename.c_str());
	cout<<"Here are the contents of "<<filename<<":\n";
	char ch;
	while (fin.get(ch))
		cout<<ch;
	cout<<"Done\n";
	fin.close();

	return 0;
}
