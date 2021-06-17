#include "Item_Equip.h"


namespace ShopGame {

	class Item_Equip_Armor : public Item_Equip
	{
	protected:
		int damage;

	public:
		virtual void Initiate();
	};
}