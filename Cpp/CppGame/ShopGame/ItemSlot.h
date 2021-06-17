#pragma once
#include "ItemObject.h"
#include "Slot.h"
namespace ShopGame {
	class ItemSlot : public Slot
	{
	private:
		ItemObject* item;
	public:
		ItemSlot():item(nullptr){}
		~ItemSlot() {}
		ItemSlot(int index);
		void AddItem(ItemObject& item);
		ItemObject& RemoveItem();
	};
}

