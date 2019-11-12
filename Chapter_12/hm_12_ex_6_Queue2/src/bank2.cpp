/*
 * bank2.cpp
 *
 *  Created on: 18 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue2.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); //появился ли новый клиент

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std:: ios_base;

	//подготовка
	std:: srand(std::time(0)); //случайная инициализация rand
	cout<<"Case study: Bank of  Heather Automatic Teller\n";
	cout<<"Enter maximum size of queue"; //ввод максимального размера очереди
	int qs;
	cin>>qs;
	Queue line1(qs); //1-я очередь может содержать до qs людей
	Queue line2(qs); //2-я очередь
	cout<<"Enter the number of simulation hours: "; //ввод количества эмулированных часов
	int hours; //часы эмуляции
	cin >>hours;

	//Эмуляция будет выпускать один цикл в минуту
	long cyclelimit = MIN_PER_HR*hours; //количество циклов
	cout<<"Enter the average number of customers per hour:";
	//вывод количества клиентов в час
	double perhour; //среднее количество появлений в час
	cin>>perhour;
	double min_per_cust; //среднее время между появлениями
	min_per_cust = MIN_PER_HR/perhour;
	Item temp; //данные нового клиента
	long turnaways = 0; //не допущены в полную очередь
	long customers = 0; //присоеденины к очереди
	long served = 0; //обслужены во время эмуляции

	long sum_line1 = 0; //длина очереди к первому банкомату
	long sum_line2 = 0; //длина очереди ко второму банкомату
	int wait_time1 = 0; //время до освобождения  1 -го банкомата
	int wait_time2 = 0; //время  доя освобождения 2-го банкомата
	long line_wait = 0; //общее время в 1 -й  очереди
	//long line_wait_2= 0; //общее время в 2- й очереди
	//запуск моделирования
	for(int cycle = 0; cycle< cyclelimit; cycle++)
	{
		if(newcustomer(min_per_cust))	//есть подходящий клиент
		{
			if(line1.isfull() && line2.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//cycle = время прибытия
				if(sum_line1 <=sum_line2)
					line1.enqueue(temp); // добавление новичка в очередь
				else
					line2.enqueue(temp);
			}
		}
		if (wait_time1<=0 && !line1.isempty())
			{
				line1.dequeue(temp); //обслуживание следующего клиента
				wait_time1 = temp.ptime();// в течение wait_time минут
				line_wait+= cycle-temp.when();
				served++;
			}
		if(wait_time1 > 0)
			wait_time1--;
		sum_line1+=line1.queuecount();

		if (wait_time2<=0 && !line2.isempty())
			{
				line2.dequeue(temp); //обслуживание следующего клиента
				wait_time2 = temp.ptime();// в течение wait_time минут
				line_wait+= cycle-temp.when();
				served++;
			}

		if(wait_time2 > 0)
			wait_time2--;
		sum_line2+=line2.queuecount();
	}

	//вывод результатов
	if(customers > 0)
	{
		cout<<"customers accepted: "<<customers <<endl; //принято клиентов
		cout<<" customers served: "<<served <<endl; //обслужено клиентов
		cout<<" turnaways: "<<turnaways<<endl;//не принято клиентов
		cout<<"average queue size: "; //средний размер очереди
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<(double)(sum_line1+sum_line2)/cyclelimit<<endl;
		cout<<" average wait_time: "//среднее время ожидания (мин)
		    <<(double) line_wait/served <<" minutes\n";
	}
	else
		cout<<"No sutomers!\n"; //клиентов нет
	cout<<"Done!\n";
	return 0;
}

//x среднее время в минутах между клиентами
// возвращается значение true, если  в эту минуту появляется клиент
bool newcustomer(double x)
{
	return std::rand()*x/RAND_MAX < 1;
}



