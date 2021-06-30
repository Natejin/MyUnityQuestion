#pragma once

#include"singleton.h"
class RandomFunction :public Singleton<RandomFunction>
{
public:
	RandomFunction() { srand(GetTickCount()); };
	~RandomFunction() {};

	inline int GetInt(int num) { return rand() % num; }
	inline int GetFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}
};

