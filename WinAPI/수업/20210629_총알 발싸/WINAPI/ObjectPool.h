#pragma once
#include <queue>
#include <type_traits>
#include <atomic>

using namespace std;

//template<class T>
//class ObjectPool
//{
//						  
//private:                                               
//	ObjectPool() { Instance = nullptr}
//	~ObjectPool() {
//		for (auto it = que.begin(); it != que.end(); ++it)
//			delete* it;
//	}                                        
//	static ObjectPool* Instance;
//public:                                                
//	static ObjectPool* GetInstance();
//
//
//	vector<T*> que;
//	int id = 0;
//public:
//	//오브젝트풀에 객체가 존재하는지확인
//	//객체가 존재하면 가져옴
//	//객체가 존재하지않으면 새로 생성해서 가져옴
//	//해당 아이디넘버가 없어도 새로 생성해서 가져옴
//	T* GetPoolObj() {
//		//남아있는 오브젝트가 있을경우
//		if (que.size() > 0)
//		{
//			T* temp = que.back();
//			que.pop_back();
//			return temp;
//		}
//		else {
//			T* temp = new T();
//			return temp;
//		}
//		
//	}
//
//	//객체돌려주기
//	//void ReturnObject(T object) {
//	//	//객체가 없을경우
//	//	que.push(object);
//
//	//}
//};
//
//

//template<typename T = Obj>
template<typename T = PoolableObject>
class ObjectPool {
public:
    int instanceID;
    ObjectPool() {
        maxSize = 0;
        instanceID = 0;
    }

    ObjectPool(int num) {
        maxSize = num;
        for (int i = 0; i < maxSize; ++i) {
            T* newObject = new T(instanceID, 0);
            instanceID++;
            queueObject.push(newObject);
        }
    }

    ~ObjectPool()
    {
        while (!queueObject.empty()) {
            T* object = queueObject.front();
            queueObject.pop();
            maxSize--;
            delete object;
        }
    }

    // 오브젝트를 꺼낸다.
    //template<typename T = Obj>

    T* PopObject()
    {
        T* retVal;
        // 꺼낼게 없으면 하나 걍 만들자.
        if (queueObject.empty()) {
            retVal = new T(instanceID, 0);
            instanceID++;            
            ++maxSize;
        }
        else {
            retVal = queueObject.front();
            queueObject.pop();
        }

        return new (retVal) T;
    }

    // 오브젝트를 수거한다.
    void ReturnObject(T* object)
    {
        object->~T();
        queueObject.push(object);
    }

    int GetObjectPoolSize() { return maxSize; }
    int GetStockSize() { return queueObject.size(); }

private:
    queue<T*> queueObject;
    std::atomic<int> maxSize; // 최대 배열 크기 (누수 체크나 모니터링 용도로 사용하면 좋을듯)
};