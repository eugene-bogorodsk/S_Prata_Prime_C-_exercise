/* ���������� � ���������� � ������� ������������
 * twofile2.cpp
 *
 *  Created on: 4 ����. 2019 �.
 *      Author: �������
 */

#include <iostream>
extern int tom;//���������� ���������� � ������ �����
static int dick=10; //�������������� ������� ���������� dick
int harry=200; //�������� � harry �� twofile ����������

void remote_access()
{
	using namespace std;
	cout<<"remote_access() reports the following addresses:\n";
	cout<<&tom<<" = &tom, "<<&dick<<" = &dick, "<<&harry<<" = &hurry.\n";
}


