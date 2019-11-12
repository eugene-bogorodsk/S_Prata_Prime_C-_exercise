//============================================================================
// Name        : coordin.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : пример программы соостоящей из трех файлов
//============================================================================

#include <iostream>
#include "coordin.h"// шаблоны структур и прототипы функций
using namespace std;

int main() {
	rect rplace;
	polar pplace;
	cout << "Enter the x and y values:"; //воод значений x и y
	while(cin>>rplace.x>> rplace.y)
	{
		pplace= rect_to_polar(rplace);
		show_polar(pplace);
		cout<<"Next two numbers(q to quit): ";
	}
	cout<<"Done.\n";
	return 0;
}
