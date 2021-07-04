#pragma once
#include "Component.h"
#include "../Core/InputManager.h"



#define INPUT InputManager::GetSingleton()

class MonoBehavior : public Component {


private:

	//해당 씬에서 사용하는 모든 GameObject 
	static list<MonoBehavior*> m_Monolist;
	//static unordered_map<TAG, MonoBehavior*> m_Prefabmap;

protected:

	MonoBehavior(const MonoBehavior& obj);
	virtual ~MonoBehavior();

public:
	MonoBehavior();
	static void AddMono(MonoBehavior* pMono);
	static MonoBehavior* FindObject(const TAG& tag);
	static void EraseMono(MonoBehavior* pMono);
	static void EraseMono();
	static void EraseMono(const TAG& tag);


protected:
	//오브젝트가 속한 씬의 포인터
	class Scene* m_pScene;
	//오브젝트가 속한 씬의 레이어
	class Layer* m_pLayer;

public:
	//씬 설정
	void SetScene(class Scene* pScene) { this->m_pScene = pScene; }
	//레이어 설정
	void SetLayer(class Layer* pLayer) { this->m_pLayer = pLayer; }

	class  Scene* GetScene() const { return m_pScene; }
	class  Layer* GetLayer() const { return m_pLayer; }

protected:
	

	//GameObject의 태그
	TAG tag;
	LAYER layer;



public:
	void SetTag(const TAG& tag) {this->tag = tag;}
	TAG GetTag() { return tag; }

	void SetLayer(const LAYER& layer) {	this->layer = layer;}
	LAYER GetLayer() { return layer; }


public:
	virtual bool Enable();
	virtual bool Disable();
	virtual bool Init() = 0;
	virtual void Input(double deltaTime);
	virtual int Update(double deltaTime);
	virtual int LateUpdate(double deltaTime);
	virtual void Collision(double deltaTime);
	virtual void Render(HDC hdc, double deltaTime);
	virtual MonoBehavior* Clone() = 0;

public:
	template<typename T = MonoBehavior>
	static T* CreateMono(const TAG& tag, string name , Layer* player = NULL);

	static MonoBehavior* CreateClone(const TAG& tagKey, const TAG& tag, class Layer* pLayer = NULL);
	

public:
	void DrawRect(HDC hdc);
	void DrawRect(HDC hdc, Color rgb);
	void DrawEllipse(HDC hdc);
	void DrawEllipse(HDC hdc, Color rgb);
};


template<typename T>
static T* MonoBehavior::CreateMono(const TAG& tag, string name , Layer* pLayer)
{
	T* pMono = new T;
	pMono->SetTag(tag);
	pMono->SetName(name);
	if (!pMono->Init())
	{
		SAFE_RELEASE(pMono);
		return NULL;
	}

	if (pLayer)
	{
		pLayer->AddMono(pMono);
	}

	//생성된 GameObject를 추가
	AddMono(pMono);
	return pMono;
}

