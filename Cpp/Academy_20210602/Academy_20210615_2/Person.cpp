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
	cout << "�̸� : " << name << endl;
	cout << "�¾ �� : " << birthYear << endl;
}
