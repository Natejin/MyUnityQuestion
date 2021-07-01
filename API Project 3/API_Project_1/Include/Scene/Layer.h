#pragma once
#include "../Game.h"

class Layer
{
private:
	friend class Scene;
private:
	Layer();
	~Layer();
private:
	class Scene* pScene;
	TAG tag;
	int ZOreder;// 출력 순서
	list<class Obj*> objList;

public:
	void SetTag(const TAG& tag) { this->tag = tag; }
	void SetZOrder(const int& _zorder) { ZOreder = _zorder; }
	void SetZOrder(Scene* pScene) { pScene = pScene; }


	int GetZOrder() const { return ZOreder; }
	TAG GetTag() const { return tag; }
	Scene* GetScene() const { return pScene; }

public:
	void AddObject(class Obj* pObj);

public:
	void Input(float deltaTime);
	int Update(float deltaTime);
	int LateUpdate(float deltaTime);
	void Collision(float deltaTime);
	void Render(HDC hdc, float deltaTime);
};

