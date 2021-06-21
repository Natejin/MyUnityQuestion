#pragma once
#include "Component.h"

namespace ShopGame {

	class Item : public Component
	{
	public:
		ITEMTYPE itemType;
		EQUIPMENTPART equipPart;
		JOBS job;

		//레벨제한
		int levelLimit;

		//가격
		int price;

		//무계
		double weight; 

		//아이템 수치
		//기본 공격력
		int baseDamage;

		//기본 방어력
		int baseDefence;



	public:
		Item();
		~Item() { cout << name << endl; }
		void UseItem() {};
		void Initiate() {};

		//void Duplicate(unsigned int code);
		void Duplicate(Item item);
		void Duplicate(Item* item);
		Item Clone();
		Item* pClone();

		//int SetPrice(int amount) { this->amount = amount; }
		
		ITEMTYPE GetItemType() { return itemType; }
		EQUIPMENTPART GetEquipPart() { return equipPart; }
		JOBS GetJobType() { return job; }
		int GetPrice() { return price; }
		//int GetAmount() { return amount; }

		Item(const unsigned int& code, 
			const string& name, 
			const string& description, 
			const ITEMTYPE& itemType, 
			const int& price,
			const EQUIPMENTPART& equipPart,
			const JOBS& job,
			const int& baseDamage,
			const int& baseDefence);
			
	};

}



