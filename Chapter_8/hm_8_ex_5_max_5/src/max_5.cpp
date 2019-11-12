//============================================================================
// Name        : max_5.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
const int max_num=5;
template <typename T> T max5(const T* m);
int main() {
	int array1[5]={234,485,213,885,353};
	double array2[5]={34.24,34.88,93.33,75.00,43.77};
	cout<<"Max elemein of the int array: "<<max5(array1)<<endl;
	cout<<"Max element of the double array: "<<max5(array2)<<endl;
	return 0;
}
template <typename T> T max5(const T m[] )
{
	T max_el=m[0];
	for(int i=0;i<max_num;i++)
			if(m[i]>max_el) max_el=m[i];
	return max_el;
}
