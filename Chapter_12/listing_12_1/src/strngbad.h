/*������������� ����������� ������ ������
 * strngbad.h
 *
 *  Created on: 6 ����. 2019 �.
 *      Author: �������
 */

#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
private:
	char* str; //��������� �� ������
	int len;// ����� ������
	static int num_strings;//���������� �����
public:
	StringBad(const char* s);
	StringBad();//����������� �� ���������
	~StringBad();

	friend std::ostream& operator <<(std::ostream& os,const StringBad& st);
};




#endif /* STRNGBAD_H_ */
