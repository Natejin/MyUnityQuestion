#pragma once
#include <math.h>

typedef struct _tagResolution {

	unsigned int width;
	unsigned int height;
	void SetSize(int width, int height) {
		this->width = width;
		this->height = height;
	}
}RESOLUTION, *PRESOLUTION;




typedef struct tagImage
{
	DWORD resID;			//리소스 ID
	HDC hMemDC;				//메모리 DC
	HBITMAP hBit;			//비트맵(새로운 비트맵 핸들)
	HBITMAP hOBit;			//올드 비트맵(기존 비트맵 핸들)
	int width;				//이미지 가로크기
	int height;				//이미지 세로크기
	BYTE loadType;
	double x;				//이미지X 좌표
	double y;				//이미지Y 좌표
	int currentFrameX;		//현재 프레임 X
	int currentFrameY;		//현재 프레임 Y
	int maxFrameX;			//최대 X프레임 갯수
	int maxFrameY;			//최대 Y프레임 갯수
	int frameWidth;			//1프레임  가로길이
	int frameHeight;		//1프레임  세로길이

	tagImage()
	{
		resID = 0;
		hMemDC = NULL,
			hBit = NULL,
			hOBit = NULL,
			x = 0;
		y = 0;
		width = 0;
		height = 0;
		currentFrameX = 0;
		currentFrameY = 0;
		maxFrameX = 0;
		maxFrameY = 0;
		frameWidth = 0;
		frameHeight = 0;
		loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_RESOURCE);
	}
} IMAGE_INFO, *pIMAGE_INFO;