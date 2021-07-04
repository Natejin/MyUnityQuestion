#pragma once

#include "../Core/Singleton.h"
class Camera : public Singleton<Camera>
{
private:
	Vector2 
public:
	Camera();
	virtual ~Camera();

	bool Init();
};

