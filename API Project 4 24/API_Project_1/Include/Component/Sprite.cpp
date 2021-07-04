
#include "Sprite.h"
#include "../Core/FileManager.h"


// ���� ���� ����� ���� ���̺귯��(lib)
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
	//������ �����Ǿ� �ִ� ������ �ٽ� �������ش�.
	SelectObject(hMemDC, hOBit);

	//Bitmap�� �����ش�.
	DeleteObject(hBit);

	//DC�� �����ش�.
	DeleteObject(hMemDC);
}

bool Sprite::CreateSprite(HINSTANCE hInst, HDC hdc,	const string& strKey, int width, int height)
{
	//�޸� DC�� ����
	//��ȭ��DC�� �޸� DC�� ����;
	hMemDC = CreateCompatibleDC(hdc);
	//const wchar_t* pPath = SINGLETON(FileManager)->FindPath(strPathKey);

	//wstring strPath;

	//if (pPath)
	//{
	//	strPath = pPath;
	//}

	//strPath += pFileName;


	//0,0������ ����ũ��
	hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);

	//������ ������� ��Ʈ�� ������ DC�� �����Ѵ�.

	//�����Ҷ� ��ȯ��ū ���� DC�� �⺻���� �����Ǿ� �ִ�

	//������ ��ȯ�ȴ�.

	hOBit = (HBITMAP)SelectObject(hMemDC, hBit);

	GetObject(hBit, sizeof(bitmapInfo), &bitmapInfo);


	return true;
}

bool Sprite::LoadSprite(HINSTANCE hInst, HDC hdc,
	const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	//�޸� DC�� ����
	//��ȭ��DC�� �޸� DC�� ����;
	hMemDC = CreateCompatibleDC(hdc);
	const wchar_t* pPath = SINGLETON(FileManager)->FindPath(strPathKey);

	wstring strPath;

	if (pPath)
	{
		strPath = pPath;
	}

	strPath += pFileName;


	//0,0������ ����ũ��
	hBit = (HBITMAP)LoadImage(hInst, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//������ ������� ��Ʈ�� ������ DC�� �����Ѵ�.

	//�����Ҷ� ��ȯ��ū ���� DC�� �⺻���� �����Ǿ� �ִ�

	//������ ��ȯ�ȴ�.

	hOBit = (HBITMAP)SelectObject(hMemDC, hBit);

	GetObject(hBit, sizeof(bitmapInfo), &bitmapInfo);


	return true;
}


//
//
//bool Sprite::Init(HINSTANCE hInst, HDC hdc, const int _width, const int _height)
//{
//
//	////�̹��� ������ ������ �����ض�
//	//if (_imageInfo != NULL)Release();
//	// 
//	//DC��������(���� �����쿡 ���� ȭ�� DC�� �ӽ÷� ������)
//	//CreateCompatibleDC: ��Ʈ���� ����ϱ� ���� �޸� DC�� ������ش�.
//	// CreateCompatibleBitmap: ����DC�� ȣȯ�Ǵ� ��Ʈ�� ����
//
//	HDC hdc = GetDC();
//	hMemDC = CreateCompatibleDC(hdc);
//
//	//�̹��� ���� ����
//	loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
//	resID = 0;
//	hMemDC = CreateCompatibleDC(hdc);
//	hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _width, _height);
//	hOBit = (HBITMAP)SelectObject(hMemDC, hBit);
//	width = _width;
//	height = _height;
//
//	//�����̸�
//	//_fileName = NULL;
//
//	//����Ű ����
//	_isTrans = false;
//	_transColor = RGB(0, 0, 0);
//
//	//���ҽ��� �����µ� �����ϸ�
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
//	//�����̸�
//	int len = _tcslen(_fileName);
//	fileName = new char[len + 1];
//	strcpy_s(fileName, len + 1, _fileName);
//
//	_isTrans = isTrans;
//	_transColor = transColor;
//
//	//���ҽ��� �����µ� �����ϸ�
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
//	//�����̸�
//	int len = _tcslen(fileName);
//	_fileName = new char[len + 1];
//	strcpy_s(_fileName, len + 1, fileName);
//
//	_isTrans = isTrans;
//	_transColor = transColor;
//
//	//���ҽ��� �����µ� �����ϸ�
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
//	//�����̸�
//	int len = _tcslen(fileName);
//	_fileName = new char[len + 1];
//	strcpy_s(_fileName, len + 1, fileName);
//
//	_isTrans = isTrans;
//	_transColor = transColor;
//
//	//���ҽ��� �����µ� �����ϸ�
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
//		//��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
//		GdiTransparentBlt(
//			hdc,						//����� ����� DC
//			0,							//����� ��ǥ�� ������X
//			0,							//����� ��ǥ�� ������Y
//			_imageInfo->width,			//����� �̹��� ����ũ��
//			_imageInfo->height,			//����� �̹��� ����ũ��
//			_imageInfo->hMemDC,			//����� ���DC
//			0,							//������� ���� X
//			0,							//������� ���� Y
//			_imageInfo->width,			//���翵�� ����ũ��
//			_imageInfo->height,			//���翵�� ����ũ��
//			_transColor);
//	}
//	else {
//		//BitBlt : DC�������� ��Ӻ���
//		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
//			_imageInfo->hMemDC, 0, 0, SRCCOPY);
//	}
//}
//
//void Sprite::Render(HDC hdc, const int destX, const int destY)
//{
//	if (_isTrans)
//	{
//		//��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
//		GdiTransparentBlt(
//			hdc,						//����� ����� DC
//			destX,							//����� ��ǥ�� ������X
//			destY,							//����� ��ǥ�� ������Y
//			_imageInfo->width,			//����� �̹��� ����ũ��
//			_imageInfo->height,			//����� �̹��� ����ũ��
//			_imageInfo->hMemDC,			//����� ���DC
//			0,							//������� ���� X
//			0,							//������� ���� Y
//			_imageInfo->width,			//���翵�� ����ũ��
//			_imageInfo->height,			//���翵�� ����ũ��
//			_transColor);
//	}
//	else {
//		//BitBlt : DC�������� ��Ӻ���
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
//		//��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
//		GdiTransparentBlt(
//			hdc,						//����� ����� DC
//			destX,							//����� ��ǥ�� ������X
//			destY,							//����� ��ǥ�� ������Y
//			sourWidth,					//����� �̹��� ����ũ��
//			sourheight,			//����� �̹��� ����ũ��
//			_imageInfo->hMemDC,			//����� ���DC
//			sourX,							//������� ���� X
//			sourY,							//������� ���� Y
//			sourWidth,			//���翵�� ����ũ��
//			sourheight,			//���翵�� ����ũ��
//			_transColor);
//	}
//	else {
//		//BitBlt : DC�������� ��Ӻ���
//		BitBlt(hdc, destX, destY, sourWidth, sourheight,
//			_imageInfo->hMemDC, sourX, sourY, SRCCOPY);
//	}
//}
//
//void Sprite::FrameRender(HDC hdc, const int destX, const int destY)
//{
//	if (_isTrans)
//	{
//		//��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
//		GdiTransparentBlt(
//			hdc,													//����� ����� DC
//			destX,													//����� ��ǥ�� ������X
//			destY,													//����� ��ǥ�� ������Y
//			_imageInfo->frameWidth,									//����� �̹��� ����ũ��
//			_imageInfo->frameHeight,								//����� �̹��� ����ũ��
//			_imageInfo->hMemDC,										//����� ���DC
//			_imageInfo->currentFrameX * _imageInfo->frameWidth,		//������� ���� X
//			_imageInfo->currentFrameY * _imageInfo->frameHeight,	//������� ���� Y
//			_imageInfo->frameWidth,									//���翵�� ����ũ��
//			_imageInfo->frameHeight,								//���翵�� ����ũ��
//			_transColor);
//	}
//	else {
//		//BitBlt : DC�������� ��Ӻ���
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
//		//��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
//		GdiTransparentBlt(
//			hdc,													//����� ����� DC
//			destX,													//����� ��ǥ�� ������X
//			destY,													//����� ��ǥ�� ������Y
//			_imageInfo->frameWidth,									//����� �̹��� ����ũ��
//			_imageInfo->frameHeight,								//����� �̹��� ����ũ��
//			_imageInfo->hMemDC,										//����� ���DC
//			_imageInfo->currentFrameX * _imageInfo->frameWidth,		//������� ���� X
//			_imageInfo->currentFrameY * _imageInfo->frameHeight,	//������� ���� Y
//			_imageInfo->frameWidth,									//���翵�� ����ũ��
//			_imageInfo->frameHeight,								//���翵�� ����ũ��
//			_transColor);
//	}
//	else {
//		//BitBlt : DC�������� ��Ӻ���
//		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
//			_imageInfo->hMemDC,
//			_imageInfo->currentFrameX * _imageInfo->frameWidth,
//			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
//	}
//}





