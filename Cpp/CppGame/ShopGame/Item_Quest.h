
#pragma once
#include "Item.h";

namespace ShopGame {

	class Item_Quest : public Item
	{
	protected:
		int levelOfReinforcement;
		int durability;

	public:
		virtual void Initiate() = 0;
	};
}
