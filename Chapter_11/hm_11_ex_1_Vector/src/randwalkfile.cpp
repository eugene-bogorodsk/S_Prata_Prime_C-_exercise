/*
 * randwalkfile.cpp
 *
 *  Created on: 23 сент. 2019 г.
 *      Author: Евгений
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Vectorhm.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	ofstream fout;//объявление объекта ofstream для вывода в файл
	fout.open("thewalk.txt");//объект ofstream связывается с файлом
	srand(time(0)); //начальное значение для генератора случайных чисел
	double direction;
	Vector step;
	Vector result(0.0,0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int number_of_tries;
	unsigned long min_steps = 100000;
	unsigned long max_steps = 0;
	unsigned long aver_steps = 0;
	cout<<"Enter targer distance (q to quite): ";
	//ввод заданного расстояния (q для завершения)
	while(cin>>target)
	{
		cout<<"Enter step length: ";//ввод длины шага
		if(!(cin>>dstep))
				break;
		cout<<"Enter a number of tries: ";//ввод количества попыток

		if(!(cin>>number_of_tries))
			break;
	for(int i = 0;i< number_of_tries;++i)
	{
		while(result.magval()<target)
		{
			direction = rand()%360;
			step.reset(dstep,direction,Vector::POL);
			result = result+step;
			fout<<steps<<": "<<result<<endl;
			steps++;
		}
		if (steps<min_steps) min_steps= steps;
		if (steps >max_steps) max_steps = steps;
		aver_steps+=steps;
		steps = 0;
		result.reset(0.0,0.0);

	}

	cout<<"After " <<number_of_tries<<" number of tries.\n";
	cout<<"The min number of steps in the tries: "<<min_steps<<endl;
	cout<<"The max number of steps in the tries: "<<max_steps<<endl;
	cout<<"The average number of steps int the tries: "<<aver_steps/number_of_tries<<endl;

	fout<<"Target distance: "<<target<<", "<<"Step Size: "<<steps
			<<endl;
		fout<<"After "<<steps<<" steps, the subject "
				"has the following location:\n";
		fout<<result<<endl;//вывод позиции после steps шагов
		result.polar_mode();
		fout<<" or\n"<<result<<endl;
		fout<<"Average outward distance per steps = "//вывод среднего расстояния на один шаг
		<<result.magval()/steps<<endl;
		//steps = 0;
		//result.reset(0.0,0.0);
		cout<<"Enter target distance (q to quit): ";
		//ввод заданного расстояния ( q для завершения)
	}
	cout<<"Bye!\n";
	cin.clear();
	while(cin.get() != '\n')
		continue;
}//end of main


