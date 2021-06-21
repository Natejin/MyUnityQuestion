#pragma once
#include"unit.h"
#include"inventory.h"
class player : public unit, public inventory
{
public:
	player();
	~player();

	void initPlayer();
	void showStatus();
};

