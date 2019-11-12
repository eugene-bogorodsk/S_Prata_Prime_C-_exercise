/*
 * worker1.h
 *
 *  Created on: 28 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef WORKER1_H_
#define WORKER1_H_

#include <string>

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
#endif /* WORKER1_H_ */
