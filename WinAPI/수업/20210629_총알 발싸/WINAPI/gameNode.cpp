
#include "gameNode.h"

gameNode::gameNode() {}

gameNode::~gameNode() {}

HRESULT gameNode::init()
{
	//타이머란 일정한 주기마다 정해진 함수 실행
	//1.윈도우 핸들, 타이머 번호, 타이머 주기, NULL이면 WM_TIMER
	SetTimer(m_hWnd, 1, 10, NULL);

	//매니저 초기화
	InputManager->init();
	return S_OK;
}

void gameNode::release()
{
	KillTimer(m_hWnd, 1);//안하면 큰일남

	//매니저 해제
	InputManager->releaseSingleTon();
}

void gameNode::update()
{
	InvalidateRect(m_hWnd, NULL, true);
}

void gameNode::render(HDC hdc) {}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//DC : device context->출력에 관한 옵션을 디폴트로 설정
	//DC를 사용하기 위해 HDC, DC의 핸들이용
	//GDI모듈에 의해 관리
	//GDI 화면 처리와 그래픽 출력을 한다.
	//HDC : 출력에 필요한 정보를 가지는 데이터 구조체
	//좌표, 굵기,색 등등 출려에 필요한 모든 정보를 담고 있다.
	//PAINTSTRUCT : 윈도우의 클라이언트 영역을 그리기 위한 정보를 담은 구조체

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
