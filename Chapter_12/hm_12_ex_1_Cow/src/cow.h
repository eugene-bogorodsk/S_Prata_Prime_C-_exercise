/*
 * cow.h
 *
 *  Created on: 15 ����. 2019 �.
 *      Author: �������
 */

#ifndef COW_H_
#define COW_H_

class Cow
{
	char name[20];
	char *hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm,const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator = (const Cow& c);
	void ShowCow() const; //����������� ������ Cow
};



#endif /* COW_H_ */
