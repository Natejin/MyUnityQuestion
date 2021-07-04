#pragma once
class Sprite
{
public:

	enum class IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,	//���ҽ� �ε�
		LOAD_FILE,			//���Ϸε�
		LOAD_EMPTY,
		LOAD_END
	};

	typedef struct tagImage
	{
		DWORD resID;			//���ҽ� ID
		HDC hMemDC;				//�޸� DC
		HBITMAP hBit;			//��Ʈ��(���ο� ��Ʈ�� �ڵ�)
		HBITMAP hOBit;			//�õ� ��Ʈ��(���� ��Ʈ�� �ڵ�)
		int width;				//�̹��� ����ũ��
		int height;				//�̹��� ����ũ��
		BYTE loadType;
		float x;				//�̹���X ��ǥ
		float y;				//�̹���Y ��ǥ
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
			currentFrameX=0;
			currentFrameY=0;
			maxFrameX  =0;
			maxFrameY	  =0;
			frameWidth	  =0;
			frameHeight  =0;
			loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_RESOURCE);
		}
	} IMAGE_INFO, *LPIMAGE_INFO;

	Sprite();
	~Sprite();

private:
	LPIMAGE_INFO	_imageInfo;			//�̹��� ����
	char*			_fileName;			//�̹��� �̸�
	bool			_isTrans;			//���� ��������?
	COLORREF		_transColor;		//���� ���� RGB

public:

	//��Ʈ�� �ʱ�ȭ
	HRESULT Init(const int width, const int height);
	HRESULT Init(const char* fileName, const int width, const int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));


	//������ �̹��� �ʱ�ȭ
	HRESULT Init(const char* fileName, const int width, const int height, const int frameX, const int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
	HRESULT Init(const char* fileName, const int x,const int y,const int width, const int height, const int frameX, const int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));



	//���� ����
	void SetTransColor(bool isTrans, COLORREF transColor);

	void Release();

	//����
	void Render(HDC hdc);
	void Render(HDC hdc, const int  destX, const int destY);
	void Render(HDC hdc, const int  destX, const int destY,const int sourX, const int sourY, const int sourWidth, const int sourheight);


	//������ ����
	void FrameRender(HDC hdc, const int destX, const int destY);
	void FrameRender(HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY);


	//DC�� �����Ͷ�
	inline HDC GetMemDC()const { return _imageInfo->hMemDC; }


	//========�̹��� �������� ���� �ϱ� ���� �༮��==============//

	//�̹��� X��ǥ
	inline float GetX()const { return _imageInfo->x; }
	inline float  SetX(const float x) { return _imageInfo->x= x; }
	//�̹��� Y��ǥ
	inline float GetY()const { return _imageInfo->y; }
	inline float  SetY(const float y) { return _imageInfo->x = y; }

	//�̹��� ���� ��ǥ����
	inline void SetCenter(const float x, const float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}
	//���μ��� ũ�� ���
	inline int GetWidth()const { return _imageInfo->width; }
	inline int GetHeight()const { return _imageInfo->height; }

	//�ٿ�� �ڽ�(�浹��)
	inline RECT getBoundingBox()
	{
		RECT rc = RectMakeCenter(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
		return rc;
	}

	//������ X����
	inline  int GetFrameX()const { return _imageInfo->currentFrameX; }
	inline  void SetFrameX(const int frameX) 
	{
		_imageInfo->currentFrameX = frameX;

		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
	}

	//������ Y����
	inline  int GetFrameY()const { return _imageInfo->currentFrameY; }
	inline  void SetFrameY(const int frameY)
	{
		_imageInfo->currentFrameY = frameY;

		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}

	//1������ ���μ�ũ�α� ���
	inline int GetFrameWidth()const { return _imageInfo->frameWidth; }
	inline int GetFrameHeight()const { return _imageInfo->frameHeight; }



	//�ƽ������� ���μ���ũ�� ���
	inline int GetMaxFrameX()const { return _imageInfo->maxFrameX; }
	inline int GetMaxFrameY()const { return _imageInfo->maxFrameY; }
};

