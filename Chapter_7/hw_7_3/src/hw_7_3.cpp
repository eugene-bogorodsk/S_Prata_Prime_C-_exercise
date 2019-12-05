//============================================================================
// Name        : hw_7_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : box structure
//============================================================================

#include <iostream>
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show( box );
void rebuild(box * );
int main() {
	using namespace std;
	box maker1 {"Pat",15.0,20.1,10.5,200.0};
	cout<<"Initial box dates: \n";
	show(maker1);
	cout<<"Dates of maker1 after changes of volume: \n";
	rebuild(&maker1);
	show(maker1);
	return 0;
}
void show(box bx)
{
	std::cout<<"Name of maker: "<<bx.maker<<std::endl;
	std::cout<<"height: "<<bx.height<<", "<<"width: "<<bx.width<<", "<<"length: "<<bx.length
			<<", "<<"volume: "<<bx.volume<<std::endl;
}
void rebuild(box * bx)
{
	bx->volume=bx->height*bx->width*bx->length;
}
