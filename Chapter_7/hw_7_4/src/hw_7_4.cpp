//============================================================================
// Name        : hw_7_4.cpp
// Author      : 
// Version     :upgrated lotto
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>


long double probability(unsigned numbers,unsigned picks, unsigned meganumber);
int main() {
	using namespace std;
	double total,choices,meganumber;
	cout<<"Enter the total number of choices on the game card,\n"
			"the number of picks allowed and volume for meganumber:\n";
	while ((cin>>total>>choices>>meganumber) && choices<=total)
	{
		cout<<"You have one chance in ";
		cout<<probability(total,choices,meganumber);
		cout<<" of winning.\n";
		cout<<"Next three numbers  (q to quit): ";
	}
	cout<<"Bye\n";
	return 0;
}

long double probability(unsigned numbers,unsigned picks,unsigned meganumber)
{
	long double result=1.0;
	long double n;
	unsigned p;
	for (n=numbers,p=picks;p>0;n--,p--)
		result*=n/p;
	return result*meganumber;
}
