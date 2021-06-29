#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<list>

//			===============================================
//			||	commonMacroFunction[함수 만든곳]		     ||
//			===============================================

//포인트
inline POINT PointMake(int x, int y){
	POINT pt = { x,y };
	return pt;
}

//선그리기
inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2){
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

//RECT만들기.
//1.좌상단 기준 부터
inline RECT RectMake(int x, int y, int width, int height){			
	RECT rc = { x,y,x + width,y + height };
	return rc;
}
//2.중심점으로 부터
inline RECT RectMakeCenter(int x, int y, int width, int height){	
	RECT rc = { x - width / 2,y - height / 2,x + width / 2,y + height / 2 };
	return rc;
}

 //RECT 그리기
inline void RectangleMake(HDC hdc, int x, int y, int width, int height){
	Rectangle(hdc, x, y, x + width, y + height);
}
inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height){
	Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

//원 그리기
inline void EllipseMake(HDC hdc, int x, int y, int width, int height){
	Ellipse(hdc, x, y, x + width, y + height);
}
inline void ElllipseMakeCenter(HDC hdc, int x, int y, int width, int height){
	Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

//			===============================================
//			||	     commonMakeClass[클래스 만든곳]       ||
//			===============================================