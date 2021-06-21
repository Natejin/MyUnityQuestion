#include "InventoryManager.h"

namespace ShopGame {
	InventoryManager::InventoryManager()
	{
		for (size_t i = 0; i < ItemTypeCount; i++)
		{
			inventorys[i] = new Inventory(InventorySize);
		}
		currentInventory = (ITEMTYPE)0;
		selectedSlot = nullptr;
	}

	InventoryManager::~InventoryManager()
	{
		for (size_t i = 0; i < ItemTypeCount; i++)
		{
			delete inventorys[i];
		}
	}

	void InventoryManager::AddItem(Item* item)
	{
		inventorys[(int)item->GetItemType()]->AddItem(item);
	}
	void InventoryManager::RemoveItem(int inventoryType, int index, Item* item)
	{
		inventorys[(int)inventoryType]->RemoveItem(index, item);
	}
	void InventoryManager::SwapItem(int itemType, int slot1, int slot2)
	{
		inventorys[itemType]->SwapItem(slot1, slot2);
	}
	void InventoryManager::SwapItem(int slot1, int slot2)
	{
		inventorys[(int)currentInventory]->SwapItem(slot1, slot2);
	}
	
}