//============================================================================
// Name        : string1.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : ������ ������ String
//============================================================================

#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

//������������� ������������ ����� ������
int String::num_string =0;

//����������� �����
 int String::HowMany()
{
	return num_string;
}

 //������ ������
 String::String(const char* s) //�������� String �� C- ������
 {
	 len = std::strlen(s);//��������� �������
	 str = new char(len+1);//��������� ������
	 std::strcpy(str,s); //������������� ���������
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
	 len = st.len; //����� �� ��
	 str = new char[len +1];//��������� ������
	 std::strcpy(str,st.str); //���������� ������ � ����� �����
 }

 String::~String() //����������� ����������
 {
	 --num_string;
	 delete [] str;
 }

 //������ ������������� ��������
 //���������� ������� String ������� String
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

 //����������� �-������ ������� String
 String& String:: operator= (const char* s)
 {
	 delete [] str;
	 len = std::strlen(s);
	 str = new char[len+1];
	 std:: strcpy(str,s);
	 return * this;
 }

 //������ ��� ������ � ������ ��������� �������� � �������������� ������ String
 char& String:: operator [](int i)
 {
	 return str[i];
 }

 // ������ ������ ��� ������ ��������� �������� � ����������� ������� String
 const char& String::operator [](int i) const
 {
	 return str[i];
 }

 //������������� ������� ������������� ��������
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

 // ������� ����� String
 ostream& operator <<(ostream& os,const String& st)
 {
	 os<<st.str;
	 return os;
 }

 //������� ����� String
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
