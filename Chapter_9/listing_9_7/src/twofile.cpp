//============================================================================
// Name        : twofile.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : переменные с внешним и внутренним связываением
//============================================================================

#include <iostream>
int tom = 3;	// внешняя переменная
int dick = 30; // внешняя переменная
static int harry = 300; // статическая, внутреннее связывание

// прототип функции
void remote_access();

int main() {
	using namespace std;
	cout << " main() reports the following addresses: \n"; // вывод адресов
	cout<<&tom<<" = &tom, "<<&dick<<" = &dick, "<<&harry<<" = &hurry.\n";
	remote_access();
	return 0;
}
