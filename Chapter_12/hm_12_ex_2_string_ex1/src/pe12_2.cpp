/*
 * pe12_2.cpp
 *
 *  Created on: 15 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include "string2.h"
using namespace std;
int main()
{
	String s1("and I am a C++ student.");
	String s2 = "Please enter your name:"; //ввод имени
	String s3;
	cout<<s2;// перегруженная операция <<
	cin>>s3; //перегруженная операция >>
	s2 = "My name is "+s3;//перегрузка операций =,+
	cout<<s2<<".\n";
	s2=s2+s1;
	s2.stringup();
	cout<<"The string\n"<<s2<<"\ncontains "<<s2.has('A')
			<<" 'A' characters in it.\n";
	s1="red"; //String(const char*),
				//тогда String& operator=(const String&)
	String rgb[3] = {String(s1),String("green"),String("blue")};
	cout<<"Enter the name of primary color for mixing light: "; //ввод цвета
	String ans;
	bool success = false;
	while(cin>>ans)
	{
		ans.stringlow(); //преобразование строки в нижний регистр
		for(int i = 0;i<3;++i)
		{
			if(ans == rgb[i]) //перегруженная операция ==
			{
				cout<<"That's right!\n";
				success = true;
				break;
			}
		}
		if(success)
			break;
		else
			cout<<"Try again!\n";
	}
	cout<<"Buy\n";
}


