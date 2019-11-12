/* интерфейс для очереди
 * queue.h
 *
 *  Created on: 9 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef QUEUE_H_
#define QUEUE_H_

//очередь содержащая элементы Customer
class Customer
{
private:
	long arrive; //момент появления клиента
	int processtime; //время обслуживания клиента
public:
	Customer(){arrive = processtime = 0;}
	void set (long when);
	long when () const {return arrive;}
	int ptime() const {return processtime;}
};

typedef Customer Item;

class Queue
{
private:
	//определения области действия класса
	//Node - вложенная структура, локальная для этого класса
	struct Node {Item item;struct Node* next;};
	enum {Q_SIZE = 10};

	// Закрытые члены класса
	Node* front; //указатель на начало очереди
	Node* rear; // указатель на конец очереди
	int items; // текущее количество элементов очереди
	const int qsize; //максимальное количество элементов в Queue

	//уперждающие объявления  для пердотварщения открытого копирования
	Queue(const Queue& q):qsize(0){}
	Queue& operator = (const Queue& q){return *this;}
public:
	Queue(int qs = Q_SIZE); //создание очереди с предельным размером qs
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);//добавление элемента в конец
	bool dequeue(Item& item);//удаление элемента из начала
};





#endif /* QUEUE_H_ */
