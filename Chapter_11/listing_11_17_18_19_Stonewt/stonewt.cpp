/*
 * stonewt.cpp
 *
 *  Created on: 23 ����. 2019 �.
 *      Author: �������
 */
#include <iostream>
using std::cout;
#include "stonewt1.h"

//������������ ������ Stonewt �� �������� ���� double
Stonewt::Stonewt(double lbs)
{
	stone= int(lbs)/Lbs_per_stn;//������������� �������
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}



//������������ ������ Stonewt �� ������� � �������� ���� double
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn*Lbs_per_stn +lbs;
}

Stonewt::Stonewt()
{
	stone=pds_left=pounds = 0;
}

Stonewt::~Stonewt(){}

//������� ���� ��� ���������
Stonewt Stonewt::operator * (double n) const
{
	/*Stonewt st;
	st.stone= stone*n + int(pds_left*n)/Lbs_per_stn;//������������� �������
	st.pds_left = int(pds_left*n) % Lbs_per_stn + pds_left*n - int(pds_left*n);
	st.pounds = pounds*n;*/
	return Stonewt(n*pounds);

}

//������������� ������� ��� ���������
Stonewt operator*(double n, const Stonewt& st)
{
	return Stonewt(st.pounds*n);
}


//����������� ���� � �������
void Stonewt::show_stn() const
{
	cout<<stone<<" stone, "<<pds_left<<" pounds\n";
}

//����������� ���� � ������
void Stonewt::show_lbs() const
{
	cout<<pounds<<" pounds\n";
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
