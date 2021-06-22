#include<iostream>
#include<assert.h>


#define MAX_VALUE 5
template<typename T>class Queue
{
private:

	int front, rear;
	T values[MAX_VALUE];

public:
	Queue() :front(-1), rear(-1)
	{
		memset(values, 0, sizeof(T) * MAX_VALUE);
	}
	bool IsEmpty()
	{
		return front == rear ? true : false;
	}
	bool IsFull()
	{
		return rear == MAX_VALUE - 1 ? true : false;
	}
	void Enqueue(T val)
	{
		bool check = IsFull();
		assert(check == false);
		values[++rear] = val;
	}
	T Dequeue()
	{
		bool check = IsEmpty();
		assert(check == false);
		return values[++front];
	}
};


int main() {

	Queue<int>* q = new Queue<int>();

	q->Enqueue(10);
	q->Enqueue(20);
	q->Enqueue(30);
	q->Enqueue(40);
	q->Enqueue(50);


	std::cout << q->Dequeue() << " ";
	std::cout << q->Dequeue() << " ";
	std::cout << q->Dequeue() << " ";
	std::cout << q->Dequeue() << " ";



	delete q;


}