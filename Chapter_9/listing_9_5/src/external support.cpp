//============================================================================
// Name        : external.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : демонтсраци€ использовани€ ключевого слова extern
//============================================================================

#include <iostream>
using namespace std;

// внешн€€ переменна€
double warming = 0.3; // переменна€ warming определена
//прототипы функций
void update(double dt);
void local();

int main() { //использует глобальную переменную
	cout << "Global warming is "<<warming<<" degrees.\n";
	update(0.1); //вызов функции, измен€ющей warming
	cout<<"Global warming is "<<warming<<" degrees.\n";
	local();
	cout<<"Global warming is "<<warming<<" degrees.\n";
	return 0;
}
