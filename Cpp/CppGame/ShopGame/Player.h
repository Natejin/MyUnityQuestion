#pragma once
#include "Unit.h"

namespace ShopGame {
	class Player : public Unit
	{
	private:
		int money;
	public:
		virtual void Initiate();
		bool UseMoney(int money);
		bool AddMoney(int money);
		bool LoseMoney(int money);
	};

}


