/*
 * employee.h
 *
 *  Created on: 10 дек. 2019 г.
 *      Author: Eugene
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <fstream>
#include <string>

class abstr_emp
{
public:
	enum classtype {Employee=1,Manager,Fink,Highfink};
private:
	std::string fname;
	std::string lname;
	std::string job;
	classtype m_classtype;
public:
	abstr_emp();
	abstr_emp(const std::string& fn,const std::string& ln,const std::string& j,int ct=Employee);
	virtual void ShowAll() const;
	virtual void SetAll();//����������� �������� � ������������
	virtual void GetAll(std::ifstream& fin,int ct);
	virtual void WriteAll(std::ofstream& fout);
	void setclasstype(classtype ct ){m_classtype=ct;}
	friend std::ostream& operator<<(std::ostream& os,const abstr_emp& e);
	//������� ������ ��� � �������
	virtual ~abstr_emp()=0;//����������� ������� �����
};

class employee:public abstr_emp
{
public:
	employee();
	employee(const std::string& fn,const std::string& ln,const std::string& j, int ct=abstr_emp::Employee);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream& fin,int ct);
	virtual void WriteAll(std::ofstream& fout);
};

class manager:virtual public abstr_emp
{
private:
	int inchargeof; //���������� abstr_emp
protected:
	int InChargeOf() const {return inchargeof;}	//�����
	int & InChargeOf() {return inchargeof;}//����
public:
	manager();
	manager(const std::string& fn,const std::string& ln,const std::string& j,int ico=0,
			int ct=abstr_emp::Manager );
	manager(const abstr_emp& e,int ico=0);
	manager(const manager& m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream & fin,int ct);
	virtual void WriteAll(std::ofstream& fout);
};

class fink:virtual public abstr_emp
{
private:
	std::string reportsto;//���� �������� ������
protected:
	const std::string ReportsTo() const {return reportsto;}
	std::string& ReportsTo() {return reportsto;}
public:
	fink();
	fink(const std::string& fn,const std::string& ln,const std::string& j,
			const std::string& rpo, int ct=abstr_emp::Fink);
	fink(const abstr_emp& e,const std::string& rpo);
	fink(const fink& e);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream & fin,int ct);
	virtual void WriteAll(std::ofstream& fout);

};

class highfink:public manager,public fink//supervision of mamagers
{
public:
	highfink();
	highfink(const std::string& fn,const std::string& ln,const std::string& j,
			 const std::string& rpo,int ico,int ct);
	highfink(const abstr_emp& e,const std::string& rpo,int ico);
	highfink(const fink& f,int ico);
	highfink(const manager& m,const std::string& rpo);
	highfink(const highfink& h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream & fin,int ct);
	virtual void WriteAll(std::ofstream& fout);
};


#endif /* EMPLOYEE_H_ */
