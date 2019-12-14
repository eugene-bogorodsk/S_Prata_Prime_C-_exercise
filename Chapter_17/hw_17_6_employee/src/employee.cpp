//============================================================================
// Name        : employee.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <fstream>
//#include <cstring>
#include "employee.h"
using std::cout;
using std::endl;

abstr_emp:: ~abstr_emp(){}

abstr_emp::abstr_emp():fname("None"),lname("None"),job("None"),m_classtype(Employee){}

abstr_emp::abstr_emp(const std::string& fn,const std::string& ln,const std::string& j,int ct)
	:fname(fn),lname(ln),job(j),m_classtype(static_cast<classtype>(ct)){}

void abstr_emp:: ShowAll() const
{
	cout<<"Classtype:"<<m_classtype<<endl;
	cout<<"First name:"<<fname<<endl;
	cout<<"Last name: "<<lname<<endl;
	cout<<"Job: "<<job<<endl;
}


void abstr_emp::SetAll()//����������� �������� � ������������
{
	std::cin.get();
	cout<<"Enter first name: "<<endl;
	getline(std::cin,fname);
	cout<<"Enter last name: "<<endl;
	getline(std::cin,lname);
	cout<<"Enter job: "<<endl;
	getline(std::cin,job);

}

void abstr_emp::GetAll(std::ifstream& fin,int ct)
{
	m_classtype=static_cast<classtype>(ct);
	getline(fin,fname);
	getline(fin,lname);
	getline(fin,job);
}

void abstr_emp::WriteAll(std::ofstream& fout)
{
	fout<<m_classtype<<endl;
	fout<<fname<<endl;
	fout<<lname<<endl;
	fout<<job<<endl;
}
std::ostream& operator<<(std::ostream& os,const abstr_emp& e)
	//������� ������ ��� � �������
{
	os<<e.fname<<" "<<e.lname<<endl;
	return os;
}


employee::employee():abstr_emp(){}
employee::employee(const std::string& fn,const std::string& ln,const std::string& j,int ct)
	:abstr_emp(fn,ln,j,ct){}
void employee:: ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee:: SetAll()
{
	setclasstype(abstr_emp::Employee);
	abstr_emp::SetAll();
}
void employee::GetAll(std::ifstream& fin,int ct)
{
	abstr_emp::GetAll(fin,ct);
}

void employee::WriteAll(std::ofstream& fout)
{
	abstr_emp::WriteAll(fout);
}

manager::manager():abstr_emp(),inchargeof(0){}
manager::manager(const std::string& fn,const std::string& ln,const std::string& j,
		int ico,int ct): abstr_emp(fn,ln,j,ct),inchargeof(ico){}
manager::manager(const abstr_emp& e,int ico)
	:abstr_emp(e),inchargeof(ico){setclasstype(abstr_emp::Manager);}

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
	setclasstype(abstr_emp::Manager);
	abstr_emp::SetAll();
	cout<<"Enter the number of employees: "<<endl;
	std::cin>>inchargeof;
	while(std::cin.get()!='\n')
		continue;
}

void manager::GetAll(std::ifstream & fin,int ct)
{
	abstr_emp::GetAll(fin,ct);
	(fin>>inchargeof).get();
}

void manager::WriteAll(std::ofstream& fout)
{
	abstr_emp::WriteAll(fout);
	fout<<inchargeof<<endl;
}

fink::fink():abstr_emp(),reportsto("None"){}
fink::fink(const std::string& fn,const std::string& ln,const std::string& j,
		const std::string& rpo, int ct):abstr_emp(fn,ln,j,ct), reportsto(rpo){}

fink::fink(const abstr_emp& e,const std::string& rpo):abstr_emp(e),reportsto(rpo)
				{setclasstype(abstr_emp::Fink);}
fink::fink(const fink& e):abstr_emp(e)
{
	setclasstype(abstr_emp::Fink);
	reportsto=e.reportsto;
}
void fink:: ShowAll() const
{
	abstr_emp::ShowAll();
	cout<<"Report: "<<reportsto<<endl;
	//cout<<endl;
}

void fink::SetAll()
{
	setclasstype(abstr_emp::Fink);
	abstr_emp::SetAll();
	cout<<"Enter report: \n";
	std::cin>>reportsto;
}

void fink::GetAll(std::ifstream& fin,int ct)
{
	abstr_emp::GetAll(fin,ct);
	getline(fin,reportsto);
}

void fink::WriteAll(std::ofstream& fout)
{
	abstr_emp::WriteAll(fout);
	fout<<reportsto<<endl;
}

highfink::highfink(){}

highfink::highfink(const std::string& fn,const std::string& ln,const std::string& j,
		 const std::string& rpo,int ico,int ct)
		:abstr_emp(fn,ln,j,ct),manager(fn,ln,j,ct),
		 fink(fn,ln,j,rpo,ct){}
highfink::highfink(const abstr_emp& e,const std::string& rpo,int ico)
		:abstr_emp(e),manager(e,ico),fink(e,rpo){/*setclasstype(abstr_emp::Highfink);*/}
highfink::highfink(const fink& f,int ico)
		:abstr_emp(f),manager(f,ico),fink(f){setclasstype(abstr_emp::Highfink);}
highfink::highfink(const manager& m,const std::string& rpo)
		:abstr_emp(m),manager(m),fink(m,rpo){setclasstype(abstr_emp::Highfink);}
highfink::highfink(const highfink& h):abstr_emp(h),manager(h),fink(h)
			{setclasstype(abstr_emp::Highfink);}

void highfink:: ShowAll() const
{
	abstr_emp::ShowAll();
	cout<<"The number of employees: "<<manager::InChargeOf()<<endl;
	cout<<"Report: "<<fink::ReportsTo()<<endl;

}
void highfink::SetAll()
{
	setclasstype(abstr_emp::Highfink);
	abstr_emp::SetAll();
	cout<<"Enter the number of employees: "<<endl;
	std::cin>>(*this).InChargeOf();
	std::cin.get();
	cout<<"Enter report: \n";
	std::cin>>(*this).ReportsTo();
	std::cin.get();

}

void highfink::GetAll(std::ifstream& fin,int ct)
{
	abstr_emp::GetAll(fin,ct);
	(fin>>(*this).InChargeOf()).get();
	(fin>>(*this).ReportsTo());
}

void highfink::WriteAll(std::ofstream& fout)
{
	abstr_emp::WriteAll(fout);
	fout<<manager::InChargeOf()<<endl;
	fout<<fink::ReportsTo()<<endl;
}
