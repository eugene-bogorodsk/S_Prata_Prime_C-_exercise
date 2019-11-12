//============================================================================
// Name        : person_ex.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <algorithm>
#include "person_ex.h"
using std::cout;
using std::endl;

//методы Person
Person::~Person(){}

void Person:: Data() const
{
	cout<<"Full name: "<<first_name<<" "<<"Last_name: "<<last_name<<endl;
}
void Person::Get()
{
	cout<<"First name: "<<endl;
	std::getline(std::cin,first_name);
	cout<<"Last name: "<<endl;
	std::getline(std::cin,last_name);
	//while(std::cin.get() != '\n')
	//	continue;
}

//методы Gunslinger
void Gunslinger::Data() const
{
	cout<<"Time's ready is "<<ready_time<<endl;
	cout<<"The number of gun's cuts are "<<gun_cuts<<endl;
}
void Gunslinger::Get()
{
	cout<<"Enter time's ready: ";
	std::cin>>ready_time;
	cout<<"Enter gun's cuts: ";
	std::cin>>gun_cuts;
	while(std::cin.get() != '\n')
		continue;
}

void Gunslinger::Set()
{
	cout<<"Enter Gunslinger's dates: "<<endl;
	Person::Get();
	Get();
}
void Gunslinger:: Show() const
{
	cout<<"Dates of Gunslinger: "<<endl;
	Person::Data();
	Data();
}

//Card's methods

std::ostream& operator<<(std::ostream& os, const Card& a_card)
{
	//const string RANKS[]= {"0","A","2","3","4","5","6","7",
	//		"8","9","10","J","Q","K"};
	//
	const string SUITS[]={"C","D","H","S"};
	os<<Card::suit_set[a_card.m_suit]<<" "<<Card::rank_set[a_card.m_rank];
	return os;
}

//PokerPlayer's methods
void PokerPlayer::Data() const
{
	cout<<"You've drawn the "<<m_card<<" card"<<endl;//показывает карту которую вытащил
}
/*
Card& Card::Get()

{
	std::vector<Card*> deck(52);
	for(int s= Card::CLUBS;s <= Card::SPADES;++s)
	{
		for(int r = Card::ACE; r <= Card::KING; ++r)
		{
			Card* pcard = new Card(static_cast<Card::rank>(r),static_cast <Card::suit>(s));
			deck.push_back(pcard);
		}
	}

	random_shuffle(deck.begin(),deck.end());

	//deck.pop_back();
	return (*deck.back());
}
*/

Card PokerPlayer::Draw() const
{
	return m_card;
}

string Card:: suit_set[Card::STypes]={"CLUBS","DIAMONDS","HEARTS","SPADES"};
string Card::rank_set[Card::RTypes]={"ACE","TWO","THREE","FOUR","FIVE","SIX",
		"SEVEN","EIGHT","NINE","TEN","JACK","QUEEN","KING"};

void PokerPlayer::Get()
{
	int _suit,_rank,i;
	cout<<"Enter number for suit of Poker Player's card: "<<endl;
	for(i=0;i<STypes;i++)
		cout<<i<<": "<<m_card.Get_Suit(i)<<" ";
	std::cin>>_suit;
	cout<<"\nEnter number for rank of Poker Player's card: "<<endl;
	for (i= 0;i<RTypes;i++)
	{
		cout<<i<<": "<<m_card.Get_Rank(i)<<" ";
		if(i%4 ==3)
			cout<<endl;
	}
	if(i%4 !=0 )
		cout<<'\n';
	std::cin>>_rank;
	m_card = Card(_suit,_rank);
}
void PokerPlayer::Set()
{
	cout<<"Enter pokerplayer dates: "<<endl;
	Person::Get();
	Get();
}
void PokerPlayer::Show() const
{
	cout<<"Pokerplayer's dates: "<<endl;
	Person::Data();
	Data();
}

//BadDude's methods
void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
}
void BadDude::Get()
{
	Gunslinger::Get();
	PokerPlayer::Get();
}

double BadDude:: Gdraw() const
{
	return Gunslinger::Draw();
}
Card BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}
void BadDude::Set()
{
	cout<<"Enter bad dude's dates: "<<endl;
	Person::Get();
	Get();
}
void BadDude::Show() const
{
	cout<<"Bad dude's dates: ";
	Person::Data();
	Data();
}
