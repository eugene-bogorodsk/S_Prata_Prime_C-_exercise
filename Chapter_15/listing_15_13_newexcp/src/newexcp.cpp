//============================================================================
// Name        : newexcp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : listing 15.13 exception bad_alloc
//============================================================================

#include <iostream>
#include <new>
#include <cstdlib> //for exit(), EXIT_FALURE
using namespace std;

struct Big
{
	double stuff[100000];
};
int main() {
	Big *pb;
	try{
		cout<<"Trying to get a big block of memory:\n";
		pb=new Big[100000]; //1 600 000 000 bytes
		cout<<"Got past the new request:\n"; //exit of results new requerment
	}
	catch(bad_alloc& ba)
	{
		cout<<"Caught the exception!\n";//oсcured exception
		cout<<ba.what()<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Memory successfully allocates\n";
	pb[0].stuff[0]=4;
	cout<<pb[0].stuff[0]<<endl;
	delete [] pb;
	return 0;
}
