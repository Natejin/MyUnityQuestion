#pragma once
#include "gameNode.h"
#include "Bullet/GameManager_Bullet.h"
#include "Card/GameManager_Card.h"


class mainGame: public gameNode
{
	GameManager_Bullet* currentlyGame;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

};

