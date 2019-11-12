/*
 * usestock2.cpp
 *
 *  Created on: 17 ����. 2019 �.
 *      Author: �������
 */

#include <iostream>
#include "stock20.h"
const int STKS=4;

int main()
{
	Stock stocks[STKS]=
	{
			Stock("Nanosmart",12,20.0),
			Stock("Boffo Object",200,2.0),
			Stock("Monolitick Obelisks",130,3.25),
			Stock("Flips Enterpirses",60,6.5)
	};

	std::cout<<"Stocks holdings:\n";
	int st;
	for(st = 0;st<STKS;st++)
		std::cout<<stocks[st]<<std::endl;

		//stocks[st].show();

	//��������� ��������� �� ������ �������
	const Stock *top = stocks;
	for(st=1;st<STKS;st++)
		top= &top->topval(stocks[st]);

	// ������ top �������� �� ������ ������ ����� �����
	std::cout<<"\nMost valuable holding:\n";
	// top->show();
	std::cout<<*top;
}


