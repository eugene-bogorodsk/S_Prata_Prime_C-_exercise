/*
 * Winepr_def.cpp
 *
 *  Created on: 4 окт. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include "wine1.h"

template <typename T1,typename T2>
T1 & Pair<T1,T2>:: first()
{
	return a;
}

template <typename T1,typename T2>
T2 & Pair<T1,T2>::second()
{
	return b;
}

void Wine:: GetBottles()
{
	std::cout<<"Enter "<<Label()<<" data for "<<Pair::first().size()<<" year(s).\n";
	size_t i=0;
		while (i<Pair::first().size())
		{
			std::cout<<"Enter year:";
			std::cin>>Pair::first()[i];
			std::cout<<"Enter bottles for that year: ";
			std::cin>>Pair::second()[i];
			++i;
		}
}

const string& Wine:: Label() const
{
	return (const string&) (*this);
}

int Wine::sum() const
{
	if(Pair::second().size() > 0)
		return Pair::second().sum();
	else
		return 0;
}
void Wine::Show() const
{
	std::cout<<Label()<<std::endl;
	std::cout<<"\tYear "<<"\tBottles"<<std::endl;
	for(size_t i = 0; i<Pair::first().size();i++)
		std::cout<<"\t"<<Pair::first()[i]<<"\t "<<Pair::second()[i]<<std::endl;
}


