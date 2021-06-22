#pragma once


struct node
{
	int value;//값
	node* pNext;//노드를 가르킬수 있는포인터ㄴ

	node(int n) : value(n),pNext(NULL){}
};

class SLL
{
private:

	node* pHead;//머리
public:
	SLL();
	~SLL();

	void Insert(int num);
	void Delete(int num);
	void Print();
};

