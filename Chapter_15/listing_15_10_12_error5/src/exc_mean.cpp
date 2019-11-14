/*exception classes for hmean() and gmean()exc_mean.h
 * exc_mean.cpp
 * listing 15.10
 *  Created on: 14 нояб. 2019 г.
 *      Author: Eugene
 */

#include <iostream>
class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a=0,double b=0):v1(a),v2(b){}
	void mesg();
};
inline void bad_hmean::mesg()
{
	std::cout<<"hmean("<<v1<<", "<<v2<<"): "
			<<"invalid arguments: a= -b\n"; //неверные аргументы
}
class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a=0,double b=0):v1(a),v2(b){}
	const char *mesg();
};
inline const char* bad_gmean::mesg()
{
	return "gmean() arguments should be >=0\n";
}





