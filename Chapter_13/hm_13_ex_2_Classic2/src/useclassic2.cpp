/*
 * useclassic2.cpp
 *
 *  Created on: 20 сент. 2019 г.
 *      Author: Евгений
 */


#include <iostream>
#include "classic2.h"
void Bravo(const Cd& );

int main()
{
	using std::cout;
	using std::cin;

	Cd c1("Beatles", "Capitol",14,35.5);
	Classic c2 = Classic("Piano Sonata in B Flat,Fantasia in C",
		"Alfred Drendel","Philips",2,57.17);
	Cd *pcd = &c1;
	//непосредственное использование объектов
	cout<<"Using object directly:\n";
	c1.Report();cout<<std::endl;
	c2.Report();cout<<std::endl;

	//использование указателя на объектвы cd
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	//вызов функции с аргументом-ссылкой  на cd
	cout<<"Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	//Тестирование присваивания
	cout<<"Testing assignments: ";
	Classic copy;
	copy = c2;
	copy.Report();
	return 0;
}
void Bravo(const Cd& disk)
{
	disk.Report();
	std::cout<<std::endl;

}



