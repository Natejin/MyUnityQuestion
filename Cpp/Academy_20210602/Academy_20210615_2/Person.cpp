#include "Person.h"

Person::Person(string name, const int year)
{
	this->name = name;
	this->birthYear = year;
}

Person::~Person()
{
}

void Person::Print()
{
	cout << "이름 : " << name << endl;
	cout << "태어난 날 : " << birthYear << endl;
}
