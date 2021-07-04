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
	//pIMAGE_INFO		_imageInfo;			//�̹��� ����
	bool			_isTrans;			//���� ��������?
	COLORREF		_transColor;		//���� ���� RGB

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
//	//��Ʈ�� �ʱ�ȭ
//	bool Init(HINSTANCE hInst, HDC hdc, const int width, const int height);
//	bool Init(HINSTANCE hInst, HDC hdc, const wchar_t* fileName, const int width, const int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//
//
//	//������ �̹��� �ʱ�ȭ
//	bool Init(HINSTANCE hInst, HDC hdc, const wchar_t* fileName, const int width, const int height, const int frameX, const int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//	bool Init(HINSTANCE hInst, HDC hdc, const wchar_t* fileName, const int x, const int y, const int width, const int height, const int frameX, const int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//
//
//
//	//���� ����
//	void SetTransColor(bool isTrans, COLORREF transColor);
//
//	void Release();
//
//	//����
//	void Render(HDC hdc);
//	void Render(HDC hdc, const int  destX, const int destY);
//	void Render(HDC hdc, const int  destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourheight);
//
//
//	//������ ����
//	void FrameRender(HDC hdc, const int destX, const int destY);
//	void FrameRender(HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY);
//
//
//	//DC�� �����Ͷ�
//	inline HDC GetMemDC()const { return _imageInfo->hMemDC; }
//
//
//	//========�̹��� �������� ���� �ϱ� ���� �༮��==============//
//
//	//�̹��� X��ǥ
//	inline float GetX()const { return _imageInfo->x; }
//	inline float  SetX(const float x) { return _imageInfo->x = x; }
//	//�̹��� Y��ǥ
//	inline float GetY()const { return _imageInfo->y; }
//	inline float  SetY(const float y) { return _imageInfo->x = y; }
//
//	//�̹��� ���� ��ǥ����
//	inline void SetCenter(const float x, const float y)
//	{
//		_imageInfo->x = x - (_imageInfo->width / 2);
//		_imageInfo->y = y - (_imageInfo->height / 2);
//	}
//	//���μ��� ũ�� ���
//	inline int GetWidth()const { return _imageInfo->width; }
//	inline int GetHeight()const { return _imageInfo->height; }
//
//	//�ٿ�� �ڽ�(�浹��)
//	inline RECT getBoundingBox()
//	{
//		RECT rc = RectMakeCenter(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
//		return rc;
//	}
//
//	//������ X����
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
//	//������ Y����
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
//	//1������ ���μ�ũ�α� ���
//	inline int GetFrameWidth()const { return _imageInfo->frameWidth; }
//	inline int GetFrameHeight()const { return _imageInfo->frameHeight; }
//
//
//
//	//�ƽ������� ���μ���ũ�� ���
//	inline int GetMaxFrameX()const { return _imageInfo->maxFrameX; }
//	inline int GetMaxFrameY()const { return _imageInfo->maxFrameY; }
};