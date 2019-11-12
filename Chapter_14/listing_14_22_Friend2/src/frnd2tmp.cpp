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

//кажда€ специализаци€ имеет собственный статический член данных
template <typename T>
int HasFriend<T>::ct=0;
//нешаблонный друг дл€ всех классов HasFriend<T>
void counts()
{
	cout<<"int count: "<<HasFriend<int>::ct<<", ";
	cout<<"double count: "<<HasFriend<double>::ct<<endl;
}

//нешаблонный друг дл€ класса HasFriend<int>
void reports(HasFriend<int>& hf)
{
	cout<<"HasFriend<int>:"<<hf.item<<endl;
}

//нешаблонный друг дл€ класса HasFriend<double>
void reports(HasFriend<double>& hf)
{
	cout<<"HasFriend<double>"<<hf.item<<endl;
}

int main() {
	cout<<"No objects declared:"; //обхекты пока не объ€влены
	counts();

	HasFriend<int> hfi1(10);
	cout<<"After hfil declared: "; //после объ€влени€ hfi1
	counts();

	HasFriend<int>hfi2(20);
	cout<<"After hfi2 declared: ";//после объ€влени€ hfi2
	counts();

	HasFriend<double>hfdb(10.5);
	cout<<"After hfdb declared: "; //после объ€влени€ hfdb
	counts();

	reports(hfi1);
	reports(hfi2);
	reports(hfdb);

	return 0;
}
