#pragma once
#include"item.h"
class shop
{
private:
	std::vector<tagItemInfo> m_vItem;
	std::vector<tagItemInfo>::iterator m_viItem;
public:
	shop();
	~shop();

	void itemSetup();
	int itemOutput(const int num);

	tagItemInfo buyItem(const int itemKind, const int num, int& gold);

	void addItem(tagItemInfo item);
};

