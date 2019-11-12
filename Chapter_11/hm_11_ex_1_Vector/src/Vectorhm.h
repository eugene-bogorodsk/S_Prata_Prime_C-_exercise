/*
 * Vectorhm.h
 *
 *  Created on: 23 ����. 2019 �.
 *      Author: �������
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
		//RECT ��� ������������� ���������, POL ��� �������� ���������
	private:
		double x;
		double y;
//		double mag;//����� �������
//		double ang;//����������� � ��������
		Mode mode; //RECT ��� POL

		// �������� ����� ��� ��������� ��������
//		void set_mag();
//		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double , double, Mode form = RECT);
		void reset(double,double, Mode form = RECT);
		~Vector();
		double xval() const{return x;} //�������� �������� x
		double yval() const{return y;}//�������� �������� y
		double magval() const ;//�������� ������
		double angval() const;//�������� ����
		void polar_mode(); //������������� ����� � POL
		void rect_mode(); // ������������ � ����� RECT

		// ���������� ��������
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		operator double() const;

		//������
		friend Vector operator*(double n, const Vector& v);
		friend std::ostream& operator<<(std::ostream& os,const Vector& v);
	};

}// ����� ������������ VECTOR




#endif /* VECTORHM_H_ */
