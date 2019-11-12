/*базовый класс для клуба по настольному теннису
 * tabtenn0.h
 *
 *  Created on: 10 сент. 2019 г.
 *      Author: Евгений
 */

#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>
using std::string;


//простой базовый класс
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer( const string & fn = "none",
				const string& ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const {return hasTable;};
	void ResetTable(bool v) {hasTable = v;};
};

//простой производный класс
class RatedPlayer:public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0,const string& fn = "none",
				const string& ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer& tp);
	unsigned Rating() const {return rating;}
	void ResetRating(unsigned r) {rating = r;}
};

#endif /* TABTENN0_H_ */
