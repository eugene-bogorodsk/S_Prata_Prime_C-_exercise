/* ������� �������� � ��������� �������
 * coordin.h
 *
 *  Created on: 4 ����. 2019 �.
 *      Author: �������
 */

#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
	double distance;// ���������� �� �������� �����
	double angle;// ����������� �� �������� �����
};

struct rect
{
	double x; //���������� �� ����������� �� �������� �����
	double y; // ���������� �� ��������� �� �������� �����
};

// ���������
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);


#endif /* COORDIN_H_ */
