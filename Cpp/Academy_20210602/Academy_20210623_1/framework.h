// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>




#include"commonMacroFunction.h"
#include <wchar.h>
//===================================
//			매크로 설정 
//===================================
#define WINNAME			(LPTSTR)(TEXT("한번더 지옥으로 떠나는 여행"))
#define WINSTARTX		100
#define WINSTARTY		100
#define WINSIZEX		1024
#define WINSIZEY		768
#define WINSTYLE		WS_CAPTION|WS_SYSMENU
//===================================
//		메인게임 릴리즈에서 사용 
//===================================
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}
//======================================
//전역변수(인스턴스,윈도우핸들,마우스 좌표) 
//======================================

//extern HINSTANCE hInstance;
//extern HWND hWnd;
extern POINT ptMouse;