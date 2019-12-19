//============================================================================
// Name        : sum_values.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw 18.3
//============================================================================

#include <iostream>

//call finish
long double sum_values(){ return 0;}

template<typename T,typename...Args>
long double sum_values(T value,Args...args)
{
	long double total=(long double)value;
	return total+sum_values(args...);

}

int main() {
	using namespace std;
	cout<<sum_values(3,4.5,34,'x',2.333333,4L)<<endl;
	return 0;
}
