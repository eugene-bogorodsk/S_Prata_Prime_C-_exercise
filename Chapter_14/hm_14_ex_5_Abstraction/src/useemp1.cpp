/*
 * useemp1.cpp
 *
 *  Created on: 12 окт. 2019 г.
 *      Author: Евгений
 */


#include <iostream>
#include "abstaction.h"
int main(void)
{
	using std::cout;
	using std::endl;
	using std::cin;

	employee em("Trip","Harris","Thumper");
	cout<<em<<endl;
	em.ShowAll();
	manager ma("Amorphia","Spindragon","Nuancer",5);
	cout<<ma<<endl;
	ma.ShowAll();
	fink fi("Matt","Oggs","Oiler","Juno Barr");
	cout<<fi<<endl;
	fi.ShowAll();
	highfink hf(ma,"Curly Kew"); //укомплектовано?
	hf.ShowAll();
	cout<<"Press a key for next phase:\n";
	//нажать любую клавишу для слудущей фразы
	cin.get();
	highfink hf2;
	hf2.SetAll();
	cout<<"Using an absrt_emp * pointer:\n";
	//использование указателя abstr_emp
	abstr_emp* tri[4]={&em,&fi,&hf,&hf2};
	for (auto ob : tri) ob->ShowAll();

	return 0;
}

