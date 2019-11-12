/*
 * cow.h
 *
 *  Created on: 15 сент. 2019 г.
 *      Author: Евгений
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
	void ShowCow() const; //отображение данный Cow
};



#endif /* COW_H_ */
