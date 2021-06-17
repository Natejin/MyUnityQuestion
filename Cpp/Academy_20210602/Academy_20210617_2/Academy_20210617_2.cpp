
#include <iostream>
#include <vector>

using namespace std;

/*
STL: standard template library // 프로그램의 필욧한 알고리즘밑 자료구조를 템플릿으로 제공한다. 

STL의 구성요소
containor : 객체를 저장하는 객체 또는 컬렉션 혹은 자료구조

 
 시퀀스 컨테이너 : 선형구조 순서를 가짐 삽입위치
 1.첫번쨰 요소와 마지막 요소를 제외한 나머지 요소들은 반드시 인접한 데이터를 가지고 있어야한다.
 2. 모든 요소가 직선순서로 배치 되어 있어야한다.

 (vector, List, deque, forward_list)
 string 시퀀스 컨테이너지만 문자열만 가능;

 vector : 동적배열(가변배열) heap에 생성이 된다.


 배열기반 컨테이너 
 로드기반 컨테이너 
 set map multimap multiset


 반복자(Iterator):  포인터와 비슷한 개념으로 컨테이너의 원소를 접근하여
가리키는 원소에 접근하여 다음 원소를 가리키게 하는 기능
*/



class myclass {


};

int main()
{
	vector<int> vec1;
	for (size_t i = 1; i < 100; i++)
	{
		vec1.push_back(i * 10);
	}
	//for (int i = 0; i < vec1.size(); i++)
	//{
	//	cout << vec1[i] << endl;
	//}

	cout << "벡터의 크기\t : " << vec1.size() << endl;
	cout << "벡터의 capacity\t : " << vec1.capacity() << endl;
	cout << "벡터의 최대저장\t : " << vec1.max_size() << endl;


	for (int i = 0; i < vec1.size(); i++)
	{
		vec1.pop_back();
		cout << "벡터의 크기\t : " << vec1.size() << endl;
		cout << "벡터의 capacity\t : " << vec1.capacity() << endl;
		cout << "벡터의 최대저장\t : " << vec1.max_size() << endl;
	}


}
