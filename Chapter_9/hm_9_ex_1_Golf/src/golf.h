
/*
 * golf.h
 *
 *  Created on: 5 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef GOLF_H_
#define GOLF_H_

const int Len=40;
const int members = 10;
struct golf
{
	char fullname[Len];
	int handicap;
};
void setgolf(golf& g,const char* name,int hc);
int setgolf(golf& g);
void handicap(golf& g,int hc);
void showgolf(const golf& g);




#endif /* GOLF_H_ */
