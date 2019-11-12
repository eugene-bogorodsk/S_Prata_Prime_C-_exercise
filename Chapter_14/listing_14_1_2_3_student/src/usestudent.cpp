/*
 * usestudent.cpp
 *
 *  Created on: 27 сент. 2019 г.
 *      Author: Евгений
 */

#include "student.h"
#include <iostream>
 using std:: cout;
 using std::endl;
 using std::cin;

 void set(Student& st,int n);

 const int pupils = 3;
 const int quizzes = 5;

 int main()
 {
	 Student ada[pupils]=
	 {Student(quizzes),Student(quizzes),Student(quizzes)};
	 int i;
	 for(i=0;i<pupils;++i)
		 set(ada[i],quizzes);
	 cout<<"\nStudent List:\n";
	 for(i=0;i<pupils;++i)
		 cout<<ada[i].Name()<<endl;
	 cout<<"\nResults:";
	 for(i=0;i<pupils;++i)
	 {
		 cout<<endl<<ada[i];
		 cout<<"average: "<<ada[i].Average()<<endl;
	 }
		cout<<"Done.\n";

 }//end of main

void set(Student& sa,int n)
{
	cout<<"Please enter the sudent's name: ";
	getline(cin,sa);
	cout<<"Please enter "<<n<<"quiz scores:\n";
	for(int i=0;i<n;++i)
			cin>>sa[i];
	while(cin.get() != '\n')
		continue;
}
