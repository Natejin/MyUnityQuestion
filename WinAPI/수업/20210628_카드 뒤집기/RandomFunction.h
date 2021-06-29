#pragma once

#include "singleton.h"

class RandomFunction : public Singleton<RandomFunction> {
public:
	RandomFunction() { srand(GetTickCount64()); };
	~RandomFunction() {};

	inline int GetInt(int num) {return rand() % num;}
	inline int GetInt(int rangeMin, int rangeMax) {return rand() % (rangeMax- rangeMin + 1) + rangeMin;}


};