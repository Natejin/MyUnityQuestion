#include "Slot.h"

namespace ShopGame {

	//ErrorCode RemoveFromSlot(T* reciveItem)
	//{
	//	if (object == nullptr)
	//	{
	//		return ErrorCode::ERROR_SlotItemIsMissing;
	//	}
	//	else {
	//		reciveItem = object;
	//		object = nullptr;
	//		return ErrorCode::NON_ERROR;
	//	}
	//}

	template<typename T>
	void Slot<T>::AddToSlot(T* _object)
	{
		component = _object;
		empty = false;
	}

	template<typename T>
	void Slot<T>::RemoveFromSlot()
	{
		if (!component == nullptr)
		{
			component = nullptr;
			empty = true;
		}
	}
	template<typename T>
	void Slot<T>::SetComponent(T* component)
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

	
	template<typename T>
	void Slot<T>::operator^(Slot<T>* slot2)
	{

		//���� 1�� �������
		if (this->isEmpty())
		{
			//���� 2�� �������� ������
			if (!slot2->isEmpty())
			{
				T* temp = this->GetComponent();
				this->SetComponent(slot2->GetComponent());
				slot2->SetComponent(temp);
			}
			else {
				//TODO ������ �ΰ��� ��������Ƿ� �ƹ��͵� ��������
			}

		}
		//���� 1�� �������� �����ϰ� ���� 2�� �������
		else if (slot2->isEmpty()) {
			T* temp = this->GetComponent();
			this->SetComponent(slot2->GetComponent());
			slot2->SetComponent(temp);
		}
		//���� �ΰ� ��ο� �������� ������
		else {
			T* temp = this->GetComponent();
			this->SetComponent(slot2->GetComponent());
			slot2->SetComponent(temp);
		}
	}
	//template<typename T>
	//void Slot<T>::Swap(Slot<T>* slot2)
	//{
	//	//���� 1�� �������
	//	if (this->isEmpty())
	//	{
	//		//���� 2�� �������� ������
	//		if (!slot2->isEmpty())
	//		{
	//			T* temp = this->GetComponent();
	//			this->SetComponent(slot2->GetComponent());
	//			slot2->SetComponent(temp);
	//		}
	//		else {
	//			//TODO ������ �ΰ��� ��������Ƿ� �ƹ��͵� ��������
	//		}

	//	}
	//	//���� 1�� �������� �����ϰ� ���� 2�� �������
	//	else if (slot2->isEmpty()) {
	//		T* temp = this->GetComponent();
	//		this->SetComponent(slot2->GetComponent());
	//		slot2->SetComponent(temp);
	//	}
	//	//���� �ΰ� ��ο� �������� ������
	//	else {
	//		T* temp = this->GetComponent();
	//		this->SetComponent(slot2->GetComponent());
	//		slot2->SetComponent(temp);
	//	}
	//}
}