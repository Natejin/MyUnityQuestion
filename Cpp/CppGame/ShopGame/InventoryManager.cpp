#include "InventoryManager.h"
namespace ShopGame {
	InventoryManager::InventoryManager()
	{
		for (size_t i = 0; i < ItemTypeCount; i++)
		{
			inventorys[i] = new Inventory();
		}
	}
	void InventoryManager::AddItem(ItemObject& item)
	{
		inventorys[item]
	}
	void InventoryManager::RemoveItem(int itemType, int index)
	{

	}
	void InventoryManager::ChangeItemSlot(ItemObject item1, ItemObject item2)
	{

	}
}