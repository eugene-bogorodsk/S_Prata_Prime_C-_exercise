//============================================================================
// Name        : frnd2tmp.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T& t):item(t) {ct++;}
	~HasFriend(){}
	friend void counts();
	friend void reports(HasFriend<T> & );//template parametr
};

//������ ������������� ����� ����������� ����������� ���� ������
template <typename T>
int HasFriend<T>::ct=0;
//����������� ���� ��� ���� ������� HasFriend<T>
void counts()
{
	cout<<"int count: "<<HasFriend<int>::ct<<", ";
	cout<<"double count: "<<HasFriend<double>::ct<<endl;
}

//����������� ���� ��� ������ HasFriend<int>
void reports(HasFriend<int>& hf)
{
	cout<<"HasFriend<int>:"<<hf.item<<endl;
}

//����������� ���� ��� ������ HasFriend<double>
void reports(HasFriend<double>& hf)
{
	cout<<"HasFriend<double>"<<hf.item<<endl;
}

int main() {
	cout<<"No objects declared:"; //������� ���� �� ���������
	counts();

	HasFriend<int> hfi1(10);
	cout<<"After hfil declared: "; //����� ���������� hfi1
	counts();

	HasFriend<int>hfi2(20);
	cout<<"After hfi2 declared: ";//����� ���������� hfi2
	counts();

	HasFriend<double>hfdb(10.5);
	cout<<"After hfdb declared: "; //����� ���������� hfdb
	counts();

	reports(hfi1);
	reports(hfi2);
	reports(hfdb);

	return 0;
}
