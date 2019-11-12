//============================================================================
// Name        : tvfm.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "tvfm.h"

bool Tv::volup()
{
	if(volume<MaxVol)
	{
		volume++;
		return true;
	}
	else
		return false;
}
bool Tv::voldown()
{
	if(volume>MinVol)
	{
		volume--;
		return true;
	}
	else
		return false;
}
void Tv::chanup()
{
	if(channel<maxchannel)
		channel++;
	else
		channel=1;
}
void Tv::chandown()
{
	if(channel>1)
		channel--;
	else
		channel=maxchannel;
}
void Tv::settings() const
{
	using std::cout;
	using std::endl;

	cout<<"TV is "<<(state==Off?"Off":"On")<<endl; //включен или выключен
	if(state==On)
	{
		cout<<"Volume settings = "<<volume<<endl;//volume level
		cout<<"Channel setting = "<<channel<<endl;//channel number
		cout<<"Mode = "<<(mode==Antenna?"antenna":"cable")<<endl;//ant or cable
		cout<<"Input = "<<(input==TV?"TV":"DVD")<<endl; //input TV or DVD
	}
}
