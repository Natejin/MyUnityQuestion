#pragma once
#include <iostream>

using namespace std;


//아이템종류
#define ItemTypeCount 4
#define InventorySize 5
#define NullString "Null_String"
#define UpgradeItemMax 7



namespace ShowGame {
	class GameManager;
}

//아이템 종류
//-1:Error
// 0:장비템
// 1:소모품
// 2:재료템
// 3:그외
enum class ITEMTYPE {

	ERROR = -1,
	EQUIP,		
	CONSUME,	
	MATERIAL,	
	ETC			
};

static const char* ITEMTYPE_Str[] =
{ "장비", "소비템", "재료", "ETC" };

//유닛의 종족 
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


//유닛의 종류 
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
{ "무기", "상의", "하의", "신발", "장신구"};


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
{ "무기", "상의", "하의", "신발", "장신구" };

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
	//무기
	ITEM_집행검 = 200000,
	ITEM_대궁,
	ITEM_건틀릿,

	//아머-상의
	ITEM_사슬갑옷 = 220000,
	ITEM_나무갑옷,

	//아머-하의
	ITEM_사슬바지 = 230000,
	ITEM_나무바지,

	//아머-신발
	ITEM_장화부츠 = 240000,

	//장식품
	ITEM_금반지 = 250000,
	ITEM_금귀걸이,

	//소모품
	ITEM_사과 = 260000,
	ITEM_파랑포션,

	//재료
	ITEM_검은물체 = 270000
};

