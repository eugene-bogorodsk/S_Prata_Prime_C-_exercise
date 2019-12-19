//============================================================================
// Name        : cpmv.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : hw_18.2
//============================================================================

#include <iostream>
class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info * pi;
public:
	Cpmv();
	Cpmv(std::string q,std::string z);
	Cpmv(const Cpmv & cp);
	Cpmv(Cpmv && mv);
	~Cpmv();
	Cpmv & operator = (const Cpmv & cp);
	Cpmv & operator = (Cpmv && mv);
	Cpmv operator + (const Cpmv & obj) const;
	void Display() const;
};

int main() {
	using namespace std;
	Cpmv one({"12458","003456"});
	Cpmv two = one;
	Cpmv three({"anna","olga"});
	Cpmv four(one+three);
	cout<<"ovject one:\n";
	one.Display();
	cout<<"object two:\n";
	two.Display();
	cout<<"object three:\n";
	three.Display();
	cout<<"object four:\n";
	four.Display();

	return 0;
}
Cpmv::Cpmv()
{
	pi=new Info({"0","0"});
}

Cpmv::Cpmv(std::string q,std::string z)
{
	pi= new Info({q,z});

}
Cpmv::Cpmv(const Cpmv & cp)
{
	pi=new Info;
	pi->qcode=cp.pi->qcode;
	pi->zcode=cp.pi->zcode;

}
Cpmv::Cpmv(Cpmv && mv)
{
	//pi=new Info;
	pi=mv.pi;
	mv.pi=nullptr;
}
Cpmv::~Cpmv()
{
	std::cout<<"Delete Cpmv"<<std::endl;
	delete pi;
}
Cpmv &Cpmv :: operator = (const Cpmv & cp)
{
	if(this != &cp)
	{
		delete pi;
		pi=new Info({cp.pi->qcode,cp.pi->zcode});
	}
	return *this;
}
Cpmv & Cpmv:: operator = (Cpmv && mv)
{
	if (this !=& mv)
	{
		delete pi;
		pi=mv.pi;
		mv.pi=nullptr;
	}
	return *this;
}
Cpmv Cpmv:: operator + (const Cpmv & obj) const
{
	Cpmv temp=Cpmv(pi->qcode+obj.pi->qcode,pi->zcode+obj.pi->zcode);
	return temp;

}
void Cpmv:: Display() const
{
	std::cout<<pi->qcode<<" "<<pi->zcode<<std::endl;
	std::cout<<"Data addresses: "<<(void*) pi<<'\n';
}
