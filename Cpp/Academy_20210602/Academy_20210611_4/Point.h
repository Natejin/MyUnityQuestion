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

	//멤버변수값을 변경하지않겠다.
	void Print()const { 
		//sum = 2; // 이함수내에서는 멤버 변수값을 변경하지않겠다.
		//a(); //const함수내에서 const가 아닌 함수의 호출이 제한된다.
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


