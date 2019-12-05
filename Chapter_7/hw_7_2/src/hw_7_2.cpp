//============================================================================
// Name        : hw_7_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_7_2 golf game results
//============================================================================

#include <iostream>
using namespace std;

const int Max_games = 10;
int fill_results(int []);
void show_results(int [],int);
double mean_result(int [],int);

int main() {
	using namespace std;
	int results[Max_games]{0};
	int count=fill_results(results);
	show_results(results,count);
	cout<<"mean result: "<<mean_result(results,count)<<endl;
	return 0;
}

int fill_results(int ar[])
{
	double temp;
	int count=0;
	cout<<"Enter result of the game (-1 for the quit): ";
	while(cin>>temp && count<Max_games)
	{
		if(!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout<<"Bad input,try again.";
			continue;
		}
		else if (temp<0)
		{
			cout<<"Finish the enter. Get the results.\n";
			break;
		}
		ar[count]=temp;
		count+=1;
		cout<<"Enter result of the game or (q for the quit): ";
	}
	return count;
}
void show_results(int ar[],int count)
{
	cout<<"results: ";
	for(int i=0;i<count;i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}

double mean_result(int ar[],int count)
{
	double sum=0;
	for(int i=0;i<count;i++)
		sum+=ar[i];
	return sum/count;
}
