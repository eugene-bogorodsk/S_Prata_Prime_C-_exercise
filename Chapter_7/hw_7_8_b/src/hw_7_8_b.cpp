//============================================================================
// Name        : hw_7_8_b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <string>

const int Seasons=4;
const char* Snames[Seasons] =
      {"Spring","Summer","Fall","Winter"};

struct Expenses
{
	double m_expensis;
};

//function for change of array object
void fill(Expenses * pa);

//function using array object but does not change it
void show(Expenses ds []);
int main() {
	Expenses expenses[Seasons] ;
	fill(expenses);
	show(expenses);
	return 0;
}
void fill(Expenses *pa)
{
	for(int i=0;i<Seasons;i++)
	{
		std::cout<<"Enter "<<Snames[i]<<" expenses: ";
				std::cin>>(*(pa+i)).m_expensis;
	}
}
void show(Expenses da[])
{
	double total = 0.0;
	std::cout<<"\nEXPENSES\n";
	for (int i=0;i<Seasons;i++)
	{
		std::cout<<Snames[i]<<": $"<<da[i].m_expensis<<std::endl;
		total+=da[i].m_expensis;
	}
	std::cout<<"Total Expenses: $"<<total<<std::endl;
}

