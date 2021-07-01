#pragma once
#include "Scene.h"
#include "../Obj/Player.h"
#include "Layer.h"

class InGameScene : public Scene
{


private:
	friend class SceneManager;
	InGameScene();
	~InGameScene();

public:
	virtual bool Init();

};

