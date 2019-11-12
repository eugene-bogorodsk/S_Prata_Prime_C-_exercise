/*создание пространства имен pers и debts
 * namesp.h
 *
 *  Created on: 5 сент. 2019 г.
 *      Author: Евгений
 */

namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void gerPerson(Person&);
	void showPerson( const Person&);
}
namespace debts
{
using namespace pers;
struct Debt
{
	Person name;
	double amount;
};
void getDebt(Debt &);
void showDebt(const Debt&);
double sumDebts(const Debt ar[],int n);
}
