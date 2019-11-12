//============================================================================
// Name        : funtemp.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//прототип шаблона функции
template<typename T>
void Swap(T& a,T& b);

int main() {
	using namespace std;
	int i=10;
	int j=20;
	cout<<"i, j= "<<i<<", "<<j<<".\n";
	cout<<"Using compiler-generated int swapper:\n";
	Swap(i,j); //генерирет coid Swap(int&,int &)
	cout<<"Now i,j = "<<i<<", "<<j<<".\n";
	double x=24.5;
	double y=81.7;
	cout<<"x,y="<<x<<", "<<y<<",\n";
	cout<<"Using compler-generated double swapper:\n";
	Swap(x,y);
	cout<<"Now x,y = "<<x<<", "<<y<<",\n";
	return 0;
}

//определение шаблона функции
template<typename T> //или class T
void Swap(T& a, T& b)
{
	T temp; //temp - переменна типа T
	temp =a;
	a=b;
	b=temp;
}
