//============================================================================
// Name        : hw_16_10_price.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_16_10
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review{
	std::string title;
	double price;
	int rating;
};
typedef std::shared_ptr<Review> Rev;
bool operator < (const Rev& r1,const Rev& r2);
bool worseThen(const Rev& r1,const Rev& r2);
bool cheapBooks(const Rev& r1,const Rev& r2);
bool FillReview(Review& rr);
void ShowReview(const Rev & rr);


int main() {
	using namespace std;
	vector<shared_ptr<Review>> books;
	Review temp;
	while(FillReview(temp))
	{
		shared_ptr<Review> sp_temp(new Review(temp));
		books.push_back(sp_temp);
	}

	if(books.size()>0)
	{
		cout<<"Thank you. You entered the following "
				<<books.size()<<" Ratings:\n"
				<<"Rating\tBook\tPrice\n";
		for_each(books.begin(),books.end(),ShowReview);
		sort(books.begin(),books.end());

		cout<<"Sortrd by title:\nRating\tBook\tPrice\n";
		//list of books sorted by title
		for_each(books.begin(),books.end(),ShowReview);

		sort(books.begin(),books.end(),worseThen);
		cout<<"Sorted by rating:\nRating\tBook\tPrice\n";
		//list of book sorted by rating
		for_each(books.begin(),books.end(),ShowReview);

		sort(books.begin(),books.end(),cheapBooks);
		cout<<"Sorted by increase price:\nRating\tBook\tPrice\n";
		for_each(books.begin(),books.end(),ShowReview);

		sort(books.rbegin(),books.rend(),cheapBooks);
		cout<<"Sorted by decrease price:\nRating\tBook\tPrice\n";
		for_each(books.begin(),books.end(),ShowReview);
	}
	else
		cout<<"No entries.";
	cout<<"Bye.\n";
	return 0;
}
bool operator<(const Rev& r1,const Rev& r2)
{
	if(r1->title<r2->title)
		return true;
	else if(r1->title==r2->title && r1->rating<r2->rating)
		return true;
	else return false;
}
bool worseThen(const Rev& r1,const Rev& r2)
{
	if(r1->rating<r2->rating)
		return true;
	else
		return false;
}
bool cheapBooks(const Rev& r1,const Rev& r2)
{
	if(r1->price < r2->price)
		return true;
	else
			return false;
}
bool FillReview(Review& rr)
{
	std::cout<<"Enter book title(quit to quit):";
	std::string _title;
	std::getline(std::cin,_title);
	if(_title=="quit")
		return false;
	rr.title=_title;
	std::cout<<"Enter book rating: ";
	std::cin>>rr.rating;
	std::cout<<"Enter price:";
	std::cin>>rr.price;
	if(!std::cin)
		return false;
	while(std::cin.get()!='\n')
		continue;
	return true;
}
void ShowReview(const Rev& rr)
{
	std::cout<<rr->rating<<"\t"<<rr->title<<"\t"<<rr->price<<std::endl;
}

