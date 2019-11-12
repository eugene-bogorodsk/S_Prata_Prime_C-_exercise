//============================================================================
// Name        : placenew2.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description :�������� new � ����������� �� ��� delete
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
	char* buffer = new char[BUF]; //��������� ����� ������
	JustTesting  *pc1,*pc2;
	pc1 = new (buffer) JustTesting; //���������� ������� � buffer
	pc2 = new JustTesting("Heap1",20);//���������� ������� � ����
	cout<<"Memory block addressed: \n"
			<<(void *) buffer <<" heap:"<<pc2<<endl; //����� ������� ������
	cout<<"Memory contents: \n"; //����� ����������� ������
	cout<<pc1<<": ";
	pc1->Show();
	cout<<pc2<<": ";
	pc2->Show();
	JustTesting *pc3,*pc4;

	//�������� ������ � ������� �������� new c �����������
	pc3 = new (buffer+ sizeof (JustTesting)) JustTesting("Better Idea",6);
	pc4 = new JustTesting("Heap2",10);
	cout<<"Memory contents: \n"; //����� ����������� ������
	cout<<pc3<<": ";
	pc3->Show();
	cout<<pc4<<": ";
	pc4->Show();
	delete pc2;//������������ pc1
	delete pc4; //������������ pc4

	//����� ����������� ��������, ��������� new  � �����������
	pc3->~JustTesting();// ����������� ������� �� ������� �������� pc3
	pc1->~JustTesting();//����������� ������� �� ������� y������� pc1
	delete [] buffer; //������������ buffer
	cout<<"Done.\n";



	return 0;
}
