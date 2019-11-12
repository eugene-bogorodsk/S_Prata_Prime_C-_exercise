/*
 * sales.h
 *
 *  Created on: 13 ����. 2019 �.
 *      Author: �������
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
