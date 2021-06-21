#pragma once
#include "Item.h"
#include "Manager.h"
#include "Inventory.h"



namespace ShopGame {
	class InventoryManager : public Manager
	{
		Inventory* inventorys[ItemTypeCount]; //ũ�� �����Ǿ������Ƿ� �迭 ���
		ITEMTYPE currentInventory;
		ItemSlot* selectedSlot;
		
	public:
		InventoryManager();
		~InventoryManager();

		//������ �߰�
		void AddItem(Item* item);

		//������ ����
		void RemoveItem(int itemType, int index, Item* item);

		//������ ��ȯ
		void SwapItem(int itemType, int slot1, int slot2);
		void SwapItem(int slot1, int slot2);

		//�κ��丮�� ��������
		Inventory* GetInventory(ITEMTYPE itemType) { return inventorys[(int)itemType]; }
		Inventory* GetInventory(int itemType) { return inventorys[itemType]; }

		//���õ� �κ��丮�� ��������
		Inventory* GetSelectedInventory() { return inventorys[(int)currentInventory]; }

		//���õ� �κ��丮 Ÿ���� ��������
		ITEMTYPE GetInventoryType() { return currentInventory; }

		//���õ� �κ��丮�� ũ�� ��������
		int GetMaxSize(ITEMTYPE itemType) { return inventorys[(int)itemType]->GetMaxSize(); }
		int GetMaxSize(int itemType) { return inventorys[itemType]->GetMaxSize(); }
		int GetMaxSize() { return inventorys[(int)currentInventory]->GetMaxSize(); }

		//���õ� �������� ���� ��������
		int GetItemHoldingAmount(ITEMTYPE itemType) { return inventorys[(int)itemType]->GetItemHoldingAmount(); }
		int GetItemHoldingAmount(int itemType) { return inventorys[itemType]->GetItemHoldingAmount(); }
		int GetItemHoldingAmount() { return inventorys[(int)currentInventory]->GetItemHoldingAmount(); }

		//�κ��丮 ����
		void SelectInventory(ITEMTYPE itemType) { selectedSlot = nullptr; currentInventory = itemType; }
		void SelectInventory(int itemType) { selectedSlot = nullptr; currentInventory = (ITEMTYPE)itemType; }

		//���� ����
		void SelectSlot(int slotIndex) { selectedSlot = inventorys[(int)currentInventory]->GetItemSlot(slotIndex);}
		
		//���� ���� ��ü
		void UnselectSlot() {selectedSlot = nullptr; }

		//���õ� ���� ��������
		ItemSlot* GetSelectedSlot() { return selectedSlot;}
	};

}