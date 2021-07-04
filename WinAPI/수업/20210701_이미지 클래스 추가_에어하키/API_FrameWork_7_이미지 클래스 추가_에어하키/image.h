#pragma once
class image
{
public:

	enum class IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,	//리소스 로딩
		LOAD_FILE,			//파일로딩
		LOAD_EMPTY,
		LOAD_END
	};

	typedef struct tagImage
	{
		DWORD resID;	//리소스 ID
		HDC hMemDC;		//메모리 DC
		HBITMAP hBit;	//비트맵(새로운 비트맵 핸들)
		HBITMAP hOBit;	//올드 비트맵(기존 비트맵 핸들)
		int width;		//이미지 가로크기
		int height;		//이미지 세로크기
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
	LPIMAGE_INFO	_imageInfo;			//이미지 정보
	char*			_fileName;			//이미지 이름
	bool			_isTrans;			//배경색 날릴꺼냐?
	COLORREF		_transColor;		//배경색 날릴 RGB

public:

	//비트맵 초기화
	HRESULT init(const int width, const int height);
	HRESULT init(const char* fileName, const int width, const int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));

	//투명값 셋팅
	void setTransColor(bool isTrans, COLORREF transColor);

	void release();

	//렌더
	void render(HDC hdc);
	void render(HDC hdc, const int  destX, const int destY);


	//DC를 가져와라
	inline HDC getMemDC()const { return _imageInfo->hMemDC; }




};

