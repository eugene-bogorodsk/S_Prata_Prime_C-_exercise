//============================================================================
// Name        : strgst1.cpp
// Author      : 
// Version     :using STL with strings
// Copyright   : Your copyright notice
// Description : listing 16.17
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>


int main() {
	using namespace std;
	string letters;
	cout<<"Enter the letter grouping(q to quit):";
	while(cin>>letters && letters !="q")
	{
		cout<<"Permutations of "<<letters<<endl;
		sort(letters.begin(),letters.end());
		cout<<letters<<endl;
		while(next_permutation(letters.begin(),letters.end()))
			cout<<letters<<endl;
		cout<<"Enter next sequence (q to quit):";
	}
	cout<<"Done.\n";
	return 0;
}
