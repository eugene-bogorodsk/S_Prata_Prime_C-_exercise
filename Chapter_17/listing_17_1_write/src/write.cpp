//============================================================================
// Name        : write.cpp
// Author      : 
// Version     :using cout.write()
// Copyright   : Your copyright notice
// Description : listing 17.1
//============================================================================

#include <iostream>
#include <cstring>

int main() {
	using std::cout;
	using std::endl;
	const char * state1="Florida";
	const char * state2="Kansas";
	const char * state3="Euphoria";
	int len = std::strlen(state2);
	cout<<"Increasing loop index:\n";
	int i;
	for (i=1;i<=len;i++)
	{
		cout.write(state2,i);
		cout<<endl;
	}
	//concatenation of output
	cout<<"Decreasing loop index:\n";
	for (i=len;i>0;i--)
		cout.write(state2,i)<<endl;
	//the excess length of the string
	cout<<"Exceeding string length:\n";
	cout.write(state2,len+5)<<endl;
	return 0;
}
