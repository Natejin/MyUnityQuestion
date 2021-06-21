#include "player.h"

player::player()
{
	initPlayer();
}

player::~player()
{
}

void player::initPlayer()
{
	m_att = 10;
	m_def = 10;
}

void player::showStatus()
{
	int addAtt = m_equipWeapon.attriibute;
	int addDef = m_equipArmor.attriibute;

	std::cout << "============스탯============" << std::endl;
	std::cout << "공격력\t\t"<<m_att<<" + "<<addAtt << std::endl;
	std::cout << "방어력\t\t"<<m_att<<" + "<< addDef << std::endl;
	std::cout << "============장착============" << std::endl;
	std::cout << "무기\t\t"<< m_equipWeapon.name << std::endl;
	std::cout << "방어구\t\t"<< m_equipArmor.name << std::endl;

}
