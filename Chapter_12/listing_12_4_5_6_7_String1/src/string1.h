/*
 * string1.h
 *
 *  Created on: 7 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char* str; //указатель на строку
	int len; //длина строки
	static int num_string; //количество объектов
	static const int CINLIM = 80; //предел ввода для cin
public:
	//конструкторы и другие методы
	String (const char* s); //конструктор
	String();// конструктор по умолчанию
	String(const String& );//конструктор копирования
	~String(); //деструктор
	int length() const { return len;}

	//методы перегруженных операций
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator [](int i);
	const char& operator [](int i) const;

	//дружественные функции перегруженных операций
	friend bool operator <( const String& st1,const String& st2);
	friend bool operator >(const String& st1,const String& st2);
	friend bool operator ==(const String& st1, const String& st2);
	friend ostream& operator <<(ostream& os,const String& st);
	friend istream& operator >>(istream& is, String& st);

	//статическая фукнция
	static int HowMany();
};




#endif /* STRING1_H_ */
