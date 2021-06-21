#pragma once
#include<Windows.h>
#include"shop.h"
#include"player.h"


enum class LOCATION
{
	LOCATION_SHOP = 1,
	LOCATION_SELL_INVENTORY,
	LOCATION_INVENTORY
};

class mainGame
{
private:
	shop* m_shop;
	player* m_player;
	LOCATION m_loc;

	int m_gold;
	int m_selectNum;
public:
	mainGame();
	~mainGame();



	void setLocation(const int number);
	void setMainPage();
	void setShopPage();
	void setShopItemPage(const int itemKind);
	void setSellInventoryPage();
	void setInventoryPage();





};

