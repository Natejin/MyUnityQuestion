// WinAPI_3.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WinAPI_3.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPI3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI3));

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

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...


			//�����ڵ� ���ڿ��� "" �տ� L�� �ٿ��� L""�� ���� �� �ִ�.
			//�ƴϸ� TEXT ��ũ�θ� �̿��Ѵ�.
			TextOut(hdc, 50, 50, TEXT("win32"), 5);
			TCHAR strMouse[64] = {};
			//wsprintf : �����ڵ� ���ڿ��� ������ִ� �Լ��̴�.
			//%d���� ������ ���Եȴ�.
			//lstrlen : �����ڵ� ���ڿ��� ���̸� �����ش�.
            if (tagArea.mouseDown)
            {
                Rectangle(hdc, tagArea.ptStart.x, tagArea.ptStart.y, tagArea.ptEnd.x, tagArea.ptEnd.y);
            }
			wsprintf(strMouse, TEXT("x : %d y: %d"), tagArea.ptStart.x, tagArea.ptStart.y);
			TextOut(hdc, 600, 30, strMouse, lstrlen(strMouse));

            wsprintf(strMouse, TEXT("x : %d y: %d"), tagArea.ptEnd.x, tagArea.ptEnd.y);
            TextOut(hdc, 600, 60, strMouse, lstrlen(strMouse));

            //�簢�� �׸��� : Left, Top Right bottom ���� ��Ƽ� �簢���� �׷��ش�.
            Rectangle(hdc, 100, 100, 200, 200);

            //���׸���
            Ellipse(hdc, 100, 100, 200, 200);

            //������ ����
            MoveToEx(hdc, 300, 100, NULL);

            //���׸���
            LineTo(hdc, 400, 150);

			//�������� 400,150���� �����Ѵ�.
			LineTo(hdc, 700, 200);
			LineTo(hdc, 350, 400);

			EndPaint(hWnd, &ps);
	}
		break;
	//���콺 ��ġ�� IParam �� ������ �Ǵµ� 16��Ʈ�� �ɰ��� x,y ����
	//32��Ʈ ������ ������ �ȴ�.
	//LoWoRD, HIWORD ��ũ�θ� �̿��ؼ� ���� ���� 16��Ʈ�� ���� ���ü��ִ�.
	case WM_LBUTTONDOWN:
        if (!tagArea.mouseDown)
        {
            tagArea.mouseDown = true;
            tagArea.ptStart.x = tagArea.ptEnd.x = lParam & 0x0000ffff;
            tagArea.ptStart.y = tagArea.ptEnd.y = lParam >> 16;
            //InvalidateRect�Լ��� ������ WM_PAINT �޼�����
            //ȣ�����ִ� �Լ��̴�.
            //1�� ���ڴ� ������ �ڵ��� ����.
            //2�� ���ڴ� ������ ������ ���µ�
            //NULL�� �־��� ��� ��ü ȭ���� ������� �ʱ�ȭ �Ѵ�.
            //3�����ڴ� TRUE�ϰ�� ����ȭ���� ����� �����Ѵ�.
            //FALSE�ϰ�� ����ȭ���� ����� ����.
            InvalidateRect(hWnd, NULL, true);
        }
		break;
    case WM_MOUSEMOVE:
        if (tagArea.mouseDown)
        {
            tagArea.ptStart.x = lParam & 0x0000ffff;
            tagArea.ptStart.y = lParam >> 16;
            InvalidateRect(hWnd, NULL, true);
        }
        break;
	case WM_LBUTTONUP:
        if (tagArea.mouseDown)
        {
            tagArea.mouseDown = false;
            tagArea.ptEnd.x = lParam & 0x0000ffff;
            tagArea.ptEnd.y = lParam >> 16;
            InvalidateRect(hWnd, NULL, true);
        }

        break;
    //Ű�� ���������� ������ �޼����̴�.
    case WM_KEYDOWN:
        
        switch (wParam)
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
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
