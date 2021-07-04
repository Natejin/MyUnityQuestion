#include "Layer.h"
#include "../Obj/MonoBehavior.h"


Layer::Layer()
	:ZOreder(0), 
	tag(TAG::NONE), 
	pScene(NULL),
	life(true),
	enable(true)
{
}

Layer::~Layer()
{
	list<class MonoBehavior*>::iterator iter;
	list<class MonoBehavior*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd; ++iter)
	{
		MonoBehavior::EraseMono(*iter);
		SAFE_RELEASE((*iter));
	}
	objList.clear();

	//SAFE_DELETE_VECLIST(objList);
}

void Layer::AddMono(MonoBehavior* pMono)
{
	pMono->SetScene(pScene);
	pMono->SetLayer(this);
	//pMonoBehavilour->AddRef();

	objList.push_back(pMono);
}

void Layer::Input(float deltaTime)
{
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd;)
	{
		//해당 오브젝트가 비활성화일경우 넘김
		if ((!(*iter)->GetEnable()))
		{
			++iter;
			continue;
		}

		(*iter)->Input(deltaTime);

		if (!(*iter)->GetLife())
		{
			MonoBehavior::EraseMono(*iter);
			SAFE_RELEASE((*iter));
			iter = objList.erase(iter);
			iterEnd = objList.end();
		}
		else {
			++iter;
		}
	}  


}

int Layer::Update(float deltaTime)
{
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd;)
	{
		//해당 오브젝트가 비활성화일경우 넘김
		if ((!(*iter)->GetEnable()))
		{
			++iter;
			continue;
		}

		(*iter)->Update(deltaTime);

		if (!(*iter)->GetLife())
		{
			MonoBehavior::EraseMono(*iter);
			SAFE_RELEASE((*iter));
			iter = objList.erase(iter);
			iterEnd = objList.end();
		}
		else {
			++iter;
		}
	}
	return 0;
}

int Layer::LateUpdate(float deltaTime)
{
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd;)
	{
		//해당 오브젝트가 비활성화일경우 넘김
		if ((!(*iter)->GetEnable()))
		{
			++iter;
			continue;
		}

		(*iter)->LateUpdate(deltaTime);

		if (!(*iter)->GetLife())
		{
			MonoBehavior::EraseMono(*iter);
			SAFE_RELEASE((*iter));
			iter = objList.erase(iter);
			iterEnd = objList.end();
		}
		else {
			++iter;
		}
	}
	return 0;
}

void Layer::Collision(float deltaTime)
{
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd;)
	{
		//해당 오브젝트가 비활성화일경우 넘김
		if ((!(*iter)->GetEnable()))
		{
			++iter;
			continue;
		}

		(*iter)->Collision(deltaTime);

		if (!(*iter)->GetLife())
		{
			MonoBehavior::EraseMono(*iter);
			SAFE_RELEASE((*iter));
			iter = objList.erase(iter);
			iterEnd = objList.end();
		}
		else {
			++iter;
		}
	}
}

void Layer::Render(HDC hdc, float deltaTime)
{
	list<MonoBehavior*>::iterator iter;
	list<MonoBehavior*>::iterator iterEnd = objList.end();

	for (iter = objList.begin(); iter != iterEnd;)
	{
		//해당 오브젝트가 비활성화일경우 넘김
		if ((!(*iter)->GetEnable()))
		{
			++iter;
			continue;
		}

		(*iter)->Render(hdc, deltaTime);

		if (!(*iter)->GetLife())
		{
			MonoBehavior::EraseMono(*iter);
			SAFE_RELEASE((*iter));
			iter = objList.erase(iter);
			iterEnd = objList.end();
		}
		else {
			++iter;
		}
	}
}
