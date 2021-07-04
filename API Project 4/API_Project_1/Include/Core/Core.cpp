#include "Core.h"
#include "../Scene/SceneManager.h"
#include "Timer.h"
#include "InputManager.h"
#include "FileManager.h"
#include "ResourceManager.h"

bool Core::loop = true;

bool Core::Init(HINSTANCE _hInst)
{
	hInst = _hInst;


	MyRegisterClass();

	//해상도 설정
	typeResolution.SetSize(WINSIZEX, WINSIZEY);

	//윈도우 창을 만들어줌
	Create();

	//화면 DC를 만들어준다.
	hdc = GetDC(hWnd);

	//타이머 초기화
	if (!Timer::GetSingleton()->Init())
		return false;

	//FileManager 초기화
	if (!FileManager::GetSingleton()->Init())
		return false;

	//InputManager 초기화
	if (!InputManager::GetSingleton()->Init())
		return false;

	//ResourceManager 초기화
	if (!ResourceManager::GetSingleton()->Init(_hInst, hdc))
		return false;

	//SceneManager 초기화
	if (!SceneManager::GetSingleton()->Init())
		return false;

	return true;
}

//게임중 계속 돌아가는곳
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
			Logic();
		}
	}
	return (int)msg.wParam;
}

Core::Core()
{
	//디버그용 메모리 누수 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //TODO 디버깅 하는곳
	//_CrtSetBreakAlloc(244);
}

Core::~Core()
{
	DESTROY_SINGLE(Timer);
	DESTROY_SINGLE(SceneManager);
	DESTROY_SINGLE(InputManager);
	DESTROY_SINGLE(FileManager);
	DESTROY_SINGLE(ResourceManager);

	ReleaseDC(hWnd, hdc);
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

void Core::Logic()
{
	//타이머 갱신
	SINGLETON(Timer)->Update();

	double fDeltaTime = SINGLETON(Timer)->GetDeltaTime();

	Input(fDeltaTime);
	Update(fDeltaTime);
	LateUpdate(fDeltaTime);
	Collision(fDeltaTime);
	Render(fDeltaTime);
}

void Core::Input(double deltaTime)
{
	SINGLETON(SceneManager)->Input(deltaTime);
}

int Core::Update(double deltaTime)
{
	SINGLETON(SceneManager)->Update(deltaTime);
	return 0;
}

int Core::LateUpdate(double deltaTime)
{
	SINGLETON(SceneManager)->LateUpdate(deltaTime);
	return 0;
}

void Core::Collision(double deltaTime)
{
	SINGLETON(SceneManager)->Collision(deltaTime);
}

//TODO: 여기서 더블버퍼링을 구현함!!!
void Core::Render(double deltaTime)
{
	//백버퍼를 매니저에서 가져옴
	Sprite* pBackBuffer = SINGLETON(ResourceManager)->GetBackBuffer();
	
	//가져온 백버퍼를 rectangle로 화면크기만큼 그림
	Rectangle(pBackBuffer->GetDC(), 0, 0, typeResolution.width, typeResolution.height);
	
	//씬매니저에서 백버퍼 DC에 렌더링을 함
	SINGLETON(SceneManager)->Render(pBackBuffer->GetDC(), deltaTime);

	//백버퍼 DC를 백버퍼에 그림
	BitBlt(hdc, 0, 0, typeResolution.width, typeResolution.height, pBackBuffer->GetDC()
		, 0, 0, SRCCOPY);

	SAFE_RELEASE(pBackBuffer);
}

LRESULT Core::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
//	//JOYINFO joyinfo;
//	//UINT wNumDevs, wDeviceID;
//	//BOOL bDev1Attached, bDev2Attached;
//
//
//
	switch (message)
	{
//	case WM_CREATE:
//	{
//		//리턴값이 0이 아닌경우 요청이 실패한것이다.
//		//if (joySetCapture(hWnd, JOYSTICKID1, NULL, FALSE))
//		//{
//		//	//비프음을 출력하고 메시지 박스로 안내 후 프로그램 종료
//		//	MessageBeep(MB_ICONEXCLAMATION);
//		//	MessageBox(hWnd, TEXT("Couldn't capture the joystick."), NULL,
//		//		MB_OK | MB_ICONEXCLAMATION);
//		//	PostMessage(hWnd, WM_CLOSE, 0, 0L);
//		//}
//	}
//	break;
//	case WM_PAINT:
//	{
//		PAINTSTRUCT ps;
//		HDC hdc = BeginPaint(hWnd, &ps);
//
//		EndPaint(hWnd, &ps);
//		break;
//	}
//	break;
//	case WM_KEYDOWN:
//		break;
	case WM_DESTROY:
		loop = false;
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
