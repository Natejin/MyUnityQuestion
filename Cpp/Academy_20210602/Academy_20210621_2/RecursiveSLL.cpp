#include "pch.h"
#include "RecursiveSLL.h"

RecursiveSLL::RecursiveSLL() : _pHead(NULL)
{
}

RecursiveSLL::~RecursiveSLL()
{
}

void RecursiveSLL::Insert(int value)
{
	Node* pNode = new Node(value);

	if (_pHead)
	{
		_pHead->insert(pNode);
	}
	else {
		_pHead = pNode;
	}

}

void RecursiveSLL::Delete(int value)
{
	if (_pHead)
	{
		_pHead->Delete(value, &_pHead);
	}
}

void RecursiveSLL::Print()
{
	if (_pHead)
	{
		_pHead->print();
	}
}
