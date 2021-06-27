#pragma once
#include "../Game.h"

class Scene
{
private:
	friend class SceneManager;
protected:
	Scene();
	virtual ~Scene();

public:
	virtual bool Init();
};

