//#pragma once
#include <Windows.h>
#include <iostream>

//////////////////////////////////////////
//				STL						//
//////////////////////////////////////////

#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

//////////////////////////////////////////
//			Custom Header				//
//////////////////////////////////////////

#include "resource.h"
#include "Macro.h"
#include "Flag.h"
#include "Types.h"
//#include "Core/Structure/Vector2.h"


//template <typename T>
//void Safe_Delete_VecList(T& p) {
//	T::iterator iter;
//	T::iterator iterEnd = p.end();
//
//	for (iter = p.begin(); iter != iterEnd; ++iter)
//	{
//		SAFE_DELETE((*iter));
//			
//	}
//	p.clear();
//}