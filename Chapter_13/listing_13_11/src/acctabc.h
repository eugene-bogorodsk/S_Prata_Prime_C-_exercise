/* классы банковских счетов
 * acctabc.h
 *
 *  Created on: 13 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

//абстрактный базовый класс
class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string& FullName() const {return fullName;}
	long AcctNum() const {return acctNum;}
	Formatting SetFormat() const;
	void Restore (Formatting& f) const;
public:
	AcctABC(const std::string& s = "Nullbody", long an = -1,
			double bal= 0.0);
	void Deposit(double amt);
	virtual void Withdraw( double amt) = 0;//чистая виртуальная функция
	double Balance() const {return balance;};
	virtual void ViewAcct() const = 0; //чистая виртуальная функция
	virtual ~AcctABC() {}
};

//класс счета Brass Account
class Brass: public AcctABC
{
public:
	Brass(const std::string& s = "Nullbody", long an = -1,
			double bal = 0.0): AcctABC(s,an,bal){}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

//класс счета Brass Plus
class BrassPlus: public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string& s = "Nullbody",long an = -1,
				double bal = 0.0,double ml= 500,
				double r =0.10);
	BrassPlus(const Brass& ba,double ml=500,double r= 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m){maxLoan = m;}
	void ResetRate(double r) {rate = r;}
	void ResetOwes(){owesBank = 0;}
};

#endif /* ACCTABC_H_ */
