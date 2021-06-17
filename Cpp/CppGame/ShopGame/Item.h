#pragma once
#include "Enum.h"

namespace ShopGame {
	class Item
	{
		ITEMTYPE itemType;
	public:
		Item() {};
		~Item() {};
		virtual void UseItem() = 0;
		virtual void Initiate() = 0;
		ITEMTYPE GetItemType() { return itemType; };

	private:

	};

}