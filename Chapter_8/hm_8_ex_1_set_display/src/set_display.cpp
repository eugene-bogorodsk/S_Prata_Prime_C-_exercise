//============================================================================
// Name        : set_display.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
static int count=0;
void set_display(const string& s,int n=0);

int main() {
	string test="Wow!!!";
	set_display(test);
	set_display(test,1);
	set_display(test);
	set_display(test,5);
	return 0;
}
void set_display(const string& s,int n)
{
	count++;
	if(n!=0)
	{
		cout<<"It was "<<count<<" "
				"recalls"<<endl;
		for(int i=0;i<count;i++)
			cout<<i+1<<": "<<s<<endl;
	}
	else
		cout<<n<<": "<<s<<endl;
}
