/*
 * usecomplex.cpp
 *
 *  Created on: 26 ����. 2019 �.
 *      Author: �������
 */

#include "complex0.h"
#include <iostream>
using namespace std;


int main()
{

	complex a(3.0,4.0);
	complex c;
	cout<<"Enter a complex number (q to quite):\n";
	//���� ������������ ����� (q ��� ����������)
	while(cin>>c)
	{
		cout<<"c is "<<c<<'\n';
		cout<<"complex conjugate is "<<~c<<'\n';
		//�������� ������������ �����
		cout<<"a is "<<a<<'\n';
		cout<<"a+c is "<<a+c<<'\n';
		cout<<"a+c is "<<a-c<<'\n';
		cout<<"a+c is "<<a*c<<'\n';
		cout<<"a+c is "<<2*c<<'\n';
		cout<<"Enter a complex number (q to quite): \n";
	}
	cout<<"Done.\n";

	return 0;
}

