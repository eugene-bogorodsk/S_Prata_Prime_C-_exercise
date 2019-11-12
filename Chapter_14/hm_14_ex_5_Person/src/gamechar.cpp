/*
 * gamechar.cpp
 *
 *  Created on: 6 окт. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include <cstring>
#include "person_ex.h"
const int SIZE=5;

int main()
{
using std::cout;
using std::endl;
using std::cin;

Person* badguy[SIZE];
int b;
for(b=0;b<SIZE;b++)
{
	char choice;
	cout<<"\nEnter the employee category:\n"
			<<"g: gunslinger  p: poker player "
			<<"b: bad dude q: quit\n";
	cin>>choice;
	while(std::strchr("gpbq",choice) ==NULL)
	{
		cout<<"Please enter a g, p, b, or q:";
		cin>>choice;
	}
	if(choice == 'q')
		break;
	switch(choice)
	{
	case 'g': badguy[b]= new Gunslinger;
		break;
	case 'p': badguy[b]= new PokerPlayer;
		break;
	case 'b': badguy[b]= new BadDude;
		break;
	}
	cin.get();
	badguy[b]->Set();
}
cout<<"\nHere are your game characters:\n";
for(int i =0; i<b;i++)
{
	cout<<endl;
	badguy[i]->Show();
}
	for (int i=0;i<b;i++)
		delete badguy[i];
	cout<<"Buy.\n";
	return 0;
}//end of the main


