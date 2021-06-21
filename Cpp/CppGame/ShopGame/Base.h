#pragma once
#include <iostream>

using namespace std;


//����������
#define ItemTypeCount 4
#define InventorySize 5
#define NullString "Null_String"
#define UpgradeItemMax 7



namespace ShowGame {
	class GameManager;
}

//������ ����
//-1:Error
// 0:�����
// 1:�Ҹ�ǰ
// 2:�����
// 3:�׿�
enum class ITEMTYPE {

	ERROR = -1,
	EQUIP,		
	CONSUME,	
	MATERIAL,	
	ETC			
};

static const char* ITEMTYPE_Str[] =
{ "���", "�Һ���", "���", "ETC" };

//������ ���� 
//-1: Error
// 0: Human
// 1: Elf
// 2: Orc
// 3: Undead
enum class RACE {
	ERROR = -1,
	HUMAN,
	ELF, 
	ORC, 
	UNDEAD};


//������ ���� 
	//-1: Error
	// 0: Player
	// 1: Enemy
	// 2: NPC
	// 3: Natural
enum class UNITTYPE {
	ERROR = -1,
	PLAYER, 
	ENEMY, 
	NPC, 
	NATURAL};

static const char* EQUIPMENTPART_Str[] =
{ "����", "����", "����", "�Ź�", "��ű�"};


enum class EQUIPMENTPART {
	NONE = -2,
	ERROR = -1,
	WEAPON,
	//HEAD,
	TOP,
	BOTTOM,
	SHOES,
	ACCESSORIES,

};

enum class JOBS {
	ERROR = -1,
	NONE,
	WARRIOR,
	MONK,
	ARCHER
};

static const char* ErrorCode_Str[] =
{ "����", "����", "����", "�Ź�", "��ű�" };

enum class ErrorCode {

	ERROR_UNKNOWN = -1,
	NON_ERROR,
	ERROR_Inventory_IsFull,
	ERROR_Inventory_IsMissing,
	ERROR_Inventory_ItemCountMoreThanInventorySize, 
	ERROR_Inventory_Unknown,
	ERROR_Inventory_SlotItemIsMissing,
	ERROR_Equipment_ClassDoesNotMatch
};


enum Code
{
	//����
	ITEM_����� = 200000,
	ITEM_���,
	ITEM_��Ʋ��,

	//�Ƹ�-����
	ITEM_�罽���� = 220000,
	ITEM_��������,

	//�Ƹ�-����
	ITEM_�罽���� = 230000,
	ITEM_��������,

	//�Ƹ�-�Ź�
	ITEM_��ȭ���� = 240000,

	//���ǰ
	ITEM_�ݹ��� = 250000,
	ITEM_�ݱͰ���,

	//�Ҹ�ǰ
	ITEM_��� = 260000,
	ITEM_�Ķ�����,

	//���
	ITEM_������ü = 270000
};

