/*
 * usebrass2.cpp
 *
 *  Created on: 12 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include <string>
#include "brass_2.h"

const int CLIENTS = 4;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	Brass* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	for(int i = 0;i < CLIENTS;i++)
	{
		cout<<"Enter clients name: ";
		getline(cin,temp);
		cout<<"Enter client's account number:	";
		cin>>tempnum;
		cout<<"Enter opening balance: $";
		cin>> tempbal;
		cout<<"Enter 1 for Brass Accoutn or"
				<<" 2 for Brass Plus Account:";
		while(cin>>kind && (kind!= '1' && kind != '2'))
			cout<<"Enter either 1 or 2:";
		if(kind == '1')
			p_clients[i] = new Brass(temp,tempnum,tempbal);
		else
		{
			double tmax,trate;
			cout<<"Enter the overdraft limit: $"; //ввод предельного овердрафта
			cin>>tmax;
			cout<<"Enter the inerest rate"
					<<"as a decimal fraction:";//ввод процентной ставки
			cin>>trate;
			p_clients[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
		}
		while(cin.get() != '\n')
			continue;
		cout<<endl;
	}
		for(int i = 0;i<CLIENTS;i++)
		{
			p_clients[i]->ViewAcct();
			cout<<endl;
		}

		for(int i = 0;i<CLIENTS;i++)
		{
			delete p_clients[i]; //освобождение памяти
		}
		cout<<"Done.\n";
		return 0;
}



