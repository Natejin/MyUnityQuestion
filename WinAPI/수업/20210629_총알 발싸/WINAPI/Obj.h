#pragma once
#include "framework.h"

class Obj 
{

public:
	Obj() {};
	Obj(int id, int classID) : instanceID(id), classID(classID) {};
	virtual ~Obj(){};

public:
	int instanceID;
	int classID;
	int ID;
	
};
