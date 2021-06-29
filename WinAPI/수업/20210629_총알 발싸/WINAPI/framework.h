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

using namespace std;
//==========================================
//					STL
//==========================================
#include <vector>


//==========================================
//				 내가만든 헤더파일
//==========================================
#include "commonMacroFunction.h"
#include "Input.h"
#include "RandomFunction.h"
#include "Obj.h"

//==========================================
//				    Manager
//==========================================

#define InputManager	Input::GetSingleTon()
#define RND				RandomFunction::GetSingleTon()
#define UFUNC			UsefulFunction::GetSingleTon()

//==========================================
//				   Enum
//==========================================

#include "enum.h"

//==========================================
//				    Struct
//==========================================
struct Color
{
	Color(int r, int g, int b) :r(r), g(g), b(b) {};
	Color() :r(0), g(0), b(0) {};
	~Color() {};
	int r, g, b;

	void Random() {
		r = RND->GetInt(256);
		g = RND->GetInt(256);
		b = RND->GetInt(256);
	}

	Color GetColor(COLOR color) {
		switch (color)
		{
		case COLOR::RED:
			r = 255;
			g = 0;
			b = 0;
			break;
		default:
			break;
		}
		return *this;
	}
};

struct Vector2
{
	double x, y;

    Vector2() { x = 0; y = 0; }
    Vector2(double x, double y) :x(x), y(y) {};
    void SetPos(double _x, double _y) {
        x = _x;
        y = _y;
    }

    bool operator !=(const Vector2& Other) const
    {
        return (x != Other.x || y != Other.y);
    }

    bool operator ==(const Vector2& Other) const
    {
        return (x == Other.x && y == Other.y);
    }

    Vector2& operator+=(const Vector2& rhs) {

        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    Vector2& operator-=(const Vector2& rhs) {

        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    Vector2& operator-() {
        this->x = -(this->x);
        this->y = -(this->y);
        return *this;
    }

    Vector2 operator +(const Vector2& Other) const
    {
        return Vector2(x + Other.x, y + Other.y);
    }

    Vector2 operator *(const double& Other) const
    {
        return Vector2(x * Other, y * Other);
    }

    Vector2 operator -(const Vector2& Other) const
    {
        return Vector2(x - Other.x, y - Other.y);
    }
};



#include "UsefulFunction.h"

//==========================================
//				 매크로 설정
//==========================================
#define WINNAME			(LPTSTR)(TEXT("카드뒤집기"))
#define WINSTARTX		100
#define WINSTARTY		100
#define WINSIZEX		1024
#define WINSIZEY		768
#define	WINSTYLE		WS_CAPTION | WS_SYSMENU


//==========================================
//			메인게임 릴리즈에서 사용
//==========================================

#define SAFE_DELETE(p) {if(p) {delete(p);(p) = nullptr;}}



//========================================================
//		전역변수 아이들(인스턴스,윈도우 핸들, 마우스 좌표)
//========================================================

extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;

