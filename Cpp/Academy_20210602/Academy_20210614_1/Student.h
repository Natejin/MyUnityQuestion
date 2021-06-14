#pragma once

#include <iostream>

using namespace std;
class Student
{
private:
	int num;
	int score[3];
	double sum;
	double average;
public:
	Student();
	Student(const int s1, const int s2, const int s3);
	~Student();
	void Print();
	
};

