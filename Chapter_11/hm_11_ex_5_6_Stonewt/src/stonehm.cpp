//============================================================================
// Name        : stonehm.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using std::cout;
#include "stonehm.h"

//������������ ������ Stonewt �� �������� ���� double
Stonewt::Stonewt(double lbs,Mode m)
{
	mode = m;
	stone= int(lbs)/Lbs_per_stn;//������������� �������
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

//������������ ������ Stonewt �� �������� ���� int

Stonewt::Stonewt(int lbs,Mode m)
{
	mode = m;
	stone= int(lbs)/Lbs_per_stn;//������������� �������
	pds_left = int(lbs) % Lbs_per_stn;
	pounds = lbs;
}



//������������ ������ Stonewt �� ������� � �������� ���� double
Stonewt::Stonewt(int stn, double lbs,Mode m)
{
	mode=m;
	stone = stn;
	pds_left = lbs;
	pounds = stn*Lbs_per_stn +lbs;
}

Stonewt::Stonewt() //����������� �� ���������
{
	stone=pds_left=pounds = 0;
	mode = INT_POUNDS;
}

Stonewt::~Stonewt(){}

//���������� ����������
Stonewt Stonewt :: operator+(const Stonewt& st) const
{
	return Stonewt(pounds+st.pounds);
}
Stonewt Stonewt:: operator-(const Stonewt& st) const
{
	return Stonewt(pounds-st.pounds);
}

Stonewt Stonewt::operator*(const Stonewt& st) const
{
	return Stonewt(pounds*st.pounds);
}
//������� ���� ��� ���������
Stonewt Stonewt::operator * (double n) const
{

	return Stonewt(n*pounds);

}

//������������� ������� ��� ���������
Stonewt operator*(double n, const Stonewt& st)
{
	return Stonewt(st.pounds*n);
}


std::ostream& operator<<(std::ostream& os, const Stonewt& st)
{
	if(st.mode == Stonewt:: STONE)
		os<<st.stone<<" stone, "<<st.pds_left<<" pounds\n";
	else if(st.mode == Stonewt::INT_POUNDS)
		os<<(int)st.pounds<<" pounds\n";
	else if(st.mode == Stonewt::FLOAT_POUNDS)
		os<<st.pounds<<" pounds\n";
	else
		os<<"Value are invalid";
//	os<<st.stone<<" stone, "<<st.pds_left<<" pounds"<<"; "<<st.pounds<<" "<<st.mode;
	os<<std::endl;
	return os;

}

//������� ��������������
Stonewt::operator int() const
		{
	return int(pounds +0.5);
		}
Stonewt::operator double() const
		{
	return pounds;
		}
Stonewt Stonewt::change_mode(Stonewt::Mode m)
{
	if (m ==Stonewt::STONE)
		return Stonewt(stone,pds_left,m);
	else
		return Stonewt(pounds,m);
}

bool operator ==(const Stonewt& lhs,const Stonewt& rhs)
{
		return lhs.pounds==rhs.pounds;
}
bool operator !=(const Stonewt& lhs,const Stonewt& rhs)
{
	return lhs.pounds != rhs.pounds;
}

bool operator <(const Stonewt& lhs,const Stonewt& rhs)
{
	return lhs.pounds <rhs.pounds;
}

bool operator <=(const Stonewt& lhs,const Stonewt& rhs)
{
	return lhs.pounds<=rhs.pounds;
}
bool operator >(const Stonewt& lhs,const Stonewt& rhs)
{
	return lhs.pounds>rhs.pounds;
}

bool operator >=(const Stonewt& lhs,const Stonewt& rhs)
{
	return lhs.pounds>=rhs.pounds;
}
