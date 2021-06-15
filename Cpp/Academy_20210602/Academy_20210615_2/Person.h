#pragma once
#include <iostream>

using namespace std;

class Person
{
private:
	string name;
	int birthYear;

public:
	Person(string name, const int year);
	~Person();

	void Print();
};

