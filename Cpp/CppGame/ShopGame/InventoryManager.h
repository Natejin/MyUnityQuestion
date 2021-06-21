#pragma once
#include "Item.h"
#include "Manager.h"
#include "Inventory.h"



namespace ShopGame {
	class InventoryManager : public Manager
	{
		Inventory* inventorys[ItemTypeCount]; //크기 고정되어있으므로 배열 사용
		ITEMTYPE currentInventory;
		ItemSlot* selectedSlot;
		
	public:
		InventoryManager();
		~InventoryManager();

		//아이템 추가
		void AddItem(Item* item);

		//아이템 제거
		void RemoveItem(int itemType, int index, Item* item);

		//아이템 교환
		void SwapItem(int itemType, int slot1, int slot2);
		void SwapItem(int slot1, int slot2);

		//인벤토리의 가져오기
		Inventory* GetInventory(ITEMTYPE itemType) { return inventorys[(int)itemType]; }
		Inventory* GetInventory(int itemType) { return inventorys[itemType]; }

		//선택된 인벤토리의 가져오기
		Inventory* GetSelectedInventory() { return inventorys[(int)currentInventory]; }

		//선택된 인벤토리 타입의 가져오기
		ITEMTYPE GetInventoryType() { return currentInventory; }

		//선택된 인벤토리의 크기 가져오기
		int GetMaxSize(ITEMTYPE itemType) { return inventorys[(int)itemType]->GetMaxSize(); }
		int GetMaxSize(int itemType) { return inventorys[itemType]->GetMaxSize(); }
		int GetMaxSize() { return inventorys[(int)currentInventory]->GetMaxSize(); }

		//선택된 아이템의 수량 가져오기
		int GetItemHoldingAmount(ITEMTYPE itemType) { return inventorys[(int)itemType]->GetItemHoldingAmount(); }
		int GetItemHoldingAmount(int itemType) { return inventorys[itemType]->GetItemHoldingAmount(); }
		int GetItemHoldingAmount() { return inventorys[(int)currentInventory]->GetItemHoldingAmount(); }

		//인벤토리 선택
		void SelectInventory(ITEMTYPE itemType) { selectedSlot = nullptr; currentInventory = itemType; }
		void SelectInventory(int itemType) { selectedSlot = nullptr; currentInventory = (ITEMTYPE)itemType; }

		//슬롯 선택
		void SelectSlot(int slotIndex) { selectedSlot = inventorys[(int)currentInventory]->GetItemSlot(slotIndex);}
		
		//슬롯 선택 해체
		void UnselectSlot() {selectedSlot = nullptr; }

		//선택된 슬롯 가져오기
		ItemSlot* GetSelectedSlot() { return selectedSlot;}
	};

}