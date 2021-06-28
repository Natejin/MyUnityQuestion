// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

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
#include "Resource.h"

//==========================================
//					STL
//==========================================
#include <vector>
#include <cmath>



//==========================================
//				 내가만든 헤더파일
//==========================================
#include "commonMacroFunction.h"
#include "Input.h"
#include "RandomFunction.h"


//==========================================
//				 네임 스페이스
//==========================================



//======================================
//##			매니저들			  ##
//======================================
#define InputManager    Input::getSingleton()
#define RND             RandomFunction::getSingleton()


//==========================================
//				 매크로 설정
//==========================================
#define WINNAME			(LPTSTR)(TEXT("지옥으로 떠나는 여행"))
#define WINSTARTX		100
#define WINSTARTY		100
#define WINSIZEX		1400
#define WINSIZEY		1000
#define	WINSTYLE		WS_CAPTION | WS_SYSMENU


//==========================================
//			메인게임 릴리즈에서 사용
//==========================================

#define SAFE_DELETE(p) {if(p) {delete(p);(p) = nullptr;}}


//==========================================
//			구조체
//==========================================

struct Vector2Int {
    int x;
    int y;

    Vector2Int() { x = 0; y = 0; }
    Vector2Int(int x, int y) :x(x), y(y) {};
    void SetPos(int _x, int _y) {
        x = _x;
        y = _y;
    }

    bool operator !=(const Vector2Int& Other) const
    {
        return (x != Other.x || y != Other.y);
    }

    bool operator ==(const Vector2Int& Other) const
    {
        return (x == Other.x && y == Other.y);
    }


    Vector2Int operator +(const Vector2Int& Other) const
    {
        return Vector2Int(x + Other.x, y + Other.y);
    }

    Vector2Int operator -(const Vector2Int& Other) const
    {
        return Vector2Int(x - Other.x, y - Other.y);
    }
};

struct Vector2Bool {
    bool x;
    bool y;

    bool GetBool() {
        return x & y ? true : false;
    }

};

struct Color {
    int r;
    int g;
    int b;

    Color():r(0), g(0), b(0) {};
    Color(int r, int g, int b):r(r), g(g), b(b) {}
    ~Color() {};
    void Random() {
        r = rand() % 256;
        g = rand() % 256;
        b = rand() % 256;
    }

    void Random(int min) {
        r = rand() % (256 - min) + min;
        g = rand() % (256 - min) + min;
        b = rand() % (256 - min) + min;
    }
};

struct Vector2 {
    double x;
    double y;

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

    void SetRandomVector(Vector2 base, Vector2 random) {
        if (random.x > 0)
        {
            this->x = RND->GetInt(base.x, random.x);
        }
        else {
            this->x = base.x;
        }
        if (random.y > 0)
        {
            this->y = RND->GetInt(base.y, random.y);
        }
        else {
            this->y = base.y;
        }
    }

    void SetRandomVectorX(Vector2 base, Vector2 random) {
        if (random.x > 0)
        {
            x = RND->GetInt(base.x, random.x);
        }
        else {
            x = base.x;
        }
    }

    void SetRandomVectorY(Vector2 base, Vector2 random) {
        if (random.y > 0)
        {
            y = RND->GetInt(base.y, random.y);
        }
        else {
            y = base.y;
        }
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

//==========================================
//			베이직 클래스
//==========================================
class Rect {
public:
    //RECT* rect;
    double x = 0;
    double y = 0;
    double left = 0;
    double right = 0;
    double top = 0;
    double bottom = 0;
    double width = 0;
    double height = 0;

    Rect() { }
    ~Rect() {}

    Rect(double posX, double posY, double _width, double _height)
    {
        x = posX;
        y = posY;
        this->width = _width * 0.5f;
        this->height = _height * 0.5f;
    }

    Rect(Vector2 pos, double width, double height)\
        :Rect(pos.x, pos.y, width, height)
    {
        
    }



    void Translate(Vector2 position) {
        x += position.x;
        y += position.y;
    }

    void Translate(double _x, double _y) {
        x += _x;
        y += _y;
    }

    void SetPos(Vector2 position) {
        x = position.x;
        y = position.y;
    }

    void SetPos(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void Render(HDC* hdc) {
        SetUpLTRBFromXY();
        Rectangle(*hdc, left, top, right, bottom);
    }

    void SetUpLTRBFromXY() {
        left = x - width;
        top = y - height;
        right = x + width;
        bottom = y + height;
    }

    Vector2Bool Collided(Rect* another) {
        Vector2Bool a;
        SetUpLTRBFromXY();
        another->SetUpLTRBFromXY();
        if (left <= another->right &&
            another->left <= right)
        {
			a.x = true;
        }
        else {
            a.x = false;
        }

        if (top <= another->bottom &&
            another->top <= bottom)
        {
            a.y = true;
        }
        else {
            a.y = false;
        }
        return a;
    }
};

//========================================================
//		전역변수 아이들(인스턴스,윈도우 핸들, 마우스 좌표)
//========================================================

extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;

//Vector2 const vectorZero = Vector2(0, 0);

double const gravity = 1;
double const fallSpeedMax =15;

static HBRUSH brush, oBrush;
static RECT g_RECT;
