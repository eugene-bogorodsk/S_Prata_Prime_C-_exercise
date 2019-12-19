//============================================================================
// Name        : average.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_18_1
//============================================================================

#include <iostream>
#include <initializer_list>
#include <functional>

template <typename T>
T average_list(std::initializer_list<T> il)
{
	 T total;
	for(auto num:il) total+=num;
	return total/il.size();
}

int main() {
	using namespace std;
	//double list was getted from list contest
	auto q = average_list({15.4,10.7,9.0});
	cout<<q<<endl;

	//int list getted from list contest
	cout<<average_list({20,30,19,17,45,39})<<endl;

	//forced using double list
	auto ad = average_list<double> ({'A',70,65.33});
	cout<<ad<<endl;

	return 0;
}
