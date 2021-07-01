//// API_FrameWork.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//#include "framework.h"
//#include "WINAPI_FrameWork.h"
//#include "mainGame.h"
//
//HINSTANCE m_hInstance;
//HWND m_hWnd;
//POINT m_ptMouse = { 0,0 };
//
//mainGame mg;
//
//
//
//
//
//
//
//
//
//LPTSTR m_lpszClass = WINNAME;
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//void setWindowSize(int x, int y, int width, int height);
//
////int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
////	LPSTR lpszCmdParam, int nCmdShow)
////{
////	m_hInstance = hInstance;
////
////	WNDCLASS wndClass;
////
////	wndClass.cbClsExtra = 0;
////	wndClass.cbWndExtra = 0;
////	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
////
////	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
////	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
////
////	wndClass.hInstance = hInstance;
////	wndClass.lpfnWndProc = (WNDPROC)WndProc;
////	wndClass.lpszClassName = m_lpszClass;
////	wndClass.lpszMenuName = NULL;
////
////	wndClass.style = CS_HREDRAW | CS_VREDRAW;
////
////	RegisterClass(&wndClass);
////
////	m_hWnd = CreateWindow(WINNAME, WINNAME, WS_OVERLAPPEDWINDOW, WINSTARTX, 
////		WINSTARTY, WINSIZEX, WINSIZEY, NULL, (HMENU)NULL, hInstance, NULL);
////
////	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
////	ShowWindow(m_hWnd, nCmdShow);
////
////	if (FAILED(mg.init())) {
////		return 0;
////	}
////
////
////
////
////	//MSG : 운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
////	MSG message;
////	//나중에 봉인해제
////	//while (true)
////	//{
////	//	if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
////	//	{
////	//		if (message.message == WM_QUIT)break;
////	//		TranslateMessage(&message);
////	//		DispatchMessage(&message);
////	//	}
////	//}
////
////	//TranslateMessage : 키보드 입력 메세지 처리 담당
////	//DispatchMessage : 윈도우 프로시져에 전달된 메세지를 실제 윈도우에 전달
////	//getMessage : 대기상태
////	// 게임용 루프
////	//while (true) {
////	//	// 입력버튼에 대해서 동작하는게 PeekMessage
////	//	// 입력시 mainProc 돌고 DefWinProc 반환해줌
////	//	// 이거 하는게 CALLBACK 함수 실행하게됨
////	//	if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
////	//		if (message.message == WM_QUIT) break;
////	//		TranslateMessage(&message);
////	//		DispatchMessage(&message);
////	//	}
////	//	// 그외에는 Update Render 돌아가게
////	//	// 키입력한다고 Update Render 돌아가지 않는건 아님
////	//	// 키입력시 PeekMessage 이후 Update Render 돌아가게됨
////	//	else {
////	//		//FRAME->Update();
////	//		// 프레임 제한
////	//		FRAME->Update(60.0f);
////	//		mg->Update();
////	//		mg->Render();
////	//	}
////	//}
////
////	mg.release();
////	return (int)message.wParam;
////}
//
//
//
//
//
////윈도우 프로시져 : 메세지를 운영체제에 전달한다. 강제로 운영체제가 호출
////hWnd : 윈도우가 발생한 메세지인지 구분
////imessage : 메세지 구분번호
////wParam : 마우스 버튼의 상태, 키보드 조합키의 상태를 전달한다.
////lParam :  마우스 클릭 좌표를 전달
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	//DC : device context->출력에 관한 옵션을 디폴트로 설정
//	//DC를 사용하기 위해 HDC, DC의 핸들이용
//	//GDI모듈에 의해 관리
//	//GDI 화면 처리와 그래픽 출력을 한다.
//	//HDC : 출력에 필요한 정보를 가지는 데이터 구조체
//	//좌표, 굵기,색 등등 출려에 필요한 모든 정보를 담고 있다.
//	//PAINTSTRUCT : 윈도우의 클라이언트 영역을 그리기 위한 정보를 담은 구조체
//
//	return mg.MainProc(hWnd, iMessage, wParam, lParam);
//}
//
////위도우 크기조정 
////클라이언트 영역 사이즈 잡자
//void setWindowSize(int x, int y, int width, int height){
//	RECT rc;
//	rc.left = 0;
//	rc.top = 0;
//	rc.right = width;
//	rc.bottom = height;
//	//위 RECT정보로 윈도우 사이즈 셋팅
//	SetWindowPos(m_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
//}



// Day29.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "framework.h"
#include "WINAPI_FrameWork.h"
#include "MainGame.h"


#define MAX_LOADSTRING 100

HINSTANCE m_hInstance;
HWND m_hWnd;
POINT m_ptMouse;

MainGame* g_mg;

void SetWindowSize(int x, int y, int width, int height);

WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

												// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.
	g_mg = new MainGame;

	m_hInstance = hInstance;


	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDS_APP_TITLE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	if (FAILED(g_mg->Init())) {
		return false;
	}

	// 이거 옮겼음 Init 문제 때문에
	UpdateWindow(m_hWnd);

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDS_APP_TITLE));

	MSG msg;

	// 메시지 들어오면 동작
	// 들어오지 않으면 동작하지 않음
	// SetTimer이용해서 주기적으로 돌렸었음
	//// 기본 메시지 루프입니다.
	//while (GetMessage(&msg, nullptr, 0, 0))
	//{
	//	if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
	//	{
	//		TranslateMessage(&msg);
	//		DispatchMessage(&msg);
	//	}
	//}

	// 게임용 루프
	while (true) {
		// 입력버튼에 대해서 동작하는게 PeekMessage
		// 입력시 mainProc 돌고 DefWinProc 반환해줌
		// 이거 하는게 CALLBACK 함수 실행하게됨
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		// 그외에는 Update Render 돌아가게
		// 키입력한다고 Update Render 돌아가지 않는건 아님
		// 키입력시 PeekMessage 이후 Update Render 돌아가게됨
		else {
			//FRAME->Update();
			// 프레임 제한
			MG_TIME->Update(60.0f);
			g_mg->Update();
			g_mg->LateUpdate();
			g_mg->Render();
		}
	}

	g_mg->Release();
	delete g_mg;

	return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_MYICON));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = WINNAME;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	m_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		nullptr, nullptr, hInstance, nullptr);

	if (!m_hWnd)
	{
		return FALSE;
	}

	SetWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	ShowWindow(m_hWnd, nCmdShow);

	return TRUE;
}

void SetWindowSize(int x, int y, int width, int height) {
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = WINSIZEX;
	rc.bottom = WINSIZEY;

	AdjustWindowRect(&rc, WINSTYLE, FALSE);

	SetWindowPos(m_hWnd, NULL, x, y,
		(rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다.
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(m_hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	default:
		return g_mg->MainProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
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
