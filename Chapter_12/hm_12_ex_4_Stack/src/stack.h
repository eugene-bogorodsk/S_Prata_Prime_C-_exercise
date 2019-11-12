/*
 * stack.h
 *
 *  Created on: 17 ����. 2019 �.
 *      Author: �������
 */

#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX=10};
	Item* pitems; // ������ �������� � �����
	int size;// ���������� ��������� � �����
	int top;// ������ ��� �������� �������� �����
public:
	Stack(int n= 10); //������� ���� � ������� ����������
	Stack(const Stack& );
	Item getItem(int x){return pitems[x];}
	~Stack();
	bool isempty() const;
	bool isfull() const;
	//push() ���������� �������� false, ���� ���� ��� ������
	// � true � ��������� ������
	bool push(const Item& ); //���������� �������� � ����
	//pop() ���������� false ���� ���� ��� ������ �
	// � true � ��������� ������
	bool pop(Item& 	);//���������� �������� �� �����
	Stack& operator=(const Stack& );
};



#endif /* STACK_H_ */
