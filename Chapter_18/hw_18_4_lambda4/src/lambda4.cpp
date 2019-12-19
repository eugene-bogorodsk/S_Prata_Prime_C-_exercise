//============================================================================
// Name        : lambda4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw 18.4
//============================================================================

#include <iostream>


#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


int main() {
	using std::list;
	using std::cout;
	using std::endl;
	int vals[10]={10,100,90,180,60,210,415,88,188,201};
	list<int> yadayada(vals,vals+10);//range designer
	list<int> etcetera(vals,vals+10);

	cout<<"Original lists:\n";
	for_each(yadayada.begin(),yadayada.end(),[](int y){cout<<y<<" ";});
	cout<<endl;

	for_each(etcetera.begin(),etcetera.end(),[](int y){cout<<y<<" ";});
	cout<<endl;
	yadayada.remove_if([](int ya){return ya>100;}); //using named function object
	etcetera.remove_if([](int el){return el>200;}); //construction of function object
	cout<<"Trimmed lists:\n";
	for_each(yadayada.begin(),yadayada.end(),[](int y){cout<<y<<" ";});
	cout<<endl;
	for_each(etcetera.begin(),etcetera.end(),[](int y){cout<<y<<" ";});
	cout<<endl;
	return 0;
}
