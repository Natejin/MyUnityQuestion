#pragma once
#include "Unit.h"


namespace WallNamPong {
	class Computer : public Unit
	{
	public:
		Computer(const int money) :Unit(money) {};
		virtual void Win(int money) {
			cout << "����� �����ϴ�. ���ñ��� ��ǻ�Ͱ� �������ϴ�." << endl;
			this->money += money;
		}


	};

}