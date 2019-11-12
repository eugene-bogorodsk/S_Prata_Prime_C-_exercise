//============================================================================
// Name        : tmp2tmp.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using std::cout;
using std::endl;

//прототипы шаблона
template <typename T> void counts();
template <typename T> void report(T&);

//шаблонный класс
template<typename TT>
class HasFriend
{
private:
	TT item;
	static int ct;
public:
	HasFriend(const TT& i):item(i){ct++;}
	~HasFriend() {ct--;}
	friend void counts<TT>();
	friend void report<>(HasFriend<TT>& );
};

template <typename T>
int HasFriend<T>::ct=0;

//определение дружественных функций для шаблона
template <typename T>
void counts()
{
	cout<<"template size: "<<sizeof(HasFriend<T>)<<"; ";//размер шаблона
	cout<<"template count(): "<<HasFriend<T>::ct<<endl;//count() из шаблона
}

template<typename T>
void report(T& hf)
{
	cout<<hf.item<<endl;
}

int main() {
	counts<int>();
	HasFriend<int> hfi1(10);
	HasFriend<int>hfi2(20);
	HasFriend<double>hfdb(10.5);
	report(hfi1);
	report(hfi2);
	report(hfdb);
	cout<<"counts<int>() output: \n";
	counts<int>();
	cout<<"counts<double>() output:\n";
	counts<double>();
	return 0;
}
