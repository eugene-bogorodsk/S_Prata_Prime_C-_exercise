//============================================================================
// Name        : sc_ex_10_vect-list.cpp
// Author      : 
// Version     :using list instead of vector (see listing 16.9)
// Copyright   : Your copyright notice
// Description :execise 10
//============================================================================

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

struct Review{
	std::string title;
	int rating;
};
bool operator < (const Review& r1,const Review& r2);
bool worseThen(const Review& r1,const Review& r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main() {
	using namespace std;
	list<Review> books;//replace vector with list
	Review temp;
	while(FillReview(temp))
		books.insert(books.end(),temp);
	if(books.size()>0)
	{
		cout<<"Thank you. You entered the following"
				<<books.size()<<"Ratings:\n"
				<<"Rating\tBook\n";
		for_each(books.begin(),books.end(),ShowReview);
		books.sort();
		cout<<"Sortrd by title:\nRating'tBook\n";
		//list of books sorted by title
		for_each(books.begin(),books.end(),ShowReview);
		books.sort();// replacing sort() function with embedded one
		cout<<"Sorted by rating:\nRating\tBook\n";
		//list of book sorted by rating
		for_each(books.begin(),books.end(),ShowReview);
		//copy to vector and backward for use of random_shuffle()
		vector<Review> temp(books.size());
		copy(books.begin(),books.end(),temp.begin());
		random_shuffle(temp.begin(),temp.end());
		copy(temp.begin(),temp.end(),books.begin());
		cout<<"After shuffling:\nRating\tBook\n";
		//list of books after mix
		for_each(books.begin(),books.end(),ShowReview);
	}
	else
		cout<<"No entries.";
	cout<<"Bye.\n";
	return 0;
}

bool operator<(const Review& r1,const Review& r2)
{
	if(r1.title<r2.title)
		return true;
	else if(r1.title==r2.title && r1.rating<r2.rating)
		return true;
	else return false;
}
bool worseThen(const Review& r1,const Review& r2)
{
	if(r1.rating<r2.rating)
		return true;
	else
		return false;
}
bool FillReview(Review& rr)
{
	std::cout<<"Enter book title(quit to quit):";
	std::getline(std::cin,rr.title);
	if(rr.title=="quit")
		return false;
	std::cout<<"Enter book rating: ";
	std::cin>>rr.rating;
	if(!std::cin)
		return false;
	while(std::cin.get()!='\n')
		continue;
	return true;
}
void ShowReview(const Review& rr)
{
	std::cout<<rr.rating<<"\t"<<rr.title<<std::endl;
}
