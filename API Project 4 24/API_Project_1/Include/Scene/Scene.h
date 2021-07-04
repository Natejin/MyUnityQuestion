#pragma once
#include "../Game.h"


class Scene
{
private:
	friend class SceneManager;
protected:
	Scene();
	virtual ~Scene() = 0;

private:
	//해당 씬에서 사용하는 모든 Prefab
	static unordered_map<TAG, class MonoBehavior*> m_Prefabmap;
public:
	static void ErasePrefab();
	static void ErasePrefab(const TAG& tag);
protected:


protected:
	list<class Layer*> layerList;
public:
	class Layer* CreateLayer(const LAYER& tag, int order);
	class Layer* CreateLayer(const LAYER& tag);
	class Layer* FindLayer(const LAYER& tag);
public:
	virtual bool Init();
	virtual void Input(double deltaTime);
	virtual int Update(double deltaTime);
	virtual int LateUpdate(double deltaTime);
	virtual void Render(HDC hdc, double deltaTime);

	virtual void Collision(double deltaTime);
	static bool LayerSort(class Layer* pL1, class Layer* pL2);

	virtual bool Enable();
	virtual bool Disable();

public:
	template<class T = MonoBehavior>
	static T* CreatePrefab(const TAG& tagKey, const string name);



public:
	static MonoBehavior* FindPrefab(const TAG& tag);

};

template<class T>
static	T* Scene::CreatePrefab(const TAG& tagKey, const string name)
{
	//if (m_Prefabmap.find(tagKey) == m_Prefabmap.end()) {
	//	T* pMono = new T;
	//	pMono->SetLayer(tagKey);
	//	if (!pMono->Init())
	//	{
	//		SAFE_RELEASE(pMono);
	//		return NULL;
	//	}

	//	pMono->AddRef();

	//	m_Prefabmap.insert(make_pair(tagKey, pMono));
	//	return pMono;
	//}
	//else {
	//	return (T*)m_Prefabmap[tagKey];

	//}


	T* pMono = new T;
	pMono->SetTag(tagKey);
	pMono->SetName(name);
	if (!pMono->Init())
	{
		SAFE_RELEASE(pMono);
		return NULL;
	}

	pMono->AddRef();

	m_Prefabmap.insert(make_pair(tagKey, pMono));
	return pMono;

}

