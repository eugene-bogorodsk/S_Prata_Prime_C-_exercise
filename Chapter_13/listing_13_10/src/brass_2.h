/*
 * brass_2.h
 *
 *  Created on: 12 ����. 2019 �.
 *      Author: �������
 */

#ifndef BRASS_2_H_
#define BRASS_2_H_

class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string& s = "Nullbody",long an = -1,
			double bal = 0.00);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass(){}
};

//����� BrassPlus
class BrassPlus:public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string& s="Nullbody", long an = -1,
			double bal = 0.0,double ml=500,
			double r = 0.11125);
	BrassPlus(const Brass& ba,double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m){ maxLoan =  m;}
	void ResetRate(double r){rate = r;}
	void ResetOwes() {owesBank = 0;}

};





#endif /* BRASS_2_H_ */
