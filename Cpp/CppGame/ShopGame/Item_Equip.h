#pragma once
#include "Item.h";

namespace ShopGame {
	
	class Item_Equip : public Item
	{
	protected:
		int elementDamage;

	public:
		virtual void Initiate() {};
		virtual Item_Equip* Duplicate() {};
		virtual void UseItem() {};

		
	};
}
