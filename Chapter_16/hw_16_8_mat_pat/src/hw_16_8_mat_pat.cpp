//============================================================================
// Name        : hw_16_8_mat_pat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_16_8
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const vector<string>&);
int main() {
	string name;	vector<string> mat_friends,pat_friends;
	cout<<"Hello, enter name Mat or Pat for continue or 'quit' to quit): "<<endl;
	while(cin>>name && name !="quit")
	{
		if (name != "Mat" and name != "Pat")
		{
			cout<<"Bad name, try again: ";
			continue;
		}
		string friend_name;

		cin.get();
		while(friend_name != "q")
		{
			cout<<"Enter name of the friend (q to quit): "<<endl;
			getline(cin,friend_name);
			if(name=="Mat" && friend_name !="q")
				mat_friends.push_back(friend_name);
			if(name=="Pat" && friend_name !="q")
				pat_friends.push_back(friend_name);

		}
		cout<<"Enter new name or 'quit' to quit"<<endl;
	}
	sort(mat_friends.begin(),mat_friends.end());
	sort(pat_friends.begin(),pat_friends.end());
	vector<string>common_friends(mat_friends.begin(),mat_friends.end());
	common_friends.insert(common_friends.end(),pat_friends.begin(),pat_friends.end());
	sort(common_friends.begin(),common_friends.end());
	auto last=unique(common_friends.begin(),common_friends.end());
	common_friends.erase(last,common_friends.end());
	cout<<"Friends of the Mat:\n";
	display(mat_friends);
	cout<<"Friends of Pat:\n";
	display(pat_friends);
	cout<<"Common friends:\n";
	display(common_friends);

	return 0;
}

void display(const vector<string>& v){
	bool flag=false;
	for(auto n:v)
	{
		if(flag)
			cout<<", ";
		cout<<n;
		flag=true;
	}
	cout<<endl;
}
