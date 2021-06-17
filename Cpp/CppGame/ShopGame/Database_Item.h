

#include "Item.h"
#include "Database.h"



namespace ShopGame {
	class Database_Item : public Database
	{
	private:
		map<int, Item*> itemDB;

	public:
		virtual void InitiateDatabase();
	};
}
