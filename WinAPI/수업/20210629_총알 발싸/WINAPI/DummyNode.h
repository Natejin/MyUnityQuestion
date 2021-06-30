
#pragma once
#include"framework.h"
#include "singleton.h"

template<typename T>
class DummyNode : public Singleton<T>
{
public:
	DummyNode() {};
	virtual ~DummyNode() {};

	virtual HRESULT init() { return S_OK; };
	virtual void release() {};
	virtual void update() {};
	virtual void render(HDC hdc) {};
};
