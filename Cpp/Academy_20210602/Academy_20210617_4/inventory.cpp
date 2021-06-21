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
        std::cout << "������ ��ȣ : " << ++itemCount << std::endl;
        std::cout << "�̸� : " << m_viItem->name << std::endl;
        std::cout << "���� : " << m_viItem->price << std::endl;
        std::cout << "�ɷ�ġ : " << m_viItem->attriibute << std::endl;
        std::cout << "���� : " << m_viItem->description << std::endl;
        std::cout << "=====================" << std::endl;
    }*/
  /*  auto  iter = m_vItem.begin();
    for (iter; iter != m_vItem.end(); ++iter)
    {
        std::cout << "=====================" << std::endl;
        std::cout << "������ ��ȣ : " << ++itemCount << std::endl;
        std::cout << "�̸� : " << iter->name << std::endl;
        std::cout << "���� : " << iter->price << std::endl;
        std::cout << "�ɷ�ġ : " << iter->attriibute << std::endl;
        std::cout << "���� : " << iter->description << std::endl;
        std::cout << "=====================" << std::endl;
    }*/

    for (auto& i : m_vItem)
    {
        std::cout << "=====================" << std::endl;
        std::cout << "������ ��ȣ : " << ++itemCount << std::endl;
        std::cout << "�̸� : " << i.name << std::endl;
        std::cout << "���� : " << i.price << std::endl;
        std::cout << "�ɷ�ġ : " << i.attriibute << std::endl;
        std::cout << "���� : " << i.description << std::endl;
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

    std::cout << sellItem.name << "��" << sellPrice << "gold�� �Ǹ��Ͽ����ϴ�." << std::endl;

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
