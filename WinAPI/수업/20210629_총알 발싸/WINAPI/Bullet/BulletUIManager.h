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
	virtual HRESULT Init();
	virtual void Release();




	virtual void Update();
	virtual void Render(HDC hdc);

public:
	void GaugeDraw();
};

