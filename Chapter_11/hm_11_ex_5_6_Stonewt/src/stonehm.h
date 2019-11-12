/*
 * stonehm.h
 *
 *  Created on: 25 ����. 2019 �.
 *      Author: �������
 */

#ifndef STONEHM_H_
#define STONEHM_H_

class Stonewt
{
public:
	enum Mode {STONE,INT_POUNDS,FLOAT_POUNDS};//��������� ��������� ����������� ������
private:
	enum {Lbs_per_stn = 14};//������ �� �����
	int stone;//������ �������
	double pds_left;//������� ����� ������
	double pounds; //����� ��� � ������
	Mode mode;
public:
	Stonewt(double lbs,Mode m = FLOAT_POUNDS); //����������� ��� �������� double ������
	Stonewt(int lbs,Mode m = INT_POUNDS); //����������� ��� �������� double ������
	Stonewt(int st,double lbs,Mode m = STONE); //����������� ��� �������  � �������
	Stonewt(); //����������� �� ���������
	~Stonewt();
	//void show_lbs() const; //����������� ���� � ������� ������
	//void show_stn() const; //����������� ���� � ������� �������
	//������� ��������������
	operator int() const;
	operator double() const;
	//���������� ���������� ��������
	Stonewt operator +(const Stonewt&) const;
	Stonewt operator-(const Stonewt&) const;
	Stonewt operator*(const Stonewt&) const;
	Stonewt operator* (double ) const;
	Stonewt change_mode(Mode m);
	friend std::ostream& operator<<(std::ostream& , const Stonewt& );
	friend Stonewt operator*(double , const Stonewt& );
	friend bool operator ==(const Stonewt&,const Stonewt&);
	friend bool operator !=(const Stonewt&,const Stonewt&);
	friend bool operator <(const Stonewt&,const Stonewt&);
	friend bool operator <=(const Stonewt&,const Stonewt&);
	friend bool operator >(const Stonewt&,const Stonewt&);
	friend bool operator >=(const Stonewt&,const Stonewt&);
};





#endif /* STONEHM_H_ */
