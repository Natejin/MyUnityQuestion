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
	Player* player;
	//HBITMAP myBitmap, oldBitmap;
	//HDC memDC;

	void SetUpImage();

public:
	MainGame() ;
	~MainGame() ;

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void FixedUpdate();
	virtual void render(HDC hdc);
};

