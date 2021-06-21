#pragma once
#include "Unit.h"

namespace WallNamPong {
	class Player : public Unit
	{
	public:

		Player(const int money) :Unit(money) {};
		virtual void Win(int money) {
			cout << "����� �̰���ϴ�. ���ñ��� �����ɴϴ�." << endl;
			this->money += money;
		}
	};


}
