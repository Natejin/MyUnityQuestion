#pragma once
#include "gameNode.h"
#include "Bullet/GameManager_Bullet.h"
#include "Card/GameManager_Card.h"


class MainGame: public GameNode
{
	GameManager_Bullet* currentlyGame;
	bool isDebug;
public:
	MainGame();
	~MainGame();

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

};

