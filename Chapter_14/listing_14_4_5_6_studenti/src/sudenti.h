/*
 * sudenti.h
 *
 *  Created on: 27 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef SUDENTI_H_
#define SUDENTI_H_

#include<iostream>
#include<valarray>
#include<string>

class Student: private std::string,private std::valarray<double>
{
private:
	typedef std::valarray<double> arrayDB;
	//метод для вывода оценок
	std::ostream& arr_out(std::ostream& os )const;
public:
	Student():	std::string("Null Student"),arrayDB(){}
	explicit Student(int n): std::string("Nully"),arrayDB(n){}
	explicit Student(const std::string& s,int n)
		:std::string(s),arrayDB(n){}
	Student(const std::string& s,const arrayDB& a)
		:std::string(s),arrayDB(a){}
	Student(const char* str,const double *pd,int n)
		:std::string(str),arrayDB(pd,n){}
	~Student(){}

	double Average() const;
	double & operator[](int i);
	double operator[](int i)const;
	const std::string& Name() const;

	//ввод
	friend std::istream& operator>>(std::istream& is, Student& st);
	friend std::istream& getline(std::istream& is, Student& st);
	friend std::ostream& operator<<(std::ostream& os,const Student& st);
};


#endif /* SUDENTI_H_ */
