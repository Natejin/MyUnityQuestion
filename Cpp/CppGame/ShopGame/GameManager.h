#pragma once
#include "InventoryManager.h"
#include "Player.h"
#include "ShopManager.h"
#include "Manager.h"
namespace ShopGame {

	class GameManager : public Manager
	{
	private:
		//Manager
		InventoryManager* inventoryManager;
		ShopManager* shopManager;

		//Unit
		Player* player;

	public:
		void Initiate();
	};

}