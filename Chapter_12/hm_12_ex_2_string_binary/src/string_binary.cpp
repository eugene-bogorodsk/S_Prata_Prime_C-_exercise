//============================================================================
// Name        : string_binary.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstring>
#include <cctype>
#include <iostream>
#include "string_binary.h"
//using namespace std;
using std::cin;
using std::cout;

//инициализация статического члена класса
int String::num_string =0;

//статический метод
 int String::HowMany()
{
	return num_string;
}

 //методы класса
 String::String(const char* s) //создание String из C- строки
 {
	 len = std::strlen(s);//установка размера
	 str = new char(len+1);//выделение памяти
	 std::strcpy(str,s); //инициализация указателя
	 num_string++;
 }

 String::String()
 {
	 len =4;
	 str = new char[1];
	 str[0] = '\0';
	 num_string++;
 }

 String::String(const String& st)
 {
	 num_string++;
	 len = st.len; //длина та же
	 str = new char[len +1];//выделение памяти
	 std::strcpy(str,st.str); //копироване строки в новое место
 }

 String::~String() //необходимый деструктор
 {
	 --num_string;
	 delete [] str;
 }


 // добравленные функции члены
 //перевод в нижний регистр
  String& String:: stringlow()
  {

 char* temp = new char[len];
 for(int i = 0 ; i<len; ++i)
	 temp[i]=std::tolower(str[i]);
 std::strcpy(str,temp);
 	 delete [] temp;
	 return *this;
  }

  //перевод в верхний регистр
  String& String:: stringup()
  {
	 char* temp = new char[len];

	for(int i = 0; i<len;++i)
		temp[i] = std::toupper(str[i]);

	 std::strcpy(str,temp);
	 delete [] temp;
	 return *this;
  }


 //методы перегруженных операций
 //присвоение объекта String объекту String
 String& String::operator=(const String& st)
 {
	 if(this ==&st)
		 return *this;
	 delete [] str;
	 len= st.len;
	 str = new char[len+1];
	 std::strcpy(str,st.str);
	 return *this;
 }

 //присовоение С-строки объекту String
 String& String:: operator= (const char* s)
 {

	 delete [] str;
	 len = std::strlen(s);
	 str = new char[len+1];
	 std:: strcpy(str,s);
	 return * this;
 }

 //доступ для чтения и записи отдельных символов в неконстанктный объект String
 char& String:: operator [](int i)
 {
	 return str[i];
 }

 // доступ только для чтения отдельных символов в константном объекте String
 const char& String::operator [](int i) const
 {
	 return str[i];
 }


 // поиск буквы в строке

 int String:: has(const char a)
 {
	  int count = 0;
	  const char *result = str;
	  while((result = std::strchr(result,a)) != NULL)
	  {
		  ++count; ++result;
	  }
	  return count;

 }

 //дружественные функции перегруженных операций
 bool operator<(const String& st1, const String& st2 )
 {
	 return (std::strcmp(st1.str,st2.str));
 }

 bool operator>(const String& st1,const String& st2)
 {
	 return st2.str<st1.str;
 }
 bool operator==(const String& st1,const String& st2)
 {
	 return (std::strcmp(st1.str,st2.str) == 0);
 }

  String& String:: operator + (const String& s )
 {
	  str= strcat(str,s.str);
	  len = strlen(str);
	  return *this;
 }

 String  operator + (const char* lhs, const String& rhs )

 {
	String new_str(lhs);
	 new_str.str = std::strcat(new_str.str,rhs.str);
	 new_str.len = std::strlen(new_str.str);
	 return new_str;
 }

 // простой вывод String
 ostream& operator <<(ostream& os,const String& st)
 {
	 os<<st.str;
	 return os;
 }

 //простой вывод String
 istream& operator>>(istream& is,String& st)
 {
	 char temp [String::CINLIM];
	 is.get(temp,String::CINLIM);
	 if(is)
		 st=temp;
	 while(is && is.get()!='\n')
		 continue;
	 return is;
 }

