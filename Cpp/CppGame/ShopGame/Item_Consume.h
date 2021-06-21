#pragma once
#include "Item.h";

namespace ShopGame {

	class Item_Consume : public Item

	{
	protected:
		

	public:
		virtual void Initiate() {};
		virtual Item_Consume* Duplicate() {};
		virtual void UseItem() {};
	};
}
