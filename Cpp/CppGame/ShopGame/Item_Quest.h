
#pragma once
#include "Item.h";

namespace ShopGame {

	class Item_Quest : public Item
	{
	protected:
		

	public:
		virtual void Initiate() {};
		virtual Item_Quest* Clone() {};
		virtual void UseItem() {};
	};
}
