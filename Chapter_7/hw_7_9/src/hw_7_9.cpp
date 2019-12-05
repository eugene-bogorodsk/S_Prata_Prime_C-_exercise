//============================================================================
// Name        : hw_7_9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : student
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

const int SLEN = 30;
struct student{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student [],int);
void display1(const student);
void display2(const student*);
void display3(const student[],int);
int main() {
	cout << "Enter class size: ";
	int class_size;
	cin>>class_size;
	while (cin.get() != '\n')
		continue;
	student *ptr_stu=new student[class_size];
	int entered= getinfo(ptr_stu,class_size);
	for(int i=0;i<entered;i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu,entered);
	delete [] ptr_stu;
	cout<<"Done.\n";
	return 0;
}

int getinfo(student st[],int n)
{
	int i=0;
	for ( i=0;i < n;i++)
	{
		cout<<"Enter full name or just Enter for quit:\n";
		cin.getline(st[i].fullname,SLEN);
		if(strlen(st[i].fullname) ==0 )
		{
			cout<<"Shit"<<endl;
			break;
		}
		cout<<"Enter hobby:\n";
		cin.getline(st[i].hobby,SLEN);
		cout<<"Enter ooplevel:\n";
		cin>>st[i].ooplevel;
		while (cin.get() != '\n')
			continue;
	}
	return i;
}
void display1(const student st)
{
	cout<<"Name: "<<st.fullname<<endl;
	cout<<"Hobby: "<<st.hobby<<endl;
	cout<<"Ooplevel: "<<st.ooplevel<<endl;
}

void display2(const student* st)
{
	cout<<"Name: "<<st->fullname<<endl;
	cout<<"Hobby: "<<st->hobby<<endl;
	cout<<"Ooplevel: "<<st->ooplevel<<endl;
}

void display3(const student st[],int n)
{
	cout<<"List of the students:\n";
	for( int i=0;i<n;i++)
	{
		cout<<"Name: "<<st[i].fullname<<endl;
		cout<<"Hobby: "<<st[i].hobby<<endl;
		cout<<"Ooplevel: "<<st[i].ooplevel<<endl;
		cout<<endl;
	}
}
