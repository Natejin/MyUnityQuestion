#pragma once
#include "framework.h"

class Obj 
{

public:
	Obj() :ID(0) {};
	Obj(int id) : ID(id) {};
	virtual ~Obj(){};
	int ID;
	
};
