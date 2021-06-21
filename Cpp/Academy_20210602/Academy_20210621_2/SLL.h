#pragma once

struct node {
	int value;
	node* pNext;
	node(int n) : value(n), pNext(nullptr) {}

};

class SLL
{
	node* pHead;
public:
	SLL();
	~SLL();

	void Insert(int num);
	//void Insert(int num);
};

