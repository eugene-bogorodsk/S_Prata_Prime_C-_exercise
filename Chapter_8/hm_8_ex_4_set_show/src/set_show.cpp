//============================================================================
// Name        : set_show.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<cstring>
struct stringy
{
	char* str;
	int xt; //длина строки не считая '\0'
};

void set(stringy& s,const char* t);
void show(const stringy& s,int n=1);
void show(const char* t,int n=1);
int main() {
	stringy beany;
	char testing[]="Reality isn't what it used to be.";
	set(beany,testing);
	show(beany);
	show(beany,2);
	testing[0]='D';
	testing[1]='u';
	show(testing);
	show(testing,3);
	show("Done!");
	return 0;
}
void set(stringy& s,const char* t)
{
	s.xt=strlen(t);
	s.str= new char[s.xt+1];
	strcpy(s.str,t);
}
void show(const stringy& s,int n)
{
	for(int i=0;i<n;i++)
		cout<<"Str: "<<s.str<<": "<<s.xt<<" characters.\n";
}
void show(const char* t,int n)
{
	for(int i=0;i<n;i++)
		cout<<t<<": "<<strlen(t)<<" characters.\n";
}

