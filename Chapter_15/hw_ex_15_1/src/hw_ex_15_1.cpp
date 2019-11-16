//============================================================================
// Name        : hw_ex_15_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : home work 15_1
//============================================================================

#include <iostream>
#include "tvUpdated.h"

bool Tv::volup()
{
	if(volume<MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}
bool Tv::voldown()
{
	if(volume>MinVal)
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

	cout<<"TV is "<<(state==Off?"Off":"On")<<endl; //������� ��� ��������
	if(state==On)
	{
		cout<<"Volume settings = "<<volume<<endl;//volume level
		cout<<"Channel setting = "<<channel<<endl;//channel number
		cout<<"Mode = "<<(mode==Antenna?"antenna":"cable")<<endl;//ant or cable
		cout<<(modeAc==Normal?"Normal":"Interactive")<<endl;//interactive or normal
		cout<<"Input = "<<(input==TV?"TV":"DVD")<<endl; //input TV or DVD
	}
}
