#include "pch.h"
#include "Node.h"

Node::Node(int value, Node* pNext)
	:_value(value), _pNext(pNext)
{
}

Node::~Node()
{
}

void Node::insert(Node* pNode)
{
	if (_pNext)
	{
		_pNext->insert(pNode);
	}
	else {
		_pNext = pNode;
	}
}

void Node::print()
{
	cout << _value << " ";
	if (_pNext) 
	{
		_pNext->print();
	}
}

void Node::Delete(int value, Node** ppThis)
{
	if (value == this->_value) {
		*ppThis = _pNext;
		delete this;
	}
	else if(_pNext) {
		_pNext->Delete(value, &_pNext);
	}
}
