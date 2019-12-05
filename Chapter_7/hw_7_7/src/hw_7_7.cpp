//============================================================================
// Name        : hw_7_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : pointers of range of values
//============================================================================

#include <iostream>
const int Max=5;

double* fill_array(double * begin,double* end);
void show_array(const double *begin,const double * end);
void revalue(double r,double * begin,double * end);

int main() {
	double properties[Max];
	double *size=fill_array(properties,properties+Max);
	show_array(properties,size);
	if (size > 0)
	{
		std::cout<<"Enter revaluation factor: ";
		double factor;
		while (!(std::cin>>factor))
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout<<"Bad input; Please enter a number: ";
		}
		revalue(factor,properties,size);
		show_array(properties,size);
	}
	std::cout<<"Done. \n";
	std::cin.get();
	return 0;
}



double* fill_array(double * begin,double* end)
{
	double temp;
	double *pt;
	int i=0;
	for(pt=begin;pt !=end;pt++,i++)
	{
		std::cout<<"Enter value #"<<(i+1)<<": ";
		std::cin>>temp;
		if(!std::cin)
		{
			std::cin.clear();
			while(std::cin.get() != '\n')
				continue;
			std::cout<<"Bad input; input process terminated.\n";
			break;
		}
		else if (temp<0)
			break;
		*(pt+i)=temp;
	}
	return pt;
}

void show_array(const double *begin,const double * end)
{
	const double *pt;
	int i=0;
	for(pt=begin;pt !=end;pt++,i++)
	{
		std::cout<<"Property #"<<(i+1)<<": $";
		std::cout<<*(pt+i)<<std::endl;

	}
}


void revalue(double r,double * begin,double * end)
{
	double *pt;
	int i=0;
	for (pt=begin;pt!=end;pt++,i++)
		*(pt+i)=*(pt+i)*r;
}

