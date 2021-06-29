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
	string tag;
	int ZOreder;// 출력 순서

public:
	void SetTag(const string& tag) {
		this->tag = tag;
		
	}

	void SetZOrder(const int& _zorder) {
		ZOreder =_zorder;
	}

	int GetZOrder() const {
		return ZOreder;
	}

	string GetTag() const {
		return tag;
	}
};

