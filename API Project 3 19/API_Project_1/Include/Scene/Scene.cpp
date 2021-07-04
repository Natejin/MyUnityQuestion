#include "Scene.h"
#include "Layer.h"




Scene::Scene()
{
	Layer* pLayer = CreateLayer(TAG::DEFAULT);
	pLayer = CreateLayer(TAG::UI, INT_MAX);
}

Scene::~Scene()
{

	SAFE_DELETE_VECLIST(list<class Layer*>, layerList);
}

Layer* Scene::CreateLayer(const TAG& tag, int order)
{
	Layer* player = new Layer;

	player->SetTag(tag);
	player->SetZOrder(order);

	layerList.push_back(player);
	if (layerList.size() >= 2)
	{
		layerList.sort(Scene::LayerSort);
	}
	return nullptr;
}

Layer* Scene::FindLayer(const TAG& tag)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd; ++iter)
	{
		
		if ((*iter)->GetTag() == tag) return *iter;
	}
	return NULL;
}




bool Scene::Init()
{
	return true;
}

void Scene::Input(float deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//레이어가 비활성화면 사용하지않음
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->Input(deltaTime);


		//레이어가 죽었으면 삭제
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = layerList.erase(iter);
			iterEnd = layerList.end();
		}
		else {
			++iter;
		}
	}
}

int Scene::Update(float deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//레이어가 비활성화면 사용하지않음
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->Update(deltaTime);


		//레이어가 죽었으면 삭제
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = layerList.erase(iter);
			iterEnd = layerList.end();
		}
		else {
			++iter;
		}
	}
	return 0;
}

int Scene::LateUpdate(float deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//레이어가 비활성화면 사용하지않음
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->LateUpdate(deltaTime);


		//레이어가 죽었으면 삭제
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = layerList.erase(iter);
			iterEnd = layerList.end();
		}
		else {
			++iter;
		}
	}
	return 0;
}



void Scene::Collision(float deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//레이어가 비활성화면 사용하지않음
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->Collision(deltaTime);


		//레이어가 죽었으면 삭제
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = layerList.erase(iter);
			iterEnd = layerList.end();
		}
		else {
			++iter;
		}
	}
}




//그래픽
void Scene::Render(HDC hdc, float deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//레이어가 비활성화면 사용하지않음
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->Render(hdc, deltaTime);


		//레이어가 죽었으면 삭제
		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = layerList.erase(iter);
			iterEnd = layerList.end();
		}
		else {
			++iter;
		}
	}
}

bool Scene::Enable()
{
	return true;
}

bool Scene::Disable()
{
	return true;
}

bool Scene::LayerSort(Layer* pL1, Layer* pL2)
{
	return pL1->GetZOrder() < pL2->GetZOrder();
}
