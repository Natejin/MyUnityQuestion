#pragma once
#include "Time.h"
#include <iostream>

using namespace std;
class Time
{
private:
	int hour;
	int minute;
public:
	Time();
	Time(const int h, const int m);
	~Time();

	void Print();


};

