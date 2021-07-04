#include "Scene.h"
#include "Layer.h"
#include "../Obj/MonoBehavior.h"

unordered_map<TAG, MonoBehavior*> Scene::m_Prefabmap;
Scene::Scene()
{
	Layer* pLayer = CreateLayer(LAYER::DEFAULT);
	pLayer = CreateLayer(LAYER::UI);
	pLayer = CreateLayer(LAYER::BACKGROUND);
}

Scene::~Scene()
{
	ErasePrefab();
	SAFE_DELETE_VECLIST(list<class Layer*>, layerList);
}

Layer* Scene::CreateLayer(const LAYER& layer, int order)
{
	Layer* player = new Layer;

	player->SetLayer(layer);
	player->SetZOrder(order);

	layerList.push_back(player);
	if (layerList.size() >= 2)
	{
		layerList.sort(Scene::LayerSort);
	}
	return nullptr;
}

Layer* Scene::CreateLayer(const LAYER& layer)
{
	Layer* player = new Layer;

	player->SetLayer(layer);
	player->SetZOrder((int)layer);

	layerList.push_back(player);
	if (layerList.size() >= 2)
	{
		layerList.sort(Scene::LayerSort);
	}
	return nullptr;
}

Layer* Scene::FindLayer(const LAYER& layer)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd; ++iter)
	{
		
		if ((*iter)->GetLayer() == layer) return *iter;
	}
	return NULL;
}




bool Scene::Init()
{
	return true;
}

void Scene::Input(double deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//���̾ ��Ȱ��ȭ�� �����������
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->Input(deltaTime);


		//���̾ �׾����� ����
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

int Scene::Update(double deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//���̾ ��Ȱ��ȭ�� �����������
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->Update(deltaTime);


		//���̾ �׾����� ����
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

int Scene::LateUpdate(double deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//���̾ ��Ȱ��ȭ�� �����������
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->LateUpdate(deltaTime);


		//���̾ �׾����� ����
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

void Scene::ErasePrefab()
{
	unordered_map<TAG, MonoBehavior*> ::iterator iter;
	unordered_map<TAG, MonoBehavior*> ::iterator iterEnd = m_Prefabmap.end();
	for (iter = m_Prefabmap.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE(iter->second);
	}
	m_Prefabmap.clear();
}

void Scene::ErasePrefab(const TAG& tag)
{
	unordered_map<TAG, MonoBehavior*> ::iterator iter = m_Prefabmap.find(tag);

	if (!iter->second)
	{
		return;
	}

	SAFE_RELEASE(iter->second);
	m_Prefabmap.erase(iter);
}

MonoBehavior* Scene::FindPrefab(const TAG& tag)
{
	unordered_map<TAG, MonoBehavior*>::iterator iter = m_Prefabmap.find(tag);
	if (iter == m_Prefabmap.end()) return NULL;
	return 	iter->second;
}






void Scene::Collision(double deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//���̾ ��Ȱ��ȭ�� �����������
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->Collision(deltaTime);


		//���̾ �׾����� ����
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




//�׷���
void Scene::Render(HDC hdc, double deltaTime)
{
	list<Layer*>::iterator iter;
	list<Layer*>::iterator iterEnd = layerList.end();

	for (iter = layerList.begin(); iter != iterEnd;)
	{

		//���̾ ��Ȱ��ȭ�� �����������
		if (!(*iter)->GetEnable()) {
			++iter;
			continue;
		}


		(*iter)->Render(hdc, deltaTime);


		//���̾ �׾����� ����
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
