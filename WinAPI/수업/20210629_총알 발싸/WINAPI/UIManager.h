#pragma once
#include "DummyNode.h"
class UIManager :public DummyNode
{
public:
	UIManager() {};
	virtual ~UIManager() {};

	virtual HRESULT init() { return S_OK; };
	virtual void release() {};
	virtual void update() {};
	virtual void render(HDC hdc) {};
};

