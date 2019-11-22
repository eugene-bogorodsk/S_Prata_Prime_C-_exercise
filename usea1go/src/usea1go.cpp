//============================================================================
// Name        : usea1go.cpp
// Author      : 
// Version     :using some STL elements
// Copyright   : Your copyright notice
// Description : listing 16.19
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

char toLower(char ch){return tolower(ch);}
string& ToLower(string& st);
void display(const string& s);

int main() {
	vector<string>	words;
	cout<<"Enter words (enter q to quit):\n";
	string input;
	while(cin>>input && input !="q")
		words.push_back(input);
	cout<<"You entered the following words:\n";
	for_each(words.begin(),words.end(),display);
	cout<<endl;
	//the placement the words in the set,converting letters to lowercase
	set<string>	wordset;
	transform(words.begin(),words.end(),
			insert_iterator<set<string>>(wordset,wordset.begin()),
			ToLower);
	cout<<"\nAlphabetic list of words:\n";
	for_each(wordset.begin(),wordset.end(),display);
	cout<<endl;

	//the placement the frequency of words
	map<string,int> wordmap;
	set<string>::iterator si;
	for(si=wordset.begin();si!=wordset.end();si++)
		wordmap[*si]=count(words.begin(),words.end(),*si);

	//display the contents of the map
	cout<<"\nWord frequency:\n";
	for(si=wordset.begin();si!=wordset.end();si++)
		cout<<*si<<": "<<wordmap[*si]<<endl;

	return 0;
}
string& ToLower(string & st)
{
	transform(st.begin(),st.end(),st.begin(),toLower);
	return st;
}
void display(const string& s)
{
	cout<<s<<" ";
}
