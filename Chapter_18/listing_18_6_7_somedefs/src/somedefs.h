/*
 * somedefs.h
 *
 *  Created on: 16 дек. 2019 г.
 *      Author: Eugene
 */

#ifndef SOMEDEFS_H_
#define SOMEDEFS_H_

#include <iostream>

template <typename T,typename F>
T use_f(T t,F f)
{
	static int count=0;
	count++;
	std::cout<<" use_f count = "<<count
			<<", &count - "<<&count<<std::endl;
	return f(t);
}

class Fp
{
private:
	double z_;
public:
	Fp(double z=1.0):z_(z){}
	double operator()(double q){return z_+q;}
};
class Fq
{
private:
	double z_;
public:
	Fq(double z=1.0):z_(z){}
	double operator()(double q){return z_+q;}
};





#endif /* SOMEDEFS_H_ */
