#pragma once

#include "Singleton.h"
#include <map>
#include <windows.h>
#include <iostream>
#include "Image.h"
#include "Macro.h"

using namespace std;

// �̹��� ���� �� ȣ��
// �̹��� �Ŵ����� �̹��� ���� �ϰ� ������ ���� ������ �ϴ� �Ŷ�� ���� ��

class ImageManager : public Singleton<ImageManager>
{
private:
	map<string, Image*> _mImageList;

public:
	ImageManager();
	~ImageManager();

	// init�� �� ������ ���� ����
	void Release();
	Image* AddImage(string strKey, const char* fileName,
		float x, float y, int width, int height,
		bool isTrans, COLORREF transColor);
	Image* AddImage(string strKey, const char* fileName,
		float x, float y, int width, int height,
		int frameX, int frameY, bool isTrans, COLORREF transColor);

	Image* FindImage(string strKey);
	bool DeleteImage(string strKey);
	bool DeleteAll();

	// ������ ����
	void FrameRender(string strKey, HDC hdc, int destX, int destY,
		int currentFrameX, int currentFrameY);
};

#define IMAGE ImageManager::GetSingleton()

