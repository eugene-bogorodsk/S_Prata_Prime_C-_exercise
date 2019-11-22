//============================================================================
// Name        : inserts.cpp
// Author      : 
// Version     : copy() and insert iterator
// Copyright   : Your copyright notice
// Description : listing 16.11
//============================================================================

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
void output(const std::string& s){std::cout<<s<<" ";}

int main() {
	using namespace std;
	string s1[4]={"fine","fish","fashion","fate"};
	string s2[2]={"busy","bats"};
	string s3[2]={"silly","singers"};
	vector <string> words(4);
	copy(s1,s1+4,words.begin());
	for_each(words.begin(),words.end(),output);
	cout<<endl;
	//constructing an anonymous object back_insert_iterator type
	copy(s2,s2+2,back_insert_iterator<vector<string>>(words));
	for_each(words.begin(),words.end(),output);
	cout<<endl;
	//constructing an anonymous object insert_iterator type
	copy(s3,s3+3,insert_iterator<vector<string>>(words,words.begin()));
	for_each(words.begin(),words.end(),output);
	cout<<endl;

	return 0;
}
