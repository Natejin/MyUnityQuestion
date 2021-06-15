#pragma once

#include "Person.h"
class Student: public Person
{
private:
	string university;
public:
	Student(string name, const int year, string university);
	~Student();

	void Print();
};

