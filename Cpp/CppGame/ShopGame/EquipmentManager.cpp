#include "EquipmentManager.h"
#include "GameManager.h"

namespace ShopGame {

	EquipmentManager::EquipmentManager()
	{
		equips = new vector<ItemSlot*>();
		equips->push_back(new ItemSlot((int)EQUIPMENTPART::WEAPON));
		equips->push_back(new ItemSlot((int)EQUIPMENTPART::TOP));
		equips->push_back(new ItemSlot((int)EQUIPMENTPART::BOTTOM));
		equips->push_back(new ItemSlot((int)EQUIPMENTPART::SHOES));
		equips->push_back(new ItemSlot((int)EQUIPMENTPART::ACCESSORIES));

	}
	EquipmentManager::~EquipmentManager()
	{
		for (size_t i = 0; i < equips->size(); i++)
		{
			delete equips->at(i);
		}
		delete equips;
	}



	void EquipmentManager::Equip(ItemSlot* slot)
	{
		EQUIPMENTPART part = slot->GetComponent()->GetEquipPart();
		//선택된 슬롯이 비어있지않을경우
		if (!slot->isEmpty())
		{
			//선택된슬롯의 장비파트가 0이상일경우 교환 (에러방지)
			if ((int)part >= 0)
			{
				//전 장비 해체
				UnequipToPlayer(part);

				//장비창 슬롯과 선택된슬롯을 교환
				equips->at((int)part)->Swap(slot);

				//현 장비 장착
				EquipToPlayer(equips->at((int)part)->GetComponent());
			}
		}
	}


	void EquipmentManager::UnequipToPlayer(EQUIPMENTPART part)
	{
		if (!equips->at((int)part)->isEmpty())
		{
			GameManager::Instance()->GetPlayer()->UnequipItem(equips->at((int)part)->GetComponent());
		}
		
	}
	void EquipmentManager::EquipToPlayer(Item* item)
	{
		if (item != nullptr)
		{
			GameManager::Instance()->GetPlayer()->EquipItem(equips->at((int)item->GetEquipPart())->GetComponent());
		}
	}
}

