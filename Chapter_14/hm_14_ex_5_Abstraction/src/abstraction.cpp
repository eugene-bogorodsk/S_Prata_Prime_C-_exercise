//============================================================================
// Name        : abstraction.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <string>
#include "abstaction.h"
using std::cout;
using std::endl;

abstr_emp:: ~abstr_emp(){}

abstr_emp::abstr_emp():fname("None"),lname("None"),job("None"){}

abstr_emp::abstr_emp(const std::string& fn,const std::string& ln,const std::string& j)
	:fname(fn),lname(ln),job(j){}

void abstr_emp:: ShowAll() const
{
	cout<<"First name:"<<fname<<endl;
	cout<<"Last name: "<<lname<<endl;
	cout<<"Job: "<<job<<endl;
}
void abstr_emp::SetAll()//запрашивает значения у пользователя
{
	cout<<"Enter first name: "<<endl;
	getline(std::cin,fname);
	cout<<"Enter last name: "<<endl;
	getline(std::cin,lname);
	cout<<"Enter job: "<<endl;
	getline(std::cin,job);

}
std::ostream& operator<<(std::ostream& os,const abstr_emp& e)
	//выводит тольок имя и фамилию
{
	os<<e.fname<<" "<<e.lname<<endl;
	return os;
}


employee::employee():abstr_emp(){}
employee::employee(const std::string& fn,const std::string& ln,const std::string& j)
	:abstr_emp(fn,ln,j){}
void employee:: ShowAll() const
{
	abstr_emp::ShowAll();
}
void employee:: SetAll()
{
	abstr_emp::SetAll();
}

manager::manager():abstr_emp(),inchargeof(0){}
manager::manager(const std::string& fn,const std::string& ln,const std::string& j,
		int ico): abstr_emp(fn,ln,j),inchargeof(ico){}
manager::manager(const abstr_emp& e,int ico)
	:abstr_emp(e),inchargeof(ico){}
manager::manager(const manager& m):abstr_emp(m)
{
	inchargeof=m.inchargeof;
}

void manager:: ShowAll() const
{
	abstr_emp::ShowAll();
	cout<<"The number of employees: "<<inchargeof<<endl;
}
void manager:: SetAll()
{
	abstr_emp::SetAll();
	cout<<"Enter the number of employees: "<<endl;
	std::cin>>inchargeof;
	while(std::cin.get()!='\n')
		continue;
}

fink::fink():abstr_emp(),reportsto("None"){}
fink::fink(const std::string& fn,const std::string& ln,const std::string& j,
		const std::string& rpo):abstr_emp(fn,ln,j),reportsto(rpo){}

fink::fink(const abstr_emp& e,const std::string& rpo):abstr_emp(e),reportsto(rpo){}
fink::fink(const fink& e):abstr_emp(e)
{
	reportsto=e.reportsto;
}
void fink:: ShowAll() const
{
	abstr_emp::ShowAll();
	cout<<"Report: "<<reportsto<<endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout<<"Enter report: ";
	std::cin>>reportsto;
}

highfink::highfink(){}

highfink::highfink(const std::string& fn,const std::string& ln,const std::string& j,
		const std::string& rpo,int ico)
		:abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo){}
highfink::highfink(const abstr_emp& e,const std::string& rpo,int ico)
		:abstr_emp(e),manager(e,ico),fink(e,rpo){}
highfink::highfink(const fink& f,int ico)
		:abstr_emp(f),manager(f,ico),fink(f){}
highfink::highfink(const manager& m,const std::string& rpo)
		:abstr_emp(m),manager(m),fink(m,rpo){}
highfink::highfink(const highfink& h):abstr_emp(h),manager(h),fink(h){}

void highfink:: ShowAll() const
{
	abstr_emp::ShowAll();
	cout<<"The number of employees: "<<manager::InChargeOf()<<endl;
	cout<<"Report: "<<fink::ReportsTo()<<endl;

}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout<<"Enter the number of employees: "<<endl;
	std::cin>>(*this).InChargeOf();
	cout<<"Enter report: ";
	std::cin>>(*this).ReportsTo();

}
