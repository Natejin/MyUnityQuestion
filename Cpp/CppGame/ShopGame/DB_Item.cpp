#include "DB_Item.h"


namespace ShopGame
{
	void DB_Item::InitiateDatabase()
	{

		itemDB = map<unsigned int, Item*>();
		itemDB.insert({ ITEM_�����,new Item(ITEM_�����, "�����", "��û ���ϴ�", ITEMTYPE::EQUIP, 10000, 
			EQUIPMENTPART::WEAPON, JOBS::WARRIOR, 10, 0) });
		itemDB.insert({ ITEM_��Ʋ��,new Item(ITEM_��Ʋ��, "��Ʋ��", "", ITEMTYPE::EQUIP, 4500,  
			EQUIPMENTPART::WEAPON, JOBS::MONK, 10, 0) });
		itemDB.insert({ ITEM_���,new Item(ITEM_���, "���", "", ITEMTYPE::EQUIP, 4500,  
			EQUIPMENTPART::WEAPON, JOBS::ARCHER, 10, 0) });

		itemDB.insert({ ITEM_�罽����,new Item(ITEM_�罽����, "�罽 ����", "��û �߸��´�", ITEMTYPE::EQUIP,  5000, 
			EQUIPMENTPART::TOP, JOBS::NONE, 0, 10) });
		itemDB.insert({ ITEM_��������,new Item(ITEM_��������, "���� ����", "�ߺμ�����", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::TOP, JOBS::NONE, 0, 10) });

		itemDB.insert({ ITEM_�罽����,new Item(ITEM_�罽����, "�罽 ����", "", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::BOTTOM, JOBS::NONE, 10, 0) });
		itemDB.insert({ ITEM_��������,new Item(ITEM_��������, "���� ����", "", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::BOTTOM, JOBS::NONE, 0, 10) });

		itemDB.insert({ ITEM_��ȭ����,new Item(ITEM_��ȭ����, "��ȭ ����", "", ITEMTYPE::EQUIP, 4500,  
			EQUIPMENTPART::SHOES, JOBS::NONE, 0, 10) });

		itemDB.insert({ ITEM_�ݹ���,new Item(ITEM_�ݹ���, "�ݹ���", "������", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::ACCESSORIES, JOBS::NONE, 0, 5) });
		itemDB.insert({ ITEM_�ݱͰ���,new Item(ITEM_�ݱͰ���, "�ݱͰ���", "������", ITEMTYPE::EQUIP, 5000,  
			EQUIPMENTPART::ACCESSORIES, JOBS::NONE, 0, 5) });

		itemDB.insert({ ITEM_���,new Item(ITEM_���, "���", "ü���� 10 ȸ���Ѵ�", ITEMTYPE::CONSUME, 100, 
			EQUIPMENTPART::NONE, JOBS::NONE, 0, 0) });
		itemDB.insert({ ITEM_�Ķ�����,new Item(ITEM_�Ķ�����, "�Ķ�����", "������ 10 ȸ���Ѵ�", ITEMTYPE::CONSUME, 200,  
			EQUIPMENTPART::NONE, JOBS::NONE, 0, 0) });
		itemDB.insert({ ITEM_������ü,new Item(ITEM_������ü, "���� ��ü", "�μ������ʴ� ���𰡴�", ITEMTYPE::MATERIAL, 500,  
			EQUIPMENTPART::NONE, JOBS::NONE, 0, 0) });
	}



	Item* DB_Item::GetItem(const unsigned int& itemCode)
	{
		return  itemDB[itemCode]->pClone();
		//return nullptr;
	}
}
//������ �����ͺ��̽��� �������� �߰��ϴ°�
//���� �̰��� �����Ű�� ����;
//json������ ������ �ҷ����� ���� ������� �ʱ�
//TODO JSON���̿��� ����� �ε�
