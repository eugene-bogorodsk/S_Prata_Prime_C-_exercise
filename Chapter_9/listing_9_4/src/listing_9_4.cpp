//============================================================================
// Name        : listing_9_4.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : иллюстрация области видимости автоматических переменных
//============================================================================

#include <iostream>
void oil(int x);

int main() {
	using namespace std;
	int texas = 31;
	int year = 2011;

	cout << "In main(), texas = "<<texas<<", &texas = ";
	cout<<&texas<<endl;
	cout<<"In main()< year = "<<year<<", &year = ";
	cout<<&year<<endl;
	oil(texas);
	cout<<"In main(), texas = "<<texas<<", &texas = ";
	cout<<&texas<<endl;
	cout<<"In main(), year = "<<year<<", &year = ";
	cout<<&year<<endl;
	return 0;
}

void oil(int x)
{
	using namespace std;
	int texas = 5;
	cout<<"In oil(), texas = "<<texas<<", &texas = ";
	cout<<&texas<<endl;
	cout<<"In oil(), x = "<<x<<", &x = ";
	cout<<&x<<endl;
	{		//начало блока
		int texas =113;
		cout<<"In block, texas = "<<texas;
		cout<<", &texas = "<<&texas<<endl;
		cout<<"In click, x = "<<x<<", &x = ";
		cout<<&x<<endl;
	}
	cout<<"Post-block texas = "<<texas;
	cout<<", &texas = "<<&texas<<endl;
}
