#include"framework.h"
#include "image.h"

image::image() : _imageInfo(NULL),
				 _fileName(NULL),
				 _isTrans(false),
				 _transColor(RGB(0, 0, 0))
{				 
}				
image::~image(){}

HRESULT image::init(const int width, const int height)
{

	//이미지 정보가 있으면 해제해라
	if (_imageInfo != NULL)release();
	//DC가져오기(현재 윈도우에 대한 화면 DC를 임시로 가져옴)
	//CreateCompatibleDC: 비트맵을 출력하기 위해 메모리 DC를 만들어준다.
	// CreateCompatibleBitmap: 원본DC와 호환되는 비트맵 생성

	HDC hdc = GetDC(m_hWnd);

	//이미지 정보 생성
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//파일이름
	_fileName = NULL;

	//투명키 셋팅
	_isTrans = false;
	_transColor = RGB(0, 0, 0);

	//리소스를 얻어오는데 실패하면
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(m_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, const int width, const int height, bool isTrans, COLORREF transColor)
{

	if (fileName == NULL)return E_FAIL;
	if (_imageInfo != NULL)release();


	HDC hdc = GetDC(m_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
									      fileName,
										  IMAGE_BITMAP,
										  width, height, 
										  LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//파일이름
	int len = _tcslen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//리소스를 얻어오는데 실패하면
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(m_hWnd, hdc);
	


	return S_OK;
}

void image::setTransColor(bool isTrans, COLORREF transColor)
{
	_isTrans = isTrans;
	_transColor = transColor;
}

void image::release()
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		_isTrans = false;
		_transColor = RGB(0, 0, 0);

	}
}

void image::render(HDC hdc)
{
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			0,							//복사될 좌표의 시작점X
			0,							//복사될 좌표의 시작점Y
			_imageInfo->width,			//복사될 이미지 가로크기
			_imageInfo->height,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, const int destX, const int destY)
{
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			destX,							//복사될 좌표의 시작점X
			destY,							//복사될 좌표의 시작점Y
			_imageInfo->width,			//복사될 이미지 가로크기
			_imageInfo->height,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}

}
