#pragma once
#include<iostream>
#include<vector>

enum class ITEM
{
	ITEM_EMPTY,
	ITEM_ARMOR,
	ITEM_WEAPON,
	ITEM_RING,
	ITEM_POTION,
	ITEM_SOLDOUT
};

struct tagItemInfo
{
	ITEM itemkind;
	std::string name;
	std::string description;
	int attriibute;
	int price;
	int count;
};

