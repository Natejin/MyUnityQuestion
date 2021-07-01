#pragma once

#include "Game.h"

class Ref
{
protected:
	Ref() :ref(1) {};
	virtual ~Ref() {};

protected:
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
};

