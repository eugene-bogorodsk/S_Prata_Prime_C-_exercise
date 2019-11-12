//============================================================================
// Name        : Port.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include "port.h"
using std::cout;
using std::endl;

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br)+1];
	strcpy(brand,br);
	strcpy(style,st);
	bottles = b;
}
Port::Port(const Port& pl)
{
	brand = new char[strlen(pl.brand)+1];
	strcpy(brand,pl.brand);
	strcpy(style,pl.style);
	bottles = pl.bottles;
}

Port& Port:: operator = (const Port& _port )
{
	if(this != &_port)
	{
		delete [] brand;
		brand = new char[strlen(_port.brand)+1];
		strcpy(brand, _port.brand);
		strcpy(style,_port.style);
		bottles= _port.bottles;
	}
	return *this;
}
Port& Port:: operator +=(int b )//добавляет b к  bottle
{
	bottles = bottles+b;
	return *this;
}
Port&Port:: operator -=(int b )//вычитаете b из bottle, если это возможно
{
	if(bottles< b)
		cout<<"Their are "<<bottles<<" only. Choice another number."<<endl;
	else
		bottles= bottles-b;
	return *this;
}
void Port::Show() const
{
	cout<<"Brand: "<<brand<<endl;
	cout<<"Kind: "<<style<<endl;
	cout<<"Bottles: "<<bottles<<endl;

}
std::ostream& operator<<(std::ostream& os, const Port& pt )
{
	os<<pt.brand<<", "<<pt.style<<", "<<pt.bottles;
	return os;
}

VintagePort::VintagePort():Port("none","vintage",0)
{
	nickname=new char[4];
	strcpy(nickname,"none");
	year=0;
}

VintagePort::VintagePort(const char* nn ,int _year, const char* br,int bt):
		Port(nn,"vintage",bt)
{
	nickname=new char[strlen(nn)+1];
	strcpy(nickname,nn);
	year=_year;
}
VintagePort::VintagePort(const VintagePort& vp):Port(vp)
{
	nickname= new char[strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year=vp.year;
}

VintagePort& VintagePort::operator = (const VintagePort& vp)
{
	if(this != &vp)
	{
		Port::operator=(vp);
		delete [] nickname;
		nickname= new char[strlen(vp.nickname)+1];
		strcpy(nickname,vp.nickname);
		year = vp.year;
	}
	return *this;
}
void VintagePort::Show() const
{
	Port::Show();
	cout<<"Nickname: "<<nickname<<endl;
	cout<<"Year: "<<year<<endl;
	cout<<endl;
}
std::ostream& operator<< (std::ostream& os,const VintagePort& vp)
{
	os<<dynamic_cast<const Port&>(vp);
	os<<", "<<vp.nickname<<", "<<vp.year<<endl;
	return os;
}
