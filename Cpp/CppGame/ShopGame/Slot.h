#pragma once
#include "Component.h"

namespace ShopGame {

	template<typename T = Component>
	class Slot
	{
	protected:
		int index;
		bool empty;
		T* component;
	public:
		Slot() :index(-1), empty(true)  { component = nullptr; }
		~Slot() {};
		Slot(int index) : index(index), empty(true) { component = nullptr; }
		bool isEmpty() { return (component == nullptr) ? true : false; }
		int GetIndex() { return index; }
		void AddToSlot(T* component);
		void RemoveFromSlot();
		T* GetComponent() { return component; }
		void SetComponent(T* component);
		void ClearSlot() { this->component = nullptr; }
		void operator^(Slot<T>* slot2);
	};
}

