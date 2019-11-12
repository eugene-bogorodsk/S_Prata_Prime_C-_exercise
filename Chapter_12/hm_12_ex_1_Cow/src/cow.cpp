//============================================================================
// Name        : cow.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include "cow.h"

	Cow::Cow() // конструктор по умолчанию
	{
		name[0] = '\0';
		hobby = new char[1];
		hobby[0] = '\0';
		weight = 0;
	}

	Cow::Cow(const char* nm,const char* ho, double wt) //конструктор с передачей аргументов
	{
		strcpy(name,nm);
		hobby = new char[std::strlen(ho)+1];
		std::strcpy(hobby,ho);
		weight = wt;
	}

	Cow::Cow(const Cow& c) //конструктор копирования
	{
		strcpy(name,c.name);
		hobby = new char[strlen(c.hobby)+1];
		strcpy(hobby,c.hobby);
		weight = c.weight;
	}

	Cow::~Cow() //необходимый деструктор
	{
		delete [] hobby;
	}

	Cow& Cow:: operator = (const Cow& c)
	{

		if(this != &c)
		{
			strcpy(name,c.name);
			delete [] hobby;
			hobby = new char[strlen(c.hobby)+1];
			strcpy(hobby,c.hobby);
			weight = c.weight;
		}
		return *this;
	}
	void Cow::ShowCow() const
	{
		std::cout<<name<<" "<<hobby<<" - "<<weight<<std::endl;
	}
