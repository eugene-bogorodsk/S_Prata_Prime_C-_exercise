/* решение задачи случайного блуждания
 * randwalk.cpp
 *
 *  Created on: 23 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0)); //начальное значение для генератора случайных чисел
	double direction;
	Vector step;
	Vector result(0.0,0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout<<"Enter targer distance (q to quite): ";
	//ввод заданного расстояния (q для завершения)
	while(cin>>target)
	{
		cout<<"Enter step length: ";//ввод длины шага
		if(!(cin>>dstep))
			break;
		while(result.magval()<target)
		{
			direction = rand()%360;
			step.reset(dstep,direction,Vector::POL);
			result = result+step;
			steps++;
		}
		cout<<"After "<<steps<<" steps, the subject "
				"has the following location:\n";
		cout<<result<<endl;//вывод позиции после steps шагов
		result.polar_mode();
		cout<<" or\n"<<result<<endl;
		cout<<"Average outward distance per steps"<<endl;//вывод среднего расстояния на один шаг
		steps = 0;
		result.reset(0.0,0.0);
		cout<<"Enter target distance (q to quit): ";
		//ввод заданного расстояния ( q для завершения)
	}
	cout<<"Bye!\n";
	cin.clear();
	while(cin.get() != '\n')
		continue;
}//end of main


