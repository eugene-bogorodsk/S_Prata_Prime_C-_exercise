/*
 * stckp1.h
 *
 *  Created on: 30 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef STCKP1_H_
#define STCKP1_H_

template <class Type>
class Stack
{
private:
	enum {SIZE =10};
	int stacksize;
	Type* item; //хранит элементы стэка
	int top; //индекс вершины стэка
public:
	explicit Stack(int ss=SIZE);
	Stack(const Stack& st);
	~Stack(){delete [] item;}
	bool isempty(){return top==0;}
	bool isfull(){return top ==stacksize;}
	bool push(const Type& item); //добавление item  стэк
	bool pop(Type& it); //выталкивание верхнего элемента в item
	Stack& operator=(const Stack& st);
};

template <class Type>
Stack<Type>::Stack(int ss):stacksize(ss),top(0)
{
	item = new Type [stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack& st)
{
	stacksize = st.stacksize;
	top=st.top;
	item = new Type[stacksize];
	for(int i = 0;i<top;i++)
		item[i]=st.item[i];
}

template <class Type>
bool Stack<Type>::push(const Type& it)
{
	if(top < stacksize)
	{
		item[top++]= it;
		return true;
	}
	else
		return false;
}

template <class Type>
bool Stack<Type>::pop(Type& it)
{
	if(top>0)
	{
		it = item[--top];
		return true;
	}
	else
		return false;
}

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st)
{
	if(this !=&st)
	{
		delete[] item;
		stacksize = st.stacksize;
		top = st.top;
		item = new Type [stacksize];
		for(int i = 0;i<top;i++)
			item[i]= st.item[i];
		return *this;
	}
}

#endif /* STCKP1_H_ */
