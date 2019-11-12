/*
 * worker0.h
 *
 *  Created on: 27 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker //абстрактный класс
{
private:
	std::string fullname;
	long id;
public:
	Worker(): fullname("no one"),id(0L){}
	Worker(const std::string& s,long n):
		fullname(s),id(n){}
	virtual ~Worker() = 0; //чистый виртуальный деструктор
	virtual void Set();
	virtual void Show() const;
};

class Waiter:public Worker
{
private:
	int panache;
public:
	Waiter():Worker(),panache(0){}
	Waiter(const std::string& s,long n, int p=0):
		Worker(s,n),panache(){}
	Waiter(const Worker& wk,int p=0):
		Worker(wk),panache(p){}
	void Set();
	void Show() const;
};

class Singer:public Worker
{
protected:
	enum {other,alto,contralto,soprano,bass,batitone,tenor};
	enum {Vtypes=7};
private:
	static const char* pv[Vtypes]; //строковые эквиваленты видов голоса
	int voice;
public:
	Singer():Worker(),voice(other){}
	Singer(const std::string& s,long n,int v = other):
		Worker(s,n),voice(v){}
	Singer(const Worker& wk,int v = other):
		Worker(wk),voice(v){}
	void Set();
	void Show() const;
};


#endif /* WORKER0_H_ */
