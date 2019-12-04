//============================================================================
// Name        : arrobj.cpp
// Author      : 
// Version     :function with array objects(C++11)
// Copyright   : Your copyright notice
// Description : listing 7.15
//============================================================================

#include <iostream>
#include <array>
#include <string>

const int Seasons=4;
const std::array<std::string,Seasons> Snames =
      {"Spring","Summer","Fall","Winter"};

//function for change of array object
void fill(std::array<double,Seasons>* ps);

//function using array object but does not change it
void show(std::array<double,Seasons> ds);
int main() {
	std::array<double,Seasons> expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}
void fill(std::array<double,Seasons>* pa)
{
	for(int i=0;i<Seasons;i++)
	{
		std::cout<<"Enter "<<Snames[i]<<" expenses: ";
				std::cin>>(*pa)[i];
	}
}
void show(std::array<double,Seasons> da)
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
