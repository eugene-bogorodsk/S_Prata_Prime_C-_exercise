/* переменные с внутренним и внешним связываением
 * twofile2.cpp
 *
 *  Created on: 4 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
extern int tom;//переменная оперделена в другом месте
static int dick=10; //переопределяет внешнюю переменную dick
int harry=200; //конфликт с harry из twofile отсутсвует

void remote_access()
{
	using namespace std;
	cout<<"remote_access() reports the following addresses:\n";
	cout<<&tom<<" = &tom, "<<&dick<<" = &dick, "<<&harry<<" = &hurry.\n";
}


