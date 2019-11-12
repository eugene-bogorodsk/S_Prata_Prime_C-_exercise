/*полиморфный пример с использованием абстрактного базового класса
 * usebrass3.cpp
 *
 *  Created on: 13 сент. 2019 г.
 *      Author: Евгений
 */

#include<iostream>
#include<string>
#include "acctabc.h"

const int CLIENTS = 4;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	AcctABC* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for(int i =0;i<CLIENTS;i++)
	{
		cout<<"Enter client's name: ";
		getline(cin,temp);//ввод имени клиента
		cout<<"Enter client's account number:";// ввод номер счета клиента
		cin>>tempnum;
		cout<<"Enter opening balance: $"; //ввод начального баланса
		cin>>tempbal;
		cout<<"Enter 1 for Brass Account or"//1 - -Brass Account
			<<"2 for Brass Plus Account: ";//2 - Brass Plus Account
		while(cin >>kind && (kind != '1' && kind !='2'))
			cout <<"Enter either 1 or 2: ";
		if(kind =='1')
			p_clients[i] = new Brass(temp,tempnum,tempbal);
		else
		{
			double tmax,trate;
			cout<<"Enter the overdraft limit: $"; //ввод предела овердрафта
			cin>>tmax;
			cout<<"Enter the interest rate"
					<<"as a decimal fraction:";// ввод процентной ставки
			cin>>trate;
			p_clients[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
		}
		while(cin.get() != '\n')
			continue;
	}
	cout<<endl;
	for(int i = 0;i<CLIENTS;i++)
	{
		p_clients[i]->ViewAcct();
		cout<<endl;
	}
	for(int i = 0; i<CLIENTS;i++)
	{
		delete p_clients[i]; //освобождение памяти
	}
	cout<<"Done.\n";
	return 0;
}

