#pragma once
#include "DummyNode.h"


template<typename T>
class UIManager :public DummyNode<T>
{
public:
	UIManager() {};
	virtual ~UIManager() {};

	virtual HRESULT init() { return S_OK; };
	virtual void release() {};
	virtual void update() {};
	virtual void render(HDC hdc) {};
};

