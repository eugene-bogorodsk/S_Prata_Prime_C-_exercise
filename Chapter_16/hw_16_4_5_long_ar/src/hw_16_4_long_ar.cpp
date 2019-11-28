//============================================================================
// Name        : hw_16_4_long_ar.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <initializer_list>
#include <iterator>
using namespace std;
template<class T>
int reduce(T ar[],int n=0);

int main() {
	int n=9;
	long* test= new long[n]{1,4,8,8,4,4,2,5,9};
	string* test_string = new string[n]{"ada","dada","kabak","barabak","ada",
		"maman","plane","plane","sex"};
	cout<<"Old long size: "<<n<<endl;
	for (int i=0;i<n;++i) cout<<test[i]<<" ";
	cout<<endl;
	int k=reduce(test,n);
	cout<<"New long array: "<<k<<endl;
	for (int i=0;i<k;++i) cout<<test[i]<<" ";
	cout<<endl;
	cout<<"Old string size: "<<n<<endl;
	for (int i=0;i<n;++i) cout<<test_string[i]<<" ";
	cout<<endl;
	k=reduce(test_string,n);
	cout<<"New long array: "<<k<<endl;
	for (int i=0;i<k;++i) cout<<test_string[i]<<" ";
	cout<<endl;

	return 0;
}
template <class T>
int reduce(T ar[],int n)
{
	sort(ar,ar+n);
	auto p_end=unique(ar,ar+n);
	int k=0;
	for(auto i=ar;i !=p_end;++i) k++;
	return k;
}
