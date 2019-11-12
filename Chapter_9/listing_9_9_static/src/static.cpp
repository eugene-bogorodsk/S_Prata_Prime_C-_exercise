//============================================================================
// Name        : static.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description :использование статической локальной переменной
//============================================================================

#include <iostream>
// константы
const int ArSize = 10;
//прототип функции
void strcount(const char* str);


int main() {
	using namespace std;
	char input [ArSize];
	char next;
	cout<<"Enter a line: \n";
	cin.get(input,ArSize);
	while(cin)
	{
		cin.get(next);
		while(next != '\n')// строка не помещается
			cin.get(next); //избавится от остатка
		strcount(input);
		cout<<"Enter next line(empty line to quit):\n";
		cin.get(input,ArSize);
	}
	cout<<"Bye.\n";
	return 0;
}
void strcount(const char* str)
{
	using namespace std;
	static int total = 0;//статическая локальня переменная
	int count = 0; //автоматическая локальная переменная
	cout<<"\""<<str<<"\" contains ";
	while(*str++)// переход к концу строки
		count++;
	total+=count;
	cout<<count<<" characters\n";
	cout<<total<<" characters total\n";
}
