/*
 * wine.h
 *
 *  Created on: 2 окт. 2019 г.
 *      Author: Евгений
 */

#ifndef WINE_H_
#define WINE_H_

#include<valarray>
#include<string>
using std::string;

template <typename T1,typename T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() 	const {return a;}
	T2 second() const {return b;}
	Pair(const T1& lhs,const T2& rhs):a(lhs),b(rhs){}
	//Pair(int n):a(n),b(n){}
	Pair(){}
};
class Wine
{

private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt,ArrayInt> PairArray;
	std::string label;
	PairArray _set;
public:
	Wine():label("no name"),_set(){}
	Wine(const std::string& l, int y):label(l),_set(ArrayInt(y),ArrayInt(y)){}
	Wine(const std::string& l,int _year,const int [],const int[]);
	void GetBottles();
	const string&  Label() const;
	int sum() const;
	void Show() const;

};




#endif /* WINE_H_ */
