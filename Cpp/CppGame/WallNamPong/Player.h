#pragma once
#include "Unit.h"

class Player : public Unit
{
public:

	Player(const int money) :Unit(money) {};
	virtual void Win(int money) {
		cout << "당신은 이겼습니다. 베팅금을 가져옵니다." << endl;
		this->money += money;
	}
};

