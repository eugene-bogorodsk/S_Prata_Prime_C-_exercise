//============================================================================
// Name        : coordin.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : ������ ��������� ���������� �� ���� ������
//============================================================================

#include <iostream>
#include "coordin.h"// ������� �������� � ��������� �������
using namespace std;

int main() {
	rect rplace;
	polar pplace;
	cout << "Enter the x and y values:"; //���� �������� x � y
	while(cin>>rplace.x>> rplace.y)
	{
		pplace= rect_to_polar(rplace);
		show_polar(pplace);
		cout<<"Next two numbers(q to quit): ";
	}
	cout<<"Done.\n";
	return 0;
}
