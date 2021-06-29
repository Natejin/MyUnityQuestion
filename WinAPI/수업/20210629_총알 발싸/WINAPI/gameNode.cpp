
#include "gameNode.h"

gameNode::gameNode() {}

gameNode::~gameNode() {}

HRESULT gameNode::init()
{
	//Ÿ�̸Ӷ� ������ �ֱ⸶�� ������ �Լ� ����
	//1.������ �ڵ�, Ÿ�̸� ��ȣ, Ÿ�̸� �ֱ�, NULL�̸� WM_TIMER
	SetTimer(m_hWnd, 1, 10, NULL);

	//�Ŵ��� �ʱ�ȭ
	InputManager->init();
	return S_OK;
}

void gameNode::release()
{
	KillTimer(m_hWnd, 1);//���ϸ� ū�ϳ�

	//�Ŵ��� ����
	InputManager->releaseSingleTon();
}

void gameNode::update()
{
	InvalidateRect(m_hWnd, NULL, true);
}

void gameNode::render(HDC hdc) {}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//DC : device context->��¿� ���� �ɼ��� ����Ʈ�� ����
	//DC�� ����ϱ� ���� HDC, DC�� �ڵ��̿�
	//GDI��⿡ ���� ����
	//GDI ȭ�� ó���� �׷��� ����� �Ѵ�.
	//HDC : ��¿� �ʿ��� ������ ������ ������ ����ü
	//��ǥ, ����,�� ��� ����� �ʿ��� ��� ������ ��� �ִ�.
	//PAINTSTRUCT : �������� Ŭ���̾�Ʈ ������ �׸��� ���� ������ ���� ����ü

	PAINTSTRUCT ps;
	HDC hdc;
	switch (iMessage)
	{
	case WM_TIMER:
		this->update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		this->render(hdc);
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
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
