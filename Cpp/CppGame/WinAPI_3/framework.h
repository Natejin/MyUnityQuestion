// header.h: ǥ�� �ý��� ���� ����
// �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>






#include <vector>


using namespace std;

struct Vector2Int {
    int x;
    int y;

    Vector2Int(int x, int y) :x(x), y(y) {};
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
    Vector2Int previousPos = Vector2Int(0, 0);
    Rect(MouseDragArea startPos)

    {
        rect = new RECT();
        rect->left = startPos.ptStart.x;
        rect->top = startPos.ptStart.y;
        rect->right = startPos.ptStart.x;
        rect->bottom = startPos.ptStart.y;

        previousPos = Vector2Int(0, 0);

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


    void TranslateTo(MouseDragArea position) {


        rect->left = position.ptEnd.x - previousPos.x - width;
        rect->top = position.ptEnd.y - previousPos.y - height;
        rect->right = position.ptEnd.x - previousPos.x + width;
        rect->bottom = position.ptEnd.y - previousPos.y + height;
        x = position.ptEnd.x - previousPos.x;
        y = position.ptEnd.y - previousPos.y;
    }
};


MouseDragArea mousePoint;