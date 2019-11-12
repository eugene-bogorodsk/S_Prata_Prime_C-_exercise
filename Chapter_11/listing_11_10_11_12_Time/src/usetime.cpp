/*
 * usetime.cpp
 *
 *  Created on: 25 сент. 2019 г.
 *      Author: Евгений
 */


#include<iostream>
#include "Time.h"
int main()
{
	using std::cout;
	using std::endl;

	Time alda(3,35);
	Time tosca(2,48);
	Time temp;
	cout<<"Aida and Tosca:\n";
	cout<<alda<<"; "<<tosca<<endl;
	temp= alda+tosca;
	cout<<"Alda+ Tosca: "<<temp<<endl;
	temp+alda*1.17;
	cout<<"Alda*1.17"<<temp<<endl;
	cout<<"10.0*Tosca: "<<10.0*tosca<<endl;
	return 0;
}



