/*
 * pe_12_2_binary.cpp
 *
 *  Created on: 16 ����. 2019 �.
 *      Author: �������
 */


#include <iostream>
#include "string_binary.h"
using namespace std;
int main()
{
	String s1("and I am a C++ student.");
	cout<<s1<<endl;
	String s2 = "Please enter your name:"; //���� �����
	String s3;
	cout<<s2;// ������������� �������� <<
	cin>>s3; //������������� �������� >>
	s2 = "My name is "+ s3;//���������� �������� =,+
	cout<<s2<<".\n";
	s2=s2+s1;
	s2.stringup();
	cout<<s2.length()<<endl;
	cout<<s1.length()<<endl;
	cout<<"The string\n"<<s2<<"\ncontains "<<s2.has('A')
			<<" 'A' characters in it.\n";
	s1="red"; //String(const char*),
				//����� String& operator=(const String&)
	String rgb[3] = {String(s1),String("green"),String("blue")};
	cout<<"Enter the name of primary color for mixing light: "; //���� �����
	String ans;
	bool success = false;
	while(cin>>ans)
	{
		cout<<ans<<endl;
		ans.stringlow(); //�������������� ������ � ������ �������
		for(int i = 0;i<3;++i)
		{
			if(ans == rgb[i]) //������������� �������� ==
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



