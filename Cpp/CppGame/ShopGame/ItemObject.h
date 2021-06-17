#pragma once
#include "Object.h"


namespace ShopGame {
	class ItemObject : public Object
	{
		ITEMTYPE itemType;
	public:
		ItemObject() {};
		~ItemObject() {};
		ItemObject(const ITEMTYPE type, const int& code) : Object(code){}
		

	};

}