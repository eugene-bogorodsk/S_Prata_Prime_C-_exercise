//============================================================================
// Name        : max_n.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;
const int max_string = 5;
template <typename T> T max_n(const T* m,int n);
template<> const char* max_n<const char*>( const char* const str[],int n);
int main() {
	int array1[6]={234,485,213,885,353,999};
	double array2[4]={34.24,34.88,93.33,75.00};
	const char* array3[5]={"Konstantin","Leonid","Eugeny","Aristarh","Evdokim"};
	cout<<"Max elemein of the int array: "<<max_n(array1,sizeof(array1)/sizeof(int))<<endl;
	cout<<"Max element of the double array: "<<max_n(array2,sizeof(array1)/sizeof(double))<<endl;
	cout<<"The longest string:"<<(int*)max_n(array3,max_string)<<endl;

	return 0;
}
template <typename T> T max_n(const T m[],int n )
{
	T max_el=m[0];
	for(int i=0;i<n;i++)
			if(m[i]>max_el) max_el=m[i];
	return max_el;
}
template<> const char*  max_n<const char*> (const char* const str[],int n)
{
	int k=0;
	for(int i=0;i<n;i++)
		if(strlen(str[k])>strlen(str[i]))  k=i;
	return str[k];
}

