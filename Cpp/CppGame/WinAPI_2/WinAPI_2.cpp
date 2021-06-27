// WinAPI_2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WinAPI_2.h"
#include <vector>

using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst; // current instance

//WCHAR �����ڵ��� 2����Ʈ ����
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//WinMain : Console�� main ���� win32�� �����ϴ� �Լ��̴�
//HINSTANCE : �ü���� ����Ǵ����α׷����� �ĺ��Ǵ� �ĺ���� (�ǵ鸮������ �ü���� �޸𸮿� �ö�� �����츦 �����ϴ¿뵵)

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings (���̸ӵ��� �߾Ⱦ���.)
	// loadString : ���̸ӵ��� �߾Ⱦ���. ,���ڿ� ������
	// szTitle : ������â�� ������ ���� 
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINAPI2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	//����Ű �����Ѱ� �������  �����ϼ� ��
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI2));

	//�̺�Ʈ�� ���� �ΰ����� ����
	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	//������â�� ������ �����ϴ� Ŭ����
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	//������ â����� ���ϴ´�� ����
	//HREDRAW ���ΰ� ���Ұ�� �ٽñ׸���.
	//VREDRAW ���ΰ� ���Ұ�� �ٽñ׸���.
	wcex.style = CS_HREDRAW | CS_VREDRAW;

	//�̺�Ʈ�� �޼����� ���� �޼���ť�� �ִ´�.
	//�̺�Ʈ ������� �־�θ� ������ ������� ����� �д´�.
	//�޼����� ���� ����� ���Ǹ� ����� ����
	// �������α׷��� �ν��Ͻ� �ڵ鷯
	// �޼��� ó���ϴ� �Լ�
	// �Լ���������
	wcex.lpfnWndProc = WndProc;
	//�����쿡�� ����ϴ� �����ʹ����� ����Ʈ�� ����
	wcex.cbClsExtra = 0;
	//�����޸𸮿��� ����ϴ� ������ �޸�
	wcex.cbWndExtra = 0;

	wcex.hInstance = hInstance;
	//Ÿ��Ʋ���� �»�� ������, �ּ�ȭ ������
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI2));
	//Ŀ�� ����
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);

	//������ �۾������� ĥ�� ��� �귯��
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	//�޴����� �Ⱦ��Ÿ� NULL�� ����
	wcex.lpszMenuName = NULL;

	//����ϰ����ϴ� �����콺 �̸�
	wcex.lpszClassName = szWindowClass;

	//Ÿ��Ʋ���� �»�� ������, �ּ�ȭ ������
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable


	//�����츦 ����
	//WS_OVERLAPPEDWINDOW : ��Ʈ�����ڷ� �ʿ��Ѱ� ����
	 //#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
     //                             WS_CAPTION        | \
     //                             WS_SYSMENU        | \
     //                             WS_THICKFRAME     | \
     //                             WS_MINIMIZEBOX    | \
     //                             WS_MAXIMIZEBOX)


	//WS_SYSMENU Ÿ��Ʋ Ŭ���� �޴�â�� ����
	//WS_THICKFRAME âũ�⸦ ����
	//WS_MINIMIZEBOX �ּ�ȭ
	//WS_MAXIMIZEBOX �ִ�ȭ

	//Ŭ���̾�Ʈ ���� : Ÿ��Ʋ�� ������ �κ�

	//CW_USEDEFAULT �»�� 0,0
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}




int dir[4] = { 0, 0, 1, 1 };
vector<RECT> rc;

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static RECT rcHead = { 25,25,50,50 };
	//left, bottom, right, top
	static RECT ground = { 100,500,1000,1000 };
	/* PAINTSTRUCT ps;
	 HDC hdc;*/
	float speed = 10;
	static int time = 0;
	char* szTime[128];
	static double m_fStartTime = 0;
	static double NowTime = 0;


	static double gravity = 0.9;
	static double forceVerticalMax = 9;



	static WCHAR szTitle1[MAX_LOADSTRING];


	static bool onGround = false;
	static float forceVertical = 0;
	static double forceJump = 20;


	static double moveSpeed = 0;

	static double forceFriction = 0.2;
	static double maxSpeed = 10;
	static double acceleration = 7;
	static LPCWSTR lastKeyInput = TEXT("���������� �Է� ���� Ű : ����");
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 0, 10, NULL);
		break;
	case WM_TIMER:
		//forceVertical
		if (forceVertical - gravity >= -forceVerticalMax)
		{
			forceVertical -= gravity;
		}
		else {
			forceVertical = -forceVerticalMax;
		}

		if (rcHead.bottom - forceVertical < ground.top ||
			rcHead.left > ground.right ||
			rcHead.right < ground.left)
		{
			rcHead.top -= forceVertical;
			rcHead.bottom -= forceVertical;
			onGround = false;
		}
		else {
			onGround = true;
		}

		//���� ������ ������  �ۿ�
		if (onGround)
		{
			//���ӷ��� �����Ͻ� �ݴ�������� ������
			if (moveSpeed > 0)
			{
				if (moveSpeed - forceFriction <= 0)
				{
					moveSpeed = 0;
				}
				else {
					moveSpeed -= forceFriction;
				}
			}
			//���ӷ��� �����Ͻ� �ݴ�������� ������
			else if (moveSpeed < 0) {
				if (moveSpeed - forceFriction >= 0)
				{
					moveSpeed = 0;
				}
				else {
					moveSpeed += forceFriction;
				}
			}
			//���ӷ��� 0�Ͻ� �ƹ����� ����
			else {

			}
		}
		//���߿����� ������ ����
		else {

		}


		//Ⱦ �̵�
		rcHead.left += moveSpeed;
		rcHead.right += moveSpeed;

		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RIGHT:
			lastKeyInput = TEXT("���������� �Է� ���� Ű : ���� ����Ű");
			if (moveSpeed + acceleration < maxSpeed)
			{
				moveSpeed += acceleration;
			}
			else {
				moveSpeed = maxSpeed;
			}
			break;
		case VK_LEFT:
			lastKeyInput = TEXT("���������� �Է� ���� Ű : ���� ����Ű");
			if (moveSpeed - acceleration > -maxSpeed)
			{
				moveSpeed -= acceleration;
			}
			else {
				moveSpeed = -maxSpeed;
			}
			break;
		case VK_DOWN:
			break;
		case VK_UP:
			break;
			//����
		case VK_SPACE:
			lastKeyInput = TEXT("���������� �Է� ���� Ű : �����̽���");
			if (onGround)
			{
				forceVertical = forceJump;
			}
			break;
		default:
			break;
		}
		break;
	//���� �׸���
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		LPCWSTR text1 = onGround ? TEXT("���� �ִ�") : TEXT("���߿� �ִ�");
		wsprintf(szTitle1, text1);
		TextOut(hdc, 500, 200, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, lastKeyInput);
		TextOut(hdc, 500, 230, szTitle1, lstrlen(szTitle1));


		wsprintf(szTitle1, TEXT("force(x,y) : (%d.%d, %d.%d)"), (int)forceVertical, (int)(forceVertical * 100) % 100, (int)moveSpeed, (int)(moveSpeed * 100) % 100);
		TextOut(hdc, 500, 260, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, TEXT("gravity : %d.%d"), (int)gravity, (int)(gravity * 100) % 100);
		TextOut(hdc, 500, 290, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, TEXT("test : %d"), -1);
		TextOut(hdc, 500, 320, szTitle1, lstrlen(szTitle1));
		//szTime = "���󿡼� �������� �����ϱ⶧���� �ӵ��� ����������\n";
		wsprintf(szTitle1, TEXT("���󿡼� �������� �����ϱ⶧���� �ӵ��� ����������\n���߿����� �ӵ��� ���������ʴ´�."));
		TextOut(hdc, 500, 340, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, TEXT("�¿��� ����Ű�� �̵��� �����ϰ� ���������� ������ ������ (�����̽��� �Է�)."));
		TextOut(hdc, 500, 380, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, TEXT("�������ڸ��� �������ϱ� ����Ű�� ������ �����սô�."));
		TextOut(hdc, 500, 410, szTitle1, lstrlen(szTitle1));

		Rectangle(hdc, rcHead.left, rcHead.top, rcHead.right, rcHead.bottom);
		Rectangle(hdc, ground.left, ground.top, ground.right, ground.bottom);

		wsprintf(szTitle1, TEXT("����� ���̴� �� ������ ����."));
		TextOut(hdc, 450, 950, szTitle1, lstrlen(szTitle1));
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;

	//�����찡 ����ɶ�
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		//������ â ������
		PostQuitMessage(0);
		break;
	default:
		//
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
