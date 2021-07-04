#pragma once
class image
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
		DWORD resID;	//���ҽ� ID
		HDC hMemDC;		//�޸� DC
		HBITMAP hBit;	//��Ʈ��(���ο� ��Ʈ�� �ڵ�)
		HBITMAP hOBit;	//�õ� ��Ʈ��(���� ��Ʈ�� �ڵ�)
		int width;		//�̹��� ����ũ��
		int height;		//�̹��� ����ũ��
		BYTE loadType;
		
		tagImage()
		{
			resID = 0;
			hMemDC = NULL,
			hBit = NULL,
			hOBit = NULL,
			width = 0;
			height = 0;
			loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_RESOURCE);
		}
	} IMAGE_INFO, *LPIMAGE_INFO;

	image();
	~image();

private:
	LPIMAGE_INFO	_imageInfo;			//�̹��� ����
	char*			_fileName;			//�̹��� �̸�
	bool			_isTrans;			//���� ��������?
	COLORREF		_transColor;		//���� ���� RGB

public:

	//��Ʈ�� �ʱ�ȭ
	HRESULT init(const int width, const int height);
	HRESULT init(const char* fileName, const int width, const int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));

	//���� ����
	void setTransColor(bool isTrans, COLORREF transColor);

	void release();

	//����
	void render(HDC hdc);
	void render(HDC hdc, const int  destX, const int destY);


	//DC�� �����Ͷ�
	inline HDC getMemDC()const { return _imageInfo->hMemDC; }




};

