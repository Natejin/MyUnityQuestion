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

	//�̹��� ������ ������ �����ض�
	if (_imageInfo != NULL)release();
	//DC��������(���� �����쿡 ���� ȭ�� DC�� �ӽ÷� ������)
	//CreateCompatibleDC: ��Ʈ���� ����ϱ� ���� �޸� DC�� ������ش�.
	// CreateCompatibleBitmap: ����DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	HDC hdc = GetDC(m_hWnd);

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//�����̸�
	_fileName = NULL;

	//����Ű ����
	_isTrans = false;
	_transColor = RGB(0, 0, 0);

	//���ҽ��� �����µ� �����ϸ�
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

	//�����̸�
	int len = _tcslen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//���ҽ��� �����µ� �����ϸ�
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
		//��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,						//����� ����� DC
			0,							//����� ��ǥ�� ������X
			0,							//����� ��ǥ�� ������Y
			_imageInfo->width,			//����� �̹��� ����ũ��
			_imageInfo->height,			//����� �̹��� ����ũ��
			_imageInfo->hMemDC,			//����� ���DC
			0,							//������� ���� X
			0,							//������� ���� Y
			_imageInfo->width,			//���翵�� ����ũ��
			_imageInfo->height,			//���翵�� ����ũ��
			_transColor);
	}
	else {
		//BitBlt : DC�������� ��Ӻ���
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, const int destX, const int destY)
{
	if (_isTrans)
	{
		//��Ʈ���� �ҷ��ö� Ư�� ������ �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt(
			hdc,						//����� ����� DC
			destX,							//����� ��ǥ�� ������X
			destY,							//����� ��ǥ�� ������Y
			_imageInfo->width,			//����� �̹��� ����ũ��
			_imageInfo->height,			//����� �̹��� ����ũ��
			_imageInfo->hMemDC,			//����� ���DC
			0,							//������� ���� X
			0,							//������� ���� Y
			_imageInfo->width,			//���翵�� ����ũ��
			_imageInfo->height,			//���翵�� ����ũ��
			_transColor);
	}
	else {
		//BitBlt : DC�������� ��Ӻ���
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}

}
