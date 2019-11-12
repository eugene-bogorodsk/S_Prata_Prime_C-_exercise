//============================================================================
// Name        : strquote.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string version1(const string& s1,const string& s2);
const string& version2(string&s1,const string&s2);//имеет побочный эффект
const string& version3(string& s1,const string& s2);//неудачное решение

int main() {
	string input;
	string copy;
	string result;
	cout<<"Enter a string: ";
	getline(cin,input);//enter of string
	copy =input;
	cout<<"Your string as entered: "<<input<<endl;//отображение выведенной строки
	result=version1(input,"***");
	cout<<"Your string enhanced: "<<result<<endl;//вывод расширенной строки
	cout<<"Your original string: "<<input<<endl;//вывод исходной строки
	result= version2(input,"###");
	cout<<"Your string enhanced: "<<result<<endl;//вывод расширенной строки
	cout<<"Your original string: "<<input<<endl;//вывод исходной строки
	cout<<"Resetting original string.\n";//восстановление исходной строки
	input=copy;
	result=version3(input,"@@@");
	cout<<"Your string enhanced: "<<result<<endl;//вывод раширенной строки
	cout<<"Your original string: "<<input<<endl;//вывод исходной строки

	return 0;
}

string version1(const string& s1,const string& s2)
{
	string temp;
	temp=s2+s1+s2;
	return temp;
}

const string& version2(string& s1,const string& s2)//имеет побочный эффект
{
	s1=s2+s1+s1; //возврат ссылки,переданной функции, безопасен
	return s1;
}

const string& version3(string& s1,const string& s2)//неудачное решение
{
	string temp;
	temp=s2+s1+s2;//возврт ссылки на локальную переменную небезопасен
	return temp;
}
