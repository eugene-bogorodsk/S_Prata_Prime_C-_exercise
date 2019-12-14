/*
 * using.cpp
 *
 *  Created on: 10 дек. 2019 г.
 *      Author: Eugene
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <memory>
#include <iterator>
#include "employee.h"

int main(void)
{
	using std::cout;
	using std::endl;
	using std::cin;

	std::vector<std::shared_ptr<abstr_emp>> workers;
	std::shared_ptr<abstr_emp> temp;

	std::ifstream fin;
	fin.open("employee.txt");
	if (fin.is_open())
	{
		cout<<"The list of current empolyees:\n";
		int classtype;

			while (fin>>classtype)
			{
				fin.get();
				switch(classtype)
				{
				case abstr_emp::Employee:temp=std::make_shared<employee>();
						break;
				case abstr_emp::Manager: temp=std::make_shared<manager>();
						break;
				case abstr_emp::Fink: temp=std::make_shared<fink>();
						break;
				case abstr_emp::Highfink: temp=std::make_shared<highfink>();
				}
				temp->GetAll(fin,classtype);
				workers.push_back(temp);
			}
			fin.close();

			for (auto ob : workers) ob->ShowAll();
	}


	std::ofstream fout("employee.txt", std::ios::out | std:: ios::app);
	if(!fout.is_open())
	{
		std::cerr<<"Cant't open  employee.txt file for output.\n";
		exit(EXIT_FAILURE);
	}

	char choice;
	cout<<"Enter the category:\n"
			<<"e:emplployee m:manager f:fink h:highfink q:quit\n";

	cin>>choice;
	int size_of_workers=workers.size();
	while(choice != 'q')
	{
		while (strchr("emfhq",choice) == NULL)
		{
			cout<<"Please enter e, m, f, h, or q: ";
			cin>>choice;
		}
		if(choice == 'q')
			break;
		switch (choice)
		{
		case 'e':temp=std::make_shared<employee>();
				break;
		case 'm': temp=std::make_shared<manager>();
				break;
		case 'f': temp=std::make_shared<fink>();
				break;
		case 'h': temp=std::make_shared<highfink>();
		}

		temp->SetAll();
		workers.push_back(temp);
		cout<<"Enter the category:\n"
				<<"e:emplployee m:manager f:fink h:highfink q:quit\n";
		cin>>choice;
	}

	cout<<"New employees:\n";
	for (auto pr=workers.begin()+size_of_workers;pr !=workers.end();pr++)
	{
		(*pr)->ShowAll();
		(*pr)->WriteAll(fout);
	}

	fout.close();

	return 0;
}


