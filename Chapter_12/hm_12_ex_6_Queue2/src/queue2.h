/*
 * queue2.h
 *
 *  Created on: 18 сент. 2019 г.
 *      Author: ≈вгений
 */

#ifndef QUEUE2_H_
#define QUEUE2_H_

//очередь содержаща€ элементы Customer
class Customer
{
private:
	long arrive; //момент по€влени€ клиента
	int processtime; //врем€ обслуживани€ клиента
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
	//определени€ области действи€ класса
	//Node - вложенна€ структура, локальна€ дл€ этого класса
	struct Node {Item item;struct Node* next;};
	enum {Q_SIZE = 10};

	// «акрытые члены класса
	Node* front; //указатель на начало очереди
	Node* rear; // указатель на конец очереди
	int items; // текущее количество элементов очереди
	const int qsize; //максимальное количество элементов в Queue

	//уперждающие объ€влени€  дл€ пердотварщени€ открытого копировани€
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







#endif /* QUEUE2_H_ */
