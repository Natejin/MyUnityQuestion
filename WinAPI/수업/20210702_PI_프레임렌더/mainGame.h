#pragma once
#include"gameNode.h"

class mainGame : public gameNode
{
private:
	Sprite* _bgImage;
	Sprite* _rockman;
	RECT rc;


	int m_index;		//프레임인덱스
	int m_count;		//프레임 돌릴 카운트
	bool isLeft;		//왼쪽임?


private:

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);


	
	
};

