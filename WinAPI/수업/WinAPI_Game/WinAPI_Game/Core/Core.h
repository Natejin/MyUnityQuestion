#pragma once
#include "../framework.h"

class Core
{
private:
	HDC hdc;
	HDC memDC;
	HBITMAP bitMap, oldBitMap;

public:
	Core() {};
	~Core() {};

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Render(HDC hdc);
};

