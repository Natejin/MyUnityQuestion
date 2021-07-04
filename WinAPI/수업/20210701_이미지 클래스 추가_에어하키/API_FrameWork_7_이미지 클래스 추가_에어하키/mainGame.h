#pragma once
#include"gameNode.h"
#include"airHockey.h"

class mainGame : public gameNode
{
private:
	image* _bgImage;
	image* _sigong;
	RECT rc;

	airHockey* ah;

private:

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);


	
	
};

