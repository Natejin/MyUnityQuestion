#pragma once


struct node
{
	int value;//��
	node* pNext;//��带 ����ų�� �ִ������ͤ�

	node(int n) : value(n),pNext(NULL){}
};

class SLL
{
private:

	node* pHead;//�Ӹ�
public:
	SLL();
	~SLL();

	void Insert(int num);
	void Delete(int num);
	void Print();
};

