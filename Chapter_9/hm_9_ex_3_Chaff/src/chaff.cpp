//============================================================================
// Name        : chaff.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description упражненеи 3 главы 9
//============================================================================

#include <iostream>
#include <new> //для операции new  с размещением
#include <cstring>
using namespace std;

const int BUFF = 512;

char buffer[BUFF];//блок памяти

struct chaff
{
	char dross[20];
	int slag;
};
int main() {
	chaff *p_chaff[2];

	p_chaff[0] = new (buffer) chaff;
	p_chaff[1] = new(buffer + sizeof(chaff)) chaff;

	strcpy(p_chaff[0]->dross,"Karl Marx");
	p_chaff[0]->slag = 90;

	strcpy(p_chaff[1]->dross,"Fridrih Engels");
	p_chaff[1]->slag = 88;

	cout<<&buffer<<endl;
	for(int i =0; i<2;++i)
		cout<<p_chaff[i]<<": "<<p_chaff[i]->dross<<" - "<<p_chaff[i]->slag<<endl;

	return 0;
}
