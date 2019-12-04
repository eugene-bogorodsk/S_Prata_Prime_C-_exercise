//============================================================================
// Name        : fun_ptr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : listing 7.18
//============================================================================

#include <iostream>
double betsy(int);
double pam(int);
//second argument - pointer to double function, which takes arguments int type
void estimate(int lines,double (*pf)(int));
int main() {
	using namespace std;
	int code;
	cout<<"Gow many lines of code so you need?";
	cin>>code;
	cout<<"Here's Betsy's estimate:\n";
	estimate(code,betsy);
	cout<<"Here's Pam's estimate:\n";
	estimate(code,pam);
	return 0;
}
double betsy(int lns)
{
	return 0.05*lns;
}
double pam(int lns)
{
	return 0.03*lns+0.0004*lns*lns;
}
void estimate(int lines,double (*pf)(int))
{
	std::cout<<lines<<" lines will take ";
	std::cout<<(*pf)(lines)<<" hour(s)\n";
}
