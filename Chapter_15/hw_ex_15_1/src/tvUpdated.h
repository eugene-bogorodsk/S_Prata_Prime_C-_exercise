/*
 * tvUpdated.h
 *
 *  Created on: 16 нояб. 2019 г.
 *      Author: Eugene
 */

#ifndef TVUPDATED_H_
#define TVUPDATED_H_

class Remote;
class Tv
{
	friend class Remote;//Remote TV
public:
	enum {Off,On};
	enum {MinVal,MaxVal=20};
	enum {Antenna,Cable};
	enum {TV,DVD};
	enum {IActive,Normal};
	Tv(int s= Off,int mc=125):state(s),volume(5),
			maxchannel(mc),channel(2),mode(Cable),input(TV),modeAc(Normal){}
	void onoff(){state=(state==On)?Off:On;}
	bool ison() const {return state==On;}
	bool volup();
	bool voldown();
	void buzz(Remote & r);//interactive mode
	void chanup();
	void chandown();
	void set_mode(){mode=(mode==Antenna)?Cable:Antenna;}
	void interactive(){if(state==On) modeAc=(modeAc==IActive)?Normal:IActive;}//added mode hw 15.1d
	void set_input() {input=(input==TV)?DVD:TV;}
	void settings() const; //display all settings
private:
	int state; //On or Off
	int volume;//selectable volume levels
	int maxchannel;//max number of channels
	int channel;//current channel
	int mode;//TV or Cable
	int input;//TV or DVD
	int modeAc;//normal or interactive mode (added)

};

class Remote
{
	friend class Tv;//hw15.1a
private:
	int mode; //select TV or DVD
	int modeAc;//interactive or normal mode hw15.1b
public:
	Remote(int m=Tv::TV,int a=Tv::Normal):mode(m),modeAc(a){}
	bool volup(Tv& t) {return t.volup();}
	bool voldows(Tv& t) {return t.voldown();}
	void onoff(Tv& t) {t.onoff();}
	void chanup(Tv& t) {t.chanup();}
	void chandown(Tv& t) {t.chandown();}
	void set_chan(Tv& t,int c) {t.channel=c;}
	void set_mode(Tv& t) {t.set_mode();}
	void set_input(Tv& t) {t.set_input();}
	void set_interactive(Tv& t){t.interactive();}//hw_15.1c

};

inline void Tv::buzz(Remote& r){ std::cout<<"Incorrect answer"<<std::endl;}


#endif /* TVUPDATED_H_ */
