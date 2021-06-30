#pragma once

#include <queue>
#include "singleton.h"
#include <map>
#include "Macro.h"
#include "PoolableObject.h"

using namespace std;




template<typename T = PoolableObject>
class ObjectPool
{
	//map<int, queue<PoolableObject>> maps;
private:                                                 
	ObjectPool(const ObjectPool&);                         
	ObjectPool& operator=(const ObjectPool&);

									  
private:                                               
	ObjectPool() {}                                            
	static ObjectPool* Instance;                               
		public:                                                
	static ObjectPool& GetInstance();

	queue<T*> que;
	int id = 0;
public:
	//������ƮǮ�� ��ü�� �����ϴ���Ȯ��
	//��ü�� �����ϸ� ������
	//��ü�� �������������� ���� �����ؼ� ������
	//�ش� ���̵�ѹ��� ��� ���� �����ؼ� ������
	T* GetObject() {
		//�����ִ� ������Ʈ�� �������
		if (que.size() > 0)
		{
			T* temp = que.front();
			que.pop();
			return temp;
		}
		else {
			T* temp = new T(id);
			return temp;
		}
		
	}

	//��ü�����ֱ�
	void ReturnObject(T* object) {
		//��ü�� �������
		que.push(object);
	}
};


