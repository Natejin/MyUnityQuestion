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
	std::cout<< "=============위치=============" << std::endl;
	std::cout<< "1.상점 2.인벤토리[판매]3.인벤토리[장착]" << std::endl;
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

		std::cout << "============상점=============" << std::endl;
		std::cout << "1.방어구 2.무기 3.악세서리 4.포션" << std::endl;
		std::cout << "==메인화면으로 나가길 원하면 0번==" << std::endl;

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
		std::cout << "현재 골드 : " << m_gold << std::endl;
		std::cout << "구매할 아이템 번호를 입력하세용" << std::endl;
		std::cout << "itemCount : " << itemCount << std::endl;
		std::cout << "==상점메뉴로 나가길 원하면 0번=="<< std::endl;
		
		std::cin >> m_selectNum;
		if (m_selectNum == 0) {
			break;
		}
		else if ((m_selectNum < 0) || m_selectNum > itemCount)
		{
			std::cout << "잘못된 입력입니다." << std::endl;
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

		std::cout << "============인벤토리=============" << std::endl;
		std::cout << "현재 골드 : " << m_gold << std::endl;
		std::cout << "판매할 아이템 번호를 입력하세용" << std::endl;
		std::cout << "==메인메뉴로 나가길 원하면 0번==" << std::endl;

		itemCount = m_player->showInventory();

		std::cin >> m_selectNum;

		if (m_selectNum==0)
		{
			setMainPage();
			break;
		}
		else if ((m_selectNum < 0) || m_selectNum > itemCount)
		{
			std::cout << "잘못된 입력입니다." << std::endl;
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
		std::cout << "============인벤토리=============" << std::endl;
		std::cout << "장착할 아이템 번호를 입력하세용" << std::endl;
		std::cout << "==메인메뉴로 나가길 원하면 0번==" << std::endl;

		itemCount = m_player->showInventory();
		std::cin >> m_selectNum;

		if (m_selectNum == 0)
		{
			setMainPage();
			break;
		}
		else if ((m_selectNum < 0) || m_selectNum > itemCount)
		{
			std::cout << "잘못된 입력입니다." << std::endl;
		}
		else {
			m_player->equipItem(m_selectNum);
			Sleep(1000);
		}
	}
}
