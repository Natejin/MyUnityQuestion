#pragma once
#include "DummyNode.h"


template<typename T>
class UIManager :public DummyNode<T>
{
public:
	UIManager() {};
	virtual ~UIManager() {};

	virtual HRESULT Init() { return S_OK; };
	virtual void Release() {};
	virtual void Update() {};
	virtual void Render(HDC hdc) {};
};

