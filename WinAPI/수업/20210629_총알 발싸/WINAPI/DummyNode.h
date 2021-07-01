
#pragma once
#include"framework.h"
#include "singleton.h"

template<typename T>
class DummyNode : public Singleton<T>
{
public:
	DummyNode() {};
	virtual ~DummyNode() {};

	virtual HRESULT Init() { return S_OK; };
	virtual void Release() {};
	virtual void Update() {};
	virtual void Render(HDC hdc) {};
};
