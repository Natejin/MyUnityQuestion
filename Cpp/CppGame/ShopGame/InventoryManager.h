#pragma once
#include "ItemObject.h"
#include "Manager.h"
#include "Inventory.h"


namespace ShopGame {
	class InventoryManager : public Manager
	{
		Inventory* inventorys[ItemTypeCount]; //크기 고정되어있으므로 배열 사용
	public:
		InventoryManager();
		~InventoryManager() {};
		void AddItem(ItemObject& item);
		void RemoveItem(int itemType, int index);
		void ChangeItemSlot(ItemObject item1, ItemObject item2);

	};

}