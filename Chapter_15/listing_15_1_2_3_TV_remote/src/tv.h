/*
 * tv.h
 *
 *  Created on: 12 ���. 2019 �.
 *      Author: �������
 */

#ifndef TV_H_
#define TV_H_


class Tv
{
public:
	friend class Remote;//Remote ����� ������ � �������� ����� TV
	enum {Off,On};
	enum {MinVal,MaxVal=20};
	enum {Antenna,Cable};
	enum {TV,DVD};
	Tv(int s= Off,int mc=125):state(s),volume(5),
			maxchannel(mc),channel(2),mode(Cable),input(TV){}
	void onoff(){state=(state==On)?Off:On;}
	bool ison() const {return state==On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode(){mode=(mode==Antenna)?Cable:Antenna;}
	void set_input() {input=(input==TV)?DVD:TV;}
	void settings() const; //����������� ���� ��������
private:
	int state; //On bkb Off
	int volume;//���������� ������ ���������
	int maxchannel;//������������ ���������� �������
	int channel;//������� �����
	int mode;//�������� ��� ��������� �����������
	int input;//TV ��� DVD
};

class Remote
{
private:
	int mode; //���������� TV ��� DVD
public:
	Remote(int m=Tv::TV):mode(m){}
	bool volup(Tv& t) {return t.volup();}
	bool voldows(Tv& t) {return t.voldown();}
	void onoff(Tv& t) {t.onoff();}
	void chanup(Tv& t) {t.chanup();}
	void chandown(Tv& t) {t.chandown();}
	void set_chan(Tv& t,int c) {t.channel=c;}
	void set_mode(Tv& t) {t.set_mode();}
	void set_input(Tv& t) {t.set_input();}

};

#endif /* TV_H_ */
