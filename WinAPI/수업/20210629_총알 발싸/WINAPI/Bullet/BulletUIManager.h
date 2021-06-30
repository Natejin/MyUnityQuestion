#pragma once
#include "../UIManager.h"
#include "../MonoBehavior.h"
class BulletUIManager:public UIManager<BulletUIManager>
{
public:
	MonoBehavior m_gaugeFront;
	RECT m_gaugeBack;

	int m_red;
	int m_green;

	int hp;

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

