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


using namespace std;







//==========================================
//					STL
//==========================================
#include <vector>

//==========================================
//				구조체
//==========================================
#pragma region 구조체
#pragma region 벡터
struct Vector2Int {
    int x;
    int y;

    Vector2Int() { x = 0; y = 0; }
    Vector2Int(int x, int y) :x(x), y(y) {};
    void SetPos(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct Vector2 {
    float x;
    float y;

    Vector2() { x = 0; y = 0; }
    Vector2(float x, float y) :x(x), y(y) {};
    void SetPos(float _x, float _y) {
        x = _x;
        y = _y;
    }
};
#pragma endregion

#pragma region 마우스 구조체
struct MouseDragArea {
    bool mouseDownLeft = false;
    bool mouseDownRight = false;
    POINT ptStart;
    POINT ptEnd;

    bool isButtonUpBoth() {
        return !mouseDownLeft && !mouseDownRight ? true : false;
    }

};
#pragma endregion

#pragma region 도형 구조체
typedef struct _tagRectangle {
    float left, top, right, bottom;

    _tagRectangle() {};
    _tagRectangle(float left, float top, float right, float bottom) {
        this->left = left;
        this->top = top;
        this->right = right;
        this->bottom = bottom;
    };
    ~_tagRectangle() {};

}RECTANGLE, * PRECTANGLE;



struct Rect {
    RECTANGLE rect;
    int x = 0;
	int y = 0;
    int width = 0;
    int height = 0;
    Vector2Int previousPos = Vector2Int(0, 0);
    Rect() {
        //rect = RECTANGLE();
        rect = { 0, 0,0,0 };
        //rect.left = 0;
        //rect.top = 0;
        //rect.right = 0;
        //rect.bottom = 0;
        previousPos = Vector2Int(0, 0);
    };
    Rect(MouseDragArea startPos)

    {
        //rect = RECTANGLE();
        rect = { 
            (float)startPos.ptStart.x, 
            (float)startPos.ptStart.y,
            (float)startPos.ptStart.x,
            (float)startPos.ptStart.y };
        //rect.left = startPos.ptStart.x;
        //rect.top = startPos.ptStart.y;
        //rect.right = startPos.ptStart.x;
        //rect.bottom = startPos.ptStart.y;
        previousPos = Vector2Int(0, 0);
    }

    Rect(float posX, float posY, float _width, float _height)
    {
        //rect = RECTANGLE();
        width = _width * 0.5f;
        height = _height * 0.5f;
        rect = { posX - width, 
            posY - height,
            posX + width,
            posY + height };
 /*       rect.left = posX - width;
        rect.top = posY - height;
        rect.right = posX + width;
        rect.bottom = posY + height;*/
        x = posX;
        y = posY;
    }
    ~Rect() {
    }
    void CreatedRect(MouseDragArea endPos) {
        rect.right = endPos.ptEnd.x;
        rect.bottom = endPos.ptEnd.y;

        width = (rect.right - rect.left) * 0.5;
        height = (rect.bottom - rect.top) * 0.5;

        x = endPos.ptEnd.x - width;
        y = endPos.ptEnd.y - height;

    }

    void CreatingRect(MouseDragArea pos) {

        rect.right = pos.ptEnd.x;
        rect.bottom = pos.ptEnd.y;
    }

    void TranslateBegin(MouseDragArea position) {
        previousPos.x = position.ptEnd.x - x;
        previousPos.y = position.ptEnd.y - y;
    }

    void  COffsetRect(int _x, int _y) {
        rect.left += _x;
        rect.right += _x;
        rect.top += _y;
        rect.bottom += _y;

        x += _x;
        y += _y;


    }

    void  COffsetRect(Vector2Int vector) {
        rect.left += vector.x;
        rect.right += vector.x;
        rect.top += vector.y;
        rect.bottom += vector.y;

        x += vector.x;
        y += vector.y;
    }

    void  COffsetRect(Vector2 vector) {
        rect.left += vector.x;
        rect.right += vector.x;
        rect.top += vector.y;
        rect.bottom += vector.y;

        x += vector.x;
        y += vector.y;
    }


    bool CIntersectRect(RECT& temp, Rect* another) {
        RECT temp1 = { this->rect.left, this->rect.top, this->rect.right, this->rect.bottom };
        RECT temp2 = { another->rect.left, another->rect.top, another->rect.right, another->rect.bottom };
        return IntersectRect(&temp, &temp1, &temp2);
    }

    void TranslateTo(MouseDragArea position) {


        rect.left = position.ptEnd.x - previousPos.x - width;
        rect.top = position.ptEnd.y - previousPos.y - height;
        rect.right = position.ptEnd.x - previousPos.x + width;
        rect.bottom = position.ptEnd.y - previousPos.y + height;
        x = position.ptEnd.x - previousPos.x;
        y = position.ptEnd.y - previousPos.y;
    }

    void TranslateTo(Vector2Int position) {
        rect.left = position.x - width;
        rect.top = position.y - height;
        rect.right = position.x + width;
        rect.bottom = position.y + height;
        x = position.x;
        y = position.y;
    }

};
#pragma endregion

#pragma endregion

//==========================================
//				 내가만든 헤더파일
//==========================================

#pragma once


inline void RectangleMakeCenter(HDC hdc, Rect* rect)
{
    Rectangle(hdc, rect->x - rect->width, rect->y - rect->height, rect->x + rect->width, rect->y + rect->height);
}

inline void RectangleMakeCenter(HDC hdc, Rect rect)
{
    Rectangle(hdc, rect.x - rect.width, rect.y - rect.height, rect.x + rect.width, rect.y + rect.height);
}

inline void RectangleMakeCenter(HDC hdc, RECT* rect)
{
    Rectangle(hdc, rect->left, rect->top, rect->right, rect->bottom);
}

inline void RectangleMakeCenter(HDC hdc, RECT& rect)
{
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}




//==========================================
//				 매크로 설정
//==========================================
#define WINNAME			(LPCTSTR)(TEXT("지옥으로 떠나는 여행"))
#define WINSTARTX		100
#define WINSTARTY		100
#define WINSIZEX		1024
#define WINSIZEY		768
#define	WINSTYLE		WS_CAPTION | WS_SYSMENU
#define MAX_LOADSTRING 100




// 각종 클래스

#pragma region  특수목적용 사각형 클래스 
class SquareObject {
protected:
    SquareObject() {};
public:
    Rect* outsideRect;

    SquareObject(int posX, int posY, int _width, int _height) {
        outsideRect = new Rect(posX, posY, _width, _height);
    }
    ~SquareObject() {
        delete outsideRect;
    }

    void RectangleMakeCenter(HDC hdc)
    {

        Rectangle(hdc, outsideRect->x - outsideRect->width, outsideRect->y - outsideRect->height, outsideRect->x + outsideRect->width, outsideRect->y + outsideRect->height);
    }
};

class SquareController : public SquareObject {
private:
    bool corrision;
protected:
    SquareController() {};
public:


    SquareController(int posX, int posY, int _width, int _height)
        : SquareObject(posX, posY, _width, _height) {};

    ~SquareController() {}

    bool PredictIntersectRect(RECT& _temp, Rect* another, Vector2Int pos) {
        RECT rect1 = { outsideRect->rect.left + pos.x, 
            outsideRect->rect.right + pos.x,
            outsideRect->rect.top + pos.y,
            outsideRect->rect.bottom + pos.y};
        RECT dummyRect = { another->rect.left, 
            another->rect.top, 
            another->rect.right, 
            another->rect.bottom };
        return IntersectRect(&_temp, &rect1, &dummyRect);
    }

    bool CheckCollision(RECT& temp, SquareObject* anotherObject, Vector2Int pos) {
        if (PredictIntersectRect(temp, anotherObject->outsideRect, pos))
        {
            auto temp = anotherObject->outsideRect;
            anotherObject->outsideRect = outsideRect;
            outsideRect = temp;
            corrision = true;
            return true;
        }
        else {
            corrision = false;
            return false;
        }
    }

    void Translate(Vector2 direction) {
        outsideRect->COffsetRect(direction);
    }
};
#pragma endregion


//========================================================
//		전역변수 아이들(인스턴스,윈도우 핸들, 마우스 좌표)
//========================================================
MouseDragArea mousePoint;

HDC hdc;
HBRUSH brush, oBrush;
HWND hwnd;
bool loop = true;
//Rect* playerRect;
RECTANGLE playerRect;

float speed = 1;
LARGE_INTEGER g_tSecond;
LARGE_INTEGER g_tTime;
float g_deltaTime;
bool isStarted = false;
RECTANGLE playerRC;
WCHAR szTitle1[MAX_LOADSTRING];

//이벤트 없을때 일로 들어옴
void Run() {
    //Rect playerRect = *_playerRect;

    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);

    g_deltaTime = (time.QuadPart - g_tTime.QuadPart) / (float)g_tSecond.QuadPart;
    g_tTime = time;

    speed = 300 * g_deltaTime;
    
  

   // if (GetAsyncKeyState('D') & 0x8000)
   // {
   //     if (playerRect->x <= WINSIZEX )
   //     {
			//playerRect->COffsetRect(Vector2(speed, 0));
   //     }
   //     else
   //     {
   //         playerRect->x = WINSIZEX ;
   //     }
   //     //playerRect->COffsetRect(Vector2(speed, 0));
   // }

   // if (GetAsyncKeyState('A') & 0x8000)
   // {
   //     if (playerRect->x >= 0)
   //     {
   //         playerRect->COffsetRect(Vector2(-speed, 0));
   //     }
   //     else
   //     {
   //         playerRect->y = playerRect->width;
   //     }

   // }

   // if (GetAsyncKeyState('S') & 0x8000)
   // {
   //     if (playerRect->y >= playerRect->height)
   //     {
   //         playerRect->COffsetRect(Vector2(0, speed));
   //     }
   //     else
   //     {
   //         playerRect->x = playerRect->height;
   //     }
   // }

   // if (GetAsyncKeyState('W') & 0x8000)
   // {
   //     if (playerRect->y >= 0)
   //     {
   //         playerRect->COffsetRect(Vector2(0, -speed));
   //     }
   //     else
   //     {
   //         playerRect->y = 0; 
   //     }
   // }

    if (GetAsyncKeyState('D') & 0x8000)
    {
        playerRect.left += speed;
        playerRect.right += speed;
    }

    if (GetAsyncKeyState('A') & 0x8000)
    {
        playerRect.left -= speed;
        playerRect.right -= speed;

    }

    if (GetAsyncKeyState('S') & 0x8000)
    {
        playerRect.top += speed;
        playerRect.bottom += speed;
    }

    if (GetAsyncKeyState('W') & 0x8000)
    {
        playerRect.top -= speed;
        playerRect.bottom -= speed;
    }
    Rectangle(hdc, playerRect.left, playerRect.top, playerRect.right, playerRect.bottom);
}



