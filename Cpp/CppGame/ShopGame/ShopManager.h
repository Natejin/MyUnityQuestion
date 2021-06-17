#pragma once
#include "Object.h"
#include "Manager.h"
#include "ItemSlot.h"

namespace ShopGame {
	class ShopManager : public Manager
	{
		map<int, ItemSlot> shopList;
	public:
		void Initiate();
		void BuyItem(int index);
		void SellItem(int index);

	};

}