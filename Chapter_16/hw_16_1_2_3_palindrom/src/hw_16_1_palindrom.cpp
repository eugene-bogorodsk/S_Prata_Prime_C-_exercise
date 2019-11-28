//============================================================================
// Name        : hw_16_1_palindrom.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool palindrom(vector<char>& st,int n=0);
char toLower(char ch){return tolower(ch);}
void prepare(string& input_word);

int main() {
	string test="Madam, I'm Adam";
	ifstream fin;
	fin.open("C:\\Users\\Eugene\\S_Prata_Prime_C-_exercise\\hw_16_1_palindrom\\src\\input.txt");
	if(fin.is_open()==false)
	{
		cerr<<"Can't open file.Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	fin>>item;
	vector<string> words_array;
	while(fin)
	{
		words_array.push_back(item);
		fin>>item;
	}
	cout<<"We've got from file "<<words_array.size()<<" words.\n";
	for(auto w:words_array) prepare(w);
	prepare(test);
	return 0;
}

bool palindrom(vector<char>& st,int n)
{
	if(n==(int)st.size()/2)
		return true;
	if(st[n] != st[int(st.size())-n-1])
		return false;
	return palindrom(st,n+1);
}

void prepare(string& input_word)
{
	vector<char> control_pal;
		for(auto st:input_word)
		if(isalpha(st)) control_pal.push_back(st);
		transform(control_pal.begin(),control_pal.end(),control_pal.begin(),toLower);
		cout<<input_word<<": "<<palindrom(control_pal)<<endl;
}
