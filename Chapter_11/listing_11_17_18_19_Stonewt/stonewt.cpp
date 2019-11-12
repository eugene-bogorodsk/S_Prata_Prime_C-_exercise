/*
 * stonewt.cpp
 *
 *  Created on: 23 сент. 2019 г.
 *      Author: Евгений
 */
#include <iostream>
using std::cout;
#include "stonewt1.h"

//конструирует объект Stonewt из значения типа double
Stonewt::Stonewt(double lbs)
{
	stone= int(lbs)/Lbs_per_stn;//целочисленное деление
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}



//конструирует объект Stonewt из стоунов и значения типа double
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

//функция член для умножения
Stonewt Stonewt::operator * (double n) const
{
	/*Stonewt st;
	st.stone= stone*n + int(pds_left*n)/Lbs_per_stn;//целочисленное деление
	st.pds_left = int(pds_left*n) % Lbs_per_stn + pds_left*n - int(pds_left*n);
	st.pounds = pounds*n;*/
	return Stonewt(n*pounds);

}

//дружественная функция для умножения
Stonewt operator*(double n, const Stonewt& st)
{
	return Stonewt(st.pounds*n);
}


//отображение веса в стоунах
void Stonewt::show_stn() const
{
	cout<<stone<<" stone, "<<pds_left<<" pounds\n";
}

//отображение веса в фунтах
void Stonewt::show_lbs() const
{
	cout<<pounds<<" pounds\n";
}

//функция преобразования
Stonewt::operator int() const
		{
	return int(pounds +0.5);
		}
Stonewt::operator double() const
		{
	return pounds;
		}
