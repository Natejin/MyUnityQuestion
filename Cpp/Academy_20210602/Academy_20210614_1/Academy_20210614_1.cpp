// Academy_20210614_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Time.h"
#include "Student.h"
#include "Sample.h"

class Person {
private:
	int age;
public:
	Person(int a) : age(a) {};
	void SetAge(int age) { this->age = age; }
	int GetAge() { return age; }
};


int main()
{
	/*Time t = Time(3,5);
	t.Print();
	Student s = Student(50, 70, 90);
	s.Print();
	*/

	//Sample s;
	//s.SetScore(10);
	//cout << s.GetScoure() << endl;

	/*���������:
	������ Ŭ������ ��ü�� �����Ͽ� �����Ҷ� ����ϴ� ������;
	�Ϲ����� ��쿡�� ���� �����ڸ� ������ �ʿ䰡 ����.*/
	Person kim(21);
	Person clone(kim);
	cout << "Ŵ�� ���� : " << kim.GetAge() << endl;
	cout << "Ŭ���� ���� : " << clone.GetAge() << endl;
}



