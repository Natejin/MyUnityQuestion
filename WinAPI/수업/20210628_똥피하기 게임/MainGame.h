#pragma once
#include"gameNode.h"
#include "MonoBehavior.h"
#include "Player.h"
#include "groundBlock.h"
#include "DropingBlock.h"
#define BOX 5
class MainGame : public GameNode
{


private:

	
	vector<GroundBlock*> groundBlocks;
	vector<DropingBlock*> dropBlocks;
	Player* player;

public:
	MainGame() ;
	~MainGame() ;

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void FixedUpdate();
	virtual void render(HDC hdc);
};

