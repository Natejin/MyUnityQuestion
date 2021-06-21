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

		//���� 1�� �������
		if (this->isEmpty())
		{
			//���� 2�� �������� ������
			if (!slot2->isEmpty())
			{
				Item* temp = this->GetComponent();
				this->SetComponent(slot2->GetComponent());
				slot2->SetComponent(temp);
			}
			else {
				//TODO ������ �ΰ��� ��������Ƿ� �ƹ��͵� ��������
			}

		}
		//���� 1�� �������� �����ϰ� ���� 2�� �������
		else if (slot2->isEmpty()) {
			Item* temp = this->GetComponent();
			this->SetComponent(slot2->GetComponent());
			slot2->SetComponent(temp);
		}
		//���� �ΰ� ��ο� �������� ������
		else {
			Item* temp = this->GetComponent();
			this->SetComponent(slot2->GetComponent());
			slot2->SetComponent(temp);
		}

	}
	
}