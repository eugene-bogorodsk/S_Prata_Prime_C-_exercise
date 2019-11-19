//============================================================================
// Name        : vect3mod3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
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
	vector<Review> books;
	Review temp;
	while(FillReview(temp))
		books.push_back(temp);
	if(books.size()>0)
	{
		cout<<"Thank you. You entered the following"
				<<books.size()<<"Ratings:\n"
				<<"Rating\tBook\n";
		for_each(books.begin(),books.end(),ShowReview);
		sort(books.begin(),books.end());
		cout<<"Sortrd by title:\nRating'tBook\n";
		//list of books sorted by title
		for_each(books.begin(),books.end(),ShowReview);
		sort(books.begin(),books.end());
		cout<<"Sorted by rating:\nRating\tBook\n";
		//list of book sorted by rating
		for_each(books.begin(),books.end(),ShowReview);
		random_shuffle(books.begin(),books.end());
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
