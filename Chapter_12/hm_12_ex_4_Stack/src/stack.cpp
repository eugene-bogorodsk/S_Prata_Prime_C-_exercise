//============================================================================
// Name        : stack.cpp
// Author      : eugene
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stack.h"

Stack::Stack(int n):
pitems(new Item[n]),size(n),top(0){}


Stack::Stack(const Stack& st)
{
	pitems = new Item[st.size];
	for(int i = 0 ;i < st.size;++i)
		pitems[i]=st.pitems[i];
	size= st.size;
	top= st.top;
}

Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack:: push(const Item& it)
{
	if(top < MAX)
	{
		pitems[top++]= it;
		return true;
	}
	else
		return false;
}
bool Stack::pop(Item& it)
{
	if(top>0)
	{
		it = pitems[--top];
		return true;
	}
	else
		return false;
}

Stack& Stack::operator =(const Stack& st)
{
	if(this != &st)
	{
		delete [] pitems;
		for(int i = 0; i<st.size;++i)
			*(pitems+i)=(*
					st.pitems+i);
		size= st.size;
		top = st.top;
	}
	return *this;
}
