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
//		//������ ���
//	}
//};
//
//class Inventory {
//	map<int, Item> slots;
//
//	void AddItem(Item item) {
//		//������ �߰�
//	}
//
//	void SwapItem(int slot1, int slot2) {
//		//������ ��ȯ
//	}
//
//	void UseItem(int slot) {
//		//������ ���
//		//������ϰ�� ���â���� �ش�������� ����
//	}
//
//	Item RemoveItem(int slot) {
//		//�������� �ش� ���Կ��� ����
//	}
//};
//
//class Equip {
//
//	bool EquipItem(Item item) {
//		//�ش�������ڵ带 �����ͺ��̽��� �����ۿ����� ���� �����Ҽ��ִ��� Ȯ��
//		//���밡���ϸ� �κ��丮�� �������� ����
//		//������ ���Ⱥ���
//		//���������Ƿ� true����
//	}
//};

