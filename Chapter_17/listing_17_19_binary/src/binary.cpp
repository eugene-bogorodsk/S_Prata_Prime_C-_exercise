//============================================================================
// Name        : binary.cpp
// Author      : 
// Version     : binary file input/output
// Copyright   : Your copyright notice
// Description : listing 17.19
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

inline void eatline() {while (std::cin.get() !='\n') continue;}
struct planet
{
	char name[20]; //planet name
	double population;
	double g; //acceleration of gravity
};
const char * file = "planets.dat";

int main() {
	using namespace std;
	planet pl;
	cout<<fixed<<right;

	//display initial content
	ifstream fin;
	fin.open(file,ios_base::in | ios_base::binary); //binary file
	if (fin.is_open())
	{
		cout<<"Here are the current contents of the "
				<<file<<" file:\n";
		while (fin.read((char *) &pl,sizeof pl))
		{
			cout<<setw(20)<<pl.name<<": "
					<<setprecision(0)<<setw(12)<<pl.population
					<<setprecision(2)<<setw(6)<<pl.g<<endl;
		}
		fin.close();
	}
	//add new date
	ofstream fout(file,
			ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr<<"Can't open "<<file<<" file foe output:\n";
		exit(EXIT_FAILURE);
	}

	cout<<"Enter planet name (enter a blank line to quit):\n";
	cin.get(pl.name,20);
	while (pl.name[0] != '\0')
	{
		eatline();
		cout<<"Enter planertary population: ";
		cin>>pl.population;
		cout<<"Enter planet's acceleration of gravity: ";
		cin>>pl.g;
		eatline();
		fout.write((char *) &pl,sizeof pl);
		cout<<"Enter planet name (enter a blank line to quit):\n";
		cin.get(pl.name,20);
	}
	fout.close();
	//display changed file
	fin.clear();
	fin.open(file,ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout<<"Here are the new contents of the "
				<<file<<" file:\n";
		while (fin.read((char * ) &pl, sizeof pl))
		{
			cout<<setw(20)<<pl.name<<": "
					<<setprecision(0)<<setw(12)<<pl.population
					<<setprecision(2)<<setw(6)<<pl.g<<endl;
		}
		fin.close();
	}
	cout<<"Done.\n";
	return 0;
}
