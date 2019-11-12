/*
 * use_wk_qu.cpp
 *
 *  Created on: 4 окт. 2019 г.
 *      Author: Евгений
 */


#include <iostream>
#include <cstring>
#include "wq.h"
const int SIZE=5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Queue< Worker*> line;
	Worker* temp;
	for( int ct=0;ct<SIZE;ct++)
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
		case 'w':  temp= new Waiter;
			break;
		case 's': temp= new Singer;
			break;
		case 't':temp = new Singwaiter;
			break;
		}
		cin.get();
	if(line.isfull())
		cout<<"There are not avaliable area\n";
	else{
		temp->Set();
		line.enqueue(temp);
	}
	}
	cout<<"\nHere is your staff:\n";

	if(!line.isempty())
	{
		temp->Show();
		temp++;
	}

	cout<<"Bye.\n";
	return 0;
}




