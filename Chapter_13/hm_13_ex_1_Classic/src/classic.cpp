//============================================================================
// Name        : classic.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "classic.h"
#include <cstring>


using std::cout;
using std::endl;

	Cd::Cd(const char* _performers,const char* _label,int _selections,double _playtime )
	{
		strcpy(performers,_performers);
		strcpy(label,_label);
		selections= _selections;
		playtime= _playtime;
	}

/*Cd::Cd(Cd& _cd)
	{
		strcpy(performers,_cd.performers);
		strcpy(label,_cd.label);
		selections = _cd.selections;
		playtime=_cd.playtime;
	}
	*/
	Cd::Cd()
	{
		strcpy(performers,"none");
		strcpy(label,"none");
		selections = 0;
		playtime = 0;
	}
	Cd:: ~Cd(){}

	void Cd::Report()const //выводит данные о компакт диске
	{
		cout<<"Performer: "<<performers<<endl;
		cout<<"Label: "<<label<<endl;
		cout<<"Selections:"<<selections<<endl;
		cout<<"Play time: "<<playtime<<endl;
	}
	Cd& Cd:: operator=(const Cd& _cd)
	{
		if(this != &_cd)
		{
			strcpy(performers,_cd.performers);
			strcpy(label,_cd.label);
			selections = _cd.selections;
			playtime=_cd.playtime;
		}
		return *this;
	}
	Classic::Classic(const char* _mainsong,const char* _performers,
			const char* _label,int _selections,double _playtime ):
		Cd(_performers,_label,_selections,_playtime)
	{
			strcpy(mainsong,_mainsong);
	}
/*	Classic::Classic(char* _mainsong, Cd& _cd):
		Cd(_cd)
		{
		strcpy(mainsong,_mainsong);
		}
	Classic::Classic(const Classic& _cl)
	{
		strcpy(mainsong,_cl.mainsong);
	}*/

	Classic::Classic():Cd(),mainsong("none"){}

	Classic:: ~Classic(){}

	void Classic:: Report() const
	{
		Cd::Report();
		cout<<"Main song: "<<mainsong<<endl;
	}

/*	Classic& Classic:: operator = (const Classic& cl )
	{
		if(this != &cl)
		{
			Cd::operator =(cl);
			strcpy(mainsong,cl.mainsong);
		}
		return *this;
	}*/

