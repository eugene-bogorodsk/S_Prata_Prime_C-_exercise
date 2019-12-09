//============================================================================
// Name        : peeker.cpp
// Author      : 
// Version     :some iostream methods
// Copyright   : Your copyright notice
// Description : listing 17.14
//============================================================================

#include <iostream>

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	//reading and displpaying characters up to a character #
	char ch;

	while(cin.get(ch))//completion on reaching eof
	{
		if (ch !='#')
			cout<<ch;
		else
		{
			cin.putback(ch);//re-insert character
			break;
		}
	}
	if(!cin.eof())
	{
		cin.get(ch);
		cout<<endl<<ch<<" is next input character.\n";
	}
	else
	{
		cout<<"End of file reached.\n";
		std::exit(0);
	}
	while(cin.peek() != '#')//look ahead
	{
		cin.get(ch);
		cout<<ch;
	}
	if(!cin.eof())
	{
		cin.get(ch);
		cout<<endl<<ch<<" is next input character.\n";
	}
	else
		cout<"End of file reached.\n";//end of file reached
	return 0;
}
