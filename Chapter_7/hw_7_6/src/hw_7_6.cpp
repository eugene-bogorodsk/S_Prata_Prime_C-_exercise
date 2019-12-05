//============================================================================
// Name        : hw_7_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int fill_array(double ar[],int n);
void show_array(double ar[],int n);
void reverse_array(double ar[],int n);

int main() {
	using namespace std;
	double ar1[5]{1.0,3.5,6.2,4.3,10.1};
	cout<<"Inital array:\n";
	show_array(ar1,5);
	double ar2[4];
	cout<<"Array after enter:\n";
	int s=fill_array(ar2,4);
	show_array(ar2,s);
	reverse_array(ar1,5);
	reverse_array(ar2,4);
	cout<<"Array 1 after reverse:\n";
	show_array(ar1,5);
	cout<<"Array 2 after reverese:\n";
	show_array(ar2,s);

	return 0;
}

int fill_array(double ar[],int n)
{
	double temp;
	int i=0;
	std::cout<<"Enter a volume of "<<i<<" element:\n";
	while(std::cin>>temp && i<n)
	{
		if(!std::cin)
		{
			std::cout<<"You finished an enter of numbers.\n";
			break;
		}
		ar[i]=temp;
		i++;
		if(i<n)
			std::cout<<"Enter a volume of "<<i<<" element:\n";
		else
		{
			std::cout<<"You finished an enter of numbers.\n";
			break;
		}
	}
	return i;
}
void show_array(double ar[],int n)
{
	std::cout<<"Your array: ";
	bool flag = true;
	for (int i=0;i<n;i++)
	{
		if(flag== false)
			std::cout<<", ";
		std::cout<<ar[i];
		flag=false;
	}
	std::cout<<std::endl;

}
void reverse_array(double ar[],int n)
{
	for (int i=0;i<n/2;i++)
	{
		double temp;
		temp=ar[n-1-i];
		ar[n-1-i]=ar[i];
		ar[i]=temp;
	}

}
