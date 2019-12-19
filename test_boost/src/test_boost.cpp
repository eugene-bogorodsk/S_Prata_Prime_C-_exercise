//============================================================================
// Name        : test_boost.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

//#include <boost/lexical_cast.hpp>

int main() {
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;
	std::for_each(
		in(std::cin),in(),std::cout<<(_1*3)<<" ");

	return 0;
}
