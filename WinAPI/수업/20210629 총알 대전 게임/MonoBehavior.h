#pragma once
#include "framework.h"

class MonoBehavior
{



	public:
		MonoBehavior() {};
		virtual ~MonoBehavior() {};

		virtual void Init() {};
		virtual void Release() {};
		virtual void Update() {};
		virtual void Render(HDC hdc) {};
};

