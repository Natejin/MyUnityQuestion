#include "Point.h"



Car::Car() {
	speed = 0;
	gear = 0;
	color = "";
}
void Car::CurrentSpeedPrint() {
	cout << speed << endl;
}

void Car::SpeedUp() {
	speed += 10;
}
void Car::SpeedDown() {
	speed -= 10;
}
void Car::SetColor(string _colorStr) {
	color = _colorStr;
}

Point::Point()
{
	cout << "포인트 생성자" << endl;
	sum = 0;
	x = 0;
	y = 0;
}

Point::Point(const int& xpos, const int& ypos)
{
	x = xpos;
	y = ypos;
}

Point::~Point()
{
	cout << "포인트 소멸자" << endl;
	Release();
}

void Point::Release()
{
	cout << "히힝" << endl;
}
