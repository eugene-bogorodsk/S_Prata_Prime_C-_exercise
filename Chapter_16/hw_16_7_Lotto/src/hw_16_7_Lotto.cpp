//============================================================================
// Name        : hw_16_7_Lotto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_16_7
//============================================================================

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stdexcept>
using namespace std;

vector<int> Lotto(int,int);
int main() {
	vector<int> winners;
	try {winners=Lotto(51,6);}
	catch(const char* s)
	{
		cout<<s<<endl;
	}
	for(auto num:winners)
		cout<<num<<" ";
	cout<<endl;
	return 0;
}
vector<int> Lotto(int n,int m)
{
	if (m>n)
		throw "bad Lotto arguments m>n ";
	srand(time(0));
	vector<int> origin;
	for(int i=1;i<n+1;++i)
		origin.push_back(i);
	random_shuffle(origin.begin(),origin.end());
	vector<int> output(origin.begin(),origin.begin()+m);
	return output;

}
