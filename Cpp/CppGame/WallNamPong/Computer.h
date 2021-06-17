#pragma once
#include "Unit.h"


namespace WallNamPong {
	class Computer : public Unit
	{
	public:
		Computer(const int money) :Unit(money) {};
		virtual void Win(int money) {
			cout << "당신은 졌습니다. 베팅금은 컴퓨터가 가져갑니다." << endl;
			this->money += money;
		}


	};

}