//============================================================================
// Name        : classic2.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "classic2.h"
#include <cstring>


using std::cout;
using std::endl;

	Cd::Cd(const char* _performers,const char* _label,int _selections,double _playtime )
	{
		performers = new char[strlen(_performers)+1];
		strcpy(performers,_performers);
		label= new char[strlen(_label)+1];
		strcpy(label,_label);
		selections= _selections;
		playtime= _playtime;
	}

	Cd::Cd(Cd& _cd)
	{
		performers= new char[strlen(_cd.performers)+1];
		strcpy(performers,_cd.performers);
		label = new char[strlen(_cd.label)+1];
		strcpy(label,_cd.label);
		selections = _cd.selections;
		playtime=_cd.playtime;
	}

	Cd::Cd()
	{
		performers = new char [5];
		strcpy(performers,"none");
		label = new char [5];
		strcpy(label,"none");
		selections = 0;
		playtime = 0;
	}
	Cd:: ~Cd(){ delete [] performers; delete [] label;}

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
			delete [] performers; delete [] label;
			performers= new char[strlen(_cd.performers)+1];
			strcpy(performers,_cd.performers);
			label = new char[strlen(_cd.label)+1];
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
			mainsong = new char [strlen(_mainsong)+1];
			strcpy(mainsong,_mainsong);
	}
	Classic::Classic(const char* _mainsong, Cd& _cd):
		Cd(_cd)
		{
		mainsong = new char [strlen(_mainsong)+1];
		strcpy(mainsong,_mainsong);
		}
	Classic::Classic(const Classic& _cl)
	{
		mainsong = new char [strlen(_cl.mainsong)+1];
		strcpy(mainsong,_cl.mainsong);
	}

	Classic::Classic():Cd(),mainsong(strcpy(mainsong,"none")){}

	Classic:: ~Classic(){delete [] mainsong;}

	void Classic:: Report() const
	{
		Cd::Report();
		cout<<"Main song: "<<mainsong<<endl;
	}

	Classic& Classic:: operator = (const Classic& cl )
	{
		if(this != &cl)
		{
			Cd::operator =(cl);
			delete [] mainsong;
			mainsong = new char [strlen(cl.mainsong)+1];
			strcpy(mainsong,cl.mainsong);
		}
		return *this;
	}


