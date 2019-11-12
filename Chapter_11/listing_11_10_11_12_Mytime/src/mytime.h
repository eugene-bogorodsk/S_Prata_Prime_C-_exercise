/*
 * mytime.h
 *
 *  Created on: 22 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef MYTIME_H_
#define MYTIME_H_
#include<iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int ,int);
	void AddMin(int);
	void AddHour(int);
	void Reset(int h=0,int m=0);
	Time operator+(const Time& ) const;
	Time operator-(const Time&) const;
	Time operator*(double n) const;
	friend Time operator*(double m,Time& t)
	{return t*m;}
	friend std::ostream& operator<<(std::ostream& os,const Time& t);
};

#endif /* MYTIME_H_ */
