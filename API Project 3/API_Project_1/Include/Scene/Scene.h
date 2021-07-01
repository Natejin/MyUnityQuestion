#pragma once
#include "../Game.h"

class Scene
{
private:
	friend class SceneManager;
protected:
	Scene();
	virtual ~Scene() = 0;

protected:
	list<class Layer*> layerList;
public:
	class Layer* CreateLayer(const TAG& tag, int order =0);
	class Layer* FindLayer(const TAG& tag);
public:
	virtual bool Init();
	virtual void Input(float deltaTime);
	virtual int Update(float deltaTime);
	virtual int LateUpdate(float deltaTime);
	virtual void Render(HDC hdc, float deltaTime);

	virtual void Collision(float deltaTime);
	static bool LayerSort(class Layer* pL1, class Layer* pL2);

	virtual bool Enable();
	virtual bool Disable();
};

