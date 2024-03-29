/*
 * bank2.cpp
 *
 *  Created on: 18 ����. 2019 �.
 *      Author: �������
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue2.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); //�������� �� ����� ������

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std:: ios_base;

	//����������
	std:: srand(std::time(0)); //��������� ������������� rand
	cout<<"Case study: Bank of  Heather Automatic Teller\n";
	cout<<"Enter maximum size of queue"; //���� ������������� ������� �������
	int qs;
	cin>>qs;
	Queue line1(qs); //1-� ������� ����� ��������� �� qs �����
	Queue line2(qs); //2-� �������
	cout<<"Enter the number of simulation hours: "; //���� ���������� ������������� �����
	int hours; //���� ��������
	cin >>hours;

	//�������� ����� ��������� ���� ���� � ������
	long cyclelimit = MIN_PER_HR*hours; //���������� ������
	cout<<"Enter the average number of customers per hour:";
	//����� ���������� �������� � ���
	double perhour; //������� ���������� ��������� � ���
	cin>>perhour;
	double min_per_cust; //������� ����� ����� �����������
	min_per_cust = MIN_PER_HR/perhour;
	Item temp; //������ ������ �������
	long turnaways = 0; //�� �������� � ������ �������
	long customers = 0; //������������ � �������
	long served = 0; //��������� �� ����� ��������

	long sum_line1 = 0; //����� ������� � ������� ���������
	long sum_line2 = 0; //����� ������� �� ������� ���������
	int wait_time1 = 0; //����� �� ������������  1 -�� ���������
	int wait_time2 = 0; //�����  ��� ������������ 2-�� ���������
	long line_wait = 0; //����� ����� � 1 -�  �������
	//long line_wait_2= 0; //����� ����� � 2- � �������
	//������ �������������
	for(int cycle = 0; cycle< cyclelimit; cycle++)
	{
		if(newcustomer(min_per_cust))	//���� ���������� ������
		{
			if(line1.isfull() && line2.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//cycle = ����� ��������
				if(sum_line1 <=sum_line2)
					line1.enqueue(temp); // ���������� ������� � �������
				else
					line2.enqueue(temp);
			}
		}
		if (wait_time1<=0 && !line1.isempty())
			{
				line1.dequeue(temp); //������������ ���������� �������
				wait_time1 = temp.ptime();// � ������� wait_time �����
				line_wait+= cycle-temp.when();
				served++;
			}
		if(wait_time1 > 0)
			wait_time1--;
		sum_line1+=line1.queuecount();

		if (wait_time2<=0 && !line2.isempty())
			{
				line2.dequeue(temp); //������������ ���������� �������
				wait_time2 = temp.ptime();// � ������� wait_time �����
				line_wait+= cycle-temp.when();
				served++;
			}

		if(wait_time2 > 0)
			wait_time2--;
		sum_line2+=line2.queuecount();
	}

	//����� �����������
	if(customers > 0)
	{
		cout<<"customers accepted: "<<customers <<endl; //������� ��������
		cout<<" customers served: "<<served <<endl; //��������� ��������
		cout<<" turnaways: "<<turnaways<<endl;//�� ������� ��������
		cout<<"average queue size: "; //������� ������ �������
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<(double)(sum_line1+sum_line2)/cyclelimit<<endl;
		cout<<" average wait_time: "//������� ����� �������� (���)
		    <<(double) line_wait/served <<" minutes\n";
	}
	else
		cout<<"No sutomers!\n"; //�������� ���
	cout<<"Done!\n";
	return 0;
}

//x ������� ����� � ������� ����� ���������
// ������������ �������� true, ����  � ��� ������ ���������� ������
bool newcustomer(double x)
{
	return std::rand()*x/RAND_MAX < 1;
}



