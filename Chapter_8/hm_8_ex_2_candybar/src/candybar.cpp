//============================================================================
// Name        : candybar.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;
struct CandyBar
{
	char* m_name;
	//string m_name;
	double m_weight;
	int m_calories;
};
void Set(CandyBar& cb,const char* nm="Millennium Munch",
		double w=2.85,int c=350);
void Show(const CandyBar& cb);

int main() {
	CandyBar candy1,candy2;
	Set(candy1);
	const char* c_name="Alpen Gold";
	double c_weight=0.150;
	int c_calories=540;
	Set(candy2,c_name,c_weight,c_calories);
	Show(candy1);
	Show(candy2);
	return 0;
}
void Set(CandyBar& cb,const char* nm,double w,int c)
{
	cb.m_name=new char[strlen(nm)+1];
	strcpy(cb.m_name,nm);
	//cb.m_name=string(nm);
	cb.m_weight=w;
	cb.m_calories=c;
}
void Show(const CandyBar& cb)
{
	cout<<cb.m_name<<endl;
	cout<<cb.m_weight<<'\t';
	cout<<cb.m_calories<<endl;
}
