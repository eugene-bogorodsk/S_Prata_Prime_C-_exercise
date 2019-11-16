/*
 * use_sales.cpp
 *listing 15.16 nested exceptions
 *  Created on: 14 нояб. 2019 г.
 *      Author: Eugene
 */

#include <iostream>
#include "sales.h"
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double vals1[12]=
	{
			1220,1100,1122,2212,1232,2334,
			2884,2393,3302,2922,3002,3544
	};
	double vals2[12]=
	{
			12,11,22,21,32,34,
			28,29,33,29,32,35
	};
	Sales sales1(2011,vals1,12);
	LabeledSales sales2("Blogstar",2012,vals2,12);
	cout<<"First try block:\n";
	try
	{
		int i;
		cout<<"Year = "<<sales1.Year()<<endl;
		for(i=0;i<12;++i)
		{
			cout<<sales1[i]<<' ';if(i%6==5)
				cout<<endl;
		}
		cout<<"Year = "<<sales2.Year()<<endl;
		cout<<"Label = "<<sales2.Label()<<endl;
		for(i=0;i<=12;++i)
		{
			cout<<sales2[i]<<' ';
			if(i%6 == 5)
				cout<<endl;
		}
		cout<<"End of try block 1.\n";
	}
	catch(Sales::bad_index *bi)
	{
		LabeledSales::nbad_index *ps;
		cout<< bi->what();
		if(ps=dynamic_cast<LabeledSales::nbad_index *>(bi))
				cout<<ps->label_val()<<endl;
		cout<<"bad index: "<< bi->bi_val()<<endl;
		delete ps;
	}

	cout<<"\nNext try block:\n";
	try
	{
		sales2[2]=37.7;
		sales1[20]=23345;
		cout<<"End of try block 2.\n";
	}
	catch(Sales::bad_index *bi)
	{
		cout<< bi->what();
		if(typeid(*bi)==typeid(LabeledSales::nbad_index))
			((LabeledSales::nbad_index *) bi) ->label_val();
		cout<<"bad index: "<< bi->bi_val()<<endl;

	}

	cout<<"done\n";
	return 0;
}//end main

