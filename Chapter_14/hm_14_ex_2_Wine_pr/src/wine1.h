/*
 * wine1.h
 *
 *  Created on: 4 окт. 2019 г.
 *      Author: Евгений
 */

#ifndef WINE1_H_
#define WINE1_H_

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
	Pair(){}
};
class Wine: private std::string,private Pair<std::valarray<int>,std::valarray<int>>
{

private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt,ArrayInt> PairArray;
	PairArray operator =(PairArray(ArrayInt(),ArrayInt()));

public:
	Wine(): std::string("no name"), PairArray(){}
	Wine(const string& l,int y):string(l),PairArray(ArrayInt(y),ArrayInt(y)){}
	Wine(const string& l,int y,const int yr[],const int bt[])
		:string(l),PairArray(ArrayInt(yr,y),ArrayInt(bt,y)){}
	~Wine(){}
	void GetBottles();
	const string&  Label() const;
	int sum() const;
	void Show() const;

};


#endif /* WINE1_H_ */
