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
	LAYER layer;
	int ZOreder;// ��� ����
	list<class MonoBehavior*> objList;

protected:
	//��ü�� ���� Ű�¿뵵 (Unity
	bool enable;
	//�츮�� ���̴� ����
	bool life;


public:
	void SetEnable(bool enable) { this->enable = enable; }
	bool GetEnable() const { return enable; }

	bool GetLife() const { return life; }
	void Destory() { life = false; }
public:
	//void SetLayer(const TAG& tag) { this->tag = tag; }
	void SetLayer(const LAYER& layer) { this->layer = layer; }
	void SetZOrder(const int& _zorder) { ZOreder = _zorder; }
	void SetZOrder(Scene* pScene) { pScene = pScene; }


	int GetZOrder() const { return ZOreder; }
	LAYER GetLayer() const { return layer; }
	Scene* GetScene() const { return pScene; }

public:
	void AddMono(class MonoBehavior* pObj);

public:
	void Input(double deltaTime);
	int Update(double deltaTime);
	int LateUpdate(double deltaTime);
	void Collision(double deltaTime);
	void Render(HDC hdc, double deltaTime);
};

