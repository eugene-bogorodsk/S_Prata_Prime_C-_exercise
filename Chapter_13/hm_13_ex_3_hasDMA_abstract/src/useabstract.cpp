/*
 * useabstract.cpp
 *
 *  Created on: 21 сент. 2019 г.
 *      Author: Евгений
 */


#include<iostream>
#include "abstract.h"

int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Fortabelly",8);
	lacksDMA balloon("red","Blimpo",4);
	hasDMA map("Mercator","Buffalo Keys",5);
	cout<<"Displaying baseDMA object:\n";
	shirt.View();
	cout<<"Displaing lacksDMA object:\n";
	balloon.View();
	cout<<"Displaying hasDMA object:\n";
	map.View();
	lacksDMA balloon2(balloon);
	cout<<"Result of lacksDMA copy:\n";
	balloon2.View();
	hasDMA map2;
	map2 = map;
	cout<<"Result of hasDMA assignment:\n";
	map2.View();
	return 0;
}




