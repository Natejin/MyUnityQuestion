#include "Student.h"

Student::Student()
{
	cout << "나는 생성자" << endl;
	average = 0;
	sum = 0;
	for (size_t i = 0; i < 3; i++)
	{
		score[i] = 0;
	}
	for (size_t i = 0; i < 3; i++)
	{
		sum += score[i];
	}
	average = sum / 3;
}

Student::Student(const int s1, const int s2, const int s3)
{
	cout << "나는 생성자" << endl;
	average = 0;
	sum = 0;
	score[0] = s1;
	score[1] = s2;
	score[2] = s3;

	for (size_t i = 0; i < 3; i++)
	{
		sum += score[i];
	}
	average = sum / 3;
}

Student::~Student()
{
}

void Student::Print()
{
	cout << sum << "," << average << endl;
}
