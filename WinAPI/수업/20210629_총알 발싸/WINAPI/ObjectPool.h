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
	//오브젝트풀에 객체가 존재하는지확인
	//객체가 존재하면 가져옴
	//객체가 존재하지않으면 새로 생성해서 가져옴
	//해당 아이디넘버가 없어도 새로 생성해서 가져옴
	T* GetObject() {
		//남아있는 오브젝트가 있을경우
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

	//객체돌려주기
	void ReturnObject(T* object) {
		//객체가 없을경우
		que.push(object);
	}
};


