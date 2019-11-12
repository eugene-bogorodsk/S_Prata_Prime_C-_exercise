/*
 * abstract.h
 *
 *  Created on: 21 ����. 2019 �.
 *      Author: �������
 */

#ifndef ABSTRACT_H_
#define ABSTRACT_H_

#include <iostream>

//����������� ������� �����
class absDMA
{
private:
	char* label;
	int rating;
protected:
	const char* Label() const {return label;}
	const int Rating() const {return rating;}
public:
	absDMA(const char* _label= "null",int r = 0);
	absDMA(const absDMA& );
	absDMA& operator=(const absDMA& );
	virtual ~absDMA(){delete [] label;}
	virtual void View() const= 0;
};
// �����  ��� ��������� �������� ������������ ������������ ��������� ������
class baseDMA:absDMA
{
public:
	baseDMA(const char* l ="null",int r= 0):absDMA(l,r){}
	baseDMA(const absDMA& _abs):absDMA(_abs){}
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA(){}
	baseDMA& operator=(const baseDMA& );
//	friend std::ostream& operator<<(std:: ostream& ,const baseDMA& );
	virtual void View() const;
};

//����������� ����� ��� ������������� ��������� ������, �������� ����
//���������� �� �����
class lacksDMA:public absDMA
{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank",const char* l="null",int r= 0);
	lacksDMA(const char*c,const absDMA& );
//	friend std::ostream& operator<<(std::ostream& os,const lacksDMA& rs);
	virtual void View() const;
};

//����������� ����� � ������������ ���������� ������
class hasDMA: public absDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null",int r= 0);
	hasDMA(const char* s, const absDMA& rs);
	hasDMA(const hasDMA& );
	~hasDMA(){delete [] style;}
	hasDMA& operator = (const hasDMA& );
	friend std::ostream& operator<<(std::ostream& os,const hasDMA& );
	virtual void View() const;
};




#endif /* ABSTRACT_H_ */
