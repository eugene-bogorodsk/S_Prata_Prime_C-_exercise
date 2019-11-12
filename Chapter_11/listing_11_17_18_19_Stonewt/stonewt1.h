/*
 * stonewt1.h
 *
 *  Created on: 23 ����. 2019 �.
 *      Author: �������
 */

#ifndef STONEWT1_H_
#define STONEWT1_H_

class Stonewt
{
private:
	enum {Lbs_per_stn = 14};//������ �� �����
	int stone;//������ �������
	double pds_left;//������� ����� ������
	double pounds; //����� ��� � ������
public:
	Stonewt(double lbs); //����������� ��� �������� double ������
	Stonewt(int ,double); //����������� ��� �������� � ������� � ������
	Stonewt(); //����������� �� ���������
	~Stonewt();
	void show_lbs() const; //����������� ���� � ������� ������
	void show_stn() const; //����������� ���� � ������� �������
	//������� ��������������
	operator int() const;
	operator double() const;
	//������� ���� ��� ���������
	Stonewt operator* (double ) const;
	friend Stonewt operator*(double , const Stonewt& );
};


#endif /* STONEWT1_H_ */
