/*
 * classic2.h
 *
 *  Created on: 20 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef CLASSIC2_H_
#define CLASSIC2_H_

class Cd
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd(const char* ,const char* ,int ,double );
	Cd(Cd& );
	Cd();
	virtual ~Cd();
	virtual void Report()const; //выводит данные о компакт диске
	virtual Cd& operator=(const Cd& );
};

class Classic:public Cd
{
private:
	char* mainsong;
public:
	Classic(const char* ,const char* ,const char* ,int ,double);
	Classic(const char*, Cd& );
	Classic(const Classic& );
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	virtual Classic& operator = (const Classic& );
};





#endif /* CLASSIC2_H_ */
