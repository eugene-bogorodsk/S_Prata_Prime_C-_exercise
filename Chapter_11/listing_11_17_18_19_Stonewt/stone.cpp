/*
 * stone.cpp
 *
 *  Created on: 23 ����. 2019 �.
 *      Author: �������
 */


#include <iostream>
#include "stonewt1.h"
using std::cout;
void display(const Stonewt& , int);
int main()
{
	Stonewt incognito=275;//������������� ������������ �� ���������
	Stonewt wolfe(285.7); //�� �� ��� � Stonwt  wolfe = 285.7
	Stonewt taft(21,8);
	cout<<"The celebrity weighed";
	incognito.show_stn();
	cout<<"The detective weighed: ";
	wolfe.show_stn();
	cout<<"The President weighed: ";
	taft.show_lbs();
	incognito = 276.8; //������������� ������������ ��� ��������������
	taft = 325; //�� �� ��� � taft = Stonewt(325);
	cout<<"After fibber,the celebrity weighed ";
	incognito.show_stn();
	cout<<"After fibber, the President weighed ";
	taft.show_lbs();
	display(taft,2);
	cout<<"The wrestler weighed even more.\n";
	display(422,2);
	cout<<"No stone left unearned\n";
	cout<<std::endl;
	Stonewt poppins(9,2.8); //9 �������, 2,8 �����
	double p_wt = poppins; //������� ��������������
	cout<<"Convert to double => ";
	cout<<"Poppins: "<<p_wt<<" pounds.\n";
	cout<<"Convert to int => ";
	cout<<"Poppins: "<<int (poppins) <<" pounds.\n";
	Stonewt test_mul(10,8);
	cout<<"Initial test_mul: ";
	test_mul.show_stn();
	test_mul= test_mul*2.0;
	test_mul.show_stn();
	test_mul.show_lbs();

	return 0;

}//end of main

void display( const Stonewt& st,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Wow!";
		st.show_stn();
	}
}
