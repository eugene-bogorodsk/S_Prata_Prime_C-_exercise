/*
 * support.cpp
 *
 *  Created on: 4 ����. 2019 �.
 *      Author: �������
 */

#include <iostream>
extern double warming; //������������� ���������� warming �� ������� �����
// ��������� �������
void update(double dt);
void local();

using namespace std;
void update(double dt) //����������� ���������� ����������
{
	extern double warming; //�������������� ��������� ����������
	warming+=dt;
	cout<<"Updating global warming to "<<warming;
	cout<<" degrees.\n";
}

void local() //���������� ��������� ����������
{
	double warming = 0.8; //����� ���������� �������� �������
	cout<<"Local warming = "<<warming<<" degrees.\n";
	//������ � ���������� ���������� � ������� �������� ���������� ���������
	cout<<"But dlobal warming = "<<::warming;
	cout<<" degrees.\n";
}


