/*
 * stonewt1.h
 *
 *  Created on: 23 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef STONEWT1_H_
#define STONEWT1_H_

class Stonewt
{
private:
	enum {Lbs_per_stn = 14};//фунтов на стоун
	int stone;//полных стоунов
	double pds_left;//дробное число фунтов
	double pounds; //общий вид в фунтах
public:
	Stonewt(double lbs); //конструктор для значения double фунтов
	Stonewt(int ,double); //конструктор для значения в стоунах и фунтах
	Stonewt(); //конструктор по умолчанию
	~Stonewt();
	void show_lbs() const; //отображение веса в формате фунтов
	void show_stn() const; //отображение веса в формате стоунов
	//функции преобразования
	operator int() const;
	operator double() const;
	//функция член для умножения
	Stonewt operator* (double ) const;
	friend Stonewt operator*(double , const Stonewt& );
};


#endif /* STONEWT1_H_ */
