#include "Student.h"
Student::Student(string name, const int year, string university)
	:Person(name, year)
{
	this->university = university;

}

Student::~Student() {}

void Student::Print()
{
	Person::Print();
	cout << "ÇÐ±³ : " << university << endl;
}

