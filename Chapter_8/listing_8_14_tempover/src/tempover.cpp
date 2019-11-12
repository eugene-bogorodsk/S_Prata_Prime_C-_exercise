//============================================================================
// Name        : tempover.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
template <typename T>
void ShowArray(T arr[],int n);//шаблон ј

template <typename T>
void ShowArray(T* arr[],int n);//шаблон B

struct debts
{
	char name[50];
	double amount;
};

int main() {
	using namespace std;
	int things[6]={13,31,103,301,310,130};
	struct debts mr_E[3]=
	{
			{"Ima Wolfe",2400.0},
			{"Ura Foxe",1300.0},
			{"Iby Stout",1800.0},
	};
	double* pd[3];
	//установка указателей на члены amount структур в mr_E
	for(int i=0;i<3;i++)
		pd[i]=&mr_E[i].amount;
	cout<<"lwsting Mr. E's counts of things:\n";
	//things= массив значений int
	ShowArray(things,6); //использует шаблон ј
	cout<<"Listing Mr. E's debts:\n";
	//pd-массив указателей на double
	ShowArray(pd,3); //использует шаблон ¬ более специализированный
	return 0;
}
template<typename T>
void ShowArray(T arr[],int n)
{
	using namespace std;
	cout<<"template A\n";
	for (int i =0;i<n;i++)
		cout<<arr[i]<<' ';
	cout<<endl;
}
template <typename T>
void ShowArray(T* arr[],int n)
{
	using namespace std;
	cout<<"template B\n";
	for (int i=0;i<n;i++)
		cout<<*arr[i]<<' ';
	cout<<endl;
}
