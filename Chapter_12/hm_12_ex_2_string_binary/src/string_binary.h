/*
 * string_binary.h
 *
 *  Created on: 16 ����. 2019 �.
 *      Author: �������
 */


#ifndef STRING_BINARY_H_
#define STRING_BINARY_H_
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char* str; //��������� �� ������
	int len; //����� ������
	static int num_string; //���������� ��������
	static const int CINLIM = 80; //������ ����� ��� cin
public:
	//������������ � ������ ������
	String (const char* s); //�����������
	String();// ����������� �� ���������
	String(const String& );//����������� �����������
	~String(); //����������
	int length() const { return len;}

	//����������� ������� �����
	String& stringlow();//��������� ��� ��������� ������� � ������ � ������ �������
	String& stringup(); //��������� ��� ��������� ������� � ������� �������
	int has(const char a);//���������� ���������� ���, ������� ������ ������� � ������

	//������ ������������� ��������
	String& operator=(const String&);
	String& operator=(const char*);
	String& operator + (const String& );
	char& operator [](int i);
	const char& operator [](int i) const;

	//������������� ������� ������������� ��������
	friend bool operator <( const String& st1,const String& st2);
	friend bool operator >(const String& st1,const String& st2);
	friend bool operator ==(const String& st1, const String& st2);
	friend ostream& operator <<(ostream& os,const String& st);
	friend istream& operator >>(istream& is, String& st);
	friend String operator +( const char * lhs,const String& s) ;
	//����������� �������
	static int HowMany();
};





#endif /* STRING_BINARY_H_ */
