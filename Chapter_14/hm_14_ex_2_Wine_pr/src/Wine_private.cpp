//============================================================================
// Name        : Wine_private.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "wine1.h"


int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	cout<<"Enter name of wine: ";
			char lab[50];
	cin.get(lab,50);
	cout<<"Enter number of years: ";
	int yrs;
	cin>>yrs;
	Wine holding(lab,yrs);
	holding.GetBottles();
	holding.Show();
	const int YRS=3;
	int y[YRS]={1993,1995,1998};
	int b[YRS]={48,60,72};
	//�������� ������ �������, �������������
	//� �������������� ������ �� �������� y � b
	Wine more("Gushing Grape Red",YRS,y,b);
	more.Show();
	cout<<"Total bottles for "<<more.Label()
			<<": "<<more.sum()<<endl;
	cout<<"Buy\n";

	return 0;\
}
