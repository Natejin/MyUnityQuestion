#pragma once
class Node
{
public:

	Node(int value= 0,Node* pNext = NULL);
	~Node();

	int _value;
	Node* _pNext;

	void insert(Node* pNode);
	void print();
	void Delete(int value, Node** ppThis);


};

