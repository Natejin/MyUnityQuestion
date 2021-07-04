#pragma once

#include "Game.h"
#include "Scene/Layer.h"

class Object
{
protected:
	Object();
	virtual ~Object() {};

protected:
	//Object 이름
	string name;

	//참조하는 횟수
	int ref;



public:
	void AddRef() {
		++ref;
	}

	int Release() {
		--ref;
		if (ref==0)
		{
			delete this;
			return 0;
		}
		return ref;
	}


protected:
	//객체를 껐다 키는용도 (Unity
	bool enable;

	//살리고 죽이는 변수
	bool life;


public:
	void SetEnable(bool enable) {this->enable = enable;}	
	bool GetEnable() const{	return enable;}

	bool GetLife() const { return life; }
	void Destory() { life = false; }
};

