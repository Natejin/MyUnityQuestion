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






#include <vector>

static bool corrision;
static HDC hdc;
static HBRUSH brush, oBrush;

using namespace std;

struct Vector2 {
    int x;
    int y;

    Vector2() { x = 0; y = 0; }
    Vector2(int x, int y) :x(x), y(y) {};
    void SetPos(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct MouseDragArea {
    bool mouseDownLeft = false;
    bool mouseDownRight = false;
    POINT ptStart;
    POINT ptEnd;

    bool isButtonUpBoth() {
        return !mouseDownLeft && !mouseDownRight ? true : false;
    }

};

struct Rect {
    RECT* rect;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    Vector2 previousPos = Vector2(0, 0);
    Rect(MouseDragArea startPos)

    {
        rect = new RECT();
        rect->left = startPos.ptStart.x;
        rect->top = startPos.ptStart.y;
        rect->right = startPos.ptStart.x;
        rect->bottom = startPos.ptStart.y;
        previousPos = Vector2(0, 0);
    }

    Rect(int posX, int posY, int _width, int _height)
    {
        rect = new RECT();
        width = _width * 0.5f;
        height = _height * 0.5f;
        rect->left = posX - width;
        rect->top = posY - height;
        rect->right = posX + width;
        rect->bottom = posY + height;
        x = posX;
        y = posY;
    }
    ~Rect() {
        delete rect;
    }
    void CreatedRect(MouseDragArea endPos) {
        rect->right = endPos.ptEnd.x;
        rect->bottom = endPos.ptEnd.y;

        width = (rect->right - rect->left) * 0.5;
        height = (rect->bottom - rect->top) * 0.5;

        x = endPos.ptEnd.x - width;
        y = endPos.ptEnd.y - height;

    }

    void CreatingRect(MouseDragArea pos) {

        rect->right = pos.ptEnd.x;
        rect->bottom = pos.ptEnd.y;
    }

    void TranslateBegin(MouseDragArea position) {
        previousPos.x = position.ptEnd.x - x;
        previousPos.y = position.ptEnd.y - y;
    }

    void  COffsetRect(int _x, int _y) {
       rect->left += _x;
       rect->right += _x;
       rect->top += _y;
       rect->bottom += _y;

        x += _x;
        y += _y;


    }    

    void  COffsetRect(Vector2 vector) {
        rect->left += vector.x;
        rect->right += vector.x;
        rect->top += vector.y;
        rect->bottom += vector.y;

        x += vector.x;
        y += vector.y;


    }


    bool CIntersectRect(RECT& temp, Rect* another) {
        return IntersectRect(&temp, this->rect, another->rect);
    }

    bool PredictIntersectRect(RECT& _temp, Rect* another, Vector2 pos) {

		RECT* temp = new RECT();
		temp->left = another->rect->left - pos.x;
		temp->right = another->rect->right - pos.x;
		temp->top = another->rect->top - pos.y;
		temp->bottom = another->rect->bottom - pos.y;
		return IntersectRect(&_temp, rect, temp);
    }



    void TranslateTo(MouseDragArea position) {


        rect->left = position.ptEnd.x - previousPos.x - width;
        rect->top = position.ptEnd.y - previousPos.y - height;
        rect->right = position.ptEnd.x - previousPos.x + width;
        rect->bottom = position.ptEnd.y - previousPos.y + height;
        x = position.ptEnd.x - previousPos.x;
        y = position.ptEnd.y - previousPos.y;
    }

    void TranslateTo(Vector2 position) {


        rect->left = position.x  - width;
        rect->top = position.y  - height;
        rect->right = position.x  + width;
        rect->bottom = position.y  + height;
        x = position.x ;
        y = position.y ;
    }

};


inline void RectangleMakeCenter(HDC hdc, Rect* rect)
{
    Rectangle(hdc, rect->x - rect->width, rect->y - rect->height, rect->x + rect->width, rect->y + rect->height);
}


MouseDragArea mousePoint;

class SquareObject {
protected:
    SquareObject() {};
public:
    Rect* outsideRect;

    SquareObject(int posX, int posY, int _width, int _height) {
        outsideRect = new Rect(posX,posY,_width, _height);
    }
    ~SquareObject() {
        delete outsideRect;
    }

    void RectangleMakeCenter(HDC hdc)
    {
        
        Rectangle(hdc, outsideRect->x - outsideRect->width, outsideRect->y - outsideRect->height, outsideRect->x + outsideRect->width, outsideRect->y + outsideRect->height);
    }
};

class SquareController : public SquareObject{
protected:
    SquareController() {};
public:
    Rect* insideRect;

    SquareController(int posX, int posY, int _width, int _height) 
        : SquareObject(posX, posY, _width, _height)
    {
        insideRect = new Rect(posX, posY, _width * 0.5, _height * 0.5);
    }

    ~SquareController() {
        delete insideRect;
    }

    bool CheckCollision(RECT& temp, SquareObject* anotherObject, Vector2 pos) {
        if (outsideRect->PredictIntersectRect(temp, anotherObject->outsideRect, pos))
        {
            auto temp = anotherObject->outsideRect;
            anotherObject->outsideRect = outsideRect;
            outsideRect = temp;
            insideRect->TranslateTo(Vector2( outsideRect->x, outsideRect->y));
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
        if (direction.x > 0)
        {
            if (insideRect->rect->left < outsideRect->rect->left)
            {
                insideRect->COffsetRect(direction);
            }
        }
        else  if (direction.x < 0) {
            if (insideRect->rect->right > outsideRect->rect->right)
            {
                insideRect->COffsetRect(direction);
            }
        }
        else  if (direction.y > 0) {
            if (insideRect->rect->top < outsideRect->rect->top)
            {
                insideRect->COffsetRect(direction);
            }
        }
        else  if (direction.y < 0) {
            if (insideRect->rect->bottom > outsideRect->rect->bottom)
            {
                insideRect->COffsetRect(direction);
            }
        }
       
    }

    void RectangleMakeCenter(HDC hdc)
    {
        brush = CreateSolidBrush(RGB(0, 200, 0));
        oBrush = (HBRUSH)SelectObject(hdc, brush);
        Rectangle(hdc, outsideRect->x - outsideRect->width, outsideRect->y - outsideRect->height, outsideRect->x + outsideRect->width, outsideRect->y + outsideRect->height);
        Rectangle(hdc, insideRect->x - insideRect->width, insideRect->y - insideRect->height, insideRect->x + insideRect->width, insideRect->y + insideRect->height);
       
    }

};