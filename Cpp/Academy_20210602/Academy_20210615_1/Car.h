#pragma once
class Car
{
private:
	int speed;
public:
	void SetSpeed(const int value) { speed = value; };
	auto GetSpeed() { return speed; }
};


class SuperCar : public Car {
private:
	bool turbo;
public:
	void SetTurbo(const int value) { turbo = value; };
	auto GetTurbo() { return turbo; }

};