//============================================================================
// Name        : hasDMA_abstract.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "abstract.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

//методы absDMA
absDMA::absDMA(const char* _label,int r)
{
	label = new char[strlen(_label)+1];
	strcpy(label,_label);
	rating= r;
}

absDMA::absDMA(const absDMA& _abs)
{
	label = new char[strlen(_abs.label)+1];
	strcpy(label,_abs.label);
	rating = _abs.rating;
}
absDMA& absDMA::operator=(const absDMA& _abs)
{
	if(this != &_abs)
	{
		delete [] label;
		label =new char[strlen(_abs.label)+1];
		strcpy(label,_abs.label);
		rating = _abs.rating;
	}
	return *this;
}
//методы baseDMA


baseDMA::baseDMA(const baseDMA& rs){}


baseDMA& baseDMA:: operator =(const baseDMA& rs)
{
	if(this != &rs)
	{
		absDMA::operator =(rs);
	}
	return * this;
}

void baseDMA::View() const
{
	cout<<"Label: "<<Label()<<endl;
	cout<<"Rating: "<<Rating()<<endl;
	cout<<endl;
}

//методы lacksDMA
lacksDMA::lacksDMA(const char* c,const char* l,int r):
		absDMA(l,r)
{
	strncpy(color,c,39);
	color[39]='\0';
}

lacksDMA::lacksDMA(const char*c ,const absDMA& rs):
		absDMA(rs)
{
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1]='\0';
}

void lacksDMA::View() const
{
	cout<<"Label: "<<Label()<<endl;
	cout<<"Rating: "<<Rating()<<endl;
	cout<<"Color: "<<color<<endl;
	cout<<endl;
}

// методы hasDMA
hasDMA::hasDMA(const char* c,const char* l,int r):
		absDMA(l,r)
{
	style = new char[strlen(c)+1];
	strcpy(style,c);

}

hasDMA::hasDMA(const char* c,const absDMA& rs):
		absDMA(rs)
{
	style= new char[strlen(c)+1];
	strcpy(style,c);
}

hasDMA::hasDMA(const hasDMA& hs):
		absDMA(hs)//вызывает конструктор копирования базовго класса
{
	style= new char[strlen(hs.style)+1];
	strcpy(style,hs.style);
}


hasDMA& hasDMA:: operator=(const hasDMA& hs)
{
	if(this != &hs)
	{
		absDMA::operator =(hs);//копирование базовой части
		delete [] style;
		style = new char[strlen(hs.style)+1];
		strcpy(style,hs.style);
	}
	return *this;
}

void hasDMA::View() const
{
	cout<<"Label: "<<Label()<<endl;
	cout<<"Rating: "<<Rating()<<endl;
	cout<<"Style: "<< style<<endl;
	cout<<endl;
}
