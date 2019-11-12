/*
 * usecow.cpp
 *
 *  Created on: 15 сент. 2019 г.
 *      Author: Евгений
 */


#include <iostream>
#include "cow.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout<<"Enter a name:";
	char t_name[20];
	char t_hobby[150];
	cin.get(t_name,20).get();
	cout<<"Enter a hobby:";
	cin.get(t_hobby,150);
	cout<<"Enter a weight:";
	int t_weight;
	cin>>t_weight;
	Cow cow(t_name,t_hobby,t_weight);
	cow.ShowCow();
	Cow cow2;
	cow2.ShowCow();
	cow2 = cow;
	cow2.ShowCow();




}

