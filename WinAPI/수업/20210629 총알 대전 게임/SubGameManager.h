#pragma once
#include "MonoBehavior.h"

class SubGameManager : public MonoBehavior
{
protected:
	static HBRUSH brush, oBrush;
	static RECT g_RECT;

public:
	SubGameManager() {};
	virtual~SubGameManager() {};

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render(HDC hdc) = 0;
};

