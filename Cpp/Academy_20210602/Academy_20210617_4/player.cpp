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

	std::cout << "============����============" << std::endl;
	std::cout << "���ݷ�\t\t"<<m_att<<" + "<<addAtt << std::endl;
	std::cout << "����\t\t"<<m_att<<" + "<< addDef << std::endl;
	std::cout << "============����============" << std::endl;
	std::cout << "����\t\t"<< m_equipWeapon.name << std::endl;
	std::cout << "��\t\t"<< m_equipArmor.name << std::endl;

}
