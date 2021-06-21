#include "mainGame.h"
mainGame::mainGame()
{
	m_shop = new shop;
	m_shop->itemSetup();
	m_player = new player;
	m_gold = 10000;
	m_selectNum = 0;

	setMainPage();
}
mainGame::~mainGame()
{
	delete m_shop;
	delete m_player;
}
void mainGame::setMainPage()
{
	system("cls");
	std::cout<< "=============��ġ=============" << std::endl;
	std::cout<< "1.���� 2.�κ��丮[�Ǹ�]3.�κ��丮[����]" << std::endl;
	std::cin >> m_selectNum;
	setLocation(m_selectNum);
}

void mainGame::setLocation(const int number)
{
	switch ((LOCATION)number)
	{
	case LOCATION::LOCATION_SHOP:
		setShopPage();
		break;
	case LOCATION::LOCATION_SELL_INVENTORY:
		setSellInventoryPage();
		break;
	case LOCATION::LOCATION_INVENTORY:
		setInventoryPage();
		break;
	default:
		setMainPage();
		break;
	}
}


void mainGame::setShopPage()
{
	while (true)
	{
		system("cls");

		std::cout << "============����=============" << std::endl;
		std::cout << "1.�� 2.���� 3.�Ǽ����� 4.����" << std::endl;
		std::cout << "==����ȭ������ ������ ���ϸ� 0��==" << std::endl;

		std::cin >> m_selectNum;

		if (m_selectNum==0)
		{
			setMainPage();
			break;
		}
		else {
			setShopItemPage(m_selectNum);
		}

	}
}

void mainGame::setShopItemPage(const int itemKind)
{
	int itemCount = 0;
	while (true)
	{
		system("cls");

		itemCount = m_shop->itemOutput(itemKind);
		std::cout << "���� ��� : " << m_gold << std::endl;
		std::cout << "������ ������ ��ȣ�� �Է��ϼ���" << std::endl;
		std::cout << "itemCount : " << itemCount << std::endl;
		std::cout << "==�����޴��� ������ ���ϸ� 0��=="<< std::endl;
		
		std::cin >> m_selectNum;
		if (m_selectNum == 0) {
			break;
		}
		else if ((m_selectNum < 0) || m_selectNum > itemCount)
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else {
			m_player->addItem(m_shop->buyItem(itemKind, m_selectNum, m_gold));
			Sleep(1000);
		}
	}
}

void mainGame::setSellInventoryPage()
{
	int itemCount = 0;
	while (true)
	{
		system("cls");

		std::cout << "============�κ��丮=============" << std::endl;
		std::cout << "���� ��� : " << m_gold << std::endl;
		std::cout << "�Ǹ��� ������ ��ȣ�� �Է��ϼ���" << std::endl;
		std::cout << "==���θ޴��� ������ ���ϸ� 0��==" << std::endl;

		itemCount = m_player->showInventory();

		std::cin >> m_selectNum;

		if (m_selectNum==0)
		{
			setMainPage();
			break;
		}
		else if ((m_selectNum < 0) || m_selectNum > itemCount)
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else {
			m_shop->addItem(m_player->sellItem(m_selectNum, m_gold));
			Sleep(1000);
		}
	}
}

void mainGame::setInventoryPage()
{
	int itemCount = 0;
	while (true)
	{
		system("cls");
		m_player->showStatus();
		std::cout << "============�κ��丮=============" << std::endl;
		std::cout << "������ ������ ��ȣ�� �Է��ϼ���" << std::endl;
		std::cout << "==���θ޴��� ������ ���ϸ� 0��==" << std::endl;

		itemCount = m_player->showInventory();
		std::cin >> m_selectNum;

		if (m_selectNum == 0)
		{
			setMainPage();
			break;
		}
		else if ((m_selectNum < 0) || m_selectNum > itemCount)
		{
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		}
		else {
			m_player->equipItem(m_selectNum);
			Sleep(1000);
		}
	}
}
