/*
 * classic.h
 *
 *  Created on: 20 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd
{
private:
	char performers[50];
	char label[20];
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
	char mainsong [50];
public:
	Classic(const char* ,const char* ,const char* ,int ,double);
	Classic(const char*, Cd& );
	Classic(const Classic& );
	Classic();
	virtual ~Classic();
	virtual void Report() const;
//	virtual Classic& operator = (const Classic& );
};



#endif /* CLASSIC_H_ */
