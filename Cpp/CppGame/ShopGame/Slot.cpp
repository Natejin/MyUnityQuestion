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

		//슬롯 1이 비어있음
		if (this->isEmpty())
		{
			//슬롯 2에 아이템이 존재함
			if (!slot2->isEmpty())
			{
				T* temp = this->GetComponent();
				this->SetComponent(slot2->GetComponent());
				slot2->SetComponent(temp);
			}
			else {
				//TODO 슬롯이 두개다 비어있으므로 아무것도 하지않음
			}

		}
		//슬롯 1에 아이템이 존재하고 슬롯 2가 비어있음
		else if (slot2->isEmpty()) {
			T* temp = this->GetComponent();
			this->SetComponent(slot2->GetComponent());
			slot2->SetComponent(temp);
		}
		//슬롯 두개 모두에 아이템이 존재함
		else {
			T* temp = this->GetComponent();
			this->SetComponent(slot2->GetComponent());
			slot2->SetComponent(temp);
		}
	}
	//template<typename T>
	//void Slot<T>::Swap(Slot<T>* slot2)
	//{
	//	//슬롯 1이 비어있음
	//	if (this->isEmpty())
	//	{
	//		//슬롯 2에 아이템이 존재함
	//		if (!slot2->isEmpty())
	//		{
	//			T* temp = this->GetComponent();
	//			this->SetComponent(slot2->GetComponent());
	//			slot2->SetComponent(temp);
	//		}
	//		else {
	//			//TODO 슬롯이 두개다 비어있으므로 아무것도 하지않음
	//		}

	//	}
	//	//슬롯 1에 아이템이 존재하고 슬롯 2가 비어있음
	//	else if (slot2->isEmpty()) {
	//		T* temp = this->GetComponent();
	//		this->SetComponent(slot2->GetComponent());
	//		slot2->SetComponent(temp);
	//	}
	//	//슬롯 두개 모두에 아이템이 존재함
	//	else {
	//		T* temp = this->GetComponent();
	//		this->SetComponent(slot2->GetComponent());
	//		slot2->SetComponent(temp);
	//	}
	//}
}