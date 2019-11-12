/* определение функций
 * golff.cpp
 *
 *  Created on: 5 сент. 2019 г.
 *      Author: Евгений
 */
#include <iostream>
#include <cstring>
#include "golf.h"


void setgolf(golf& g,const char* name,int hc)
{
	int j=0;
	while(*name){
		*(g.fullname+j)=*name++;
		++j;
	}
	*(g.fullname+j)='\0';

	g.handicap = hc;
}

int setgolf(golf& g)
{
	char enter[Len];
	int hc;

	std::cout<<"Enter full name: ";
	std::cin.get();
	std::cin.get(enter,Len);


	if (enter[0]== '\0')
	{
		return 0;
	}
	else
	{
		std::cout<<"Enter handicap: ";
		std::cin>>hc;
		//std::cin.get();
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
