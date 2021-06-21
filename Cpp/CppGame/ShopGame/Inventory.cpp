#include "Inventory.h"
#include "GameManager.h"
namespace ShopGame {

	Inventory::Inventory()
	{

	}

	Inventory::Inventory(int size)
	{
		itemSlots = map<int, ItemSlot*>();
		maxSlotAmount = size;
		currentItemHoldingAmount = 0;
		
		for (size_t i = 0; i < size; i++)
		{
			itemSlots.insert({ i, new ItemSlot(i) });
		}
	}

	Inventory::~Inventory()
	{
		for (size_t i = 0; i < itemSlots.size(); i++)
		{
			delete itemSlots[i];
		}
	}

	void Inventory::CheckFullInventory()
	{
	}

	void Inventory::AddItem(Item* item)
	{
		cout <<"아이템을 집어넣는중" << GetItemHoldingAmount() << "," << GetMaxSize() << endl;
		//인벤토리가 꽉참
		if (currentItemHoldingAmount == maxSlotAmount)
		{
			GameManager::Instance()->AddErrorCode(ErrorCode::ERROR_Inventory_IsFull);
			return;
		}
		//인벤토리가 가지고 있는 아이템이 인벤토리가 보유할수있는 최대치를 넘음
		if (currentItemHoldingAmount > maxSlotAmount)
		{
			GameManager::Instance()->AddErrorCode(ErrorCode::ERROR_Inventory_ItemCountMoreThanInventorySize);
			return;
		}
		for (int i = 0; i < itemSlots.size(); i++)
		{
			if (itemSlots[i]->isEmpty())
			{
				cout << i << "번쨰 슬롯에 넣음" << endl;
				itemSlots[i]->AddToSlots(item);
				currentItemHoldingAmount++;
				return;
			}
		}

		//원인모를에러
		GameManager::Instance()->AddErrorCode(ErrorCode::ERROR_Inventory_Unknown);
	}
	void Inventory::RemoveItem(int index, Item* reciveItem)
	{
		if (0 <= index && index < itemSlots.size())
		{
			itemSlots[index]->RemoveFromSlots();
			currentItemHoldingAmount--;
		}
	}

	//선택된 ItemSlot내의 아이템 두개를 교환한다
	void Inventory::SwapItem(int slot1, int slot2)
	{
		if (slot1 < 0 || slot1 >= maxSlotAmount || slot2 < 0 || slot2 >= maxSlotAmount)
		{
			return;
		}
		itemSlots[slot1]->Swap(itemSlots[slot2]);
	}
}