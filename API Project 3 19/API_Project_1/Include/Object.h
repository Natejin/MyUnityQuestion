#pragma once

#include "Game.h"
#include "Scene/Layer.h"

class Object
{
protected:
	Object();
	virtual ~Object() {};

protected:
	//Object �̸�
	string name;

	//�����ϴ� Ƚ��
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
	//��ü�� ���� Ű�¿뵵 (Unity
	bool enable;

	//�츮�� ���̴� ����
	bool life;


public:
	void SetEnable(bool enable) {this->enable = enable;}	
	bool GetEnable() const{	return enable;}

	bool GetLife() const { return life; }
	void Destory() { life = false; }
};

