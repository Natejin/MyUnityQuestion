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
		//���õ� ������ ��������������
		if (!slot->isEmpty())
		{
			//���õȽ����� �����Ʈ�� 0�̻��ϰ�� ��ȯ (��������)
			if ((int)part >= 0)
			{
				//�� ��� ��ü
				UnequipToPlayer(part);

				//���â ���԰� ���õȽ����� ��ȯ
				equips->at((int)part)->Swap(slot);

				//�� ��� ����
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

