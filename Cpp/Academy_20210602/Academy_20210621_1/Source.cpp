#include<iostream>
#include<list>
#include<vector>
using namespace std;


int main() {

	//list <int>lt;
	////µÚ
	//lt.push_back(10);
	//lt.push_back(20);
	//lt.push_back(30);
	//lt.push_back(40);
	//lt.push_back(50);

	//list<int>::iterator iter;
	//for (iter = lt.begin(); iter != lt.end(); ++iter)
	//{
	//	cout << *iter << "	";
	//}
	//cout << endl;

	////¾ÕÂÊ
	//lt.push_front(100);
	//lt.push_front(200);

	//for (iter = lt.begin(); iter != lt.end(); ++iter)
	//{
	//	cout << *iter << "	";
	//}
	//cout << endl << endl;
	//cout <<"================================"<< endl;

	//list<int>lt1;
	//lt1.push_back(10);
	//lt1.push_back(20);
	//lt1.push_back(30);
	//lt1.push_back(40);
	//lt1.push_back(50);

	//list<int>::iterator iter1 = lt1.begin();
	//list<int>::iterator iter2;

	//++iter1;
	//++iter1;
	//
	//iter2 = lt1.erase(iter1);


	//for (iter1 = lt1.begin(); iter1 != lt1.end(); ++iter1)
	//{
	//	cout << *iter1 << "	";
	//}
	//cout << endl;
	//cout << "*iter2 :" << *iter2 << endl;


	//iter1 = iter2;
	//iter2 = lt1.insert(iter1, 300);
	//for (iter1 = lt1.begin(); iter1 != lt1.end(); ++iter1)
	//{
	//	cout << *iter1 << "	";
	//}
	//cout << endl;



	//////////////////////////////////////////////////////


	vector<int>v;
	list<int> li;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);


	li.push_back(10);
	li.push_back(20);
	li.push_back(30);
	li.push_back(40);
	li.push_back(50);

	vector<int>::iterator vIter = v.begin();
	list<int>::iterator liIter = li.begin();

	++vIter;
	++liIter;

	vIter = v.insert(vIter, 500);
	liIter = li.insert(liIter, 500);

	cout << "vIter  : " << *vIter << endl;
	cout << "liIter  : " << *liIter << endl;

	for (vIter = v.begin(); vIter != v.end(); ++vIter)
	{
		cout << *vIter << " ";
	}
	cout << endl;
	for (liIter = li.begin(); liIter != li.end(); ++liIter)
	{
		cout << *liIter << " ";
	}
	cout << endl;


	/////////////////////////////////////////////////////
	cout << "================================" << endl;
	list<int> lt3;
	lt3.push_back(10);
	lt3.push_back(60);
	lt3.push_back(100);
	lt3.push_back(10);
	lt3.push_back(110);
	lt3.push_back(10);
	lt3.push_back(50);

	list<int>::iterator iter3;

	for (iter3 = lt3.begin(); iter3 != lt3.end(); ++iter3)
	{
		cout << *iter3 << " ";
	}

	cout << endl;

	lt3.remove(10);
	for (iter3 = lt3.begin(); iter3 != lt3.end(); ++iter3)
	{
		cout << *iter3 << " ";
	}

	cout << endl;

}