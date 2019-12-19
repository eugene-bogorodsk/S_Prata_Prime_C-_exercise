/*
 * error4.h
 *homework 15.2
 *  Created on: 16 нояб. 2019 г.
 *      Author: Eugene
 */

#ifndef ERROR4_H_
#define ERROR4_H_

#include <iostream>
#include  <stdexcept>
#include <string>
class bad_hmean:public std::logic_error
{

public:
	explicit bad_hmean(
			const std::string& s="hmean() invalid arguments: a=-b.\n");
	virtual ~bad_hmean() throw() {}
};

bad_hmean::bad_hmean( const std::string& s):
		std::logic_error(s){}

class bad_gmean:public std::logic_error
{

public:
	explicit bad_gmean(
			const std::string& s="gmean() arguments should be >=0\n");
	virtual ~bad_gmean() throw(){}
};

bad_gmean::bad_gmean( const std::string& s):
	std::logic_error(s){}




#endif /* ERROR4_H_ */
