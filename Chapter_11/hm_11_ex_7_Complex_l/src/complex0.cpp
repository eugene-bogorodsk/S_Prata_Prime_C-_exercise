//============================================================================
// Name        : complex0.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "complex0.h"
#include <iostream>




complex::complex(double r, double im)
{
	real = r; image = im;
}

complex::complex()
{
	real=image=0.0;
}

complex complex:: operator+(const complex& cm ) const
{
	return complex(real+cm.real,image+cm.image);
}

complex complex:: operator-(const complex& cm) const
{
	return complex(real-cm.real,image-cm.image);
}

complex complex:: operator* (const complex& cm) const
{
	return complex((real*cm.real-image*cm.image),(real*cm.image-image*cm.real));
}
complex complex:: operator*( double m )const
{
	return complex (real*m,image*m);
}

complex complex:: operator ~() const
{
	return complex(real,-image);
}

complex operator*(double m,const complex& cm)
{
	return cm*m;
}
std::istream& operator>>(std::istream& is, complex& cp)
{
	std::cout<<"real: ";
	is>>cp.real;
	if (!std::cin.fail()){
	std::cout<<"image: ";
	is>>cp.image;
	}
//	std::cin.clear();
//	while(std::cin.get() != '\n')
//		continue;
	return is;
}
 std::ostream& operator<<(std::ostream& os,const complex& cp )
 {
	 os<<"("<<cp.real<<","<<cp.image<<"i)"<<std::endl;
	 return os;
 }

