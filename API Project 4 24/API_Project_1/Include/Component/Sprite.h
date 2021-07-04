#pragma once
#include "../Obj/Component.h"


class Sprite : public Component {

private:

	wchar_t* fileName;
	DWORD resID;
	HDC hMemDC;
	HBITMAP hBit;
	HBITMAP hOBit;
	BITMAP bitmapInfo;
	BYTE loadType;
	int width;
	int height;
	//pIMAGE_INFO		_imageInfo;			//이미지 정보
	bool			_isTrans;			//배경색 날릴꺼냐?
	COLORREF		_transColor;		//배경색 날릴 RGB

public:
	Sprite();
	Sprite(const Sprite& obj);
	virtual ~Sprite();



	bool CreateSprite(HINSTANCE hInst, HDC hdc, const string& strKey, int width, int height);

	bool LoadSprite(HINSTANCE hInst, HDC hdc, const string& strKey,
		const wchar_t* pFileName,
		const string& strPathKey = TEXTURE_PATH);


	HDC GetDC() const { return hMemDC; }

//
//public:
//
//	//비트맵 초기화
//	bool Init(HINSTANCE hInst, HDC hdc, const int width, const int height);
//	bool Init(HINSTANCE hInst, HDC hdc, const wchar_t* fileName, const int width, const int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//
//
//	//프레임 이미지 초기화
//	bool Init(HINSTANCE hInst, HDC hdc, const wchar_t* fileName, const int width, const int height, const int frameX, const int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//	bool Init(HINSTANCE hInst, HDC hdc, const wchar_t* fileName, const int x, const int y, const int width, const int height, const int frameX, const int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//
//
//
//	//투명값 셋팅
//	void SetTransColor(bool isTrans, COLORREF transColor);
//
//	void Release();
//
//	//렌더
//	void Render(HDC hdc);
//	void Render(HDC hdc, const int  destX, const int destY);
//	void Render(HDC hdc, const int  destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourheight);
//
//
//	//프레임 렌더
//	void FrameRender(HDC hdc, const int destX, const int destY);
//	void FrameRender(HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY);
//
//
//	//DC를 가져와라
//	inline HDC GetMemDC()const { return _imageInfo->hMemDC; }
//
//
//	//========이미지 조작질을 쉽게 하기 위한 녀석들==============//
//
//	//이미지 X좌표
//	inline float GetX()const { return _imageInfo->x; }
//	inline float  SetX(const float x) { return _imageInfo->x = x; }
//	//이미지 Y좌표
//	inline float GetY()const { return _imageInfo->y; }
//	inline float  SetY(const float y) { return _imageInfo->x = y; }
//
//	//이미지 센터 좌표셋팅
//	inline void SetCenter(const float x, const float y)
//	{
//		_imageInfo->x = x - (_imageInfo->width / 2);
//		_imageInfo->y = y - (_imageInfo->height / 2);
//	}
//	//가로세로 크기 얻기
//	inline int GetWidth()const { return _imageInfo->width; }
//	inline int GetHeight()const { return _imageInfo->height; }
//
//	//바운딩 박스(충돌용)
//	inline RECT getBoundingBox()
//	{
//		RECT rc = RectMakeCenter(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
//		return rc;
//	}
//
//	//프레임 X셋팅
//	inline  int GetFrameX()const { return _imageInfo->currentFrameX; }
//	inline  void SetFrameX(const int frameX)
//	{
//		_imageInfo->currentFrameX = frameX;
//
//		if (frameX > _imageInfo->maxFrameX)
//		{
//			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
//		}
//	}
//
//	//프레임 Y셋팅
//	inline  int GetFrameY()const { return _imageInfo->currentFrameY; }
//	inline  void SetFrameY(const int frameY)
//	{
//		_imageInfo->currentFrameY = frameY;
//
//		if (frameY > _imageInfo->maxFrameY)
//		{
//			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
//		}
//	}
//
//	//1프레임 가로세크로기 얻기
//	inline int GetFrameWidth()const { return _imageInfo->frameWidth; }
//	inline int GetFrameHeight()const { return _imageInfo->frameHeight; }
//
//
//
//	//맥스프레임 가로세로크기 얻기
//	inline int GetMaxFrameX()const { return _imageInfo->maxFrameX; }
//	inline int GetMaxFrameY()const { return _imageInfo->maxFrameY; }
};