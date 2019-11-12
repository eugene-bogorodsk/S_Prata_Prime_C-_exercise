/*
 * stacker.cpp
 *
 *  Created on: 17 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include "stack.h"

int main()
{
	using  std::cout;
	using std::cin;
	Stack st[3];
	char ch;
	int dep;//номер департамента
	unsigned long epo;
	unsigned long po [3];

	//А- добавление заказа, P - обработка заказа, Q- завершение
	cout<<"Please enter A to add a purchase order,\n"
			<<"P to process a PO,\n"
			<< "G to pass for processing another department\n"
				<<	"or Q to quit.\n";

	while(cin>>ch && toupper(ch) != 'Q')
	{
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch))
		{
			cout<<'\a';
			continue;
		}
		switch(ch)
		{
		case 'A':
		case 'a': cout<<"Enter a PO number to ass and  number of department: "; //запрос номера заказа
					cin>>dep>>epo;
					if(st[dep-1].isfull())
						cout<<"stack already full\n"; //стек уже полон
					else{
						po[dep-1]=epo;
						st[dep-1].push(po[dep-1]);
						}
					break;
		case 'P':
		case 'p':
					cout<<"Enter number of department:\n ";
					cin>>dep;
					if(st[dep-1].isempty())
					cout<<"stack already empty\n"; //стэк уже пуст
					else
					{
						st[dep-1].pop(po[dep-1]);
						cout<<"PO # "<<po[dep-1]<<" poped\n"; //заказ вытолкнут
					}
					break;
		case 'G':
		case 'g': 	st[0]=st[1];
					po[0]=po[1];
					cout<<"Your get the file from office #2. \n";
					cout<<st[0].getItem(0)<<'\n';
					break;
		}
		cout<<"Please enter A to add a purchase order,\n"
				<<"P to process a PO, or Q to quit.\n";
	}
	cout<<"Buy\n";
}


