#pragma once
#include"gameNode.h"
#include "MonoBehavior.h"
#include "Player.h"
#include "groundBlock.h"

class MainGame : public GameNode
{


private:


	//Player player;

	RECT land[3];
	vector<GroundBlock*> physicalMoveObjects;

	Player* player;
	RECT* playerRC;

public:
	MainGame() ;
	~MainGame() ;

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void FixedUpdate();
	virtual void render(HDC hdc);
};

