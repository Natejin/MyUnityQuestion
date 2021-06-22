#include "pch.h"
#include "SLL.h"

SLL::SLL() : pHead(NULL){}

SLL::~SLL()
{
	while (pHead!=NULL)
	{
		node* temp = pHead;
		pHead = pHead->pNext;
		delete temp;
	}
}

void SLL::Insert(int num)
{
	node* newNode = new node(num);

	if (pHead == NULL) {
		pHead = newNode;
		return;
	}
	else{
		node* temp = pHead;
		while (temp->pNext !=NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = newNode;
	}
}

void SLL::Delete(int num)
{
	node* pCurrent = pHead;
	node* pNext = pHead->pNext;

	if (pCurrent->value == num)
	{
		pHead = pNext;
		delete pCurrent;
		return;
	}
	while (pNext->value !=num)
	{
		pCurrent = pCurrent->pNext;
		pNext = pNext->pNext;
		if (pNext == NULL)return;
	}
	pCurrent->pNext = pNext->pNext;
	delete pNext;
}

void SLL::Print()
{
	node* temp = pHead;
	cout << "=========Print=========" << endl;
	while (temp!=NULL)
	{
		cout << temp->value << " ";
		temp = temp->pNext;
	}
	cout << endl;
}
