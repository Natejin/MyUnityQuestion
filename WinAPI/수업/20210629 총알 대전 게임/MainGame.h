#pragma once
#include "GameNode.h"
#include "Game/CollisionBlock/GroundBlock.h"
#include "Game/DropBlock/DropingBlock.h"

//game play
#include "Game/Bullet/BulletFightManager.h"
#define BOX 5

using namespace BulletFight;


class MainGame : public GameNode
{


private:
	enum class CURRENTRECT {
		CURRENTRECT_0,
		CURRENTRECT_1,
		CURRENTRECT_2,
		CURRENTRECT_3,
		CURRENTRECT_4,
		CURRENTRECT_5,
		CURRENTRECT_6,
		CURRENTRECT_7,
		CURRENTRECT_NULL,
	};

	vector<HBITMAP> bitmaps;

private:
	CURRENTRECT m_currentRect;
	vector<RECT> m_v_rc;

	vector<GroundBlock*> groundBlocks;
	vector<DropingBlock*> dropBlocks;

	BulletFightManager bulletFightManager;

	void SetUpImage();

public:
	MainGame() ;
	virtual ~MainGame() ;

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Render(HDC hdc);
};

