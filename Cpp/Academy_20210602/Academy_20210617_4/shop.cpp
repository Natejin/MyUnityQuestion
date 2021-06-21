#include "shop.h"

shop::shop()
{
}

shop::~shop()
{
}

void shop::itemSetup()
{
    tagItemInfo armor1;
    armor1.itemkind = ITEM::ITEM_ARMOR;
    armor1.name = "���׹���";
    armor1.price = 50;
    armor1.attriibute = 50;
    armor1.description = "�������� �������";
    armor1.count = 1;
    m_vItem.push_back(armor1);

    tagItemInfo armor2;
    armor2.itemkind = ITEM::ITEM_ARMOR;
    armor2.name = "�� ����";
    armor2.price = 150;
    armor2.attriibute = 150;
    armor2.description = "��� �������";
    armor2.count = 1;
    m_vItem.push_back(armor2);


    tagItemInfo weapon1;
    weapon1.itemkind = ITEM::ITEM_WEAPON;
    weapon1.name = "�� �հ�";
    weapon1.price = 100;
    weapon1.attriibute = 3;
    weapon1.description = "�ٷ�� �����";
    weapon1.count = 1;
    m_vItem.push_back(weapon1);


    tagItemInfo weapon2;
    weapon2.itemkind = ITEM::ITEM_WEAPON;
    weapon2.name = "������";
    weapon2.price = 1000;
    weapon2.attriibute = 13;
    weapon2.description = "��Ÿ��� ����";
    weapon2.count = 1;
    m_vItem.push_back(weapon2);

}

int shop::itemOutput(const int num)
{
    int itemCount = 0;
    m_viItem = m_vItem.begin();
    for (m_viItem; m_viItem !=m_vItem.end(); ++m_viItem)
    {

        if (m_viItem->itemkind != (ITEM)num)continue;
        std::cout << "========================" << std::endl;
        std::cout << "������ ��ȣ : " << ++itemCount << std::endl;
        std::cout << "�̸� : " <<m_viItem->name << std::endl;
        std::cout << "���� : " <<m_viItem->price << std::endl;
        std::cout << "�ɷ�ġ : " <<m_viItem->attriibute << std::endl;
        std::cout << "���� : " <<m_viItem->description << std::endl;
        std::cout << "���� : ";
        (m_viItem->count > 0) ? std::cout << m_viItem->count << std::endl : std::cout << "����" << std::endl;
        std::cout << "========================" << std::endl;

    }
    return itemCount;
}

tagItemInfo shop::buyItem(const int itemKind, const int num, int& gold)
{
    tagItemInfo buyItem;
    buyItem.itemkind = ITEM::ITEM_EMPTY;
    int itemCount = 0;
    m_viItem = m_vItem.begin();

    for (m_viItem; m_viItem != m_vItem.end(); ++m_viItem)
    {
        if (m_viItem->itemkind != (ITEM)itemKind)continue;

        if (++itemCount == num)
        {
            if (gold >= m_viItem->price) 
            {
                if(m_viItem->count>0)
                {
                    std::cout << m_viItem->name << "��" << m_viItem->price << "gold�� �����Ͽ����ϴ�" << std::endl;
                    gold -= m_viItem->price;
                    m_viItem->count--;
                    buyItem = *m_viItem;
                }
                else
                {
                    std::cout << "�α⸸��!!!���ȸ�!!!" << std::endl;
                }
            }
            else
            {
                std::cout << "������!!!���� ��������" << std::endl;
            }
            break;
        }
    }
    return buyItem;
}

void shop::addItem(tagItemInfo item)
{
    bool isNemItem = true;
    m_viItem = m_vItem.begin();

    for (m_viItem; m_viItem != m_vItem.end(); ++m_viItem)
    {
        if (m_viItem->itemkind != item.itemkind)continue;

        if (m_viItem->name.compare(item.name) == 0) {
            m_viItem->count++;
            isNemItem = false;
            break;
        }
    }
    if (isNemItem == true)
    {
        m_vItem.push_back(item);
    }
}
