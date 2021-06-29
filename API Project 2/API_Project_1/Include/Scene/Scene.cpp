#include "Scene.h"
#include "Layer.h"

Scene::Scene()
{
	Layer* pLayer = CreateLayer("Default");
	pLayer = CreateLayer("UI", INT_MAX);
}

Scene::~Scene()
{
	SAFE_DELETE_VECLIST(list<class Layer*>, layerList);
}

Layer* Scene::CreateLayer(const string& tag, int order)
{
	Layer* player = new Layer;

	player->SetTag(tag);
	player->SetZOrder(order);
	player->SetScene(this);

	layerList.push_back(player);
	if (layerList.size() >= 2)
	{
		layerList.sort(Scene::LayerSort);
	}
	return nullptr;
}

bool Scene::Init()
{
	return true;
}

bool Scene::LayerSort(Layer* pL1, Layer* pL2)
{
	return pL1->GetZOrder() < pL2->GetZOrder();
}
