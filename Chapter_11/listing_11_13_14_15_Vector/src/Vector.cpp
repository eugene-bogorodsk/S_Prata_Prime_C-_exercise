
//============================================================================
// Name        : Vector.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cmath>
#include "vector.h"
using std::cout;

namespace VECTOR
{
	// вычисляеь количество градусов в одном радиане
	// примерно равно 57.295
const double Rad_to_dag = 45.0/atan(1.0);

	//закрытые методы, вычисляет модуль из x и y
void Vector::set_mag()
	{
		mag = sqrt(x*x+y*y);
	}
void Vector::set_ang()
{
	if(x==0.0 && y==0.0)
		ang = 0.0;
	else
		ang = atan2(y,x);
}
void Vector:: set_x() //устанавливает х по полярным координатам
{
	x= mag*cos(ang);
}
void Vector:: set_y()//устанавливает у по полярным координатам
{
	y = mag*sin(ang);
}

//открытые методы
Vector::Vector()
{ x=y=mag=ang= 0; mode = RECT;}

//конструирует вектор по прямоугольным координатам если form=RECT
//(по умолчанию) пли по полярным координатам если form=POL
Vector::Vector(double _x, double _y, Mode form)
{
	mode=form;
	if(form==RECT)
	{
		x=_x;y=_y;
		set_mag();set_ang();
	}
	else if (form==POL)
	{
		mag=_x;ang=_y;
		set_x();set_y();
	}
	else
	{
		//некорректный третий аргумент Vector(); вектор устанавливается в 0
		cout<<"Incorrect 3rd argument to Vector() --";
		cout<<"vector set to 0\n";
		x=y=mag=ang=0.0;
		mode=RECT;
	}
}

//устанавливает вектор по прямоуголным кооридинатам, если form  равно RECT
//(по умолчанию) или по полярным координатам если POL
void Vector:: reset(double _x,double _y, Mode form)
{
	mode=form;
	if(form==RECT)
	{
		x=_x;y=_y;
		set_mag();set_ang();
	}
	else if(form ==
			POL)
	{
		mag=_x;ang=_y;
		set_x();set_y();
	}
	else
	{
		cout<<"Incorrect 3rd argument to Vector()--";
		cout<<" vector set to 0\n";
		x=y=mag=ang=0.0;
		mode=RECT;
	}
}
Vector::~Vector(){}

void Vector:: polar_mode()
{
	mode=POL;
}
void Vector:: rect_mode()
{
	mode=RECT;
}

//перегрузка операций
Vector Vector::operator+(const Vector& b) const
{
	return Vector(x+b.x,y+b.y);
}
Vector Vector:: operator-(const Vector& b) const
{
	return Vector(x-b.x,y-b.y);
}
Vector Vector::operator-() const
{
	return Vector(-x,-y);
}
Vector Vector::operator*(double n) const
{
	return Vector(n*x,n*y);
}

Vector operator*(double n, const Vector& v)
{
	return v*n;
}
std::ostream& operator<<(std::ostream& os,const Vector& v)
{
	if(v.mode==Vector::RECT)
		os<<"(x,y) = ("<<v.x<<", "<<v.y<<")";
	else if(v.mode ==Vector::POL)
	{
		os<<"(m,a) = ("<<v.mag<<", "<<v.ang*Rad_to_dag<<")";
	}
	else
		os<<"Vector object mode is invalid";//недопустимый режим объекта Vector
	return os;
}

//оператор преобразования типа
Vector::operator double() const
{
	return mag;
}
}//end of namespace VECTOR


