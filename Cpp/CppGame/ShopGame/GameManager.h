#pragma once

#include "Player.h"

//#include "Manager.h"
#include "Item.h"
#include "Base.h"
#include "DB_Item.h"
#include <iostream>

#include "InventoryManager.h"
#include "ShopManager.h"
#include "EquipmentManager.h"
#include "ConsoleManager.h"
#include <queue>

using namespace std;



namespace ShopGame {

	class GameManager
	{
	private:


		//Manager

		ShopManager* shopManager;

		EquipmentManager* equipManager;
		InventoryManager* invenManager;
		ConsoleManager* consoleManager;
		//DataBase
		DB_Item* dbItem;

		//Unit
		Player* player;

		GameManager();
		~GameManager();

		static GameManager *instance ;
	public:


		void Initiate();

		//Unit
		void CreatePlayer();
		void LoadPlayerData();

		void Display();
		void DisplayInventory();
		void DisplayEquipment();
		void DisplayStatus();
		int GetInput(string text, int min, int max);



		Item* CreateItem(unsigned int code);
		//Item CloneItem(Item item);

		void GUI_SelectInventory();
		void GUI_SelectCreateItem();
		void GUI_SelectSlot();
		void GUI_SwapItemsBetweenSlots();

		InventoryManager* GetInventoryManager() { return invenManager; };
		EquipmentManager* GetEquipmentManager() { return equipManager; };
		ConsoleManager* GetConsoleManager() { return consoleManager; };
		Player* GetPlayer() { return player; };

		void AddErrorCode(ErrorCode error) { consoleManager->ErrorCodePush(error); }

		void UseItem();


		//ΩÃ±€≈Ê ∆–≈œ
		//static GameManager& Instance() { 
		//	static GameManager* instance = new GameManager(); 
		//	return *instance; 
		//}

		static GameManager* Instance() {
			if (!instance) { 
				instance = new GameManager(); 			
			}
			return instance;
		}

		//static GameManager& Instance() { return instance; }


	};

}