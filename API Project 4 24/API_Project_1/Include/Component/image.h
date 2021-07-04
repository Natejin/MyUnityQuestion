//#pragma once
//#include "../Obj/Component.h"
//
//class image
//{
//public:
//
//	
//
//	typedef struct tagImage
//	{
//		DWORD resID;			//���ҽ� ID
//		HDC hMemDC;				//�޸� DC
//		HBITMAP hBit;			//��Ʈ��(���ο� ��Ʈ�� �ڵ�)
//		HBITMAP hOBit;			//�õ� ��Ʈ��(���� ��Ʈ�� �ڵ�)
//		int width;				//�̹��� ����ũ��
//		int height;				//�̹��� ����ũ��
//		BYTE loadType;
//		double x;				//�̹���X ��ǥ
//		double y;				//�̹���Y ��ǥ
//		int currentFrameX;		//���� ������ X
//		int currentFrameY;		//���� ������ Y
//		int maxFrameX;			//�ִ� X������ ����
//		int maxFrameY;			//�ִ� Y������ ����
//		int frameWidth;			//1������  ���α���
//		int frameHeight;		//1������  ���α���
//		
//		tagImage()
//		{
//			resID = 0;
//			hMemDC = NULL,
//			hBit = NULL,
//			hOBit = NULL,
//			x = 0;
//			y = 0;
//			width = 0;
//			height = 0;
//			currentFrameX=0;
//			currentFrameY=0;
//			maxFrameX  =0;
//			maxFrameY	  =0;
//			frameWidth	  =0;
//			frameHeight  =0;
//			loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_RESOURCE);
//		}
//	} IMAGE_INFO, *LPIMAGE_INFO;
//
//	image();
//	~image();
//
//private:
//	LPIMAGE_INFO	_imageInfo;			//�̹��� ����
//	char*			_fileName;			//�̹��� �̸�
//	bool			_isTrans;			//���� ��������?
//	COLORREF		_transColor;		//���� ���� RGB
//
//public:
//
//	//��Ʈ�� �ʱ�ȭ
//	HRESULT init(const int width, const int height);
//	HRESULT init(const char* fileName, const int width, const int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//
//
//	//������ �̹��� �ʱ�ȭ
//	HRESULT init(const char* fileName, const int width, const int height, const int frameX, const int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//	HRESULT init(const char* fileName, const int x,const int y,const int width, const int height, const int frameX, const int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
//
//
//
//	//���� ����
//	void setTransColor(bool isTrans, COLORREF transColor);
//
//	void release();
//
//	//����
//	void render(HDC hdc);
//	void render(HDC hdc, const int  destX, const int destY);
//	void render(HDC hdc, const int  destX, const int destY,const int sourX, const int sourY, const int sourWidth, const int sourheight);
//
//
//	//������ ����
//	void frameRender(HDC hdc, const int destX, const int destY);
//	void frameRender(HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY);
//
//
//	//DC�� �����Ͷ�
//	inline HDC getMemDC()const { return _imageInfo->hMemDC; }
//
//
//	//========�̹��� �������� ���� �ϱ� ���� �༮��==============//
//
//	//�̹��� X��ǥ
//	inline double getX()const { return _imageInfo->x; }
//	inline double  setX(const double x) { return _imageInfo->x= x; }
//	//�̹��� Y��ǥ
//	inline double getY()const { return _imageInfo->y; }
//	inline double  setY(const double y) { return _imageInfo->x = y; }
//
//	//�̹��� ���� ��ǥ����
//	inline void setCenter(const double x, const double y)
//	{
//		_imageInfo->x = x - (_imageInfo->width / 2);
//		_imageInfo->y = y - (_imageInfo->height / 2);
//	}
//	//���μ��� ũ�� ���
//	inline int getWidth()const { return _imageInfo->width; }
//	inline int getHeight()const { return _imageInfo->height; }
//
//	//�ٿ�� �ڽ�(�浹��)
//	inline RECT getBoundingBox()
//	{
//		RECT rc = RectMakeCenter(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
//		return rc;
//	}
//
//	//������ X����
//	inline  int getFrameX()const { return _imageInfo->currentFrameX; }
//	inline  void setFrameX(const int frameX) 
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
//	inline  int getFrameY()const { return _imageInfo->currentFrameY; }
//	inline  void setFrameY(const int frameY)
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
//	inline int getFrameWidth()const { return _imageInfo->frameWidth; }
//	inline int getFrameHeight()const { return _imageInfo->frameHeight; }
//
//
//
//	//�ƽ������� ���μ���ũ�� ���
//	inline int getMaxFrameX()const { return _imageInfo->maxFrameX; }
//	inline int getMaxFrameY()const { return _imageInfo->maxFrameY; }
//};
//
