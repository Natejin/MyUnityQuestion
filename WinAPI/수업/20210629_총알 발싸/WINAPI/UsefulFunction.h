#pragma once
#include "singleton.h"
#include "Obj.h"
//#include "MonoBehavior.h"

class UsefulFunction :public SingleTon<UsefulFunction>
{
public:
	UsefulFunction() {};
	~UsefulFunction() {};
	
	template <typename T>
	std::vector<T>* Shuffle(std::vector<T>* vec, int size);
	
	

	//static void DrawRect(HDC hdc, RECT rc);
	static void DrawRect(HDC hdc, RECT rc);
	static void DrawRect(HDC hdc, RECT rc, Color rgb);

	
};


