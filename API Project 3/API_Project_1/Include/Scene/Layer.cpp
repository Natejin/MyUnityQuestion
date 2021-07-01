#include "Layer.h"
#include "../Obj/Obj.h"

Layer::Layer()
	:ZOreder(0), tag(TAG::NONE), pScene(NULL)
{
}

Layer::~Layer()
{
	list<class Obj*>::iterator iter;
	list<class Obj*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE((*iter));
	}
	objList.clear();
}

void Layer::AddObject(Obj* pObj)
{
	pObj->SetScene(pScene);
	pObj->SetLayer(this);
	pObj->AddRef();

	objList.push_back(pObj);
}

void Layer::Input(float deltaTime)
{
	list<Obj*>::iterator iter;
	list<Obj*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Input(deltaTime);
	}  
}

int Layer::Update(float deltaTime)
{
	list<Obj*>::iterator iter;
	list<Obj*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Update(deltaTime);
	}
	return 0;
}

int Layer::LateUpdate(float deltaTime)
{
	list<Obj*>::iterator iter;
	list<Obj*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->LateUpdate(deltaTime);
	}
	return 0;
}

void Layer::Collision(float deltaTime)
{
	list<Obj*>::iterator iter;
	list<Obj*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Collision(deltaTime);
	}
}

void Layer::Render(HDC hdc, float deltaTime)
{
	list<Obj*>::iterator iter;
	list<Obj*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render(hdc, deltaTime);
	}
}
