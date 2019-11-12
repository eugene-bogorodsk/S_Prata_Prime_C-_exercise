/*
 * support.cpp
 *
 *  Created on: 4 сент. 2019 г.
 *      Author: ≈вгений
 */

#include <iostream>
extern double warming; //использование переменной warming из другого файла
// прототипы функций
void update(double dt);
void local();

using namespace std;
void update(double dt) //модфицирует глобальную переменную
{
	extern double warming; //необ€зательное повторное объ€вление
	warming+=dt;
	cout<<"Updating global warming to "<<warming;
	cout<<" degrees.\n";
}

void local() //использует локальную переменную
{
	double warming = 0.8; //нова€ переменна€ св€зывае внешнюю
	cout<<"Local warming = "<<warming<<" degrees.\n";
	//доступ к глобальной переменной с помощью операции разрешени€ контекста
	cout<<"But dlobal warming = "<<::warming;
	cout<<" degrees.\n";
}


