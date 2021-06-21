
#pragma once
#include "Item.h";

namespace ShopGame {

	class Item_Material : public Item
	{
	protected:
	

	public:
		virtual void Initiate() {};
		virtual Item_Material* Duplicate() {};
		virtual void UseItem() {};
	};
}
