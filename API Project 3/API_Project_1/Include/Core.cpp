#include "Core.h"
#include "Scene/SceneManager.h"
#include "Core/Timer.h"

bool Core::loop = true;

bool Core::Init(HINSTANCE _hInst)
{
	hInst = _hInst;

	MyRegisterClass();

	//�ػ� ����
	typeResolution.SetSize(WINSIZEX, WINSIZEY);

	Create();
	//ȭ�� DC�� ������ش�.
	hdc = GetDC(hWnd);


	//Ÿ�̸� �ʱ�ȭ
	if (!Timer::GetInst()->Init())
		return false;


	//�������� �ʱ�ȭ
	if (!SceneManager::GetInst()->Init()) 
		return false;

	return true;
}

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

}

Core::~Core()
{
	DESTROY_SINGLE(Timer);
	DESTROY_SINGLE(SceneManager);
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
	GET_SINGLE(Timer)->Update();

	float fDeltaTime = GET_SINGLE(Timer)->GetDeltaTime();

	Input(fDeltaTime);
	Update(fDeltaTime);
	LateUpdate(fDeltaTime);
	Collision(fDeltaTime);
	Render(fDeltaTime);
}

void Core::Input(float deltaTime)
{
	GET_SINGLE(SceneManager)->Input(deltaTime);
}

int Core::Update(float deltaTime)
{
	GET_SINGLE(SceneManager)->Update(deltaTime);
	return 0;
}

int Core::LateUpdate(float deltaTime)
{
	GET_SINGLE(SceneManager)->LateUpdate(deltaTime);
	return 0;
}

void Core::Collision(float deltaTime)
{
	GET_SINGLE(SceneManager)->Collision(deltaTime);
}

void Core::Render(float deltaTime)
{
	GET_SINGLE(SceneManager)->Render(hdc, deltaTime);
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
