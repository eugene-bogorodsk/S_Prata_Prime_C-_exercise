//============================================================================
// Name        : sales.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include "sales.h"

namespace SALES
{
	using std::cout;
	using std::cin;
	using std::endl;



	void setSales(Sales& s, const double ar [], int n)
	{

		for(int i= 0; i< n ;++i) s.sales[i] = ar[i];
		if(n<QUARTERS)
			for(int i=n ;i<QUARTERS;++i) s.sales[i] = 0.0;
		auto result = std::minmax_element(s.sales.begin(),s.sales.begin()+n);
		s.min = *result.first;
		s.max = *result.second;
		s.average = std::accumulate(s.sales.begin(),s.sales.end(),0.0)/n;
	}

	void setSales(Sales& s)
	{
		double temp_sales [QUARTERS];
		for(int i =0;i<QUARTERS;++i)
		{
			cout<<"Enter  sales volume for "
					<<i+1<<"quarter: ";
			cin>>temp_sales[i];
		}

		setSales(s,temp_sales,4);
	}

	void showSales(const Sales& s)
	{
		cout<<"Sales for the last four quarters:\n";
		for (auto p:s.sales)
			cout<<p<<' ';
		cout<<endl;
		cout<<"min sales: "<<s.min<<endl;
		cout<<"max sales: "<<s.max<<endl;
		cout<<"average sales: "<<s.average<<endl;
	}
}


