#pragma once


class PoolableObject {
protected:
	int ID;
	int instanceID;
	int classID;
public:
	//PoolableObject():objectId(NULL) {};
	PoolableObject() :ID(-1) {};
	PoolableObject(int instanceID, int classID) :ID(-1), instanceID(instanceID), classID(classID){};
	~PoolableObject() {};
	int GetID() { return ID; }
	void SetID(int ID) { this->ID = ID; }
	int GetInstanceID() { return instanceID; }
	int GetClassID() { return classID; }
};