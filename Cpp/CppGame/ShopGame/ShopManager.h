#pragma once
#include "Component.h"
#include "Manager.h"
#include "ItemSlot.h"
#include "ItemObject.h"

namespace ShopGame {

	class ShopManager : public Manager
	{
		map<int, ItemSlot> shopList;
	public:

		ShopManager() {};
		~ShopManager() {};
		void Initiate();
		void BuyItem(int index);
		void SellItem(int item);
		bool CheckPrice(int index);
		void ShowItemList();

	};

}
//
//
//class ItemBase {
//
//	int code;
//	int itemType;
//	int damage[5] = { 5,8, 11, 13,15 };
//};
//
//static class ItemDB {
//	map<int, ItemBase> items;
//
//
//};
//
//
//
//
//class Item {
//	int code;
//	int itemLevel;
//
//	void UseItem() {
//		//아이템 사용
//	}
//};
//
//class Inventory {
//	map<int, Item> slots;
//
//	void AddItem(Item item) {
//		//아이템 추가
//	}
//
//	void SwapItem(int slot1, int slot2) {
//		//아이템 교환
//	}
//
//	void UseItem(int slot) {
//		//아이템 사용
//		//장비템일경우 장비창으로 해당아이템을 전송
//	}
//
//	Item RemoveItem(int slot) {
//		//아이템을 해당 슬롯에서 제거
//	}
//};
//
//class Equip {
//
//	bool EquipItem(Item item) {
//		//해당아이템코드를 데이터베이스의 아이템원형을 보고 착용할수있는지 확인
//		//착용가능하면 인벤토리의 아이템을 제거
//		//착용후 스탯변경
//		//착용했으므로 true리턴
//	}
//};

