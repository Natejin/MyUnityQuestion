#pragma once
#include <map>
#include "ItemSlot.h"
#include "Item.h"
#include "Base.h"

namespace ShopGame {
	class Inventory
	{
	private:
		map<int,ItemSlot*> itemSlots;


		int maxSlotAmount;
		int currentItemHoldingAmount;
		bool fullInventory;
		void CheckFullInventory();
	public:
		Inventory();
		Inventory(int size);
		~Inventory();
		void AddItem(Item* item);
		void RemoveItem(int index,Item* item);

		void SwapItem(int slot1, int slot2);
		int GetItemHoldingAmount() {return currentItemHoldingAmount; }
		int GetMaxSize() { return maxSlotAmount; }
		ItemSlot* GetItemSlot(int index) { return itemSlots[index]; }
	};
}
