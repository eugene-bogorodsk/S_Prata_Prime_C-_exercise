/*
 * Time.h
 *
 *  Created on: 25 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>

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
	friend Time operator+(const Time& lhs,const Time& rhs );
	friend Time operator-(const Time&,const Time&);
	friend Time operator*(const Time&, double n);
	friend Time operator*(double m,Time& t)
	{return t*m;}
	friend std::ostream& operator<<(std::ostream& os,const Time& t);
};



#endif /* TIME_H_ */
