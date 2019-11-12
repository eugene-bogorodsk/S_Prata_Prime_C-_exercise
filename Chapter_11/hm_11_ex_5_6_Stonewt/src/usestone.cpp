/*
 * usestone.cpp
 *
 *  Created on: 25 сент. 2019 г.
 *      Author: Евгений
 */

#include <iostream>
#include "stonehm.h"

using std::cout;
void display(const Stonewt& , int);
int main()
{
	Stonewt incognito=275;//использование конструктора по умолчанию
	Stonewt wolfe(285.7,Stonewt::FLOAT_POUNDS); //то же что и Stonwt  wolfe = 285.7
	Stonewt taft(21.8,Stonewt::STONE);
	cout<<"The celebrity weighed: ";
	cout<<incognito<<std::endl;
	cout<<"The detective weighed: ";
	cout<<wolfe<<std::endl;
	cout<<"The President weighed: ";
	cout<<taft<<std::endl;
	incognito = 276.8; //использование конструктора для преобразования
	taft = 325; //то же что и taft = Stonewt(325);
	cout<<"After fibber,the celebrity weighed ";
	cout<<incognito<<std::endl;
	cout<<"After fibber, the President weighed ";
	cout<<taft<<std::endl;
	display(taft,2);
	cout<<"The wrestler weighed even more.\n";
	display(422,2);
	cout<<"No stone left unearned\n";
	cout<<std::endl;
	Stonewt poppins(9,2.8,Stonewt::STONE); //9 стоунов, 2,8 фунта
	double p_wt = poppins; //неявное преобразование
	cout<<"Convert to double => ";
	cout<<"Poppins: "<<p_wt<<" pounds.\n";
	cout<<"Convert to int => ";
	cout<<"Poppins: "<<int (poppins) <<" pounds.\n";
	Stonewt test_mul(10,8);
	cout<<"Initial test_mul: ";
	cout<<test_mul<<std::endl;
	test_mul= test_mul*2.0;
	cout<<test_mul<<std::endl;
	cout<<test_mul<<std::endl;
	cout<<"Test of summation: incognito + wolfe\n";
	cout<<incognito + wolfe<<std::endl;
	cout<<"Test of multiplication: ";
	test_mul=incognito*wolfe;
	cout<<test_mul;
	cout<<test_mul.change_mode(Stonewt::STONE);
	cout<<"Test of subtraction: ";
	test_mul=incognito-wolfe;
	cout<<test_mul;
	cout<<test_mul.change_mode(Stonewt::STONE);

	Stonewt stone[6];
	stone[0]=Stonewt(155);
	stone[1]={50,5.0};
	stone[2]=Stonewt(112.5);
	for(int i=3;i<6;++i)
	{
		double _lbs_double =0;
		int _stone;
		std::string type;
		cout<<"Enter weight of "<<i+1 <<" object. \n";
		cout<<"If  wheight is in pounds, set the 0 in area of stones";
		std::cin>>_stone>>_lbs_double;
		if (_stone == 0)
			stone[i]=Stonewt(_lbs_double);
		else
			stone[i]=Stonewt(_stone,_lbs_double);
	}
	Stonewt min_stone = stone[0];
	Stonewt max_stone = stone[0];
	Stonewt st11(11,0);
	int count = 0;
	for( auto st:stone)
	{
		if(st<min_stone)	min_stone=st;
		if(st>max_stone)    max_stone=st;
		if(st>=st11)      count++;
	}
	cout<<"The min object: "<<min_stone.change_mode(Stonewt::STONE);
	cout<<"The max object: "<<max_stone.change_mode(Stonewt::STONE);
	cout<<"The number of counts > 11:  "<<count<<std::endl;
	return 0;

}//end of main

void display( const Stonewt& st,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Wow!";
		cout<<st<<std::endl;
	}
}



