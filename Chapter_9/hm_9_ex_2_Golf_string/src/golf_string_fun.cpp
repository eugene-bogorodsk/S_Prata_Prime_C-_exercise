/*
 * golf_string_fun.cpp
 *
 *  Created on: 10 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include <cstring>
#include "golf_string.h"


void setgolf(golf& g,string& name,int hc)
{

	g.fullname=name;
	g.handicap = hc;
}

int setgolf(golf& g)
{
	string enter;
	int hc;

	std::cout<<"Enter full name: ";
	std::cin.get();
	std::getline(std::cin,enter);


	if (enter== "")
	{
		return 0;
	}
	else
	{
		std::cout<<"Enter handicap: ";
		std::cin>>hc;
		setgolf(g,enter,hc);
		return 1;
	}
}

void handicap(golf& g,int hc)
{
	g.handicap = hc;
}
void showgolf(const golf& g)
{
	if ( g.fullname[0] !=0){
		std::cout<<g.fullname<<": "<<g.handicap<<"\n";
	}
}




