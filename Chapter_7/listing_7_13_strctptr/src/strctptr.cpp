//============================================================================
// Name        : strctptr.cpp
// Author      : 
// Version     :function with arguments pointers to the structure
// Copyright   : Your copyright notice
// Description :listing 7.13
//============================================================================

#include <iostream>
#include <cmath>

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

void rect_to_polar(const rect* pxy,polar* pda);
void show_polar(const polar * pda);


int main() {
	using namespace std;
	rect rplace;
	polar pplace;
	cout<<"Enter the x and y valumes: ";
	while (cin>>rplace.x>>rplace.y)
	{
		rect_to_polar(&rplace,&pplace);
		show_polar(&pplace);
		cout<<"Next two numbers (q to quit): ";
	}
	cout<<"Done. \n";
	return 0;
}
//display of polar coordinates with conversion of radians to degrees
void show_polar (const polar* pda)
{
	using namespace std;
	const double Rad_to_deg=57.2957;
	cout<<"distance = "<<pda->distance;
	cout<<", angle = "<<pda->angle*Rad_to_deg;
	cout<<"degrees\n";
}
//conversion rectangular coordinats to polar ones
void rect_to_polar(const rect * pxy,polar * pda)
{
	pda->distance=
			std::sqrt(pxy->x*pxy->x+pxy->y*pxy->y);
	pda->angle=std::atan2(pxy->y,pxy->x);
}
