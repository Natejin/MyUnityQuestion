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

	/*복사생성자:
	동일한 클래스의 객체를 복사하여 생성할때 사용하는 생성자;
	일반적인 경우에는 복사 생성자를 정의할 필요가 없다.*/
	Person kim(21);
	Person clone(kim);
	cout << "킴의 나이 : " << kim.GetAge() << endl;
	cout << "클론의 나이 : " << clone.GetAge() << endl;
}



