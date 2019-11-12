/*
 * sales.h
 *
 *  Created on: 13 сент. 2019 г.
 *      Author: Евгений
 */
#include <array>
namespace SALES
{
	const int QUARTERS=4;
	struct Sales
	{
		std::array <double,QUARTERS> sales;
		double average;
		double max;
		double min;
	};


	void setSales(Sales& s, const double ar[],int n);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}
