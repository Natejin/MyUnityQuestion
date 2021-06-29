#pragma once
#include "../UIManager.h"
class BulletUIManager:public UIManager
{
public:
	RECT m_gaugeFront;
	RECT m_gaugeBack;

	int m_red;
	int m_green;

public:
	BulletUIManager() {};
	virtual ~BulletUIManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

public:
	void GaugeDraw();
};

