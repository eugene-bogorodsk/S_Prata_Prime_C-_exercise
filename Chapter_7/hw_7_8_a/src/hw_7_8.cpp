//============================================================================
// Name        : hw_7_8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using const char* array
//============================================================================

#include <iostream>
#include <array>
#include <string>

const int Seasons=4;
const char* Snames[Seasons] =
      {"Spring","Summer","Fall","Winter"};

//function for change of array object
void fill(double * pa);

//function using array object but does not change it
void show(double ds []);
int main() {
	double expenses[Seasons] ;
	fill(expenses);
	show(expenses);
	return 0;
}
void fill(double *pa)
{
	for(int i=0;i<Seasons;i++)
	{
		std::cout<<"Enter "<<Snames[i]<<" expenses: ";
				std::cin>>*(pa+i);
	}
}
void show(double da[])
{
	double total = 0.0;
	std::cout<<"\nEXPENSES\n";
	for (int i=0;i<Seasons;i++)
	{
		std::cout<<Snames[i]<<": $"<<da[i]<<std::endl;
		total+=da[i];
	}
	std::cout<<"Total Expenses: $"<<total<<std::endl;
}
