/*несовершенное определение класса строки
 * strngbad.h
 *
 *  Created on: 6 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
private:
	char* str; //указатель на строку
	int len;// длина строки
	static int num_strings;//количество строк
public:
	StringBad(const char* s);
	StringBad();//конструктор по умолчанию
	~StringBad();

	friend std::ostream& operator <<(std::ostream& os,const StringBad& st);
};




#endif /* STRNGBAD_H_ */
