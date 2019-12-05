//============================================================================
// Name        : hw_7_10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : function calculate()
//============================================================================

#include <iostream>
using namespace std;

double add(double,double);
double multiplay(double,double);
double division(double,double);
double calculate(double,double,double(*p_f)(double,double));

int main() {
	double x,y;
	double (*pf[3])(double,double)={add,multiplay,division};
	cout<<"Enter pair of numbers for calculating or q for exit:\n";
	while(cin>>x>>y){
		if(!cin)
			break;
		for(int i=0;i<3;i++)
			cout << calculate(x,y,pf[i])<<" ";
		cout<<"\nEnter next pair:\n";
	}
	cout<<"Finish";
	return 0;

}

double calculate(double x,double y,double (*p_f)(double,double))
{
	return (*p_f)(x,y);
}
double add(double x,double y)
{
	return x+y;
}
double multiplay(double x,double y)
{
	return x*y;
}
double division(double x,double y)
{
	return x/y;
}
