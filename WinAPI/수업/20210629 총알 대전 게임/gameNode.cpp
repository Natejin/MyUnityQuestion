#include "framework.h"
#include "gameNode.h"


GameNode::GameNode()
{
}


GameNode::~GameNode()
{
}

HRESULT GameNode::Init()
{
	//Ÿ�̸Ӷ� ������ �ֱ⸶�� ������ �Լ��� �����Ѵ�.
	//1 : ������ �ڵ�
	//2 :  Ÿ�̸� ��ȣ
	//3 :  Ÿ�̸��ֱ� 1000=1��
	//4 :  �ֱ⸶�� ������ �Լ�
	//NULL�̸� WM_TIMER�� ����
	SetTimer(m_hWnd, 1, 10, NULL);
	//�Ŵ��� �ʱ�ȭ
	InputManager->Init();

	return S_OK;
}

void GameNode::Release()
{	//Ÿ�̸� ����

	//������ ���ϸ� ���Ḧ �ص� �޸𸮰� ������~
	KillTimer(m_hWnd, 1);
	//�Ŵ��� ����
	InputManager->releaseSingleton();
	RND->releaseSingleton();
}

void GameNode::Update()
{
	//������� ���� ������� �ʴ´� true->false
	InvalidateRect(m_hWnd, NULL, true);
}
void GameNode::Render(HDC hdc)
{
}

LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;


	 HDC MemDC;
	 HBITMAP myBitmap, oldBitmap;
	switch (iMessage)
	{
	case WM_TIMER:
		this->Update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//MemDC = CreateCompatibleDC(hdc);
		//MyBitmap = LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP4));
		//OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);
		//BitBlt(hdc, 0, 0, 400, 600, MemDC, 0, 0, SRCCOPY);
		//SelectObject(MemDC, OldBitmap);
		//DeleteObject(MyBitmap);
		//DeleteDC(MemDC);
		this->Render(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}//end of switch

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
