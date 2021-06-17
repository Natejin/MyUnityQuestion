#pragma once
#include "Item.h";

namespace ShopGame {
	
	class Item_Equip : public Item
	{
	protected:
		int levelOfReinforcement;
		int durability;

	public:
		virtual void Initiate() = 0;
	};
}
