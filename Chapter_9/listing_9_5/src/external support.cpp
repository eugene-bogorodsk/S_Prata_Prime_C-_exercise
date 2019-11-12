//============================================================================
// Name        : external.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : ������������ ������������� ��������� ����� extern
//============================================================================

#include <iostream>
using namespace std;

// ������� ����������
double warming = 0.3; // ���������� warming ����������
//��������� �������
void update(double dt);
void local();

int main() { //���������� ���������� ����������
	cout << "Global warming is "<<warming<<" degrees.\n";
	update(0.1); //����� �������, ���������� warming
	cout<<"Global warming is "<<warming<<" degrees.\n";
	local();
	cout<<"Global warming is "<<warming<<" degrees.\n";
	return 0;
}
