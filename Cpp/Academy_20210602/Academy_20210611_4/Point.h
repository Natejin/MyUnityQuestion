#pragma once

#include <iostream>
using namespace std;

class Point
{
	int sum = 0;
	int x;
	int y;
public:
	Point();
	Point(const int& xpos, const int& ypos);
	~Point();

	void a() {
		sum = 1;
	}

	void b() {
	
	}

	//����������� ���������ʰڴ�.
	void Print()const { 
		//sum = 2; // ���Լ��������� ��� �������� ���������ʰڴ�.
		//a(); //const�Լ������� const�� �ƴ� �Լ��� ȣ���� ���ѵȴ�.
	}

	void Release();
};

class Car {
private:
	int speed;
	int gear;
	string color;
public:
	Car();
	void SpeedUp();
	void SpeedDown();
	void SetColor(string _colorStr);
	void CurrentSpeedPrint();
};


