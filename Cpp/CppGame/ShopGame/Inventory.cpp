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
		cout <<"�������� ����ִ���" << GetItemHoldingAmount() << "," << GetMaxSize() << endl;
		//�κ��丮�� ����
		if (currentItemHoldingAmount == maxSlotAmount)
		{
			GameManager::Instance()->AddErrorCode(ErrorCode::ERROR_Inventory_IsFull);
			return;
		}
		//�κ��丮�� ������ �ִ� �������� �κ��丮�� �����Ҽ��ִ� �ִ�ġ�� ����
		if (currentItemHoldingAmount > maxSlotAmount)
		{
			GameManager::Instance()->AddErrorCode(ErrorCode::ERROR_Inventory_ItemCountMoreThanInventorySize);
			return;
		}
		for (int i = 0; i < itemSlots.size(); i++)
		{
			if (itemSlots[i]->isEmpty())
			{
				cout << i << "���� ���Կ� ����" << endl;
				itemSlots[i]->AddToSlots(item);
				currentItemHoldingAmount++;
				return;
			}
		}

		//���θ𸦿���
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

	//���õ� ItemSlot���� ������ �ΰ��� ��ȯ�Ѵ�
	void Inventory::SwapItem(int slot1, int slot2)
	{
		if (slot1 < 0 || slot1 >= maxSlotAmount || slot2 < 0 || slot2 >= maxSlotAmount)
		{
			return;
		}
		itemSlots[slot1]->Swap(itemSlots[slot2]);
	}
}