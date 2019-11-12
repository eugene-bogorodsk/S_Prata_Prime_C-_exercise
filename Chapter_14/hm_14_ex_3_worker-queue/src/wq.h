/*
 * wq.h
 *
 *  Created on: 4 окт. 2019 г.
 *      Author: Евгений
 */

#ifndef WQ_H_
#define WQ_H_
#include <string>

using std::string;

template <typename Item>
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

class Worker
{
	std::string fullname;
	long id;
protected:
	virtual void  Data() const;
	virtual void Get();
public:
	Worker():fullname("no one"),id(0){}
	Worker(const std:: string & s,long n)
		:fullname(s),id(n){}
	virtual ~Worker() = 0; //чистая виртуальная функция
	virtual void Set() = 0;
	virtual void Show() const =0;
};

class Waiter:virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter():Worker(),panache(0){}
	Waiter(const std::string & s,long n,int p=0)
		:Worker(s,n),panache(p){}
	Waiter(const Worker& wk, int p)
		:Worker(wk),panache(p){}
	void Set();
	void Show() const;
};

class Singer:virtual public Worker
{
protected:
	enum {other,alto,contralto,soprano,bass,batitone,tenor};
	enum {Vtypes = 7};
	void Data() const;
	void Get();
private:
	static const char* pv[Vtypes];
	int voice;
public:
	Singer():Worker(),voice(other){}
	Singer(const std::string & s,long n,int v=other)
		:Worker(s,n),voice(v){}
	Singer(const Worker& wk,int v = other)
		:Worker(wk),voice(v){}
	void Set();
	void Show() const;

};

//множественное наследование
class Singwaiter:public Singer,public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	Singwaiter(){}
	Singwaiter(const std::string& s,long n, int p=0, int v = other)
		:Worker(s,n),Waiter(s,n,p),Singer(s,n,v){}
	Singwaiter(const Worker & wk,int p = 0, int v= other)
		:Worker(wk),Waiter(wk,p),Singer(wk,v){}
	Singwaiter(const Waiter& wt,int v=other)
		:Worker(wt),Waiter(wt),Singer(wt,v){}
	Singwaiter( const Singer& sn,int p=0)
		:Worker(sn),Waiter(sn,p),Singer(sn){}
	void Set();
	void Show() const;
};

#endif /* WQ_H_ */
