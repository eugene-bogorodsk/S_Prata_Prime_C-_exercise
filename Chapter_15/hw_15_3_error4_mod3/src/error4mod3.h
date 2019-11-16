/*
 * error4.h
 *
 *  Created on: 16 нояб. 2019 г.
 *      Author: Eugene
 */

#ifndef ERROR4MOD3_H_
#define ERROR4MOD3_H_

#include <iostream>
#include  <stdexcept>
#include <string>

class bad_hmean:public std::logic_error

{
private:
	double v1;
	double v2;
public:
	explicit bad_hmean(double v1,double v2,
			const std::string& s="hmean() invalid arguments: a=-b.\n");
	double b_v1() const {return v1;}
	double b_v2() const {return v2;}
	virtual ~bad_hmean() throw() {}

};

bad_hmean::bad_hmean(double _v1, double _v2, const std::string& s):
		std::logic_error(s),v1(_v1),v2(_v2){}

class bad_gmean:public std::logic_error
{
private:
	double v1;
	double v2;
public:
	explicit bad_gmean(double v1,double v2,
			const std::string& s="gmean() arguments should be >=0\n");
	double bi_v1() const {return v1;}
	double bi_v2() const {return v2;}
	virtual ~bad_gmean() throw(){}
};

bad_gmean::bad_gmean(double _v1,double _v2,const std::string& s):
	std::logic_error(s),v1(_v1),v2(_v2){}


#endif /* ERROR4MOD3_H_ */
