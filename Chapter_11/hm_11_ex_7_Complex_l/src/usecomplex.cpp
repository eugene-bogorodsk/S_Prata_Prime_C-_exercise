/*
 * usecomplex.cpp
 *
 *  Created on: 26 сент. 2019 г.
 *      Author: Евгений
 */

#include "complex0.h"
#include <iostream>
using namespace std;


int main()
{

	complex a(3.0,4.0);
	complex c;
	cout<<"Enter a complex number (q to quite):\n";
	//вход комплексного числа (q для завершения)
	while(cin>>c)
	{
		cout<<"c is "<<c<<'\n';
		cout<<"complex conjugate is "<<~c<<'\n';
		//значение сопряженного числа
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

