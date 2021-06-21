#include "Item.h"

namespace ShopGame {
	Item::Item() :
		Component(), 
		itemType(ITEMTYPE::ERROR), 
		price(-1), 
		equipPart(EQUIPMENTPART::ERROR),
		job(JOBS::ERROR),
		baseDamage(-1),
		baseDefence(-1)
	{
	}
	
	void Item::Duplicate(Item item)
	{
		//Component
		code = item.code;
		name = item.name;
		description = item.description;

		//Item
		itemType = item.itemType;
		price = item.price;

		equipPart = item.equipPart;
		job = item.job;

		//status
		baseDefence = item.baseDefence;
		baseDamage = item.baseDamage;
	}

	//아이템을 깊은 복사합니다.
	void Item::Duplicate(Item* item)
	{
		//Component
		code = item->code;
		name = item->name;
		description = item->description;

		//Item
		itemType = item->itemType;
		price = item->price;

		equipPart = item->equipPart;
		job = item->job;

		//status
		baseDefence = item->baseDefence;
		baseDamage = item->baseDamage;

	}

	//아이템을 깊은 복사합니다.
	Item* Item::pClone()
	{
		Item* item = new Item();
		item->Duplicate(this);
		return item;
	}

	Item Item::Clone()
	{
		Item item = Item();
		item.Duplicate(this);
		return item;
	}

	////아이템을 깊은 복사합니다.
	//void Item::Duplicate(unsigned int code)
	//{
	//	//Duplicate(Database_Item::GetItem(code));		
	//}



	Item::Item(const unsigned int& code, 
		const string& name, 
		const string& description,
		const ITEMTYPE& itemType, 
		const int& price,
		const EQUIPMENTPART& equipPart,
		const JOBS& job,
		const int& baseDamage,
		const int& baseDefence)

		:Component(code, name,description), 
		itemType(itemType), 
		price(price), 
		equipPart(equipPart),
		job(job),
		baseDamage(baseDamage),
		baseDefence(baseDefence)
	{

	}
}