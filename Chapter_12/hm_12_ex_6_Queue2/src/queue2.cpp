//============================================================================
// Name        : queue2.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "queue2.h"
#include <cstdlib> //для rand()

//методы класса Queue
Queue::Queue(int qs):qsize(qs)
{
	front = rear = nullptr;//nullptr
	items = 0;
}
Queue::~Queue()
{
	Node* temp;
	while(front != nullptr) //пока очередь не пуста
	{
		temp = front;//сохранение адреса начального элемента
		front = front->next;//переустановка указателя на следующий элемент
		delete temp;//удаление предыдущего элемента
	}
}

bool Queue::isempty() const
{
	return items==0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue:: queuecount() const
{
	return items;
}

//добавление элемента в очередь
bool Queue::enqueue(const Item& item)
{
	if(isfull())
		return false;
	Node* add = new Node; //создание узла
	// при неудачном выполнении операции new генерируется исключени std::bad_alloc
	add->item = item; //занесение указателей на узлы
	add->next = nullptr;// или nullptr
	items++;
	if(front == nullptr) //если очередь пуста элемент помещается в начало
		front = add;
	else
		rear->next = add;//иначе он помещается в конец
	rear = add;
	return true;
}

//перемещение элемента front в переменную item и его удаление из очереди
bool Queue::dequeue(Item& item)
{
	if(front == nullptr)
		return false;
	item = front->item; //в item заносится первый элемент из очереди
	items--;
	Node* temp = front; //сохранение местоположения первого элемента
	front = front->next; //сдвиг указателя на следующий элемент
	delete temp;
	if(items == 0)
		rear = nullptr;
	return true;
}

//метод класса Customer
//при появлении клиента фиксируется момент его прибытия а время
//обслужинваия выбирается случайным образом из диапазона 1-3
void Customer::set(long when)
{
	processtime = std::rand() % 3 +1;
	arrive = when;
}
