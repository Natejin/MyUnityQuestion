#pragma once
#include"item.h"
class inventory
{

protected:
	std::vector<tagItemInfo> m_vItem;
	std::vector<tagItemInfo>::iterator m_viItem;

	tagItemInfo m_equipArmor;
	tagItemInfo m_equipWeapon;
public:

	inventory();
	~inventory();
	

	int showInventory();
	
	void addItem(tagItemInfo item);
	
	tagItemInfo sellItem(const int num, int& gold);
	
	void equipItem(const int num);

	tagItemInfo getEquipArmor() { return m_equipArmor; }
	void setEquipArmor(tagItemInfo& equipArmor) { m_equipArmor = equipArmor; }

	tagItemInfo getEquipWeapon() { return m_equipWeapon; }
	void setEquipWeapon(tagItemInfo& equipWeapon) { m_equipWeapon = equipWeapon; }







};

