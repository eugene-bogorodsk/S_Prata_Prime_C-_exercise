//============================================================================
// Name        : string_ex1.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstring>
#include <cctype>
#include "string2.h"
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
  String& String:: stringlow() const
  {
	 String temp[len];
	 for(int i =0;i<len;++i)
	  temp[i] =std::tolower(str[i]);
	 return temp;
  }

  //перевод в верхний регистр
  String& String:: stringup()
  {
	 String temp[len];
	 for(int i =0;i<len;++i)
	  temp[i] =std::toupper(str[i]);
	 return temp;
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

 String operator +(const String& lhs,const String& rhs)
 {
	 return std::strcat(lhs.str,rhs.str);
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
