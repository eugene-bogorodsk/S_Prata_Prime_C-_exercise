/*
 * usesales.cpp
 *
 *  Created on: 14 ����. 2019 �.
 *      Author: �������
 */

#include <iostream>
#include "sales.h"

int main()
{
	using SALES::Sales;
	Sales _2018;
	Sales _2019;
	double dates_2019 [] = {40,50,30};
	//setSales(_2018);
	//showSales(_2018);
	setSales(_2019,dates_2019,3);
	showSales(_2019);
}


