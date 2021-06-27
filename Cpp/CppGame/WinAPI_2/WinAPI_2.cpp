// WinAPI_2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WinAPI_2.h"
#include <vector>

using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst; // current instance

//WCHAR 유니코드기반 2바이트 문자
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//WinMain : Console의 main 같이 win32의 진입하는 함수이다
//HINSTANCE : 운영체제가 실행되는프로그램마다 식별되는 식별방법 (건들리지말자 운영체제가 메모리에 올라온 윈도우를 관리하는용도)

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings (게이머들은 잘안쓴다.)
	// loadString : 게이머들은 잘안쓴다. ,문자열 관련임
	// szTitle : 윈도우창의 제목을 지정 
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINAPI2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	//단축키 지정한걸 가지고옴  무시하셈 ㅋ
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI2));

	//이벤트에 따른 부가적인 정보
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
	//윈도우창의 구조를 저장하는 클래스
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	//윈도우 창모양을 원하는대로 쓰기
	//HREDRAW 가로가 변할경우 다시그린다.
	//VREDRAW 세로가 변할경우 다시그린다.
	wcex.style = CS_HREDRAW | CS_VREDRAW;

	//이벤트를 메세지로 만들어서 메세지큐에 넣는다.
	//이벤트 순서대로 넣어두면 읽을때 순서대로 꺼내어서 읽는다.
	//메세지에 따른 사용자 정의를 만드는 공간
	// 응용프로그램의 인스턴스 핸들러
	// 메세지 처리하는 함수
	// 함수포인터임
	wcex.lpfnWndProc = WndProc;
	//윈도우에서 사용하는 데이터단위를 바이트로 지정
	wcex.cbClsExtra = 0;
	//개별메모리에서 사용하는 여분의 메모리
	wcex.cbWndExtra = 0;

	wcex.hInstance = hInstance;
	//타이틀바의 좌상단 아이콘, 최소화 아이콘
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI2));
	//커서 지정
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);

	//윈도우 작업영역에 칠한 배경 브러쉬
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	//메뉴지정 안쓸거면 NULL로 지정
	wcex.lpszMenuName = NULL;

	//등록하고자하는 윈도우스 이름
	wcex.lpszClassName = szWindowClass;

	//타이틀바의 좌상단 아이콘, 최소화 아이콘
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


	//윈도우를 만듬
	//WS_OVERLAPPEDWINDOW : 비트연산자로 필요한게 있음
	 //#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
     //                             WS_CAPTION        | \
     //                             WS_SYSMENU        | \
     //                             WS_THICKFRAME     | \
     //                             WS_MINIMIZEBOX    | \
     //                             WS_MAXIMIZEBOX)


	//WS_SYSMENU 타이틀 클릭시 메뉴창이 나옴
	//WS_THICKFRAME 창크기를 조절
	//WS_MINIMIZEBOX 최소화
	//WS_MAXIMIZEBOX 최대화

	//클라이언트 영역 : 타이틀을 제외한 부분

	//CW_USEDEFAULT 좌상단 0,0
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
	static LPCWSTR lastKeyInput = TEXT("마지막으로 입력 받은 키 : 없음");
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

		//지상에 있을시 마찰력  작용
		if (onGround)
		{
			//가속력이 좌측일시 반대방향으로 마찰력
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
			//가속력이 우측일시 반대방향으로 마찰력
			else if (moveSpeed < 0) {
				if (moveSpeed - forceFriction >= 0)
				{
					moveSpeed = 0;
				}
				else {
					moveSpeed += forceFriction;
				}
			}
			//가속력이 0일시 아무짓도 안함
			else {

			}
		}
		//공중에서는 마찰력 없음
		else {

		}


		//횡 이동
		rcHead.left += moveSpeed;
		rcHead.right += moveSpeed;

		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RIGHT:
			lastKeyInput = TEXT("마지막으로 입력 받은 키 : 우측 방향키");
			if (moveSpeed + acceleration < maxSpeed)
			{
				moveSpeed += acceleration;
			}
			else {
				moveSpeed = maxSpeed;
			}
			break;
		case VK_LEFT:
			lastKeyInput = TEXT("마지막으로 입력 받은 키 : 좌측 방향키");
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
			//점프
		case VK_SPACE:
			lastKeyInput = TEXT("마지막으로 입력 받은 키 : 스페이스바");
			if (onGround)
			{
				forceVertical = forceJump;
			}
			break;
		default:
			break;
		}
		break;
	//무언가 그릴때
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		LPCWSTR text1 = onGround ? TEXT("지상에 있다") : TEXT("공중에 있다");
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
		//szTime = "지상에선 마찰력이 존재하기때문에 속도가 감소하지만\n";
		wsprintf(szTitle1, TEXT("지상에선 마찰력이 존재하기때문에 속도가 감소하지만\n공중에서는 속도가 감소하지않는다."));
		TextOut(hdc, 500, 340, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, TEXT("좌우측 방향키로 이동이 가능하고 땅위에서만 점프가 가능함 (스페이스바 입력)."));
		TextOut(hdc, 500, 380, szTitle1, lstrlen(szTitle1));

		wsprintf(szTitle1, TEXT("시작하자마자 떨어지니깐 방향키로 땅위에 착지합시다."));
		TextOut(hdc, 500, 410, szTitle1, lstrlen(szTitle1));

		Rectangle(hdc, rcHead.left, rcHead.top, rcHead.right, rcHead.bottom);
		Rectangle(hdc, ground.left, ground.top, ground.right, ground.bottom);

		wsprintf(szTitle1, TEXT("여기는 땅이다 넌 못지나 간다."));
		TextOut(hdc, 450, 950, szTitle1, lstrlen(szTitle1));
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;

	//윈도우가 종료될때
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		//윈도우 창 끝내기
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
