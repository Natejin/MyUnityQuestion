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
	cout << "����Ʈ ������" << endl;
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
	cout << "����Ʈ �Ҹ���" << endl;
	Release();
}

void Point::Release()
{
	cout << "����" << endl;
}
