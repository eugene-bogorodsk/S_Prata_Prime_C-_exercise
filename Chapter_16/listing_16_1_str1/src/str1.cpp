//============================================================================
// Name        : str1.cpp
// Author      : 
// Version     :using variable designers of string class
// Copyright   : Your copyright notice
// Description : listing 16.1
//============================================================================

#include <iostream>
#include <string>

int main() {
	using namespace std;
	string one("Lottery Winner!"); //ctor #1
	cout<<one<<endl;		//overloaded <<
	string two(20,'S');		//ctor #2
	cout<<two<<endl;
	string three(one); //ctor #3
	cout<<three<<endl;
	one+="OOps!"; //overloaded +=
	cout<<one<<endl;
	two="Sorry! That was ";
	three[0]='P';
	string four;  //ctor #4
	four=two+three; //overloaded +, =
	cout<<four<<endl;
	char alls[]="All well that ends well";
	string five(alls,20);  //ctor #5
	cout<<five<<"!\n";
	string six(alls+6,alls+10); //ctor #6
	cout<<six<<", ";
	string seven(&five[6],&five[10]);//again ctor #6
	cout<<seven<<"...\n";
	string eight(four,7,16); //ctor #7
	cout<<eight<<" in motion!"<<endl;


	return 0;
}
