/*использование базового класса
 * usett0.cpp
 *
 *  Created on: 10 сент. 2019 г.
 *      Author: Евгений
 */

#include "tabtenn0.h"
#include <iostream>

int main(void)
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara","Boomdea",false);
	RatedPlayer rplayer1(1140,"Mallory","Duck",true);
	rplayer1.Name(); //объект производного класса использует метод базового класса
	if(rplayer1.HasTable())
		cout<<" : has a table.\n";
	else
		cout<<" : hasn't a table.\n";
	player1.Name(); //объект базового класса использует метод базового класса
	if(player1.HasTable())
			cout<<" : has a table.\n";
	else
		cout<<" : hasn't a table.\n";

	cout<<"Name: ";
	rplayer1.Name();
	cout<<"; Rating: "<<rplayer1.Rating()<<endl;

	//Инициализация объекта RatedPlayer  с помощью объекта TableTennisPlayer
	RatedPlayer rplayer2(1212,player1);
	cout<<"Name: ";
	rplayer2.Name();
	cout<<"; Rating: "<<rplayer2.Rating()<<endl;
	return 0;
}


