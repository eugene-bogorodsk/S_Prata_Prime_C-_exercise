/*
 * stacktp.h
 *
 *  Created on: 1 ���. 2019 �.
 *      Author: �������
 */

#ifndef STACKTP_H_
#define STACKTP_H_

template <class Type>
class Stack
{
private:
	enum {SIZE =10};
	int stacksize;
	Type* item; //������ �������� �����
	int top; //������ ������� �����
public:
	explicit Stack(int ss=SIZE);
	Stack(const Stack& st);
	~Stack(){delete [] item;}
	bool isempty(){return top==0;}
	bool isfull(){return top ==stacksize;}
	bool push(const Type& item); //���������� item  ����
	bool pop(Type& it); //������������ �������� �������� � item
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




#endif /* STACKTP_H_ */
