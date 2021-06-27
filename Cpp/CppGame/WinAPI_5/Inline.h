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

//inline void RectangleMakeCenter(HDC hdc, RECT rect)
//{
//    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
//}

inline void RectangleMakeCenter(HDC hdc, RECT& rect)
{
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}