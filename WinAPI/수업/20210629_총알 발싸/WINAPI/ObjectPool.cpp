#include "ObjectPool.h"


template<typename T>
ObjectPool<T>* ObjectPool<T>::Instance = 0;

template<typename T>
ObjectPool<T>& ObjectPool<T>::GetInstance()
{
	
}