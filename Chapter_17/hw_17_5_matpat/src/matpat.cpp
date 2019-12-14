//============================================================================
// Name        : matpat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : saving dates in containers
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
	string name;	vector<string> mat_friends,pat_friends;
	ifstream fin("mat.txt");
	if (!fin.is_open())
	{
		cout<<"Error of opening in mat file"<<endl;
		exit(EXIT_FAILURE);
	}
	string line;
	while (getline(fin,line))
		mat_friends.push_back(line);
	fin.clear();fin.close();
	fin.open("pat.txt");
	if (!fin.is_open())
	{
		cout<<"Error of opening in pat file"<<endl;
		exit(EXIT_FAILURE);
	}
	while (getline(fin,line))
		pat_friends.push_back(line);
	fin.clear();fin.close();
	sort(mat_friends.begin(),mat_friends.end());
	sort(pat_friends.begin(),pat_friends.end());
	vector<string>common_friends(mat_friends.begin(),mat_friends.end());
	common_friends.insert(common_friends.end(),pat_friends.begin(),pat_friends.end());
	sort(common_friends.begin(),common_friends.end());
	auto last=unique(common_friends.begin(),common_friends.end());
	common_friends.erase(last,common_friends.end());
	ofstream fout("common_friends.txt");
	cout<<"Mat friends: "<<endl;
	for(auto fr:mat_friends)
		cout<<fr<<" ";
	cout<<"\nPat friends:\n";
	for(auto fr:pat_friends)
			cout<<fr<<" ";
	cout<<"\nCommon friends:\n";
	for(auto fr:common_friends)
		cout<<fr<<" ";
	for(auto fr:common_friends)
		fout<<fr<<endl;
	fout.clear();fout.close();

	return 0;
}


