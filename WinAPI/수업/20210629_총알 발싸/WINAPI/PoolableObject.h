#pragma once
class PoolableObject {
	int objectId;
	bool setId = true;
public:
	//PoolableObject():objectId(NULL) {};
	//PoolableObject(){};
	PoolableObject(int id) :objectId(id) {};
	~PoolableObject() {};
	int GetID() { return objectId; }
};