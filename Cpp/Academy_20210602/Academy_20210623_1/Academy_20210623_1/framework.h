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
//			��ũ�� ���� 
//===================================
#define WINNAME			(LPTSTR)(TEXT("�ѹ��� �������� ������ ����"))
#define WINSTARTX		100
#define WINSTARTY		100
#define WINSIZEX		1024
#define WINSIZEY		768
#define WINSTYLE		WS_CAPTION|WS_SYSMENU
//===================================
//		���ΰ��� ������� ��� 
//===================================
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}
//======================================
//��������(�ν��Ͻ�,�������ڵ�,���콺 ��ǥ) 
//======================================

//extern HINSTANCE hInstance;
//extern HWND hWnd;
extern POINT ptMouse;