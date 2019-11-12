/*
 * person_ex.h
 *
 *  Created on: 5 окт. 2019 г.
 *      Author: Евгений
 */

#ifndef PERSON_EX_H_
#define PERSON_EX_H_
#include <string>
#include <iostream>
#include <valarray>
#include <vector>

using std::string;

class Person
{
private:
	string first_name;
	string last_name;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Person():first_name("No"),last_name("name"){}
	Person(const string& fn,const string& ln):first_name(fn),last_name(ln){}
	virtual ~Person()=0;
	virtual void Set()=0;
	virtual void Show() const = 0;
};

class Gunslinger:virtual public Person
{
private:
	double ready_time;
	int gun_cuts;
protected:
	void Data() const;
	void Get();
public:
	Gunslinger():Person(),ready_time(0.0),gun_cuts(0){}
	Gunslinger(const string& fn,const string& ln,double rt,int gc)
		:Person(fn,ln),ready_time(rt),gun_cuts(gc){}
	Gunslinger(const Person& pr,double rt,int gc)
		:Person(pr),ready_time(rt),gun_cuts(gc){}
	double Draw() const {return ready_time;}
	void Set();
	void Show() const;
};

class Card
{
protected:
	enum suit {CLUBS=1,DIAMONDS,HEARTS,SPADES};
	enum rank {ACE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};
	enum {STypes= 4};
	enum {RTypes=13};
	Card Set();
private:
	static string suit_set[STypes];
	static string rank_set[RTypes];
	int m_suit;
	int m_rank;
public:
	Card(){m_rank=1;m_suit=1;}
	Card(int r,int s):m_suit(s),m_rank(r){}
	Card(const Card& cd){ m_rank= cd.m_rank;m_suit= cd.m_suit;}
	string Get_Suit(int i) const {return suit_set[i];}
	string Get_Rank(int i) const {return rank_set[i];}
	//Card(int _suit ,int _rank):m_rank(_rank),m_suit(_suit){}

	friend std::ostream& operator<<(std::ostream& os,const Card& a_card);
};

class PokerPlayer:public Card,virtual public Person
{

protected:
	Card m_card;
	void Data() const;
	void Get();
public:
	PokerPlayer():Person(),m_card(){}
	PokerPlayer(const string& fn,const string& ln,int s,int r)
		:Person(fn,ln),m_card(s,r){}
	PokerPlayer(const Person& pr, int s,int r)
		:Person(pr),m_card(s,r){}
//	virtual ~ PokerPlayer(){}
	Card Draw() const;
	void Set();
	void Show() const;
};

class BadDude:public Gunslinger,public PokerPlayer
{
protected:
	void Data() const;
	void Get();
public:
	BadDude(){}
	BadDude(const string& fn,const string& ln,double rt=0.0,int gc=0,int s=1, int r=1)
		:Person(fn,ln),Gunslinger(fn,ln,rt,gc),PokerPlayer(fn,ln,s,r){}
	BadDude(const Person& pr,double rt=0.0,int gc=0,int s=1,int r=1)
		:Person(pr),Gunslinger(pr,rt,gc),PokerPlayer(pr,s,r){}
	BadDude(const Gunslinger& gl,int s,int r)
		:Person(gl),Gunslinger(gl),PokerPlayer(gl,r,s){}
	BadDude(const PokerPlayer& pp,double rt=0,int gc=0)
		:Person(pp),Gunslinger(pp,rt,gc),PokerPlayer(pp){}
	//virtual ~BadDude();
	double Gdraw() const;
	Card Cdraw() const;
	void Set();
	void Show() const;
};


#endif /* PERSON_EX_H_ */
