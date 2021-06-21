#include "inventory.h"
inventory::inventory()
{
    tagItemInfo itemEmpty = { ITEM::ITEM_EMPTY,"","",0,0,0 };
    m_equipArmor = itemEmpty;
    m_equipWeapon = itemEmpty;
}

inventory::~inventory()
{
}

int inventory::showInventory()
{
    int itemCount  = 0;
    /*m_viItem = m_vItem.begin();
    for (m_viItem; m_viItem != m_vItem.end(); ++m_viItem)
    {
        std::cout << "=====================" << std::endl;
        std::cout << "아이템 번호 : " << ++itemCount << std::endl;
        std::cout << "이름 : " << m_viItem->name << std::endl;
        std::cout << "가격 : " << m_viItem->price << std::endl;
        std::cout << "능력치 : " << m_viItem->attriibute << std::endl;
        std::cout << "설명 : " << m_viItem->description << std::endl;
        std::cout << "=====================" << std::endl;
    }*/
  /*  auto  iter = m_vItem.begin();
    for (iter; iter != m_vItem.end(); ++iter)
    {
        std::cout << "=====================" << std::endl;
        std::cout << "아이템 번호 : " << ++itemCount << std::endl;
        std::cout << "이름 : " << iter->name << std::endl;
        std::cout << "가격 : " << iter->price << std::endl;
        std::cout << "능력치 : " << iter->attriibute << std::endl;
        std::cout << "설명 : " << iter->description << std::endl;
        std::cout << "=====================" << std::endl;
    }*/

    for (auto& i : m_vItem)
    {
        std::cout << "=====================" << std::endl;
        std::cout << "아이템 번호 : " << ++itemCount << std::endl;
        std::cout << "이름 : " << i.name << std::endl;
        std::cout << "가격 : " << i.price << std::endl;
        std::cout << "능력치 : " << i.attriibute << std::endl;
        std::cout << "설명 : " << i.description << std::endl;
        std::cout << "=====================" << std::endl;

    }

    return itemCount;

}

void inventory::addItem(tagItemInfo item)
{
    if (item.itemkind != ITEM::ITEM_EMPTY)
    {
        m_vItem.push_back(item);
    }
}

tagItemInfo inventory::sellItem(const int num, int& gold)
{
    tagItemInfo sellItem;

    m_viItem = m_vItem.begin() + (num - 1);
    sellItem = *m_viItem;
    m_vItem.erase(m_viItem);

    int sellPrice = sellItem.price / 2;

    std::cout << sellItem.name << "을" << sellPrice << "gold에 판매하였습니다." << std::endl;

    gold += sellPrice;


    return sellItem;

}

void inventory::equipItem(const int num)
{
    tagItemInfo beforeItem;

    m_viItem = m_vItem.begin() + (num - 1);

    switch (m_viItem->itemkind)
    {

    case ITEM::ITEM_ARMOR:
        beforeItem = getEquipArmor();
        setEquipArmor(*m_viItem);
        m_vItem.erase(m_viItem);

        if (beforeItem.itemkind == ITEM::ITEM_ARMOR)
        {
            m_vItem.push_back(beforeItem);
        }
        break;
    case ITEM::ITEM_WEAPON:
        beforeItem = getEquipWeapon();
        setEquipWeapon(*m_viItem);
        m_vItem.erase(m_viItem);

        if (beforeItem.itemkind == ITEM::ITEM_WEAPON) 
        {
            m_vItem.push_back(beforeItem);
        }
        break;
    }
}
