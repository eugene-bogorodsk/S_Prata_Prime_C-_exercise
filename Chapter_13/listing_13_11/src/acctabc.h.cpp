//============================================================================
// Name        : h.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description :методы класса банковских счетов
//============================================================================

#include <iostream>
#include "acctabc.h"
using std::cout;
using std::endl;
using std::ios_base;
using std::string;

//Абстрактный базовый класс
AcctABC::AcctABC(const string& s,long int an, double bal):fullName(s),
			acctNum(an),balance(bal){}

void AcctABC::Deposit(double amt)
{
	if(amt<0)
		cout<<"Negative deposit not allowed;"
		<<" deposit is cacelled.\n"; //отрицательный вклад не допускается
	else
		balance+=amt;
}

void AcctABC::Withdraw(double amt)
{
	balance-=amt;
}

//защищенные методы для форматирования
AcctABC::Formatting AcctABC::SetFormat() const
{
	//установка формата ###.##
	Formatting f;
	f.flag =
			cout.setf(ios_base::fixed,ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting& f) const
{
	cout.setf(f.flag,ios_base::floatfield);
	cout.precision(f.pr);
}

//методы Brass
void Brass::Withdraw(double amt)
{
	if(amt<0)
		cout<<"Withdrawal amount must be positive;"
		<<"Withdrawal canceled.\n";// снимаемая сумма дложна быть положительной
		else if (amt <= Balance())
			AcctABC:Withdraw(amt);
		else
			cout<<"Withdrawal amount of $"<<amt
			<<"exeeds your balance.\n"
			<<"Withdrawl canceled.\n";//снимаемая сумма превышает текущий баланс
}
void Brass::ViewAcct() const
{
	Formatting f = SetFormat();
	cout<<"Brass Client: "<<FullName()<<endl; //клиент Brass
	cout<<"Account Number: "<<AcctNum()<<endl;//номер счета
	cout<<"Balance: $"<<Balance() <<endl; //баланс
	Restore(f);
}

//методы BrassPlus
BrassPlus::BrassPlus(const string& s,long an,double bal,
			double ml,double r):
			AcctABC(s,an,bal),maxLoan(ml),owesBank(0.0),rate(r){}

BrassPlus::BrassPlus(const Brass& ba,double ml,double r):
		AcctABC(ba),maxLoan(ml),owesBank(0.0),rate(r){}//используется неявный конструктор копирования

void BrassPlus::ViewAcct() const
{
	Formatting f = SetFormat();
	cout<<"BrassPlus Client: "<<FullName()<<endl; //клиент BrassPlus
	cout<<"Account Number:"<<AcctNum()<<endl;//номер счета
	cout<<"Balance: $"<<Balance()<<endl;//баланс
	cout<<"Maximum loan: $"<<maxLoan<<endl;//максимальный заем
	cout<<"Owed to bank: $"<<owesBank<<endl;//долг банку
	cout.precision(3);
	cout<<"Loan Rate:"<<100*rate<<"%\n";//процент на заем
	Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f= SetFormat();
	double bal = Balance();
	if(amt<= bal)
		AcctABC::Withdraw(amt);
	else if(amt <= bal+maxLoan- owesBank)
	{
		double advance = amt-bal;
		owesBank+=advance*(1.0 + rate);
		cout<<"Bank advance: $"<<advance<<endl;//аванс банку
		cout<<"Finance charge: $"<<advance*rate<<endl;// долг банку
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout<<"Credit limit exceeded.Transaction cancelled.\n";//предел кредита превышен
	Restore(f);
}
