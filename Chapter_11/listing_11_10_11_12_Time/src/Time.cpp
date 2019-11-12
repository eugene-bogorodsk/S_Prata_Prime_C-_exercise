//============================================================================
// Name        : Time.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Time.h"

Time::Time():hours(0),minutes(0){}
Time::Time(int h,int m):hours(h),minutes(m){}
void Time:: AddMin(int m)
{
	minutes+=m;
	hours+=minutes/60;
	minutes %= 60;
}
void Time:: AddHour(int h){hours+=h;}

void Time::Reset(int h,int m)
{
	hours= h; minutes= m;
}
Time operator+(const Time& lhs,const Time& rhs)
{
	Time sum;
	sum.minutes= lhs.minutes+rhs.minutes;
	sum.hours = lhs.hours +rhs.hours + sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}
Time operator-(const Time& lhs,const Time& rhs)
{
	Time diff;
	int tot1,tot2;
	tot1 = rhs.minutes + 60 + rhs.hours;
	tot2 = lhs.minutes + 60 + lhs.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) /60;
	return diff;
}
Time  operator*(const Time& t, double n)
{
	Time result;
	long totalminutes = t.hours*n*60 +t.minutes*n;
	result.hours = totalminutes /60;
	result.minutes = totalminutes % 60;
	return result;
}

 std::ostream& operator<<(std::ostream& os,const Time& t)
 {
	 os<<t.hours<<" hours, "<<t.minutes<<" minutes";
	 return os;
 }

