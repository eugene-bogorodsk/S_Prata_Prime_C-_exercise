/*
 * queue.h
 *
 *  Created on: 13 окт. 2019 г.
 *      Author: Евгений
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template <class Item>
class QueueTP
{
	enum {Q_SIZE=10};
	//Node - определение вложенного класса
	class Node
	{
	public:
		Item item;
		Node* next;
		Node(const Item& i):item(i),next(0){}
	};
	Node* front;
	Node* rear;
	int items;//текущее количество элементов в очереди
	const int qsize; //максимальное количество элементов в очереди
	QueueTP(const QueueTP & q):qsize(0){}
	QueueTP& operator=(const QueueTP& q) {return *this;}
public:
	QueueTP(int qs=Q_SIZE);
	~QueueTP();
	bool isempty() const { return items==0;}
	bool isfull() const {return items == qsize;}
	int queuecount() const {return items;}
	bool enqueue (const Item& item); //добавляем Item в конец
	bool dequeue(Item& item);//удаление item из начала
};

//Queue methods
template <class Item>
QueueTP<Item>::QueueTP(int qs):qsize(qs)
{
	front = rear= 0;
	items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
	Node* temp;
	while(front != 0) //пока очередь не пуста
	{
		temp=front; // сохранение адреса первого элемента
		front = front->next;// сдвиг указателя на следующий элемент
		delete temp;//удаление предыдущего элемента
	}
}
//добавление элемента в очередь
template <class Item>
bool QueueTP<Item>::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add=new Node(item); //создание узла
	//в случае сбоя операция new генерирует исключение std::bad_alloc
	items++;
	if(front == 0) //если очередь пуста
		front = add;  //элемент доавляется в начало
	else
		rear->next = add; //иначе добавляем в указатель некст последнего элемента адрес вновь созданного
	rear = add; //новый узел назначается последним элементом
	return true;
}
//помещение последнего элемента в переменную item и удаление его из очереди
template <class Item>
bool QueueTP<Item>::dequeue(Item& item)
{
	if(front ==0)
		return false;
	item = front->item; //item - первый элемент в очереди
	items--;
	Node* temp = front; //сохранение местоположения первого элемента
	front= front->next;// слудующий элемента становится первым
	delete temp;		//удаление пердыдущего первого элемента
	if (items ==0)
		rear=0;
	return true;

}

#endif /* QUEUE_H_ */
