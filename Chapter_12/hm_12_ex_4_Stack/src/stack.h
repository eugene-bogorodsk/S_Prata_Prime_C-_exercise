/*
 * stack.h
 *
 *  Created on: 17 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX=10};
	Item* pitems; // хранит элементы в стеке
	int size;// количество элементов в стэке
	int top;// индекс для верхнего элемента стэка
public:
	Stack(int n= 10); //создает стэк с десятью элементами
	Stack(const Stack& );
	Item getItem(int x){return pitems[x];}
	~Stack();
	bool isempty() const;
	bool isfull() const;
	//push() возвращает значения false, если стек уже полный
	// и true в противном случае
	bool push(const Item& ); //добавление элемента в стэк
	//pop() возвращает false если стэк уже пустой и
	// и true в противном случае
	bool pop(Item& 	);//извлечение элемента из стэка
	Stack& operator=(const Stack& );
};



#endif /* STACK_H_ */
