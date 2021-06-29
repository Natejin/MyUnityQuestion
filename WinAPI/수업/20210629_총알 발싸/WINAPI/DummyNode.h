
#pragma once
#include"framework.h"

class DummyNode
{
public:
	DummyNode() {};
	virtual ~DummyNode() {};

	virtual HRESULT init() { return S_OK; };
	virtual void release() {};
	virtual void update() {};
	virtual void render(HDC hdc) {};
};
