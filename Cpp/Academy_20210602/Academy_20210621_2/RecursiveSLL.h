#pragma once
#include"Node.h"
class RecursiveSLL
{
private:
	Node* _pHead;
public:
	RecursiveSLL();
	~RecursiveSLL();

	void Insert(int value);
	void Delete(int value);
	void Print();

};

