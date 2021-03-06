#include "Core.h"

bool Core::loop = true;

bool Core::Init(HINSTANCE _hInst)
{
	hInst = _hInst;

	MyRegisterClass();

	//해상도 설정
	typeResolution.SetSize(WINSIZEX, WINSIZEY);

	Create();

	return true;
}

int Core::Run()
{
	
	MSG msg;

	while (loop)
	{
		//PeekMessage 는 메세지가 메세지큐에 없어도 바로 빠져
		//나온다 메세지가 있을 경우 true, 없을 경우 false
		//가 된다 메세지가 없는 시간이 윈도우의 데드타임이다.
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//윈도우 데드타임일경우
		else {

		}
	}
	return (int)msg.wParam;
}

ATOM Core::MyRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Core::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInst;
	wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL; //MAKEINTRESOURCEW(IDC_WINAPI4);
	wcex.lpszClassName = WINNAME; //szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
	//return ATOM();
}

BOOL Core::Create()
{
	hWnd = CreateWindowW(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		nullptr,
		nullptr,
		hInst,
		nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	//실제 윈도우 타이틀바나 메뉴를 포함한 윈도우의 크기를
	// 구해준다.

	RECT rect = { WINSTARTX,WINSTARTY, WINSIZEX, WINSIZEY};
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	//위에서 구해준 크기로 윈도우 클라이언트 영역의 크기를
	// 원하는 크기로 맞춰줘야 한다.
	SetWindowPos(hWnd, HWND_TOPMOST, WINSTARTX, WINSTARTY, rect.right - rect.left,
		rect.bottom - rect.top, SWP_NOMOVE | SWP_NOZORDER);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	return TRUE;
}

LRESULT Core::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		EndPaint(hWnd, &ps);
		break;
	}
	break;
	case WM_KEYDOWN: 
		break;
	case WM_DESTROY:
		loop = false;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
