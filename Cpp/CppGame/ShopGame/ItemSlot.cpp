#include "ItemSlot.h"




namespace ShopGame {

	ItemSlot::ItemSlot(int index)
		:Slot(index)
	{
		item = nullptr;
	}

	void ItemSlot::AddItem(ItemObject& item)
	{
		*(this->item) = item;
	}

	ItemObject& ItemSlot::RemoveItem()
	{
		return *(this->item);
	}
}