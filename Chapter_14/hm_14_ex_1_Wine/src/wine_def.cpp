/*
 * wine_def.cpp
 *
 *  Created on: 3 окт. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include "wine.h"

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


Wine::Wine(const std::string& l,int y,const int yr[],const int bt[])
			:label(l),_set(ArrayInt(yr,y),ArrayInt(bt,y)){}
/*{

	for(int i=0;i<_year;i++)
	{
		_set.first()[i]=y[i];
		_set.second()[i]= b[i];
	}
}*/
void Wine:: GetBottles()
{
	std::cout<<"Enter "<<label<<" data for "<<_set.first().size()<<" year(s).\n";
			size_t i=0;
		while (i<_set.first().size())
		{
			std::cout<<"Enter year:";
			std::cin>>_set.first()[i];
			std::cout<<"Enter bottles for that year: ";
			std::cin>>_set.second()[i];
			++i;
		}
}

const string& Wine:: Label() const
{
	return label;
}
int Wine::sum() const
{

	return _set.second().sum();
}
void Wine::Show() const
{
	std::cout<<label<<std::endl;
	std::cout<<"\tYear "<<"\tBottles"<<std::endl;
	for(size_t i = 0; i<_set.first().size();i++)
		std::cout<<"\t"<<_set.first()[i]<<"\t "<<_set.second()[i]<<std::endl;
}
