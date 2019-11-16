/*
 * useUpdated.cpp
 *
 *  Created on: 16 нояб. 2019 г.
 *      Author: Eugene
 */


#include <iostream>
#include "tvUpdated.h"
int main()
{
	using std::cout;
	Tv s42;
	cout<<"Initial settings for 42\"TV:\n";//initial settings
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout<<"\nAdjusted settings for 42\"TV:\n"; //adjusting settings

	s42.settings();
	Remote grey;
	grey.set_chan(s42,10);
	grey.volup(s42);
	grey.volup(s42);
	grey.set_interactive(s42);//added at hw
	cout<<"\n42\" settings after using remote:\n"; //settings TV42 after using of Remote
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58,28);
	cout<<"\n58\" settings:\n";
	s58.settings();
	return 0;
}

