//============================================================================
// Name        : functor.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : listing 16.15
//============================================================================

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T> //functor class defines operator(){}
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t):cutoff(t){}
	bool operator()(const T & v) {return v > cutoff;}
};

void outint(int n){std::cout<<n<<" ";}

int main() {
	using std::list;
	using std::cout;
	using std::endl;
	TooBig<int> f100(100);
	int vals[10]={10,100,90,180,60,210,415,88,188,201};
	list<int> yadayada(vals,vals+10);//range designer
	list<int> etcetera(vals,vals+10);

	cout<<"Original lists:\n";
	for_each(yadayada.begin(),yadayada.end(),outint);
	cout<<endl;

	for_each(etcetera.begin(),etcetera.end(),outint);
	cout<<endl;
	yadayada.remove_if(f100); //using named function object
	etcetera.remove_if(TooBig<int>(200)); //construction of function object
	cout<<"Trimmed lists:\n";
	for_each(yadayada.begin(),yadayada.end(),outint);
	cout<<endl;
	for_each(etcetera.begin(),etcetera.end(),outint);
	cout<<endl;
	return 0;
}
