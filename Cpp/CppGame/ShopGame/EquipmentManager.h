#pragma once
#include "Manager.h"
#include "ItemSlot.h"

namespace ShopGame {
	class EquipmentManager : public Manager
	{
		vector<ItemSlot*>* equips;
		void UnequipToPlayer(EQUIPMENTPART part);
		void EquipToPlayer(Item* item);
	public:
		EquipmentManager();
		~EquipmentManager();

		void Equip(ItemSlot* item);
		vector<ItemSlot*>* GetEquips() { return equips; }
	};
}