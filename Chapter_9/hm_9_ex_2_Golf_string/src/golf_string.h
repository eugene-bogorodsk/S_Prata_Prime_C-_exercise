/*
 * golf_string.h
 *
 *  Created on: 10 сент. 2019 г.
 *      Author: Евгений
 */
//#include<string>
#ifndef GOLF_STRING_H_
#define GOLF_STRING_H_
using std::string;

const int Len=40;
const int members = 10;
struct golf
{
	string fullname;
	int handicap;
};
void setgolf(golf& g,string& name,int hc);
int setgolf(golf& g);
void handicap(golf& g,int hc);
void showgolf(const golf& g);



#endif /* GOLF_STRING_H_ */
