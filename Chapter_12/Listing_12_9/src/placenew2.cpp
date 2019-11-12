//============================================================================
// Name        : placenew2.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description :операци€ new с размещением но без delete
//============================================================================

#include <iostream>
#include <new>
using namespace std;

const int BUF = 512;

class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting( const string& s = "Just Testing",int n=0)
{
		words = s; number = n; cout<<words<<" constructed.\n";
}
	~JustTesting()
	{
		cout<<words<<" destroyed.\n";
	}
	void Show() const
	{
		cout<<words<<"; "<<number<<endl;
	}
};

int main() {
	char* buffer = new char[BUF]; //получение блока пам€ти
	JustTesting  *pc1,*pc2;
	pc1 = new (buffer) JustTesting; //размещение объекта в buffer
	pc2 = new JustTesting("Heap1",20);//размещение объекта в куче
	cout<<"Memory block addressed: \n"
			<<(void *) buffer <<" heap:"<<pc2<<endl; //вывод адресов пам€ти
	cout<<"Memory contents: \n"; //вывод содержимого пам€ти
	cout<<pc1<<": ";
	pc1->Show();
	cout<<pc2<<": ";
	pc2->Show();
	JustTesting *pc3,*pc4;

	//фиксаци€ €чейки с которой работает new c размещением
	pc3 = new (buffer+ sizeof (JustTesting)) JustTesting("Better Idea",6);
	pc4 = new JustTesting("Heap2",10);
	cout<<"Memory contents: \n"; //вывод содержимого пам€ти
	cout<<pc3<<": ";
	pc3->Show();
	cout<<pc4<<": ";
	pc4->Show();
	delete pc2;//освобождение pc1
	delete pc4; //освобождение pc4

	//€вное уничтожение объектов, созданных new  с размещением
	pc3->~JustTesting();// уничтожение объекта на который указывал pc3
	pc1->~JustTesting();//уничтоженме объекта на который yказывал pc1
	delete [] buffer; //освобождение buffer
	cout<<"Done.\n";



	return 0;
}
