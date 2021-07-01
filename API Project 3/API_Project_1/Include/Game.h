//#pragma once
#include <Windows.h>
#include <iostream>

//////////////////////////////////////////
//				STL						//
//////////////////////////////////////////

#include <vector>
#include <unordered_map>
#include <map>
#include <list>

using namespace std;

//////////////////////////////////////////
//			Custom Header				//
//////////////////////////////////////////
#include "Enum.h"
#include "resource.h"
#include "Macro.h"
#include "Types.h"
#include "Inline.h"
#include "Core/Image/Image.h"


//////////////////////////////////////////
//			Custom Struct				//
//////////////////////////////////////////
#include "Core/Structure/Color.h"
#include "Core/Structure/Vector2.h"

//////////////////////////////////////////
//			Obj							//
//////////////////////////////////////////




// extern
extern HINSTANCE g_hInstance;
extern HWND g_hWnd;
extern POINT g_ptMouse;

//const double Pi = 3.141592;
//
//template <typename T>
//void Safe_Release_VecList(T& p) {
//	T::iterator iter;
//	T::iterator iterEnd = p.end();
//
//	for (iter = p.begin(); iter != iterEnd; ++iter)
//	{
//		SAFE_RELEASE((*iter));
//	}
//	p.clear();
//}
//
//template <typename T>
//void Safe_Delete_VecList(T& p) {
//	T::iterator iter;
//	T::iterator iterEnd = p.end();
//
//	for (iter = p.begin(); iter != iterEnd; ++iter)
//	{
//		SAFE_DELETE((*iter));
//	}
//	p.clear();
//}