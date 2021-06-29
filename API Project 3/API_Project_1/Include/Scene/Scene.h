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
	class Layer* CreateLayer(const string& tag, int order =0);
public:
	virtual bool Init();

	static bool LayerSort(class Layer* pL1, class Layer* pL2);
};

