#pragma once

#include <iostream>

using namespace std;
class Animal
{
public :
	void Speak() {
		cout << "애니멀은 부모클래스!!!" << endl;
	}
};

class Dog : public Animal
{
public:
	void Speak() {
		Animal::Speak(); //부모 부르기
		cout << "나는 자식클래스의 개다 왈 왈" << endl;
	}
};

