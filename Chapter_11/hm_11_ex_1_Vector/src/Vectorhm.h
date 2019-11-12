/*
 * Vectorhm.h
 *
 *  Created on: 23 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef VECTORHM_H_
#define VECTORHM_H_

#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode{RECT,POL};
		//RECT для прямоугольных координат, POL для полярных координат
	private:
		double x;
		double y;
//		double mag;//длина вектора
//		double ang;//направление в крадусах
		Mode mode; //RECT или POL

		// закрытый метод для установки значений
//		void set_mag();
//		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double , double, Mode form = RECT);
		void reset(double,double, Mode form = RECT);
		~Vector();
		double xval() const{return x;} //сообщает значение x
		double yval() const{return y;}//сообщает значение y
		double magval() const ;//сообщает модуль
		double angval() const;//сообщает угол
		void polar_mode(); //устанавливает режим в POL
		void rect_mode(); // устанвливает а режим RECT

		// перегрузка операций
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		operator double() const;

		//друзья
		friend Vector operator*(double n, const Vector& v);
		friend std::ostream& operator<<(std::ostream& os,const Vector& v);
	};

}// конец пространства VECTOR




#endif /* VECTORHM_H_ */
