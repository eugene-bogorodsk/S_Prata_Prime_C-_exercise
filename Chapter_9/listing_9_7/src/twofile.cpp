//============================================================================
// Name        : twofile.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : ���������� � ������� � ���������� ������������
//============================================================================

#include <iostream>
int tom = 3;	// ������� ����������
int dick = 30; // ������� ����������
static int harry = 300; // �����������, ���������� ����������

// �������� �������
void remote_access();

int main() {
	using namespace std;
	cout << " main() reports the following addresses: \n"; // ����� �������
	cout<<&tom<<" = &tom, "<<&dick<<" = &dick, "<<&harry<<" = &hurry.\n";
	remote_access();
	return 0;
}
