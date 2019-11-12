/* содержит функции, вызываемые в main
 * functions_file.cpp
 *
 *  Created on: 4 сент. 2019 г.
 *      Author: ≈вгений
 */

#include <iostream>
#include<cmath>
#include "coordin.h"

//преобразование пр€моугольных координат в пол€рные
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;
	answer.distance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
	answer.angle=atan2(xypos.y,xypos.x);
	return answer; //возврат структуры polar
}

// отображение пол€рных координат с преборазование радиан в градусы
void show_polar(polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.2958;
	cout<<"distance = "<<dapos.distance;
	cout<<", angle = "<< dapos.angle*Rad_to_deg;
	cout<<" degrees\n";
}


