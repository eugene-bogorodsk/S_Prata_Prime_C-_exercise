/*тестирование классов банковских счетов
 * usebrass1.cpp
 *
 *  Created on: 11 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include "brass.h"

int main()
{
	using std::cout;
	using std::endl;

	Brass Piggy("Porcellon Pigg",381299,4000.00);
	BrassPlus Hoggy("Horatto Hogg",382288,3000.00);
	Piggy.ViewAcct();
	cout<<endl;
	Hoggy.ViewAcct();
	cout<<endl;
	cout<<"Depositing $1000 into the Hoggy Account:\n";
	Hoggy.Deposit(1000.00);
	cout<<"New balance: $ "<<Hoggy.Balance()<<endl;
	cout<<"Withdrawing $4200 from the Pigg Account:\n";
	Piggy.Withdraw(4200.00);
	cout<<"Pigg account balance: $"<<Piggy.Balance()<<endl;
	cout<<"Withdrawing $ 4200 form the Hogg Account:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
	return 0;

}
