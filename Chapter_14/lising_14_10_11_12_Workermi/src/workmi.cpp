/*
 * workmi.cpp
 *
 *  Created on: 29 ����. 2019 �.
 *      Author: �������
 */

#include <iostream>
#include <cstring>
#include "worker1.h"
const int SIZE=5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Worker *lolas[SIZE];
	int ct;
	for(ct=0;ct<SIZE;ct++)
	{
		char choice;
		cout<<"Enter the employee category:\n";
		cout<<"w: waiter s:singer t:singer waiter q: quite\n";
		cin>>choice;
		while(strchr("wstq",choice) == NULL)
		{
			cout<<"Please enter w, s, t, or q: ";
			cin>>choice;
		}
		if(choice =='q')
			break;
		switch(choice)
		{
		case 'w': lolas[ct]= new Waiter;
			break;
		case 's': lolas[ct]= new Singer;
			break;
		case 't': lolas[ct] = new Singwaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout<<"\nHere is your staff:\n";
	int i;
	for(i = 0;i<ct;i++)
	{
		cout<<endl;
		lolas[i]->Show();
	}
	for(i=0;i<ct;i++)
		delete lolas[i];
	cout<<"Bye.\n";
	return 0;
}


