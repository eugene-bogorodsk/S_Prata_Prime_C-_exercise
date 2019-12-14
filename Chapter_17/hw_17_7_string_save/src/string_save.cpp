//============================================================================
// Name        : string_save.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_17.7
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;


struct Store
{
	Store(ofstream& fout):os(fout){}
	void operator() (const string& str){
		size_t len= str.size();
		os.write((char*) & len,sizeof(std::size_t));
		os.write(str.data(),len);
	}
private:
	ofstream & os;
};
void ShowStr(const string& str) {cout<<str<<endl;}
void GetStrs(ifstream & fin,vector<string>& v)
{
	size_t len;
	char ch;
	while (fin.read((char*) &len,sizeof(len)))
	{
		string temp;
		for (size_t i=0;i<len;i++){
			fin.read((char*) &ch,sizeof(char));
			temp.push_back(ch);
		}
		temp.push_back('\0');

		v.push_back(temp);
	}

}

int main() {
	using namespace std;
	vector<string> vostr {"temp","brass","sex","topic"};
	vector<int> test;
	string temp;

	//get strings
	//cout<<"Enter strings (empty line to quit):\n";
	//while (getline(cin,temp) && temp[0] != '\0')
	//	vostr.push_back(temp);
	cout<<"Here is your input.\n"; //output strings
	for_each(vostr.begin(),vostr.end(),ShowStr);


	//save in a file
	ofstream fout("strings.dat",ios_base::out | ios_base::binary);
	for_each(vostr.begin(),vostr.end(), Store(fout));
	fout.close();

	//rebuild a file content
	vector<string> vistr;
	ifstream fin;
	fin.open("strings.dat",ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr<<"Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}

	GetStrs(fin,vistr);
	cout<<"\nHere are the strings read from the file:\n";
	for_each(vistr.begin(),vistr.end(),ShowStr);

	return 0;
}

