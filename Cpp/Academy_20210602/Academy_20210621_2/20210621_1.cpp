//

#include "pch.h"
#include"SLL.h"
#include"RecursiveSLL.h"
int main()
{
	SLL sll;


	sll.Insert(1);
	sll.Insert(2);
	sll.Insert(3);
	sll.Insert(4);
	sll.Insert(5);
	sll.Insert(6);
	sll.Insert(7);
	sll.Insert(8);
	sll.Insert(9);
	sll.Insert(10);

	sll.Print();
	sll.Delete(10);
	sll.Print();
	sll.Delete(7);
	sll.Print();
	sll.Delete(1);
	sll.Print();


	cout << "RecursiveSLL" << endl;
	RecursiveSLL rSll;

	rSll.Insert(51);
	rSll.Insert(11);
	rSll.Insert(21);
	rSll.Insert(31);
	rSll.Insert(41);
	rSll.Print();
	rSll.Delete(11);
	cout << endl;
	rSll.Print();

	

}
