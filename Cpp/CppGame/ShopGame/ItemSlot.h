#pragma once
#include "Item.h"
#include "Slot.h"
namespace ShopGame {
	class ItemSlot : public Slot<Item>
	{
	private:
	public:
		ItemSlot() :Slot<Item>() {};
		~ItemSlot() {};
		ItemSlot(int index) :Slot<Item>(index) {};
		void AddToSlots(Item* _object);
		void RemoveFromSlots();
		//Item* GetComponent() { return component; }

		void Swap(ItemSlot* slot2);

		void SetComponent(Item* component);
	};
}

