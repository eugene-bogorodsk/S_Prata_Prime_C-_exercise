//============================================================================
// Name        : golf.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "golf.h"

int main() {

	golf ann;
	setgolf(ann,"Ann Birdfree",24);
	showgolf(ann);

	std::cout<<"Enter the players.\n";
	golf players[3];
	for (int j = 0;j<3;++j)
	{
			players[j].fullname[0] = '\0';
			players[j].handicap	= 0;
	}
	int index = 1;
	for(int i=0;i<3;++i)
	{
		if(index == 0){

			break;
		}

		else
			index = setgolf(players[i]);
	}

	std::cout<<std::endl;
	std::cout<<"Would you like to change a handicap?\n";


	for(int i=0;i<3;++i)
	{
		if(players[i].fullname[0] !='\0')
					std::cout<<i+1<<": ";
		showgolf(players[i]);
	}
	std::cout<<std::endl;


	std::cout<<"Choice a player, enter his number and new handicap.\n";
	if( std::cin.fail())
		std::cin.clear();
	int number,_hc;

	std::cin>>number>>_hc;
	handicap(players[number-1],_hc);
	for(int i=0;i<3;++i)
	{
		if(players[i].fullname[0] !='\0')
			std::cout<<i+1<<": ";
		showgolf(players[i]);
	}
	return 0;
}
