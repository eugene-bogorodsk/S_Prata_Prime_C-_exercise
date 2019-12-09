//============================================================================
// Name        : cinexcp.cpp
// Author      : 
// Version     :exceptions generation
// Copyright   : Your copyright notice
// Description : listing 17.12
//============================================================================

#include <iostream>
#include <exception>

int main() {
	using namespace std;
	//setted failbit causes an exception to the thrown
	cin.exceptions(ios_base::failbit);
	cout<<"Enter numbers: ";
	int sum=0;
	int input;
	try{
		while(cin>>input)
			sum+=input;
	} catch(ios_base::failure & bf)
	{
		cout<<bf.what()<<endl;
		cout<<"O! the horror!\n";
	}
	cout<<"Last value entered = "<<input<<endl;
	cout<<"Sum = "<<sum<<endl;
	return 0;
}
