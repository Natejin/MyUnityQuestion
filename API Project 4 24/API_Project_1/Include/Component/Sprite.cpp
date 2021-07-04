
#include "Sprite.h"
#include "../Core/FileManager.h"


// 알파 블랜드 사용을 위한 라이브러리(lib)
#pragma comment(lib, "msimg32.lib")

//Sprite::Image()
//	:m_imageInfo(NULL)
//	, _fileName(NULL)
//	, isTrans(false)
//	, transColor(RGB(0, 0, 0))
//	, blendImage(NULL)
//{
//}
//
//Sprite::~Image() {
//	this->Release();
//}

Sprite::Sprite()
	:hMemDC(NULL)
{
}

Sprite::Sprite(const Sprite& obj)
{
	*this = obj;
}

Sprite::~Sprite()
{
	//기존에 지정되어 있던 도구를 다시 지정해준다.
	SelectObject(hMemDC, hOBit);

	//Bitmap를 지워준다.
	DeleteObject(hBit);

	//DC를 지워준다.
	DeleteObject(hMemDC);
}

bool Sprite::CreateSprite(HINSTANCE hInst, HDC hdc,	const string& strKey, int width, int height)
{
	//메모리 DC를 만듬
	//이화면DC로 메모리 DC를 만듬;
	hMemDC = CreateCompatibleDC(hdc);
	//const wchar_t* pPath = SINGLETON(FileManager)->FindPath(strPathKey);

	//wstring strPath;

	//if (pPath)
	//{
	//	strPath = pPath;
	//}

	//strPath += pFileName;


	//0,0넣으면 원본크기
	hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);

	//위에서 만들어준 비트맵 도구를 DC에 저장한다.

	//지정할때 반환된큰 값은 DC에 기본으로 지정되어 있던

	//도구가 반환된다.

	hOBit = (HBITMAP)SelectObject(hMemDC, hBit);

	GetObject(hBit, sizeof(bitmapInfo), &bitmapInfo);


	return true;
}

bool Sprite::LoadSprite(HINSTANCE hInst, HDC hdc,
	const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	//메모리 DC를 만듬
	//이화면DC로 메모리 DC를 만듬;
	hMemDC = CreateCompatibleDC(hdc);
	const wchar_t* pPath = SINGLETON(FileManager)->FindPath(strPathKey);

	wstring strPath;

	if (pPath)
	{
		strPath = pPath;
	}

	strPath += pFileName;


	//0,0넣으면 원본크기
	hBit = (HBITMAP)LoadImage(hInst, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//위에서 만들어준 비트맵 도구를 DC에 저장한다.

	//지정할때 반환된큰 값은 DC에 기본으로 지정되어 있던

	//도구가 반환된다.

	hOBit = (HBITMAP)SelectObject(hMemDC, hBit);

	GetObject(hBit, sizeof(bitmapInfo), &bitmapInfo);


	return true;
}


//
//
//bool Sprite::Init(HINSTANCE hInst, HDC hdc, const int _width, const int _height)
//{
//
//	////이미지 정보가 있으면 해제해라
//	//if (_imageInfo != NULL)Release();
//	// 
//	//DC가져오기(현재 윈도우에 대한 화면 DC를 임시로 가져옴)
//	//CreateCompatibleDC: 비트맵을 출력하기 위해 메모리 DC를 만들어준다.
//	// CreateCompatibleBitmap: 원본DC와 호환되는 비트맵 생성
//
//	HDC hdc = GetDC();
//	hMemDC = CreateCompatibleDC(hdc);
//
//	//이미지 정보 생성
//	loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
//	resID = 0;
//	hMemDC = CreateCompatibleDC(hdc);
//	hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _width, _height);
//	hOBit = (HBITMAP)SelectObject(hMemDC, hBit);
//	width = _width;
//	height = _height;
//
//	//파일이름
//	//_fileName = NULL;
//
//	//투명키 셋팅
//	_isTrans = false;
//	_transColor = RGB(0, 0, 0);
//
//	//리소스를 얻어오는데 실패하면
//	if (hBit == NULL)
//	{
//		Release();
//		return false;
//	}
//
//	ReleaseDC(g_hWnd, hdc);
//
//	return true;
//}
//
//bool Sprite::Init(HINSTANCE hInst, HDC hdc, const wchar_t* _fileName, const int _width, const int _height, bool isTrans, COLORREF transColor)
//{
//
//	if (_fileName == NULL)return E_FAIL;
//	if (_imageInfo != NULL)Release();
//
//
//	HDC hdc = GetDC();
//
//	//_imageInfo = new IMAGE_INFO;
//	loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
//	resID = 0;
//	hMemDC = CreateCompatibleDC(hdc);
//	hBit = (HBITMAP)LoadImage(hInst,
//		_fileName,
//		IMAGE_BITMAP,
//		_width, _height,
//		LR_LOADFROMFILE);
//	hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
//	width = _width;
//	height = _height;
//
//	//파일이름
//	int len = _tcslen(_fileName);
//	fileName = new char[len + 1];
//	strcpy_s(fileName, len + 1, _fileName);
//
//	_isTrans = isTrans;
//	_transColor = transColor;
//
//	//리소스를 얻어오는데 실패하면
//	if (_imageInfo->hBit == NULL)
//	{
//		Release();
//		return E_FAIL;
//	}
//
//	ReleaseDC(g_hWnd, hdc);
//
//
//
//	return S_OK;
//}
//
//bool Sprite::Init(const char* fileName, const int width, const int height, const int frameX, const int frameY, bool isTrans, COLORREF transColor)
//{
//	if (fileName == NULL)return E_FAIL;
//	if (_imageInfo != NULL)Release();
//
//
//	HDC hdc = GetDC(m_hWnd);
//
//	_imageInfo = new IMAGE_INFO;
//	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
//	_imageInfo->resID = 0;
//	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
//	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
//		fileName,
//		IMAGE_BITMAP,
//		width, height,
//		LR_LOADFROMFILE);
//	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
//	_imageInfo->width = width;
//	_imageInfo->height = height;
//	_imageInfo->maxFrameX = frameX - 1;
//	_imageInfo->maxFrameY = frameY - 1;
//	_imageInfo->frameWidth = width / frameX;
//	_imageInfo->frameHeight = height / frameY;
//
//	//파일이름
//	int len = _tcslen(fileName);
//	_fileName = new char[len + 1];
//	strcpy_s(_fileName, len + 1, fileName);
//
//	_isTrans = isTrans;
//	_transColor = transColor;
//
//	//리소스를 얻어오는데 실패하면
//	if (_imageInfo->hBit == NULL)
//	{
//		Release();
//		return false;
//	}
//
//	ReleaseDC(m_hWnd, hdc);
//	return true;
//}
//
//bool Sprite::Init(const char* fileName, const int x, const int y, const int width, const int height, const int frameX, const int frameY, bool isTrans, COLORREF transColor)
//{
//
//	if (fileName == NULL)return E_FAIL;
//	if (_imageInfo != NULL)Release();
//
//
//	HDC hdc = GetDC(m_hWnd);
//
//	_imageInfo = new IMAGE_INFO;
//	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
//	_imageInfo->resID = 0;
//	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
//	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
//		fileName,
//		IMAGE_BITMAP,
//		width, height,
//		LR_LOADFROMFILE);
//	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
//
//	_imageInfo->x = x;
//	_imageInfo->y = y;
//	_imageInfo->width = width;
//	_imageInfo->height = height;
//	_imageInfo->maxFrameX = frameX - 1;
//	_imageInfo->maxFrameY = frameY - 1;
//	_imageInfo->frameWidth = width / frameX;
//	_imageInfo->frameHeight = height / frameY;
//
//	//파일이름
//	int len = _tcslen(fileName);
//	_fileName = new char[len + 1];
//	strcpy_s(_fileName, len + 1, fileName);
//
//	_isTrans = isTrans;
//	_transColor = transColor;
//
//	//리소스를 얻어오는데 실패하면
//	if (_imageInfo->hBit == NULL)
//	{
//		Release();
//		return false;
//	}
//
//	ReleaseDC(m_hWnd, hdc);
//	return true;
//}
//
//void Sprite::SetTransColor(bool isTrans, COLORREF transColor)
//{
//	_isTrans = isTrans;
//	_transColor = transColor;
//}
//
//void Sprite::Release()
//{
//	if (_imageInfo)
//	{
//		SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
//		DeleteObject(_imageInfo->hBit);
//		DeleteDC(_imageInfo->hMemDC);
//
//		SAFE_DELETE(_imageInfo);
//		SAFE_DELETE(fileName);
//
//		_isTrans = false;
//		_transColor = RGB(0, 0, 0);
//
//	}
//}
//
//void Sprite::Render(HDC hdc)
//{
//	if (_isTrans)
//	{
//		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
//		GdiTransparentBlt(
//			hdc,						//복삳될 장소의 DC
//			0,							//복사될 좌표의 시작점X
//			0,							//복사될 좌표의 시작점Y
//			_imageInfo->width,			//복사될 이미지 가로크기
//			_imageInfo->height,			//복사될 이미지 세로크기
//			_imageInfo->hMemDC,			//복사될 대상DC
//			0,							//복사시작 지점 X
//			0,							//복사시작 지점 Y
//			_imageInfo->width,			//복사영역 가로크기
//			_imageInfo->height,			//복사영역 세로크기
//			_transColor);
//	}
//	else {
//		//BitBlt : DC영역끼리 고속복사
//		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
//			_imageInfo->hMemDC, 0, 0, SRCCOPY);
//	}
//}
//
//void Sprite::Render(HDC hdc, const int destX, const int destY)
//{
//	if (_isTrans)
//	{
//		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
//		GdiTransparentBlt(
//			hdc,						//복삳될 장소의 DC
//			destX,							//복사될 좌표의 시작점X
//			destY,							//복사될 좌표의 시작점Y
//			_imageInfo->width,			//복사될 이미지 가로크기
//			_imageInfo->height,			//복사될 이미지 세로크기
//			_imageInfo->hMemDC,			//복사될 대상DC
//			0,							//복사시작 지점 X
//			0,							//복사시작 지점 Y
//			_imageInfo->width,			//복사영역 가로크기
//			_imageInfo->height,			//복사영역 세로크기
//			_transColor);
//	}
//	else {
//		//BitBlt : DC영역끼리 고속복사
//		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
//			_imageInfo->hMemDC, 0, 0, SRCCOPY);
//	}
//
//}
//
//void Sprite::Render(HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourheight)
//{
//	if (_isTrans)
//	{
//		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
//		GdiTransparentBlt(
//			hdc,						//복삳될 장소의 DC
//			destX,							//복사될 좌표의 시작점X
//			destY,							//복사될 좌표의 시작점Y
//			sourWidth,					//복사될 이미지 가로크기
//			sourheight,			//복사될 이미지 세로크기
//			_imageInfo->hMemDC,			//복사될 대상DC
//			sourX,							//복사시작 지점 X
//			sourY,							//복사시작 지점 Y
//			sourWidth,			//복사영역 가로크기
//			sourheight,			//복사영역 세로크기
//			_transColor);
//	}
//	else {
//		//BitBlt : DC영역끼리 고속복사
//		BitBlt(hdc, destX, destY, sourWidth, sourheight,
//			_imageInfo->hMemDC, sourX, sourY, SRCCOPY);
//	}
//}
//
//void Sprite::FrameRender(HDC hdc, const int destX, const int destY)
//{
//	if (_isTrans)
//	{
//		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
//		GdiTransparentBlt(
//			hdc,													//복삳될 장소의 DC
//			destX,													//복사될 좌표의 시작점X
//			destY,													//복사될 좌표의 시작점Y
//			_imageInfo->frameWidth,									//복사될 이미지 가로크기
//			_imageInfo->frameHeight,								//복사될 이미지 세로크기
//			_imageInfo->hMemDC,										//복사될 대상DC
//			_imageInfo->currentFrameX * _imageInfo->frameWidth,		//복사시작 지점 X
//			_imageInfo->currentFrameY * _imageInfo->frameHeight,	//복사시작 지점 Y
//			_imageInfo->frameWidth,									//복사영역 가로크기
//			_imageInfo->frameHeight,								//복사영역 세로크기
//			_transColor);
//	}
//	else {
//		//BitBlt : DC영역끼리 고속복사
//		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
//			_imageInfo->hMemDC,
//			_imageInfo->currentFrameX * _imageInfo->frameWidth,
//			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
//	}
//}
//
//void Sprite::FrameRender(HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY)
//{
//
//	_imageInfo->currentFrameX = currentFrameX;
//	_imageInfo->currentFrameY = currentFrameY;
//
//	if (_isTrans)
//	{
//		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
//		GdiTransparentBlt(
//			hdc,													//복삳될 장소의 DC
//			destX,													//복사될 좌표의 시작점X
//			destY,													//복사될 좌표의 시작점Y
//			_imageInfo->frameWidth,									//복사될 이미지 가로크기
//			_imageInfo->frameHeight,								//복사될 이미지 세로크기
//			_imageInfo->hMemDC,										//복사될 대상DC
//			_imageInfo->currentFrameX * _imageInfo->frameWidth,		//복사시작 지점 X
//			_imageInfo->currentFrameY * _imageInfo->frameHeight,	//복사시작 지점 Y
//			_imageInfo->frameWidth,									//복사영역 가로크기
//			_imageInfo->frameHeight,								//복사영역 세로크기
//			_transColor);
//	}
//	else {
//		//BitBlt : DC영역끼리 고속복사
//		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
//			_imageInfo->hMemDC,
//			_imageInfo->currentFrameX * _imageInfo->frameWidth,
//			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
//	}
//}





