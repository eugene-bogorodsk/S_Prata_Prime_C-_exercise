//============================================================================
// Name        : n.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include "strngbad.h"
using namespace std;
using std::cout;

//инициализация статического члена класса
int StringBad::num_strings =0;

//методы класса
StringBad::StringBad(const char* s)
{
	len= std::strlen(s); //установка размера
	str = new char[len+1]; //выделение памяти
	std::strcpy(str,s); //инициализация указателя
	num_strings++;
	cout<<num_strings<<": "<<str<<"\"object created\n"; //для целей отладки
}

StringBad::StringBad()
{
	len=4;
	str= new char[4];
	std::strcpy(str,"C++");// строка по умолчанию
	num_strings++;
	cout<<num_strings<<": \""<<str<<"\"defalt object created\n"; // для целей отладки
}

StringBad::~StringBad()
{
	cout<<"\""<<str<<"\""
			" object deleted. "; //для целей отладки
	--num_strings;
	cout<<num_strings<<" left\n"; //для целей отладки
	delete [] str;
}

std::ostream& operator <<(ostream& os,const StringBad& st)
{
	os<<st.str;
	return os;
}
