//============================================================================
// Name        : stckp1.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stckp1.h"
const int Num=10;

int main() {
	std::srand(std::time(0));
	std::cout<<"Please enter stack size:";
	int stacksize;
	std::cin>>stacksize;

	//создание пустого счетчика с размероа stacksize
	Stack<const char* >st(stacksize);

	//входной ящик
	const char* in[Num]={
			"1:Hank Gilgamesh","2:Kiki Ishtar",
			"3:Betty Ricker", "4: Ian Flagranti",
			"5:Wolfgang Kibble","6: Portia Koop",
			"7:Joy Almindo","8: Xaverie Paprika",
			"9:Juan Moore","10:Misha Mashe"
	};

	//выходной ящик
	const char* out[Num];
	int processed = 0;
	int nextin= 0;
	while(processed<Num)
	{
	if(st.isempty())
		st.push(in[nextin++]);
	else if(st.isfull())
		st.pop(out[processed++]);
	else if (std::rand() % 2 && nextin < Num) //шансы 50 на 50
		st.push(in[nextin++]);
	else
		st.pop(out[processed++]);
	}

	for(int i = 0;i<Num;i++)
		std::cout<<out[i]<<std::endl;
	std::cout<<"Buy\n";
	return 0;
}
