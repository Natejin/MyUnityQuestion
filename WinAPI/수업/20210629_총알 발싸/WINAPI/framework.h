// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


#include<iostream>
using namespace std;
//==========================================
//					STL
//==========================================
#include <vector>
#include<vector>
#include<map>
#include<list>

//==========================================
//				   Enum
//==========================================

#include "enum.h"

//==========================================
//				 내가만든 헤더파일
//==========================================
#include "commonMacroFunction.h"
#include "Input.h"
#include "RandomFunction.h"

#include "Obj.h"
#include "Macro.h"
#include "ObjectPool.h"
#include "Image.h"
#include "TimeManager.h"

//==========================================
//				    Struct
//==========================================
#include "Vector2.h"
#include "Color.h"
#include "Inline.h"

//==========================================
//				    Manager
//==========================================

#define MG_INPUT		InputManager::GetSingleton()
#define MG_RND			RandomManager::GetSingleton()
#define MG_TIME			TimeManager::GetSingleton()
#define UFUNC			UsefulFunction::GetSingleton()
//#define UFUNC			UsefulFunction::GetSingleton()


#include "UsefulFunction.h"





//==========================================
//			메인게임 릴리즈에서 사용
//==========================================




//========================================================
//		전역변수 아이들(인스턴스,윈도우 핸들, 마우스 좌표)
//========================================================

extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;

