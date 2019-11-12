//============================================================================
// Name        : studenti.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "sudenti.h"
using std::ostream;
using std::istream;
using std::cout;
using std::string;

double Student:: Average() const
{
	if(arrayDB::size()>0)
		return arrayDB::sum()/arrayDB::size();
	else
		return 0;
}
double& Student::operator[](int i)
{
	return arrayDB::operator[](i); //использование arrayDB::operator[]()
}
double Student::operator[](int i)const
{
	return arrayDB::operator[](i);
}
const string& Student::Name() const
{
	return (const string& )*this;
}

ostream& Student::arr_out(ostream& os )const
{
	int i;
	int lim=arrayDB::size();
	if(lim > 0)
	{
		for(i=0;i<lim;++i)
		{
			os<<arrayDB::operator[](i)<<" ";
		if(i % 5 ==4)
			os<<std::endl;
		}
		if(i % 5 != 0)
				os<<std::endl;
	}
	else
		os<<"empty array";
	return os;
}
//ввод
istream& operator>>(istream& is, Student& st)
{
	is>>(string & )st;
	return is;
}
istream& getline(std::istream& is, Student& st)
{
	getline(is,(string &) st);
	return is;
}
ostream& operator<<(std::ostream& os,const Student& st)
{
	os<<"Scores for "<<(const string& )st<<":\n";
	st.arr_out(os);//использоавание закрытого метода
	return os;
}
