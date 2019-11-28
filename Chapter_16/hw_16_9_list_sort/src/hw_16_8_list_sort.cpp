//============================================================================
// Name        : hw_16_8_list_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_16_9
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>
using namespace std;

const int N[]={100000,1000000,10000000};
void timeTest(vector<int>& cont);
void timeTest(list<int>& cont);
void timeTest(list<int>& li,vector<int>& vi);

int main() {
	srand(time(0));
	for(int k=0;k<3;k++)
	{
		cout<<"Test "<<k+1<<endl;
		vector<int> vi0(N[k]);
		for(int i=0;i<N[k];++i)
			vi0.push_back(rand()%100);
		vector<int> vi(vi0);
		list<int> li;
		li.insert(li.begin(),vi0.begin(),vi0.end());
		timeTest(vi);
		timeTest(li);
		copy(vi0.begin(),vi0.end(),li.begin());
		timeTest(li,vi);

	}
	return 0;
}
void timeTest(vector<int>& cont)
{
	clock_t start=clock();
	sort(cont.begin(),cont.end());
	clock_t end=clock();
	cout<<"sort vi= "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}
void timeTest(list<int>& cont)
{
	clock_t start1=clock();
	cont.sort();
	clock_t end1=clock();
	cout<<"sort li 1 = "<<(double)(end1-start1)/CLOCKS_PER_SEC<<endl;
}

void timeTest(list<int>& li,vector<int>& vi)
{
	clock_t start2=clock();
	copy(li.begin(),li.end(),vi.begin());
	sort(vi.begin(),vi.end());
	copy(vi.begin(),vi.end(),li.begin());
	clock_t end2=clock();
	cout<<"sort li 2 ="<<(double)(end2-start2)/CLOCKS_PER_SEC<<endl;
}
