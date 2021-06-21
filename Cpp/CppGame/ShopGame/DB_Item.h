#pragma once
#include "Item.h"
#include <vector>
#include <map>

namespace ShopGame {

	class DB_Item {
	private:
		map<unsigned int, Item*> itemDB;
	public:
		DB_Item() {};
		~DB_Item() {};
		Item* GetItem(const unsigned int& itemCode);
		void InitiateDatabase();
		map<unsigned int, Item*> GetItemDB() { return itemDB; }
	};
}