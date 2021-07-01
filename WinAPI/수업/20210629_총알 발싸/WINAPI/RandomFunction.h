#pragma once

#include "singleton.h"
#include <Windows.h>
class RandomManager :public Singleton<RandomManager>
{
public:
	RandomManager() {  
		//srand(GetTickCount64());
	};
	~RandomManager() {};

	inline int GetInt(int num) { return rand() % num; }
	inline int GetFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}
};

