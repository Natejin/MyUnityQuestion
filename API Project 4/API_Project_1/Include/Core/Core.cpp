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

	//�ػ� ����
	typeResolution.SetSize(WINSIZEX, WINSIZEY);

	//������ â�� �������
	Create();

	//ȭ�� DC�� ������ش�.
	hdc = GetDC(hWnd);

	//Ÿ�̸� �ʱ�ȭ
	if (!Timer::GetSingleton()->Init())
		return false;

	//FileManager �ʱ�ȭ
	if (!FileManager::GetSingleton()->Init())
		return false;

	//InputManager �ʱ�ȭ
	if (!InputManager::GetSingleton()->Init())
		return false;

	//ResourceManager �ʱ�ȭ
	if (!ResourceManager::GetSingleton()->Init(_hInst, hdc))
		return false;

	//SceneManager �ʱ�ȭ
	if (!SceneManager::GetSingleton()->Init())
		return false;

	return true;
}

//������ ��� ���ư��°�
int Core::Run()
{
	
	MSG msg;
	while (loop)
	{
		//PeekMessage �� �޼����� �޼���ť�� ��� �ٷ� ����
		//���´� �޼����� ���� ��� true, ���� ��� false
		//�� �ȴ� �޼����� ���� �ð��� �������� ����Ÿ���̴�.
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//������ ����Ÿ���ϰ��
		else {
			Logic();
		}
	}
	return (int)msg.wParam;
}

Core::Core()
{
	//����׿� �޸� ���� üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //TODO ����� �ϴ°�
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

	//���� ������ Ÿ��Ʋ�ٳ� �޴��� ������ �������� ũ�⸦
	// �����ش�.

	RECT rect = { WINSTARTX,WINSTARTY, WINSIZEX, WINSIZEY};
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	//������ ������ ũ��� ������ Ŭ���̾�Ʈ ������ ũ�⸦
	// ���ϴ� ũ��� ������� �Ѵ�.
	SetWindowPos(hWnd, HWND_TOPMOST, WINSTARTX, WINSTARTY, rect.right - rect.left,
		rect.bottom - rect.top, SWP_NOMOVE | SWP_NOZORDER);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	return TRUE;
}

void Core::Logic()
{
	//Ÿ�̸� ����
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

//TODO: ���⼭ ������۸��� ������!!!
void Core::Render(double deltaTime)
{
	//����۸� �Ŵ������� ������
	Sprite* pBackBuffer = SINGLETON(ResourceManager)->GetBackBuffer();
	
	//������ ����۸� rectangle�� ȭ��ũ�⸸ŭ �׸�
	Rectangle(pBackBuffer->GetDC(), 0, 0, typeResolution.width, typeResolution.height);
	
	//���Ŵ������� ����� DC�� �������� ��
	SINGLETON(SceneManager)->Render(pBackBuffer->GetDC(), deltaTime);

	//����� DC�� ����ۿ� �׸�
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
//		//���ϰ��� 0�� �ƴѰ�� ��û�� �����Ѱ��̴�.
//		//if (joySetCapture(hWnd, JOYSTICKID1, NULL, FALSE))
//		//{
//		//	//�������� ����ϰ� �޽��� �ڽ��� �ȳ� �� ���α׷� ����
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
