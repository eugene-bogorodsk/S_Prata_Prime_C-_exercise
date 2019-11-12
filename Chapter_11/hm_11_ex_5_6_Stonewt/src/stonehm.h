/*
 * stonehm.h
 *
 *  Created on: 25 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef STONEHM_H_
#define STONEHM_H_

class Stonewt
{
public:
	enum Mode {STONE,INT_POUNDS,FLOAT_POUNDS};//установка состояния принимаемых данных
private:
	enum {Lbs_per_stn = 14};//фунтов на стоун
	int stone;//полных стоунов
	double pds_left;//дробное число фунтов
	double pounds; //общий вид в фунтах
	Mode mode;
public:
	Stonewt(double lbs,Mode m = FLOAT_POUNDS); //конструктор для значения double фунтов
	Stonewt(int lbs,Mode m = INT_POUNDS); //конструктор для значения double фунтов
	Stonewt(int st,double lbs,Mode m = STONE); //конструктор для знаений  в стоунах
	Stonewt(); //конструктор по умолчанию
	~Stonewt();
	//void show_lbs() const; //отображение веса в формате фунтов
	//void show_stn() const; //отображение веса в формате стоунов
	//функции преобразования
	operator int() const;
	operator double() const;
	//перегрузка операторов операций
	Stonewt operator +(const Stonewt&) const;
	Stonewt operator-(const Stonewt&) const;
	Stonewt operator*(const Stonewt&) const;
	Stonewt operator* (double ) const;
	Stonewt change_mode(Mode m);
	friend std::ostream& operator<<(std::ostream& , const Stonewt& );
	friend Stonewt operator*(double , const Stonewt& );
	friend bool operator ==(const Stonewt&,const Stonewt&);
	friend bool operator !=(const Stonewt&,const Stonewt&);
	friend bool operator <(const Stonewt&,const Stonewt&);
	friend bool operator <=(const Stonewt&,const Stonewt&);
	friend bool operator >(const Stonewt&,const Stonewt&);
	friend bool operator >=(const Stonewt&,const Stonewt&);
};





#endif /* STONEHM_H_ */
