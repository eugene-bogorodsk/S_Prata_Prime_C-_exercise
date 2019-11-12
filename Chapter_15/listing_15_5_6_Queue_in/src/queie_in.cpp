//============================================================================
// Name        : queie_in.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "queue.h"

int main() {
	using std::string;
	using std::cin;
	using std::cout;
	QueueTP<string> cs(5);
	string temp;
	while(!cs.isfull())
	{
		cout<<"Please enter your name. You will be "
				<<"served in the order of arrival.\n"
				<<"name: "; //ввод имени и фамилии
		getline(cin,temp);
		cs.enqueue(temp);
	}
	cout<<"The queue is full. Processing begins!\n";
		//очередь полна; начало обслуживания
	while(!cs.isempty())
	{
		cs.dequeue(temp);
		cout<<"Now processing "<<temp<<"...\n";
	}
	return 0;

}

