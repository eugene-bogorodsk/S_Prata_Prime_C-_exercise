/*
 * port.h
 *
 *  Created on: 21 ����. 2019 �.
 *      Author: �������
 */

#ifndef PORT_H_
#define PORT_H_

#include <iostream>
using namespace std;
class Port
{
private:
	char* brand;
	char style[20];
	int bottles;
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& pl);
	virtual ~Port() {delete [] brand;}
	Port& operator = (const Port& );
	Port& operator +=(int b );//��������� b �  bottle
	Port& operator -=(int b );//��������� b �� bottle, ���� ��� ��������
	int BottleCount() const {return bottles;}
	virtual void Show() const;
	friend ostream& operator<<(ostream& , const Port& );
};

class VintagePort:public Port //style ����������� = vintage
{
private:
	char * nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* ,int , const char* ,int);
	VintagePort(const VintagePort& );
	virtual ~VintagePort(){delete [] nickname;}
	VintagePort& operator = (const VintagePort& );
	virtual void Show() const;
	friend ostream& operator<< (ostream& ,const VintagePort& );
};

#endif /* PORT_H_ */
