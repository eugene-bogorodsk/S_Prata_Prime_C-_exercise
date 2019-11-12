/*
 * dma.h
 *
 *  Created on: 18 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef DMA_H_
#define DMA_H_

#include <iostream>
// базовый класс использующий динамическое выделение памяти
class baseDMA
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l ="null",int r= 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	baseDMA& operator=(const baseDMA& );
	friend std::ostream& operator<<(std:: ostream& ,const baseDMA& );
};

//производный класс без динамического выделения памяти
//деструктор не нужен
class lacksDMA:public baseDMA
{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank",const char* l="null",int r= 0);
	lacksDMA(const char*c,const baseDMA& );
	friend std::ostream& operator<<(std::ostream& os,const lacksDMA& rs);
};

//производный класс с динамическим выделением памяти
class hasDMA: public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null",int r= 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& );
	~hasDMA();
	hasDMA& operator = (const hasDMA& );
	friend std::ostream& operator<<(std::ostream& os,const hasDMA& );
};

#endif /* DMA_H_ */
