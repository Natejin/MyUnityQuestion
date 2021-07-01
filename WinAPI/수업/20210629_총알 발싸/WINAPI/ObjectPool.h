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
//	//������ƮǮ�� ��ü�� �����ϴ���Ȯ��
//	//��ü�� �����ϸ� ������
//	//��ü�� �������������� ���� �����ؼ� ������
//	//�ش� ���̵�ѹ��� ��� ���� �����ؼ� ������
//	T* GetPoolObj() {
//		//�����ִ� ������Ʈ�� �������
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
//	//��ü�����ֱ�
//	//void ReturnObject(T object) {
//	//	//��ü�� �������
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

    // ������Ʈ�� ������.
    //template<typename T = Obj>

    T* PopObject()
    {
        T* retVal;
        // ������ ������ �ϳ� �� ������.
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

    // ������Ʈ�� �����Ѵ�.
    void ReturnObject(T* object)
    {
        object->~T();
        queueObject.push(object);
    }

    int GetObjectPoolSize() { return maxSize; }
    int GetStockSize() { return queueObject.size(); }

private:
    queue<T*> queueObject;
    std::atomic<int> maxSize; // �ִ� �迭 ũ�� (���� üũ�� ����͸� �뵵�� ����ϸ� ������)
};