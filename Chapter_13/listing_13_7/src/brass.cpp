//============================================================================
// Name        : brass.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : методы классов банковских счетов
//============================================================================

#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

//для целей форматирования
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f,precis pi);

//методы Brass
Brass::Brass(const string& s,long an, double bal):
		fullName(s),acctNum(an),balance(bal){}

void Brass::Deposit(double amt)
{
	if(amt<0)
		cout<<"Negative deposit not allowed;"
		<<" deposite if canceled.\n	";// отрицательный вклад не допускается
		else
			balance+=amt;
}

void Brass:: Withdraw(double amt)
{
	//Установка формата ###.##
	format initialState = setFormat();
	precis prec=cout.
			precision(2);
	if(amt<0)
		cout<<"Withdrawl amount must be positive;"
		<<" withdrawl canceled.\n"; //cнимаемая сумма должна быть положительной
	else if (amt <= balance)
		balance-=amt;
	else
		cout<<"Withdrawl amount of $ "<<amt
		<<"exceeds your balance.\n"
		<<"Withdrawl canceled.\n"; //снимаемая сумма превышает текущий баланс
	restore(initialState,prec);
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	//Установка формата ###.##
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout<<"Client: "<<fullName<<endl; //клиент
	cout<<"Account Number: "<<acctNum<<endl; //номер счета
	cout<<"Balance: $"<<balance<<endl; //баланс
	restore(initialState,prec); //восстановление исходного формата
}

// методы BrassPlus
BrassPlus::BrassPlus(const string& s,long int an,double bal,
			double ml,double r):Brass(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;

}

BrassPlus::BrassPlus(const Brass& ba,double ml,double r):
		Brass(ba),maxLoan(ml),owesBank(0.0),rate(r){}

//переопределение реализации метода ViewAcct()
void BrassPlus::ViewAcct() const
{
	//Установка формата ###.##
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct();
	cout<<"Maximum loan: $"<<maxLoan<<endl;// отображение базовой части
	cout<<"Owed to bank: $"<<owesBank<<endl;// максимальный заем
	cout.precision(3);	//формат ###.###
	cout<<"Loan Rate:"<<100*rate<<"%\n"; //процент на заем
	restore(initialState,prec);
}

//переопределение реализации метода Withdraw
void BrassPlus::Withdraw(double amt)
{
	//Установка формата ###.##
format initialState= setFormat();
precis prec = cout.precision(2);
double bal = Balance();
if(amt<=bal)
	Brass::Withdraw(amt);
else if (amt <= bal+ maxLoan -owesBank)
{
	double advance= amt-bal;
	owesBank+=advance*(1.0 + rate);
	cout<<"Bank advance: $"<<advance<<endl;//аванс банка
	cout<<" Finance charge: $"<<advance*rate<<endl;//долг банку
	Deposit(advance);
	Brass::Withdraw(amt);
}
else
	cout<<"Credit limit exceeded. Tansaction cancelled.\n";//предел кредита первышен
restore(initialState,prec);
}
format setFormat()
{
	//Установка формата ###.##
	return cout.setf(std::ios_base::fixed,
	std::ios_base::floatfield);
}
void restore(format f,precis p)
{
	cout.setf(f,std::ios_base::floatfield);
	cout.precision(p);
}
