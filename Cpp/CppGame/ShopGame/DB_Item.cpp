#include "DB_Item.h"


namespace ShopGame
{
	void DB_Item::InitiateDatabase()
	{

		itemDB = map<unsigned int, Item*>();
		itemDB.insert({ ITEM_집행검,new Item(ITEM_집행검, "집행검", "엄청 강하다", ITEMTYPE::EQUIP, 10000, 
			EQUIPMENTPART::WEAPON, JOBS::WARRIOR, 10, 0) });
		itemDB.insert({ ITEM_건틀릿,new Item(ITEM_건틀릿, "건틀릿", "", ITEMTYPE::EQUIP, 4500,  
			EQUIPMENTPART::WEAPON, JOBS::MONK, 10, 0) });
		itemDB.insert({ ITEM_대궁,new Item(ITEM_대궁, "대궁", "", ITEMTYPE::EQUIP, 4500,  
			EQUIPMENTPART::WEAPON, JOBS::ARCHER, 10, 0) });

		itemDB.insert({ ITEM_사슬갑옷,new Item(ITEM_사슬갑옷, "사슬 갑옷", "엄청 잘막는다", ITEMTYPE::EQUIP,  5000, 
			EQUIPMENTPART::TOP, JOBS::NONE, 0, 10) });
		itemDB.insert({ ITEM_나무갑옷,new Item(ITEM_나무갑옷, "나무 갑옷", "잘부셔진다", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::TOP, JOBS::NONE, 0, 10) });

		itemDB.insert({ ITEM_사슬바지,new Item(ITEM_사슬바지, "사슬 바지", "", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::BOTTOM, JOBS::NONE, 10, 0) });
		itemDB.insert({ ITEM_나무바지,new Item(ITEM_나무바지, "나무 바지", "", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::BOTTOM, JOBS::NONE, 0, 10) });

		itemDB.insert({ ITEM_장화부츠,new Item(ITEM_장화부츠, "장화 부츠", "", ITEMTYPE::EQUIP, 4500,  
			EQUIPMENTPART::SHOES, JOBS::NONE, 0, 10) });

		itemDB.insert({ ITEM_금반지,new Item(ITEM_금반지, "금반지", "빛난다", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::ACCESSORIES, JOBS::NONE, 0, 5) });
		itemDB.insert({ ITEM_금귀걸이,new Item(ITEM_금귀걸이, "금귀걸이", "빛난다", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::ACCESSORIES, JOBS::NONE, 0, 5) });

		itemDB.insert({ ITEM_사과,new Item(ITEM_사과, "사과", "체력을 10 회복한다", ITEMTYPE::CONSUME, 100, 
			EQUIPMENTPART::NONE, JOBS::NONE, 0, 0) });
		itemDB.insert({ ITEM_파랑포션,new Item(ITEM_파랑포션, "파랑포션", "마나를 10 회복한다", ITEMTYPE::CONSUME, 200,  
			EQUIPMENTPART::NONE, JOBS::NONE, 0, 0) });
		itemDB.insert({ ITEM_검은물체,new Item(ITEM_검은물체, "검은 물체", "부셔지지않는 무언가다", ITEMTYPE::MATERIAL, 500,  
			EQUIPMENTPART::NONE, JOBS::NONE, 0, 0) });
	}



	Item* DB_Item::GetItem(const unsigned int& itemCode)
	{
		return  itemDB[itemCode]->pClone();
		//return nullptr;
	}
}
//아이템 데이터베이스에 아이템을 추가하는곳
//이후 이곳은 변경시키지 않음;
//json등으로 파일을 불러오고 이후 사용하지 않기
//TODO JSON을이용한 저장과 로드
