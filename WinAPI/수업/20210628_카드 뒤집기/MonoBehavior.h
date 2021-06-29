#pragma once
#include "framework.h"

class MonoBehavior
{
	public:
		MonoBehavior() {};
		virtual ~MonoBehavior() {};

		virtual void init() {};
		virtual void release() {};
		virtual void update() {};
		virtual void render(HDC* hdc) {};
};

