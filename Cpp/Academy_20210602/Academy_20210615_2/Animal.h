#pragma once

#include <iostream>

using namespace std;
class Animal
{
public :
	void Speak() {
		cout << "�ִϸ��� �θ�Ŭ����!!!" << endl;
	}
};

class Dog : public Animal
{
public:
	void Speak() {
		Animal::Speak(); //�θ� �θ���
		cout << "���� �ڽ�Ŭ������ ���� �� ��" << endl;
	}
};

