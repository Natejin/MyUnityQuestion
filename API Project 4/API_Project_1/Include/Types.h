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
	DWORD resID;			//���ҽ� ID
	HDC hMemDC;				//�޸� DC
	HBITMAP hBit;			//��Ʈ��(���ο� ��Ʈ�� �ڵ�)
	HBITMAP hOBit;			//�õ� ��Ʈ��(���� ��Ʈ�� �ڵ�)
	int width;				//�̹��� ����ũ��
	int height;				//�̹��� ����ũ��
	BYTE loadType;
	double x;				//�̹���X ��ǥ
	double y;				//�̹���Y ��ǥ
	int currentFrameX;		//���� ������ X
	int currentFrameY;		//���� ������ Y
	int maxFrameX;			//�ִ� X������ ����
	int maxFrameY;			//�ִ� Y������ ����
	int frameWidth;			//1������  ���α���
	int frameHeight;		//1������  ���α���

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