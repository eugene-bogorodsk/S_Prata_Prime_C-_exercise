//============================================================================
// Name        : bank_queue.cpp
// Author      : 
// Version     :hw 16_6
// Copyright   : Your copyright notice
// Description : using queue container instead class Queue
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
const int MIN_PER_HR = 60;

class Customer
{
private:
	long arrive; //������ ��������� �������
	int processtime; //����� ������������ �������
public:
	Customer(){arrive = processtime = 0;}
	void set (long when);
	long when () const {return arrive;}
	int ptime() const {return processtime;}

};

typedef Customer Item;
bool newcustomer(double x); //is there new client
//void set(long when);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std:: ios_base;

	//preparation
	std:: srand(std::time(0)); //random initialization rand()
	cout<<"Case study: Bank of  Heather Automatic Teller\n";
	cout<<"Enter maximum size of queue";
	int qs;
	cin>>qs;
	std::queue<Item> line; //queue can include till qs people
	cout<<"Enter the number of simulation hours: ";
	int hours; //emulation clocks
	cin >>hours;

	//emulation runs one cycle per minute
	long cyclelimit = MIN_PER_HR*hours; //number of cycles
	cout<<"Enter the average number of customers per hour:";
	//enter the number of clients per hour
	double perhour; //average number of appearance per hour
	cin>>perhour;
	double min_per_cust; //the average time between the appearance
	min_per_cust = MIN_PER_HR/perhour;
	Item temp; //the data of the new client
	long turnaways = 0; //not admitted to the new queue
	long customers = 0; //attached to the queue
	long served = 0; //served during emulation

	long sum_line = 0; //the total length of the queue
	int wait_time = 0; //time until ATM is released
	long line_wait = 0; //total time in the queue
	//run the simulation
	for(int cycle = 0; cycle< cyclelimit; cycle++)
	{
		if(newcustomer(min_per_cust))	//approached customer
		{
			if(line.size()>(size_t)qs)
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//cycle = approached time
				line.push(temp); // adding a newbie to the queue
			}
		}
		if (wait_time<=0 && !line.empty())
			{
				line.pop(); //next customer service
				wait_time = temp.ptime();//during wait_time minutes
				line_wait+= cycle-temp.when();
				served++;
			}
		if(wait_time > 0)
			wait_time--;
		sum_line+=line.size();
	}

	//output results
	if(customers > 0)
	{
		cout<<"customers accepted: "<<customers <<endl; //accepted customers
		cout<<" customers served: "<<served <<endl; //served clients
		cout<<" turnaways: "<<turnaways<<endl;//not accepted customers
		cout<<"average queue size: "; //average queue size
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<(double)sum_line/cyclelimit<<endl;
		cout<<" average wait_time: "//average waiting time (minutes)
		    <<(double) line_wait/served <<" minutes\n";
	}
	else
		cout<<"No customers!\n"; //not clients
	cout<<"Done!\n";
	return 0;
}

//x average time between clients in minutes
// return true, if at this moment the client appears
bool newcustomer(double x)
{
	return std::rand()*x/RAND_MAX < 1;
}
void Customer::set (long when)
{
	processtime = std::rand() % 3 +1;
	arrive = when;
}
