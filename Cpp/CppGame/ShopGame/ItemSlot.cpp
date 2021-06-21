#include "ItemSlot.h"




namespace ShopGame {
	void ItemSlot::AddToSlots(Item* _object)
	{
		component = _object;
		empty = false;
	}
	void ItemSlot::RemoveFromSlots()
	{
		empty = true;
		component = nullptr;
	}

	void ItemSlot::SetComponent(Item* component)
	{
		if (component == nullptr)
		{
			this->component = nullptr;
			empty = true;
		}
		else {
			this->component = component;
			empty = false;
		}
	}


	void ItemSlot::Swap(ItemSlot* slot2)
	{

		//슬롯 1이 비어있음
		if (this->isEmpty())
		{
			//슬롯 2에 아이템이 존재함
			if (!slot2->isEmpty())
			{
				Item* temp = this->GetComponent();
				this->SetComponent(slot2->GetComponent());
				slot2->SetComponent(temp);
			}
			else {
				//TODO 슬롯이 두개다 비어있으므로 아무것도 하지않음
			}

		}
		//슬롯 1에 아이템이 존재하고 슬롯 2가 비어있음
		else if (slot2->isEmpty()) {
			Item* temp = this->GetComponent();
			this->SetComponent(slot2->GetComponent());
			slot2->SetComponent(temp);
		}
		//슬롯 두개 모두에 아이템이 존재함
		else {
			Item* temp = this->GetComponent();
			this->SetComponent(slot2->GetComponent());
			slot2->SetComponent(temp);
		}

	}
	
}