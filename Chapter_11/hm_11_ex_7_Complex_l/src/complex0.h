/*
 * complex0.h
 *
 *  Created on: 26 ����. 2019 �.
 *      Author: �������
 */

#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>


class complex
{
private:
	double real;
	double image;
public:
	complex(double r, double im);
	complex();
	~complex(){}
	complex operator+(const complex& ) const;
	complex operator-(const complex& ) const;
	complex operator* (const complex&) const;
	complex operator*( double )const;
	complex operator ~() const;
	friend complex operator*(double ,const complex& );
	friend std::istream& operator>>(std::istream& , complex&);
	friend std::ostream& operator<<(std::ostream& ,const complex& );
};



#endif /* COMPLEX0_H_ */
