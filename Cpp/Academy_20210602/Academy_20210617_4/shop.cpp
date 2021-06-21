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
    armor1.name = "가죽바지";
    armor1.price = 50;
    armor1.attriibute = 50;
    armor1.description = "가죽으로 만든바지";
    armor1.count = 1;
    m_vItem.push_back(armor1);

    tagItemInfo armor2;
    armor2.itemkind = ITEM::ITEM_ARMOR;
    armor2.name = "쇠 바지";
    armor2.price = 150;
    armor2.attriibute = 150;
    armor2.description = "쇠로 만든바지";
    armor2.count = 1;
    m_vItem.push_back(armor2);


    tagItemInfo weapon1;
    weapon1.itemkind = ITEM::ITEM_WEAPON;
    weapon1.name = "한 손검";
    weapon1.price = 100;
    weapon1.attriibute = 3;
    weapon1.description = "다루기 쉬운검";
    weapon1.count = 1;
    m_vItem.push_back(weapon1);


    tagItemInfo weapon2;
    weapon2.itemkind = ITEM::ITEM_WEAPON;
    weapon2.name = "광선검";
    weapon2.price = 1000;
    weapon2.attriibute = 13;
    weapon2.description = "스타워즈에 나옴";
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
        std::cout << "아이템 번호 : " << ++itemCount << std::endl;
        std::cout << "이름 : " <<m_viItem->name << std::endl;
        std::cout << "가격 : " <<m_viItem->price << std::endl;
        std::cout << "능력치 : " <<m_viItem->attriibute << std::endl;
        std::cout << "설명 : " <<m_viItem->description << std::endl;
        std::cout << "갯수 : ";
        (m_viItem->count > 0) ? std::cout << m_viItem->count << std::endl : std::cout << "매진" << std::endl;
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
                    std::cout << m_viItem->name << "을" << m_viItem->price << "gold에 구매하였습니당" << std::endl;
                    gold -= m_viItem->price;
                    m_viItem->count--;
                    buyItem = *m_viItem;
                }
                else
                {
                    std::cout << "인기만점!!!다팔림!!!" << std::endl;
                }
            }
            else
            {
                std::cout << "돈없음!!!대출 ㄱㄱㄱㄱ" << std::endl;
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
