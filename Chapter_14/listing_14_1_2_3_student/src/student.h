/*
 * student.h
 *
 *  Created on: 27 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
	typedef std::valarray<double> arrayDb;
	std::string name; //включенный объект
	arrayDb scores; // включенный объект
	//закрытый метод для вывода оценок
	std:: ostream& arr_out(std::ostream& os) const;
public:
	Student():name("Null Student"),scores(){}
	explicit Student(const std::string& s):
			name(s),scores(){}
	explicit Student(int n): name("Nully"), scores(n){}
	Student(const std::string& s,int n):
		name(s),scores(n){}
	Student(const std::string& s,const arrayDb& a):
		name(s),scores(a){}
	Student(const char* str,const double *pd,int n):
		name(str),scores(pd,n){}
	~Student(){}
	double Average() const;
	const std::string& Name() const;
	double& operator[](int i);
	double operator[](int i) const;

	//ввод и вывод
	friend std::istream& operator>>(std::istream& is,
			Student& stu); //1 word
	friend std::istream& getline(std::istream& is,
			Student& stu);//1 string
	friend std::ostream& operator<<(std::ostream& os,
			const Student& stu);
};




#endif /* STUDENT_H_ */
